#include<set>
#include<unordered_map>
#include<algorithm>
using namespace std;
 
set<pair<int, int>> Machine; // {mTime, mId}
unordered_map<int, int> Map; //{ mId, mTime }
 
void global_reset()
{
    Machine.clear();
    Map.clear();
}
 
void init(int N, int mId[], int mTime[]) {
 
    global_reset();
 
    for (int i = 0; i < N; i++)
    {
        Machine.insert({mTime[i], mId[i]});
        Map[mId[i]] = mTime[i];
    }
    return;
}
 
int add(int mId, int mTime) {
     
    if (Map.find(mId) != Map.end())
    {
        Machine.erase({Map[mId], mId}); //Delete old one
    }
 
    Machine.insert({mTime, mId}); //insert new one
    Map[mId] = mTime;
     
    return Machine.size();
}
 
int remove(int K) {
 
    int ans = 0;
    pair<int, int> now;
 
    while (K-- && Machine.size())
    {
        auto pos = --Machine.end();
        now = *pos;
        Machine.erase(pos);
 
        Map.erase(now.second);
    }
 
    if (Machine.size() > 0)
    {
        now = *Machine.rbegin();
        ans = now.second;
    }
 
    return ans;
}
 
bool isGood(int time, int M)
{
    int cnt = 0;
    for (auto x : Machine)
    {
        cnt += (time / x.first);
    }
 
    return cnt >= M;
}
 
int produce(int M) {
    int ans = -1;
 
    int beg = 0, end = M * 3000;
 
    while (beg <= end)
    {
        int mid = (beg + end) / 2;
        if (isGood(mid, M))
        {
            ans = mid; 
            end = mid - 1;
        }
        else beg = mid + 1;
    }
 
    return ans;
}