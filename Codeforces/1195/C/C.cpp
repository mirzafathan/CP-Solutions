//https://codeforces.com/problemset/problem/1195/C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n; cin >> n;
  ll h[n+1][2]; h[0][0] = 0; h[0][1] = 0;
  ll dp[n+1][2]; dp[0][0] = 0; dp[0][1] = 0;

  for(ll i=1; i<=n; i++) {
    cin >> h[i][0];
    dp[i][0] = h[i][0];
  }

  for(ll i=1; i<=n; i++) {
    cin >> h[i][1];
    dp[i][1] = h[i][1];
  }

  for(ll i=2; i<=n; i++) {
    dp[i][0] = max(dp[i-1][1]+h[i][0], dp[i-2][1]+h[i][0]);
    dp[i][1] = max(dp[i-1][0]+h[i][1], dp[i-2][0]+h[i][1]);
  }

  cout << max(dp[n][0], dp[n][1]) << endl;;

  return 0;
}
