#include <queue>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define FOR(i, n) for (register int (i) = 0; (i) < (n); ++(i))
 
constexpr int FILE_SIZE = 500000, BRANCH_SIZE = 10001, MASK = 0b11111, QUEUE_SIZE = 52;
constexpr ll ROOT_NAME = 605684;
 
template <typename NODE>
struct CircularQueue {
    NODE arr[QUEUE_SIZE];
    int st, en;
 
    CircularQueue() : st(0), en(0) {}
 
    NODE pop() {
        NODE temp = arr[st];
        st = (st + 1) % QUEUE_SIZE;
        return temp;
    }
    void push(NODE x) {
        if ((en - st + QUEUE_SIZE) % QUEUE_SIZE == 50) pop();
        arr[en] = x;
        en = (en + 1) % QUEUE_SIZE;
    }
 
    void clear() { st = en = 0; }
    bool empty() { return st == en; }
    NODE front() { return arr[st]; }
};
 
struct File {
    ll name, content;
    int create, modify;
};
struct Branch {
    ll name; bool valid;
    Branch* parent;
    CircularQueue<File*> file;
    queue<Branch*> child;
};
 
// fileHash[압축가지이름] = 가지 주소
unordered_map<ll, Branch*> branchHash;
 
// 메모리 풀로 정리
File fileArr[FILE_SIZE];
Branch branchArr[BRANCH_SIZE];
int fileCount, branchCount;
 
// 문자열 압축
ll str_compression(const char* str) {
    ll ans = 0; char c;
    while (c = *(str++)) ans = (ans << 5) | (c ^ 96);
    return ans;
}
// 문자열 압축해제
int str_decompression(ll compressed, char* rslt) {
    int len = 0;
    while (compressed > 0) {
        rslt[9 - len] = (compressed & MASK) ^ 96;
        len++, compressed >>= 5;
    }
    FOR(i, len) rslt[i] = rslt[i + 10 - len];
    rslt[len] = '\0';
    return len;
}
 
File* find_file(Branch* branch, ll target) {
    for (register int idx = branch->file.st; idx != branch->file.en; idx = (idx + 1) % QUEUE_SIZE)
        if (branch->file.arr[idx]->name == target) return branch->file.arr[idx];
}
 
//////////////////////////////////////////////////////////////////////////////////
void init() {
    fileCount = branchCount = 0;
    Branch& root = branchArr[branchCount++];
    branchHash[ROOT_NAME] = &root;
    root = { ROOT_NAME, true, nullptr };
    root.file.clear();
    while (!root.child.empty()) root.child.pop();
}
 
void create(int mTime, char mBranch[], char mFile[], char mData[]) {
    Branch* curBranch = branchHash[str_compression(mBranch)];
    fileArr[fileCount] = { str_compression(mFile), str_compression(mData), mTime, mTime };
    curBranch->file.push(&fileArr[fileCount++]);
}
 
void edit(int mTime, char mBranch[], char mFile[], char mData[]) {
    Branch* curBranch = branchHash[str_compression(mBranch)];
    File* target = find_file(curBranch, str_compression(mFile));
    target->content = str_compression(mData);
    target->modify = mTime;
}
 
void branch(int mTime, char mBranch[], char mChild[]) {
    Branch* parentBranch = branchHash[str_compression(mBranch)];
 
    Branch& childBranch = branchArr[branchCount++];
    childBranch = { str_compression(mChild), true, parentBranch };
    branchHash[childBranch.name] = &childBranch;
    while (!childBranch.child.empty()) childBranch.child.pop();
 
    parentBranch->child.push(&childBranch);
 
    for (register int idx = parentBranch->file.st; idx != parentBranch->file.en; idx = (idx + 1) % QUEUE_SIZE) {
        File* curFile = parentBranch->file.arr[idx];
        fileArr[fileCount] = { curFile->name, curFile->content, curFile->create, curFile->modify };
        childBranch.file.push(&fileArr[fileCount++]);
    }
}
 
CircularQueue<File*> orig, temp;
unordered_map<ll, File*> fileVisit;
 
void merge_rec(Branch* cur) {
    while (!cur->child.empty()) {
        Branch* nxt = cur->child.front(); cur->child.pop();
        if (nxt->valid) merge_rec(nxt);
    }
 
    Branch* parent = cur->parent;
    fileVisit.clear();
 
    while (!parent->file.empty()) {
        File* curFile = parent->file.pop();
        fileVisit[curFile->name] = curFile;
        orig.push(curFile);
    }
 
    while (!cur->file.empty()) {
        File* curFile = cur->file.pop();
        if (fileVisit.find(curFile->name) == fileVisit.end()) {
            temp.push(curFile);
        }
        else {
            File* prevFile = fileVisit[curFile->name];
            if (prevFile->create == curFile->create && prevFile->modify < curFile->modify)
                prevFile->content = curFile->content, prevFile->modify = curFile->modify;
        }
    }
 
    while (!orig.empty() && !temp.empty())
        if (orig.front()->create < temp.front()->create) parent->file.push(orig.front()), orig.pop();
        else parent->file.push(temp.front()), temp.pop();
 
    while (!orig.empty()) parent->file.push(orig.front()), orig.pop();
    while (!temp.empty()) parent->file.push(temp.front()), temp.pop();
 
    cur->valid = false;
}
 
void merge(int mTime, char mBranch[]) {
    merge_rec(branchHash[str_compression(mBranch)]);
}
 
int readfile(int mTime, char mBranch[], char mFile[], char retString[]) {
    Branch* curBranch = branchHash[str_compression(mBranch)];
    File* target = find_file(curBranch, str_compression(mFile));
    return str_decompression(target->content, retString);
}