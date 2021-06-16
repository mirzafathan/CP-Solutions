// Muhammad Mirza Fathan
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
vector< vector<ll> > con;
vector<bool> vis;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  con.resize(n+1);
  vis.resize(n+1);

  vis.push_back(true);
  for(ll i=1; i<=n; i++) {
    vis.push_back(false);
  }

  for(ll i=1; i<=m; i++) {
    ll a, b;
    cin >> a >> b;
    con[a].push_back(b);
    con[b].push_back(a);
  }

  ll curr;
  vector<ll> route(n+1);
  queue<ll> q;
  q.push(1);
  while(!q.empty()) {
    curr = q.front();
    vis[curr] = true;

    q.pop();
    for(ll i=0; i<con[curr].size(); i++) {
      if(!vis[con[curr][i]]) {
        q.push(con[curr][i]);
        vis[con[curr][i]] = true;
        route[con[curr][i]] = curr;
      }
    }
  }

  if(vis[n]==false) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  } else {
    vector<ll> ans;
    ll i=n;
    ans.push_back(i);
    while(i!=1) {
      ans.push_back(route[i]);
      i = route[i];
    }
    cout << ans.size() << endl;
    for(ll i=ans.size()-1; i>=0; i--) {
      cout << ans[i] << " ";
    } cout << endl;

  }

  ll k=0;

  return 0;
}
