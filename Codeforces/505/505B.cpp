// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
vector< vector< pair<ll,ll> > > graph;
vector<bool> vis;

void clear(vector<bool> a) {
  for(ll i=0; i<a.size(); i++) {
    a[i]=false;
  }
}

bool dfs(ll u, ll v, ll c) {
  ll vertices = graph[u].size();
  vis[u] = true;
  if(u==v) return true;
  for(ll i=0; i<vertices; i++) {
    ll fr = graph[u][i].first;
    ll sc = graph[u][i].second;
    if(sc==c && vis[fr]==false) {
      return dfs(fr, v, c);
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  ll a, b, c, q;

  graph.resize(n+1);
  vis.resize(n+1);
  clear(vis);

  for(ll i=1; i<=m; i++) {
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }

  cin >> q;
  ll u, v;

  for(ll i=1; i<=q; i++) {
    cin >> u >> v;
    ll num =0;
    for(ll j=1; j<=m; j++) {
//      cout << j << endl;
      clear(vis);
      if(dfs(u, v, j)) {
//        cout << "j" << j << " " << dfs(u,v,j) << endl;
        num++;
      }
    }
    cout << num << endl;
  }

  return 0;
}
