//https://codeforces.com/contest/1282/problem/B2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n, p, k, in; cin >> n >> p >> k;
  vector<ll> a;
  a.push_back(0);
  for(ll i=1; i<=n; i++) {
    cin >> in;
    a.push_back(in);
  }
  sort(a.begin(), a.end());


  ll dp[n+1];
  dp[0] = 0;
  for(ll i=1; i<=n; i++) {
    if(i>=k) {
      dp[i] = a[i] + dp[i-k];
    } else {
      dp[i] = a[i] + dp[i-1];
    }
  }

  for(ll i=n; i>=0; i--) {
    if(dp[i]<=p) {
      cout << i << endl;
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t; cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}
