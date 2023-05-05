// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
#include <stdio.h>

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
/************************/
/* TEMPLATES */

#define fr front
#define bk back
#define pb push_back
#define mp make_pair
#define sc second
#define fi first
# define ll long long
# define ld long double
# define rep(i,x,y) for(ll i=x;i<y;i++)
# define rrep(i,x,y) for(ll i=x;i>=y;i--)
# define debug_stl(x) for(auto i:x){cout<<i<<" ";}cout<<endl;
# define debug_1d(x,a,b) rep(i,a,b){cout<<x[i]<<" ";}cout<<endl;
# define debug_2d(x,a1,b1,a2,b2) rep(i,a1,b1){rep(j,a2,b2){cout<<x[i][j]<<" ";}cout<<endl;}
# define all(x) x.begin(), x.end()
# define MOD (ll)(1e9+7)
# define INF8 (ll)(1e17+5)
# define endl '\n'
#define CMD_INIT 100
#define CMD_DROP 200
#define CMD_REMOVE 300
using namespace std;

typedef vector<ll> VI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<vector<ll> > VVI;
typedef pair<ll,ll> PI;
typedef pair<ll,PI > PPI;
typedef vector<PI> VP;
typedef vector<PPI> VPP;

typedef struct Triplet {
  ll numRow;
  ll numBlock;
  list<pair<ll,ll>> blockRow;
} Triplet;

vector<ll> primeList;
vector<bool> primes;
ll Row, Col;
ll currentTimestamp = 0;
ll currentBlockNum = 0;
list<Triplet> board;
void init(int R, int C);
int dropBlocks(int mTimestamp, int mCol, int mLen);
int removeBlocks(int mTimestamp);




static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ret, ans;
    bool ok = false;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);

        if (query == CMD_INIT)
        {
            int R, C;
            scanf("%d %d", &R, &C);
            init(R, C);
            ok = true;
        }
        else if (query == CMD_DROP)
        {
            int mTimestamp, mCol, mLen;
            scanf("%d %d %d", &mTimestamp, &mCol, &mLen);
            ret = dropBlocks(mTimestamp, mCol, mLen);
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
                cout << ret << " drop, block: " << ans << endl;
            } 
        }
        else if (query == CMD_REMOVE)
        {
            int mTimestamp;
            scanf("%d", &mTimestamp);
            ret = removeBlocks(mTimestamp);
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
                cout << ret << " remove, block: " << ans << endl;
            }
        }
    }
    //cout << "blocks: " << ans << endl;
    return ok;
}

void printListTriplet(list<Triplet> l) {
  list<Triplet>::iterator it;
  for(it = l.begin(); it != l.end(); ++it) {
    cout << "numRow: " << it->numRow << ", " << "numBlock: " << it->numBlock << ", blockRow: ";
    cout  << "[";
    list<pair<ll,ll>>::iterator itr;
    for(itr = it->blockRow.begin(); itr != it->blockRow.end(); ++itr) {
      cout << "(" << itr->first << ", " << itr->second << ")";
    }
    cout << "]" << endl;
  }
}
void init(int R, int C)
{
  board.clear();
  currentBlockNum = 0;
  Row = R;
  Col = C; 
}

int dropBlocks(int mTimestamp, int mCol, int mLen)
{
    ll dif = mTimestamp - currentTimestamp;
    list<Triplet>::iterator it = board.begin();
    while(it != board.end()) {
      if(it->numRow + dif >= Row) {
        currentBlockNum = currentBlockNum - it->numBlock;
        it = board.erase(it);
      } else {
        it->numRow = it->numRow + dif;
        ++it;
      }
    }

    list<pair<ll,ll>> blockRow;
    blockRow.push_back(mp(mCol, mLen));
    Triplet dropped;
    dropped.numRow = 0;
    dropped.numBlock = mLen;
    dropped.blockRow = blockRow;
    board.push_back(dropped);
    currentBlockNum += mLen;
    //cout << "timestamp (drop): " << mTimestamp << endl;
    //cout << "Blocks: " << currentBlockNum << endl;
    //printListTriplet(board);

    currentTimestamp = mTimestamp;
    return currentBlockNum;
}

int removeBlocks(int mTimestamp)
{
  ll dif = mTimestamp - currentTimestamp;
  vector<bool> removedCol;
  for(int i=0; i < Col; i++) removedCol.push_back(false);

  list<Triplet>::iterator itBoard = board.begin();
  while(itBoard != board.end()) {
    if(itBoard->numRow + dif >= Row)
    {
      currentBlockNum = currentBlockNum - itBoard->numBlock;
      itBoard = board.erase(itBoard);
    }
    
    else
    {
      itBoard->numRow = itBoard->numRow + dif;
      int blockRowSize = itBoard->blockRow.size();

      list<pair<ll,ll>>::iterator itRow = itBoard->blockRow.begin();
      int initNumBlock = itBoard->numBlock;


      for(int i=0; i < blockRowSize; i++) {
        int j = itRow->first;

        while(j < (itRow->first + itRow->second)) {
          if(!removedCol[j])
          {
            itBoard->numBlock--;
            removedCol[j] = true;
            j++;
          }
          
          else
          {
            int k = j+1;
            //cout << "j " << j << endl;

            while(k < (itRow->first + itRow->second)) {
              if(!removedCol[k]) {
                break;
              }
              //cout << "j " << j << " k " << k << endl; 
              k++;
            }

            itBoard->blockRow.push_back(mp(j, k-j));
            j=k;
          }
        }

        ++itRow;
        itBoard->blockRow.pop_front();
      }


      currentBlockNum = currentBlockNum - (initNumBlock - itBoard->numBlock);

      if(itBoard->numBlock <= 0) {
        itBoard = board.erase(itBoard);
      } else {
        ++itBoard;
      }
    }
  }
  /*
    ll dif = mTimestamp - currentTimestamp;
    vector<bool> removedCol(Col);
    for(int i = 0; i < Col; i++) removedCol[i] = false;
    list<Triplet>::iterator it = board.begin();
    while(it != board.end()) {
      if(it->numRow + dif >= Row) {
        currentBlockNum = currentBlockNum - it->numBlock;
        it = board.erase(it);
      } else {
        it->numRow = it->numRow + dif;
        VP newBlocks;
        for(int i = 0; i < it->blockRow.size(); i++) {
          vector<bool> removedColThisRow(Col); 
          for(int j = 0; j < Col; j++) removedColThisRow[j] = false;
          for(int j = it->blockRow[i].first; j <= it->blockRow[i].second; j++) {
            if(!removedCol[j]) {
              removedCol[j] = true;
              removedColThisRow[j] = true;
              it->numBlock--;
              currentBlockNum--;
            }
          }
          for(int j = it->blockRow[i].first; j <= it->blockRow[i].second; j++) {
            if(!removedColThisRow[j]) {
              int a, b;
              bool boundaryExist = false;
              a = j;
              for(int k = j; k < it->blockRow[i].second; k++) {
                if(removedColThisRow[k+1]) {
                  b = k;
                  boundaryExist = true;
                  break;
                }
              }
              if(!boundaryExist) b = it->blockRow[i].second;
              newBlocks.push_back(mp(a, b));
              j = b;
            }
          }
        }
        if(it->numBlock == 0) it = board.erase(it);
        else {
          it->blockRow = newBlocks;
          ++it;
        }
      }
    }
    */

    //cout << "Timestamp (removal): " << mTimestamp << endl;
    //cout << "Blocks: " << currentBlockNum << endl;
    //printListTriplet(board);

    currentTimestamp = mTimestamp;
    return currentBlockNum;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("sample_input copy.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}
