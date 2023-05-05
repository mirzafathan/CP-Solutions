#include <vector>
#include <algorithm>

using namespace std;
typedef struct segTree {
    vector<int> node;
    int size;
} segTree;

vector<int> input;
segTree ST;
vector<vector<int>> typeIdx;
int NPoint, NType;

void buildTree(int beg, int end, int pos, segTree* ST) { 
    if(beg==end) {
        ST->node[pos] = input[beg];
        //cout << "beg==end: ";
        //cout << ST->node[pos];
        //cout << ", pos: " << pos << endl;

    } else {
        int mid = (beg + end) / 2;

        buildTree(beg, mid, 2*pos + 1, ST);

        buildTree(mid + 1, end, 2*pos + 2, ST);

        ST->node[pos] = ST->node[2*pos + 1] + ST->node[2*pos + 2];
        //cout << "else: ";
        //cout << ST->node[pos];
        //cout << ", pos: " << pos << endl;
    }


}

void updateTree(int idx, int pos, int beg, int end, int val) {
    //cout << "test " << pos << endl;
    if((beg == end) && (beg == idx)) {
        //cout << "beg==end: ";
        //cout << ST->node[pos];
        //cout << ", pos: " << pos << endl;
        input[idx] = val;
        ST.node[pos] = val;
    } else {
        int mid = (beg + end) / 2;

        if((beg <= idx) && (idx <= mid)) {
            updateTree(idx, 2*pos + 1, beg, mid, val);
        } else {
            updateTree(idx, 2*pos + 2, mid + 1, end, val);
        }

        ST.node[pos] = ST.node[2*pos + 1] + ST.node[2*pos + 2];

        //cout << "else: ";
        //cout << ST->node[pos];
        //cout << ", pos: " << pos << endl;
    }
}

int rangeQuery(int pos, int l, int r, int beg, int end) {
    if((r<beg) || (l>end)) {
        //no overlap
        //cout << "no overlap" << endl;
        //cout << "l: " << l << ", r: " << r << ", beg: " << beg << ", end: " << end << endl;
        return 0;
    } else if ((l<=beg) && (end<=r)) {
        //complete overlap
        //cout << "complete overlap" << endl;
        return ST.node[pos];
    } else {
        //partial overlap
        //cout << "partial overlap" << endl;
        int mid = (beg + end) / 2;
        return rangeQuery(2*pos + 1, l, r, beg, mid) + rangeQuery(2*pos + 2, l, r, mid+1, end);
    }
}

//void printTree(segTree ST) {
//    for(int i=0; i<ST.node.size(); i++) {
//        cout << ST.node[i] << " ";
//    }
//    cout << endl;
//}

//void printTypeMatrix() {
//    cout << "printTypeMatrix" << endl;
//    for(int i=0; i<typeIdx.size(); i++) {
//        for(int j=0; j<typeIdx[i].size(); j++) {
//            cout << typeIdx[i][j] << " ";
//        } cout << endl;
//    }
//}

void init(int N, int M, int mType[], int mTime[])
{
    NPoint = N;
    NType = M;
    ST.size = 4*N;
    ST.node.resize(ST.size);
    
    typeIdx.resize(M);

    for(int i=0; i<N-1; i++) {
        input.push_back(mTime[i]);
        typeIdx[mType[i]].push_back(i);
    }

    //cout << "input: ";
    //for(int i=0; i<N-1; i++) {
    //    cout << input[i] << " ";
    //} cout << ", size: " << input.size() << endl;
//
    buildTree(0, N-2, 0, &ST);
    //cout << "init: ";
    //printTree(ST);

    //printTypeMatrix();
}

void destroy()
{
    ST.node.clear();
    ST.size = 0;
    typeIdx.clear();
    input.clear();
}

void update(int mID, int mNewTime)
{
   //cout << "update: " << mID << " " << mNewTime << endl; 
   //cout << NPoint-2 << endl;
   //cout << input.size() << endl;
   //cout << "tree size: " << ST.size << endl;
    updateTree(mID, 0, 0, NPoint-2, mNewTime);
    //printTree(ST);
}

int updateByType(int mTypeID, int mRatio256)
{
    int sum = 0;
    for(int i=0; i<typeIdx[mTypeID].size(); i++) {
        int idx = typeIdx[mTypeID][i];
        int newTime = input[idx] * mRatio256 / 256;
        input[idx] = newTime;
        updateTree(idx, 0, 0, NPoint-2, newTime);
        sum+=newTime;
    }
    //cout << "sum: " << sum << endl;
	return sum;
}

int calculate(int mA, int mB)
{
    int a = 0;
    if(mB > mA) 
        a = rangeQuery(0, mA, mB-1, 0, NPoint - 2);
    else
        a = rangeQuery(0, mB, mA-1, 0, NPoint - 2);
    //cout << "calculate: " << a << endl;
    //printTree(ST);
	return a;
}