// Muhammad Mirza Fathan | 2021
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
  ll c[1000000+5];
  for(int i=0; i<n; i++) {
    cin >> c[i];
  }

  ll dp[101];
  dp[0] = 0;

  for(int i=0; i<=100; i++) {
    dp[i] = INF8;
  }

  for(int i=1; i<=x; i++) {
    for(int j=0; j<n; i++) {
      if(i<c[j]) continue;
      dp[i] = min(dp[i], dp[i-c[j]]);
    }
  }

  cout << dp[x] << endl;

  return 0;
}
