// Muhammad Mirza Fathan
#include <bits/stdc++.h>
#define pb push_back
#define fr front
using namespace std;
typedef long long ll;
int n, m;
vector <vector<int> > friendlist;
vector<bool> visited;
vector<int> colour;

bool dfs(int a, int c, int par) {
  visited[a] = true;
  colour[a] = c;
  for(int i=0; i<friendlist[a].size(); i++) {
    int cur = friendlist[a][i];
    if(cur == par) continue;
    if(colour[cur]==0 && c==1)
      if(!dfs(cur, 2, a)) return false;
    if(colour[cur]==0 && c==2)
      if(!dfs(cur, 1, a)) return false;
    if(colour[cur] == colour[a])
      return false;
  }
  return true;

}

int checkNeighbor(int a) {
  int size = friendlist[a].size();
  if(size==0) return 1;
  int cur;
  for(int i=0; i<size; i++) {
    if(colour[friendlist[a][i]]!=0) {
      cur = colour[friendlist[a][i]];
      break;
    } cur = 0;
  }
  if(cur == 0) return 2;
  for(int i=0; i<size; i++) {
    if(colour[friendlist[a][i]]!=0) {
      if(colour[friendlist[a][i]]!=cur)
        return 0;
      break;
    }
  }
  return cur;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  friendlist.resize(n+1);
  visited.resize(n+1);
  colour.resize(n+1);

  for(int i=0; i<=n; i++) {
    visited[i] = false;
    colour[i] = 0;
  }

  int a, b;
  for(int i=0; i<m; i++) {
    cin >> a >> b;
    friendlist[a].pb(b);
    friendlist[b].pb(a);
  }

  for(int i=1; i<=n; i++) {
    if(visited[i]==false) {
      if(!dfs(i, 1 , -1)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    }
  }

  for(int i=1; i<=n; i++) {
    cout << colour[i] << " ";
  } cout << endl;

  return 0;
}
