//https://codeforces.com/problemset/problem/859/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n; cin >> n;
  ll pie[n];

  for(ll i=0; i<n; i++) cin >> pie[i];

  ll dp[n];
  dp[n-1] = pie[n-1];
  ll sum= pie[n-1];

  for(ll i=n-2; i>=0; i--) {
    sum+=pie[i];
    dp[i] = max(dp[i+1], sum-dp[i+1]);
  }

  cout << sum-dp[0] << " " << dp[0] << endl;

  return 0;
}
