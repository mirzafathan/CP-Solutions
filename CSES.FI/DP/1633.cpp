// Muhammad Mirza Fathan | 2024
// Dice Combinations
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define INF8 (ll)(1e17+5)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll mod = ((ll) 1e9+7);
  ll n; cin >> n;
  ll dp[1000000+7];
  dp[0] = 1;
  dp[1] = dp[0];
  dp[2] = dp[1] + dp[0];
  dp[3] = dp[2] + dp[1] + dp[0];
  dp[4] = dp[3] + dp[2] + dp[1] + dp[0];
  dp[5] = dp[4] + dp[3] + dp[2] + dp[1] + dp[0];
  dp[6] = dp[5] + dp[4] + dp[3] + dp[2] + dp[1] + dp[0];

  for(ll i=7; i<=n; i++) {
    dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]) % mod;
  }

  cout << dp[n] << endl;

  return 0;
}
