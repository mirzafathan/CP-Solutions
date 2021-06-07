//https://codeforces.com/problemset/problem/698/A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n; cin >> n;
  ll a[n+1];
  for(ll i=1; i<=n; i++) cin >> a[i];

  ll dp[n+1][3];
  dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;

  for(ll i=1; i<=n; i++) {
    dp[i][0] = min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2])+1;
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
    if(a[i]==0) {
      dp[i][1]++; dp[i][2]++;
    }
    else if(a[i]==1) dp[i][2]++;
    else if(a[i]==2) dp[i][1]++;
  }

  cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;

  return 0;
}
