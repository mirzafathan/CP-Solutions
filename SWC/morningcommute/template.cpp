#include <vector>
#include<algorithm>
using namespace std;
 
struct segmentTree
{
    vector<int> st;
    int n = 0;
 
 
    void init(int _n)
    {
        n = _n;
        st.resize(4 * n + 1, 0);
    }
    void buildHelper(int node, int beg, int end, vector<int> &a)
    {
        if (beg == end)
        {
            //leaf
            st[node] = a[beg];
            return;
        }
        int mid = (beg + end) / 2;
        buildHelper(2 * node, beg, mid, a);             //left-subTree
        buildHelper(2 * node + 1, mid + 1, end, a);        //right-subTree
        st[node] = st[2 * node] + st[2 * node + 1];
 
 
    }
    void build(vector<int> &a)
    {
        init(a.size());
        buildHelper(1, 0, n - 1, a);
    }
    void updateHelper(int node, int beg, int end, int i, int value)
    {
        if (beg == end) //leaf
        {
            if (beg == i)
            {
                st[node] = value;
            }
            return;
        }
        int mid = (beg + end) / 2;
        if (i <= mid) updateHelper(2 * node, beg, mid, i, value); //left-subTree
        else updateHelper(2 * node + 1, mid + 1, end, i, value); //right - subTree
        st[node] = st[2 * node] + st[2 * node + 1];
    }
    void update(int i, int value)
    {
        updateHelper(1, 0, n - 1, i, value);
    }
    int sumHelper(int node, int beg, int end, int l, int r)
    {
        //no - overlap
        if (end < l || r < beg) return 0;
        //Full - overlap
        if (l <= beg && end <= r) return st[node];
        //partial-overlap
        int mid = (beg + end) / 2;
        return sumHelper(2 * node, beg, mid, l, r) + sumHelper(2 * node + 1, mid + 1, end, l, r);
    }
    int sum(int l, int r)
    {
        return sumHelper(1, 0, n - 1, l, r);
    }
};
 
 
vector<int> pathTime;
vector<int> pathType;
 
 
segmentTree tree;
 
 
void init(int N, int M, int mType[], int mTime[])
{
    pathTime.resize(N - 1, 0); //sections = N - 1
    pathType.resize(N - 1, 0);
 
 
    for (int i = 0; i < N - 1; i++)
    {
        pathTime[i] = mTime[i];
        pathType[i] = mType[i];
    }
 
 
    tree.build(pathTime);
}
 
 
void destroy()
{
 
 
}
 
 
void update(int mID, int mNewTime)
{
    pathTime[mID] = mNewTime;
    tree.update(mID, mNewTime);
}
 
 
int updateByType(int mTypeID, int mRatio256)
{
    int sum = 0;
    for (int i = 0; i < pathType.size(); i++)
    {
        if (pathType[i] != mTypeID) continue;
 
 
        pathTime[i] = pathTime[i] * mRatio256 / 256;
 
 
        tree.update(i, pathTime[i]);
 
 
        sum += pathTime[i];
    }
    return sum;
}
 
 
int calculate(int mA, int mB)
{
    int mn = min(mA, mB); //IMP
    int mx = max(mA, mB); //IMP
    return tree.sum(mn, mx - 1);
}
