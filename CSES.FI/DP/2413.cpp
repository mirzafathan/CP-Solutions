// Muhammad Mirza Fathan | 2024
// CSES Problem Set #2413: Counting Towers
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define INF8 (ll)(1e17+5)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t; cin >> t;

  ll dp[1000000 + 5][2];
  ll MOD = 1e9 + 7;
  vector<ll> ans;
  ans.push_back(1);
  dp[1][0] = 1;
  dp[1][1] = 1;
  ans.push_back(2);

  for(int i = 2; i <= 1000000; i++) {
    dp[i][0] = (4*(dp[i-1][0])%MOD + dp[i-1][1])%MOD;
    dp[i][1] = (2*(dp[i-1][1])%MOD + dp[i-1][0])%MOD;
    ans.push_back((dp[i][0] + dp[i][1]) % MOD);
  }
  while(t--) {
    int n; cin >> n;
    cout << ans[n] << endl;
  }

  return 0;
}
