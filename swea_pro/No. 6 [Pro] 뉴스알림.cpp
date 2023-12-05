#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define FOR(i, n) for (register int (i) = 0; (i) < (n); ++(i))
 
struct News;
struct User {
    vector<News*> notify;
} userArr[5000];
 
struct Channel {
    vector<User*> userInfo;
} channelArr[150000];
 
struct News {
    int start, end, nID;
    bool valid;
    Channel* from;
} newsArr[30000];
 
struct mHeap {
    News* arr[30000];
    int size = 0;
 
    void init() { size = 0; }
    bool cmp(const News* a, const News* b) {
        if (a->end == b->end) return a->nID < b->nID;
        else return a->end < b->end;
    }
    void push(News* x) {
        arr[++size] = x;
        register int cur = size, p = cur >> 1;
        while (cur > 1) {
            register int p = cur >> 1;
            if (cmp(arr[p], arr[cur])) break;
            swap(arr[p], arr[cur]); cur = p;
        }
    }
    News* pop() {
        News* temp = arr[1];
        arr[1] = arr[size--];
        register int cur = 1, l = cur << 1, r = l | 1, ch = l;
        while (l <= size) {
            if (r <= size && cmp(arr[r], arr[l])) ch = r;
            if (cmp(arr[cur], arr[ch])) break;
            swap(arr[ch], arr[cur]);
            cur = ch, l = cur << 1, r = l | 1, ch = l;
        }
        return temp;
    }
} mPQ;
 
unordered_map<int, User*> userHash;
unordered_map<int, Channel*> channelHash;
unordered_map<int, News*> newsHash;
int newsCount, channelCount, userCount;
 
void notifyUser(int mTime) {
    while (mPQ.size && mPQ.arr[1]->end <= mTime) {
        News* curNews = mPQ.pop();
        if (!curNews->valid) continue;
        for (auto& curUser : curNews->from->userInfo) {
            curUser->notify.push_back(curNews);
        }
    }
}
 
//////////////////////////////////////////////////////////////////////////
 
void init(int N, int K) {
    mPQ.init();
    newsCount = channelCount = userCount = 0;
    userHash.clear(), channelHash.clear(), newsHash.clear();
}
 
void registerUser(int mTime, int mUID, int mNum, int mChannelIDs[]) {
    notifyUser(mTime);
 
    User* curUser;
    if (userHash.find(mUID) == userHash.end()) {
        User& newUser = userArr[userCount++];
        newUser.notify.clear();
        curUser = userHash[mUID] = &newUser;
    }
    else curUser = userHash[mUID];
 
     
    FOR(i, mNum) {
        Channel* curChannel;
        if (channelHash.find(mChannelIDs[i]) == channelHash.end()) {
            Channel& newChannel = channelArr[channelCount++];
            newChannel.userInfo.clear();
            curChannel = channelHash[mChannelIDs[i]] = &newChannel;
        }
        else curChannel = channelHash[mChannelIDs[i]];
        curChannel->userInfo.push_back(curUser);
    }
}
 
int offerNews(int mTime, int mNewsID, int mDelay, int mChannelID) {
    Channel* curChannel = channelHash[mChannelID];
    News* curNews;
    if (newsHash.find(mNewsID) == newsHash.end()) {
        News& newNews = newsArr[newsCount++];
        newNews = { mTime, mTime + mDelay, mNewsID, true, curChannel };
        curNews = newsHash[mNewsID] = &newNews;
    }
    else curNews = newsHash[mNewsID];
    mPQ.push(curNews);
    return curChannel->userInfo.size();
}
 
void cancelNews(int mTime, int mNewsID) {
    newsHash[mNewsID]->valid = false;
}
 
int checkUser(int mTime, int mUID, int mRetIDs[]) {
    notifyUser(mTime);
    int ans = 0;
    vector<News*>& notify = userHash[mUID]->notify;
    for (register int i = notify.size() - 1; i >= 0; --i) {
        News*& curNews = notify[i];
        if (curNews->valid) if (++ans <= 3) mRetIDs[ans - 1] = curNews->nID;
    }
    notify.clear();
    return ans;
}