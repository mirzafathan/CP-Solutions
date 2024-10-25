// Muhammad Mirza Fathan | 2024
// Minimizing Coins
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define INF8 (ll)(1e17+5)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n; cin >> n;
  ll x; cin >> x;
  ll c[101];
  for(int i=0; i<n; i++) {
    cin >> c[i];
  }

  ll dp[1000000+5];
  dp[0] = 0;

  for(int i=1; i<=x; i++) {
    dp[i] = INF8;
  }

  for(int i=1; i<=x; i++) {
    for(int j=0; j<n; j++) {
      if(i<c[j]) continue;
      dp[i] = min(dp[i], dp[i-c[j]] + 1);
    }
  }

  if(dp[x]==INF8) {
    cout << -1 << endl;
    return 0;
  }
  cout << dp[x] << endl;

  return 0;
}
