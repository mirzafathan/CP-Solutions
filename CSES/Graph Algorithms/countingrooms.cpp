#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll room = 0;
bool vis[1000][1000];

void dfs(ll a, ll b) {
  vis[a][b] = true;
  if(b<m-1 && !vis[a][b+1])
      dfs(a, b+1);
  if(a<n-1 && !vis[a+1][b])
      dfs(a+1, b);
  if(a>0 && !vis[a-1][b])
      dfs(a-1, b);
  if(b>0 && !vis[a][b-1])
      dfs(a, b-1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(ll i=0; i<n; i++) {
    string s; cin >>s ;
//    house.push_back(s);
    for(ll j=0; j<m; j++) {
      vis[i][j] = (s[j]=='#');
    }
  }

  for(ll i=0; i<n; i++) {
    for(ll j=0; j<m; j++) {
      if(!vis[i][j]) {
        ll a=i;
        ll b=j;
        dfs(a, b);
        room++;
//        cout << room << "i" << i << "j" << j <<endl;
      //  cout << "a" << a << "b" << b << endl;
      }
    }
  }
  cout << room << endl;


  return 0;
}
