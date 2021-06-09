//https://codeforces.com/problemset/problem/191/A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n; cin >> n;
  string king[n];
  ll dp[26][26];

  for(ll i=0; i<26; i++) {
    for(ll j=0; j<26; j++) dp[i][j] = 0;
  }

  for(ll i=0; i<n; i++) {
    ll left, right, len;
    string kingi; cin >> kingi;
    king[i] = kingi;
    len = kingi.length();
    left = kingi[0] - 'a';
    right = kingi[len-1] - 'a';
    for(ll j=0; j<26; j++) {
      if(dp[j][left])
        dp[j][right] = max(dp[j][right], dp[j][left]+len);
    }
    dp[left][right] = max(dp[left][right], len);
  }

  ll ans = 0;
  for(ll i=0; i<26; i++)
    ans = max(ans, dp[i][i]);

  cout << ans << endl;

  return 0;
}
