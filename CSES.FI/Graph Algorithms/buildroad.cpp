// Muhammad Mirza Fathan
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
vector<bool> vis;
vector< vector<ll> > roads;
vector<ll> sets;

void dfs(ll a) {
  vis[a] = true;
  for(ll i=0; i<roads[a].size(); i++) {
    if(!vis[roads[a][i]]) dfs(roads[a][i]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  ll a, b;

  vis.resize(n+1);
  roads.resize(n+1);


  for(ll i=0; i<=n; i++)
    vis[i] = false;

  for(ll i=1; i<=m; i++) {
    cin >> a >> b;
    roads[a].push_back(b);
    roads[b].push_back(a);
  }

  for(ll i=1; i<=n; i++) {
    if(!vis[i]) {
      sets.push_back(i);
      dfs(i);
    }
  }

  cout << sets.size()-1 << endl;

  for(ll i=0; i<sets.size()-1; i++) {
    cout << sets[i] << " " << sets[i+1] << endl;
  }

  return 0;
}
