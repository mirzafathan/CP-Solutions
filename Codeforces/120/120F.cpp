// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll spiders[200][200];
ll visited[200];
ll dist[200];
ll beads;


void dfs(ll start, ll par) {
  visited[start] = true;
  dist[start] = dist[par] + 1;
  for(ll i=1; i<=beads; i++) {
    if(!visited[i] && spiders[start][i]) {
      dfs(i, start);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  ll n; cin >> n;

  ll ans = 0;

  for(ll i=1; i<=n; i++) {

    cin >> beads;
    for(ll j=0; j<200; j++) {
      dist[j] = 0;
      visited[j] = false;
      for(ll k=0; k<200; k++) {
        spiders[j][k] = 0;
      }
    }

    for(ll j=1; j<= beads-1; j++) {
      ll a, b; cin >> a >> b;
      spiders[a][b] = 1;
      spiders[b][a] = 1;
    }
    if(beads==2) {
      ans+=1;
      continue;
    }
    if(beads==3) {
      ans+=2;
      continue;
    }

    dfs(1, 0);

    ll maxel = *max_element(dist, dist+200);
    ll maxidx;
    for(ll j=1; j<=beads; j++) {
      if(dist[j]== maxel) {
        maxidx = j;
        break;
      }
    }



    for(ll j=0; j<=beads; j++) {
      dist[j] = 0;
      visited[j] = false;
    }

    dfs(maxidx, 0);
    ans += *max_element(dist, dist+200)-1;

  }

  cout << ans << endl;

  return 0;
}
