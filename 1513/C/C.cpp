#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
long long dp[200000];

void solve() {
  long long n, m;
  cin >> n >> m;
  long long ans = 0;
  while(n) {
    long long last = n%10;
    if(last+m<10) ans+=1;
    else ans+=dp[m+last-10];
    ans= ans%mod;
    n/=10;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t; cin >> t;

  for(int i=0; i<200000; i++) {
    if(i<9) dp[i] = 2;
    else if(i==9) dp[i] = 3;
    else {
      dp[i] = dp[i-9] + dp[i-10];
    }
  }

  while(t--) {
    solve();
  }

  return 0;
}
