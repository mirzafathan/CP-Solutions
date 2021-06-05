//https://codeforces.com/problemset/problem/1207/C
//https://codeforces.com/problemset/problem/1207/C
#include <bits/stdc++.h>
using namespace std;
const lmax = LLONG_MAX;

void solve() {
  long long n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  long long dp[n][2];
  dp[0][0] = b;
  dp[0][1] = 9999;
  cout << lmax << endl;
/*
  for(long long i=1; i<n; i++) {
    if(s[i]=='1') {
      if(s[i-1]=='0') {
        dp[i][1] = min(dp[i-1][0]+2*(a+b), dp[i-1][1]+a+2*b);
        dp[i][0] = 999
      }

    }
    dp[i][0] = min(dp[i-1][0])
  }
  */
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
