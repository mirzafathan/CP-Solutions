// Muhammad Mirza Fathan | 2024
// Coin Combinations I

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define INF8 (ll)(1e17+5)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, x;

  cin >> n >> x;

  int c[105];

  for(int i = 0; i < n; i++) {
    cin >> c[i];
  }

  ll dp[1000000 + 5] = {};
  dp[0] = 1;
  
  for(int i = 1; i <= x; i++) {
    ll dpi = 0;
    for(int j = 0; j < n; j++) {
      if(i < c[j]) continue;
      dpi += dp[i - c[j]];
    }
    dp[i] = dpi%((ll) 1e9 + 7);
  }

  cout << dp[x] << endl;

  return 0;
}
