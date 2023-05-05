#include<iostream>
#include<deque>
using namespace std;

#define N 10005

class node {
public:
    int time;
    int start;
    int len;
    int end;
    node(int t, int s, int l) {
        time = t;
        start = s;
        len = l;
        end = s + l - 1;
    }
};

int r, c;
int total;
deque<node*>dq;
int arr[N];
int removed[N];


void check(int time) {


    while (!dq.empty()) {
        node* temp = dq.back();
        int a = temp->start;
        int b = temp->len;
        int t = temp->time;

        if (time < t + r) return;
        
        for (int i = 0; i < b; i++)
        {
            if (removed[i+a] >0) {
                removed[i+a] --;
            }
            else {
                arr[a + i]--;
                total--;
            }
        }
        //cout << temp->time <<"TIME"<< endl;
        dq.pop_back();
    }
}

void init(int R, int C)
{
    r = R;
    c = C;
    dq.clear();
    total = 0;
    //memset(arr, 0, sizeof(arr));
    //memset(removed, 0, sizeof(removed));
    for (int i = 0; i <= c; i++) {
        arr[i] = 0;
        removed[i] = 0;
    }
}

int dropBlocks(int mTimestamp, int mCol, int mLen)
{
    check(mTimestamp);
    node* t = new node(mTimestamp, mCol, mLen);
    dq.push_front(t);
    total += mLen;
    for (int i = 0; i < mLen; i++) {
        arr[mCol + i]++;
    }
    //for (int i = 0; i < c; i++)cout << arr[i] << " ";
    //cout << endl;
    //for (int i = 0; i < c; i++)cout << removed[i] << " ";
    //cout << endl;
    //cout << total << endl;
    

    return total;
}

int removeBlocks(int mTimestamp)
{
    //Check if any of the block removes or not.
    check(mTimestamp);
    //remove the lower range
    for (int i = 0; i < c; i++) {
        if (arr[i] > 0) {
            arr[i]--;
            total--;
            removed[i]++;

        }
    }

    //for (int i = 0; i < c; i++)cout << arr[i] << " ";
    //cout << endl;
    //for (int i = 0; i < c; i++)cout << removed[i] << " ";
    //cout << endl;
    //cout << total << endl;
    return total;
}

