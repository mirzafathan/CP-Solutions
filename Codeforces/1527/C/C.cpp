//https://codeforces.com/problemset/problem/1527/C
#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long n; cin >> n;
  vector<long long> a(n+1);

  for(long long i=1; i<=n; i++)
    cin >> a[i];

  vector<long long> dp(n+1);
  map<long long, long long> hash;

  long long ans = 0;

  dp[0] = 0;
  for(long long i=1; i<=n; i++) {
    dp[i] = dp[i-1] + hash[a[i]];
    hash[a[i]] += i;
    ans += dp[i];
  }

  cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long t; cin >> t;

    while(t--) solve();

    return 0;
}
