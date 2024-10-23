#include<string.h>
#include<unordered_map>
#include<utility>
#include<queue>
#include<algorithm>
#include<set>
#include<iostream>
using namespace std;
  
  
#define MAX_N (3000)
  
  
int dist[MAX_N + 5][3];
unordered_map<int, vector<pair<int, int>>> adj;
int idx2id[MAX_N + 5];
unordered_map<int, int> id2idx;
unordered_map<int, int> downtownlist;
int n, lim;
int a[MAX_N + 5];
int cost[MAX_N + 5];
  
  
struct City
{
    int cost;
    int dist_sum;
    int ID;
  
  
    City()
    {
        cost = dist_sum = ID = 0;
    }
  
  
    City(int _cost, int _dist[], int opt, int _ID)
    {
        ID = _ID;
        cost = _cost;
  
  
        dist_sum = 0;
        for (int i = 0; i < 3; i++)
        {
            if ((opt & (1 << i)) == 0)
                continue;
  
  
            dist_sum += _dist[i];
        }
    }
};
  
  
struct citycmp
{
    bool operator()(const City& l, const City& r) const
    {
        if (l.cost != r.cost)
            return l.cost < r.cost;
  
  
        if (l.dist_sum != r.dist_sum)
            return l.dist_sum < r.dist_sum;
  
  
        return l.ID < r.ID;
    }
};
  
  
vector<City> b[MAX_N + 5];
  
  
void init(int N, int mDownTown[])
{
    memset(dist, 0, sizeof(dist));
    memset(cost, 0, sizeof(cost));
    memset(idx2id, 0, sizeof(idx2id));
    adj.clear();
    id2idx.clear();
  
  
    downtownlist.clear();
    n = N;
    lim = 0;
  
  
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        b[i].clear();
  
  
    }
  
  
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mDownTown[0] || a[i] == mDownTown[1] || a[i] == mDownTown[2])
        {
            swap(a[i], a[k]);
            k++;
        }
    }
  
  
    for (int i = 0; i < 3; i++)
    {
        downtownlist[a[i]] = i;
    }
  
  
    sort(a + 3, a + n);
  
  
    for (int i = 0; i < n; i++)
    {
        id2idx[a[i]] = i;
        idx2id[i] = a[i];
    }
}
  
  
queue<pair<int, int >> q;
set<City, citycmp> cand[7];
const int mask[7] = { 1,2,4,3,5,6,7 };
void newLine(int M, int mCityIDs[], int mDistances[])
{
    for (int i = 0; i < M - 1; i++)
    {
        int x = id2idx[mCityIDs[i]];
        int y = id2idx[mCityIDs[i + 1]];
        int w = mDistances[i];
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }
  
  
}
  
  
void changeLimitDistance(int mLimitDistance)
{
    lim = mLimitDistance;
  
  
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < n; k++)
            dist[k][i] = 2e7;
    }
  
  
    for (int i = 0; i < 3; i++)
    {
        pair<int, int> here = { i, 0 };
        dist[here.first][i] = here.second;
        q.push(here);
  
  
        while (q.empty() == false)
        {
            here = q.front();
            q.pop();
  
  
            for (auto it : adj[here.first])
            {
                pair<int, int> there = { it.first, it.second + here.second };
  
  
                if (dist[there.first][i] <= there.second)
                    continue;
  
  
                dist[there.first][i] = there.second;
                q.push(there);
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        cand[i].clear();
    }
  
  
    for (int i = 3; i < n; i++)
    {
        b[i].clear();
  
  
        for (int k = 0; k < 7; k++)
        {
            b[i].push_back(City(cost[i], dist[i], mask[k], idx2id[i]));
            if (b[i][k].dist_sum <= lim)
            {
                cand[k].insert(b[i][k]);
            }
        }
    }
}
  
  
int findCity(int mOpt, int mDestinations[])
{
    cout << "adf " << endl;
    int ret = -1;
    int opt = 0;
    for (int i = 0; i < mOpt; i++)
    {
        opt |= 1 << downtownlist[mDestinations[i]];
    }
  
  
    int c = 0;
    for (int i = 0; i < 7; i++)
    {
        if (opt == mask[i])
        {
            c = i;
        }
    }
  
  
    if (cand[c].size() == 0)
        return -1;
  
  
    ret = cand[c].begin()->ID;
  
  
    int idx = id2idx[ret];
    cost[idx]++;
    for (int i = 0; i < 7; i++)
    {
        if (b[idx][i].dist_sum <= lim)
        {
            cand[i].erase(b[idx][i]);
            b[idx][i].cost++;
            cand[i].insert(b[idx][i]);
        }
    }
    return ret;
}