// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n; ll k; cin >> n >> k; ll a[n+1];
  for(ll i=1; i<=n; i++) cin >> a[i];

  ll dp[n+1];
  dp[0] = 0;
  dp[1] = min(n, k+1);

  for(ll i=2; i<=n; i++) {
    ll link = a[i];
    ll add = min(n, i+k) - max((ll)1, i-k) + 1;

    if(link!=0 && i-link-1<2*k)
      add = min(n, i+k) - min(n,link+k);
    dp[i] = dp[link] + add;
  }

  for(ll i=1; i<=n; i++) {
    cout << dp[i] << " ";
  } cout << endl;

  return 0;
}
