#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
 
typedef unsigned long long ull;
#define FOR(i, n) for (register int (i) = 0; (i) < (n); ++(i))
#define FOR1(i, n) for (register int (i) = 1; (i) <= (n); ++(i))
#define MAXL 10
 
constexpr int PLAYER_SIZE = 50, CARD_SIZE = 10000, SUBJECT_SIZE = 20, OFFSET = 'a';
 
struct TrieNode {
    int isEnd;
    int child[26];
};
struct Trie {
    TrieNode node[CARD_SIZE * MAXL];
    int nodeCount = 0;
 
    void init() {
        memset(node[0].child, 0, sizeof(node[0].child));
        nodeCount = 1;
    }
    void insert(const char* str, int cardNum) {
        register int cur = 0;
        while (char c = *(str++)) {
            register int chNum = c - OFFSET;
            if (node[cur].child[chNum]) cur = node[cur].child[chNum];
            else {
                node[nodeCount].isEnd = 0;
                memset(node[nodeCount].child, 0, sizeof(node[nodeCount].child));
                cur = node[cur].child[chNum] = nodeCount++;
            }
        }
        node[cur].isEnd = cardNum;
    }
} subTrie[SUBJECT_SIZE];
 
unordered_map<ull, int> subjectHash;
int trieCount;
 
struct Player {
    bool valid;
    int score;
    int cardVisit[CARD_SIZE + 1];
} playerArr[PLAYER_SIZE + 1];
 
struct Card {
    char name[MAXL + 1];
    int playerCount;
    bool playerVisit[PLAYER_SIZE + 1];
} cardArr[CARD_SIZE + 1];
 
ull strComp(const char* str) {
    ull ans = -1; char c;
    while (c = *(str++)) ans = (ans << 5) | (c ^ 96);
    return ans;
}
 
bool cmp(const int& a, const int& b) {
    if (cardArr[a].playerCount == cardArr[b].playerCount)
        return strcmp(cardArr[a].name, cardArr[b].name) < 0;
    else return cardArr[a].playerCount > cardArr[b].playerCount;
}
 
struct Heap {
    int arr[CARD_SIZE], size;
 
    void init() { size = 0; }
    void push(int x) {
        arr[++size] = x;
        register int cur = size, p = cur >> 1;
        while (cur > 1) {
            if (cmp(arr[p], arr[cur])) break;
            swap(arr[p], arr[cur]);
            cur = p, p = cur >> 1;
        }
    }
    int pop() {
        int rslt = arr[1];
        arr[1] = arr[size--];
        register int cur = 1, l = cur << 1, r = l | 1, ch = l;
        while (l <= size) {
            if (r <= size && cmp(arr[r], arr[l])) ch = r;
            if (cmp(arr[cur], arr[ch])) break;
            swap(arr[cur], arr[ch]);
            cur = ch, l = cur << 1, r = l | 1, ch = l;
        }
        return rslt;
    }
} pq;
 
////////////////////////////////////////////////////////////////////////////
void init(int N, char mWordList[][MAXL + 1], char mSubjectList[][MAXL + 1]) {
    FOR1(i, PLAYER_SIZE) playerArr[i].valid = false;
    trieCount = 0;
 
    FOR(i, N) {
        ull curSub = strComp(mSubjectList[i]);
        if (subjectHash.find(curSub) == subjectHash.end()) {
            subTrie[trieCount].init();
            subjectHash[curSub] = trieCount++;
        }
        subTrie[subjectHash[curSub]].insert(mWordList[i], i + 1);
 
        Card& curCard = cardArr[i + 1];
        strcpy(curCard.name, mWordList[i]);
        curCard.playerCount = 0;
        memset(curCard.playerVisit, 0, sizeof(curCard.playerVisit));
    }
}
 
void join(int mID, int M, int mCardList[]) {
    Player& curP = playerArr[mID];
    curP.score = 0, curP.valid = true;
    memset(curP.cardVisit, 0, sizeof(curP.cardVisit));
    FOR(i, M) if (curP.cardVisit[mCardList[i]]++ == 0) {
        cardArr[mCardList[i]].playerCount++;
        cardArr[mCardList[i]].playerVisit[mID] = true;
    }
}
 
void dfs(Trie& trie, int idx) {
    TrieNode& curNode = trie.node[idx];
    if (curNode.isEnd) pq.push(curNode.isEnd);
    FOR(i, 26) if (curNode.child[i]) dfs(trie, curNode.child[i]);
}
 
int playRound(char mBeginStr[], char mSubject[]) {
    Trie& curTrie = subTrie[subjectHash[strComp(mSubject)]];
 
    register int cur = 0;
    while (char c = *(mBeginStr++)) {
        if (!curTrie.node[cur].child[c - OFFSET]) return 0;
        cur = curTrie.node[cur].child[c - OFFSET];
    }
 
    pq.init();
    dfs(curTrie, cur);
 
    bool playerCheck[PLAYER_SIZE + 1] = { 0, };
    FOR1(i, PLAYER_SIZE) if (playerArr[i].valid) playerCheck[i] = true;
 
    register int ans = 0;
    while (pq.size) {
        register int curCardNum = pq.pop();
        Card& curCard = cardArr[curCardNum];
 
        register int curCardPlayerCount = 0;
        vector<Player*> usePlayer;
 
        FOR1(i, PLAYER_SIZE) if (curCard.playerVisit[i] && playerCheck[i]) {
            Player& curPlayer = playerArr[i];
            ans += curCardNum;
            if (--curPlayer.cardVisit[curCardNum] == 0) {
                curCard.playerCount--;
                curCard.playerVisit[i] = false;
            }
            playerCheck[i] = false;
            curCardPlayerCount++;
            usePlayer.push_back(&curPlayer);
        }
        curCardPlayerCount = (curCardPlayerCount - 1) * (curCardPlayerCount - 1);
        for (auto& p : usePlayer) p->score += curCardPlayerCount;
    }
    return ans;
}
 
int leave(int mID) {
    Player& curP = playerArr[mID];
    FOR1(i, CARD_SIZE) if (curP.cardVisit[i]) {
        cardArr[i].playerCount--;
        cardArr[i].playerVisit[mID] = false;
    }
    curP.valid = false;
    return curP.score;
}