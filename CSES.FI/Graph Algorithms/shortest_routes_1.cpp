// Muhammad Mirza Fathan 2022
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define INF8 (ll)(1e17+5)

void addEdge(vector< pair<ll,ll> > adj[], ll u, ll v, ll w) {
  adj[u].push_back(make_pair(v, w));
}

void dijkstra(vector< pair<ll,ll> > adj[], ll src, ll n) {
  ll dist[n];
  priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
  bool sptSet[n];

  for(ll i=0; i<n; i++) {
    dist[i] = INF8;
    sptSet[i] = false;
  }
  dist[1] = 0;
  pq.push(make_pair(0,1));


  while(!pq.empty()) {
    ll md = pq.top().second;
    pq.pop();
    // debug cout << md << " md" << endl;
    if(sptSet[md]) continue;
    sptSet[md] = true;

    for(ll j=0; j<adj[md].size(); j++) {
      ll newDistance = adj[md][j].second + dist[md];
      ll curNeighbor = adj[md][j].first;
      if(!sptSet[curNeighbor] && (newDistance<dist[curNeighbor]))
        dist[curNeighbor] = newDistance;
        pq.push(make_pair(newDistance, curNeighbor));
    }
  }

  for(ll i=1; i<n; i++) {
    cout << dist[i] << " ";
  } cout << endl;
}



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, m;
  ll dist[n+1];
  cin >> n >> m;
  vector< pair<ll,ll> > adj[n+1];
  while(m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    addEdge(adj, a, b, c);
  }

  dijkstra(adj, 1, n+1);

  return 0;
}
