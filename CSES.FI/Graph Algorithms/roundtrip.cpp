// Muhammad Mirza Fathan
#include <bits/stdc++.h>
#define fr front
#define pb push_back
using namespace std;
typedef long long ll;
vector< vector<ll> > cities;
vector<ll> visited;
vector<ll> route;
ll start, tail;

bool dfs(ll a, ll par) {
  visited[a] = true;
  route[a] = par;
  for(ll i=0; i<cities[a].size(); i++) {
    ll cur = cities[a][i];
    if(visited[cur] && cur!=par) {
      start = cur;
      tail = a;
      return true;
    }
    else if(!visited[cur]) {
      if(dfs(cur, a)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, m; cin >> n >> m;
  ll a, b;

  visited.resize(n+1);
  cities.resize(n+1);
  route.resize(n+1);

  for(ll i=0; i<=n; i++) {
    visited[i] = 0;
    route[i] = 0;
  }

  for(ll i=1; i<=m; i++) {
    cin >> a >> b;
    cities[a].pb(b);
    cities[b].pb(a);
  }

  vector<ll> ans;

  for(ll i=1; i<=n; i++) {
    if(!visited[i]) {
      if(dfs(i, 0)) {
        ll last = tail;
        while(tail!=start) {
          ans.pb(route[tail]);
          tail = route[tail];
        } ans.pb(last);
        cout << ans.size()+1 << endl;
        for(ll j=0; j<ans.size(); j++) {
          cout << ans[j] << " ";
        } cout << ans[0] << endl;
        return 0;
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}
