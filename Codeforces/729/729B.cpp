// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, m; cin >> n >> m;
  ll ans = 0;

  ll a[n+1][m+1];

  for(ll i=1; i<=n; i++) {
    for(ll j=1; j<=m; j++) {
      cin >> a[i][j];
    }
  }

  for(ll i=1; i<=n; i++) {
    bool f = false;
    for(ll j=1; j<=m; j++) {
      if(a[i][j]==1) f = true;
      if(f && a[i][j]==0) ans++;
    }
  }

  for(ll i=1; i<=n; i++) {
    bool f = false;
    for(ll j=m; j>=1; j--) {
      if(a[i][j]==1) f = true;
      if(f && a[i][j]==0) ans++;
    }
  }

  for(ll j=1; j<=m; j++) {
    bool f = false;
    for(ll i=1; i<=n; i++) {
      if(a[i][j]==1) f = true;
      if(f && a[i][j]==0) ans++;
    }
  }


  for(ll j=1; j<=m; j++) {
    bool f = false;
    for(ll i=n; i>=1; i--) {
      if(a[i][j]==1) f = true;
      if(f && a[i][j]==0) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
