// Muhammad Mirza Fathan 2022
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void addEdge(vector< pair<int,int> > adj[], int u, int v, int w) {
  adj[u].push_back(make_pair(v, w));
  adj[v].push_back(make_pair(u, w));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector< pair<int,int> > adj[n+1];
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    addEdge(adj, a, b, c);
  }

  return 0;
}
