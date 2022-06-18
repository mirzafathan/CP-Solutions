// Muhammad Mirza Fathan 2022
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define INF8 (ll)(1e17+5)

void addEdge(vector< pair<ll,ll> > adj[], ll u, ll v, ll w) {
  adj[u].push_back(make_pair(v, w));
  adj[v].push_back(make_pair(u, w));
}

ll minDistance(ll dist[], bool sptSet[], ll n) {
  ll min = INF8;
  int minIndex;

  for(int i=0; i<n; i++) {
    if(!sptSet[i] && dist[i]<min) {
      min = dist[i];
      minIndex = i;
    }
  }

  return minIndex;
}

void dijkstra(vector< pair<ll,ll> > adj[], ll src, ll n) {
  ll dist[n];
  bool sptSet[n];

  for(int i=0; i<n; i++) {
    dist[i] = INF8;
    sptSet[i] = false;
  }
  dist[1] = 0;


  for(int i=1; i<n-1; i++) {
    ll md = minDistance(dist, sptSet, n);
    sptSet[md] = true;
    // debug cout << md << " md" << endl;

    for(int j=0; j<adj[md].size(); j++) {
      int newDistance = adj[md][j].second + dist[md];
      int curNeighbor = adj[md][j].first;
      if(!sptSet[curNeighbor] && (newDistance<dist[curNeighbor]))
        dist[curNeighbor] = newDistance;
    }
  }

  for(int i=1; i<n; i++) {
    cout << dist[i] << " ";
  } cout << endl;
}



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
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
