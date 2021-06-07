//https://codeforces.com/problemset/problem/1207/C
//https://codeforces.com/problemset/problem/1207/C
#include <bits/stdc++.h>
using namespace std;
const long long lmax = LLONG_MAX/2;

void solve() {
  long long n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  long long dp[n+1][2];
  dp[0][0] = b;
  dp[0][1] = lmax;

  for(long long i=1; i<n; i++) {
    if(s[i]=='1' || s[i-1]=='1') {
      dp[i][1] = min(dp[i-1][0]+2*(a+b), dp[i-1][1]+a+2*b);
      dp[i][0] = lmax;
    } else {
      dp[i][1] = min(dp[i-1][0]+2*(a+b), dp[i-1][1]+2*b+a);
      dp[i][0] = min(dp[i-1][0]+a+b, dp[i-1][1]+2*a+b);
    }
  }

  dp[n][0] = min(dp[n-1][0]+a+b, dp[n-1][1]+b+2*a);

  cout << dp[n][0] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long t; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
