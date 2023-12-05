#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define FOR(i, n) for (register int (i) = 0; (i) < (n); ++(i))
 
constexpr int TRIE_SIZE = 400000, ROOM_SIZE = 30000, CHILD_SIZE = 26, OFFSET = 'a';
 
struct TrieNode {
    int child[CHILD_SIZE];
    int isTerminal;
};
struct Trie {
    TrieNode arr[TRIE_SIZE];
    int size;
 
    void init() {
        memset(arr[0].child, 0, sizeof(arr[0].child));
        size = 1;
    }
    void insert(const char* str, int roomNum) {
        int cur = 0;
        while (char c = *(str++)) {
            int chIdx = c - OFFSET;
            if (!arr[cur].child[chIdx]) {
                memset(arr[size].child, 0, sizeof(arr[size].child));
                arr[size].isTerminal = 0;
                arr[cur].child[chIdx] = size++;
            }
            cur = arr[cur].child[chIdx];
        }
        arr[cur].isTerminal = roomNum;
    }
    void remove(const char* str) {
        int cur = 0;
        while (char c = *(str++))
            cur = arr[cur].child[c - OFFSET];
        arr[cur].isTerminal = 0;
    }
} trie, revTrie;
 
struct Room {
    char word[12];
    int len[3];
} roomPool[ROOM_SIZE + 1];
 
unordered_map<string, int> roomHash;
unordered_map<int, unordered_set<int>> midHash;
 
int midCompress(const char* str) {
    int rslt = 0;
    FOR(i, 3) rslt = (rslt << 5) | (str[4 + i] ^ 96);
    return rslt;
}
 
void mStrrev(char* str) {
    register int len = strlen(str);
    FOR(i, len / 2) swap(str[i], str[len - i - 1]);
}
 
//////////////////////////////////////////////////////////////////////////////////////
 
void init() {
    trie.init(); revTrie.init();
    roomHash.clear();
    midHash.clear();
}
 
void addRoom(int mID, char mWord[], int mDirLen[]) {
    Room& curRoom = roomPool[mID];
    strcpy(curRoom.word, mWord);
    FOR(i, 3) curRoom.len[i] = mDirLen[i];
 
    trie.insert(mWord, mID);
    mStrrev(mWord);
    revTrie.insert(mWord, mID);
    roomHash[curRoom.word] = mID;
 
    int comp = midCompress(curRoom.word);
    if (midHash.find(comp) == midHash.end()) midHash[comp] = unordered_set<int>();
    midHash[midCompress(curRoom.word)].insert(mID);
}
 
int curRoomIdx;
void setCurrent(char mWord[]) {
    curRoomIdx = roomHash[mWord];
}
 
int findTrie(Trie& t, const char* str) {
    int cur = 0;
    while (char c = *(str++)) {
        int chIdx = c - OFFSET;
        if (t.arr[cur].child[chIdx]) cur = t.arr[cur].child[chIdx];
        else return 0;
    } return cur;
}
void dfs(Trie& t, int cur, int& rslt) {
    TrieNode& curNode = t.arr[cur];
    int curRoomID = curNode.isTerminal;
    if (curRoomID && curRoomID != curRoomIdx) {
        if (rslt == 0) rslt = curRoomID;
        else if (strcmp(roomPool[rslt].word, roomPool[curRoomID].word) > 0) rslt = curRoomID;
    }
    FOR(i, CHILD_SIZE) if (curNode.child[i]) dfs(t, curNode.child[i], rslt);
}
 
int moveDir(int mDir) {
    Room& curRoom = roomPool[curRoomIdx];
    if (mDir == 1) {
        unordered_set<int>& curUS = midHash[midCompress(curRoom.word)];
        if (curUS.size() == 1) return 0;
         
        int rslt = 0;
        for (auto it = curUS.begin(); it != curUS.end(); ++it) if ((*it) != curRoomIdx) {
            if (rslt == 0) rslt = (*it);
            else if (strcmp(roomPool[rslt].word, roomPool[*it].word) > 0) rslt = (*it);
        }
        if (rslt == 0) return 0;
        return curRoomIdx = rslt;
    }
 
    int curLen = curRoom.len[mDir];
    char targetStr[12]; strcpy(targetStr, curRoom.word);
    if (mDir == 2) mStrrev(targetStr);
 
    if (mDir == 0) {
        strcpy(targetStr, curRoom.word);
        targetStr[curLen] = '\0';
        mStrrev(targetStr);
    }
    else {
        FOR(i, curLen) targetStr[i] = curRoom.word[11 - curLen + i];
        targetStr[curLen] = '\0';
    }
 
    int trieIdx = findTrie((mDir == 0 ? revTrie : trie), targetStr);
    if (trieIdx == 0) return 0;
 
    int rslt = 0;
    dfs((mDir == 0 ? revTrie : trie), trieIdx, rslt);
    if (rslt == 0) return 0;
    return curRoomIdx = rslt;
}
 
void changeWord(char mWord[], char mChgWord[], int mChgLen[]) {
    int curRID = roomHash[mWord];
    Room& curRoom = roomPool[curRID];
    strcpy(curRoom.word, mChgWord);
    FOR(i, 3) curRoom.len[i] = mChgLen[i];
    midHash[midCompress(mWord)].erase(curRID);
 
    trie.remove(mWord), mStrrev(mWord), revTrie.remove(mWord);
    trie.insert(mChgWord, curRID), mStrrev(mChgWord), revTrie.insert(mChgWord, curRID);
    roomHash[curRoom.word] = curRID;
    midHash[midCompress(curRoom.word)].insert(curRID);
}