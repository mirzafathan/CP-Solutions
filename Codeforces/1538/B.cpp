#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n;
  ll t; cin >> t;
  while(t--) {

    cin >> n;
    ll a[n+1];
    ll sum = 0;
    bool allsame = true;
    for(ll i=1; i<n+1; i++) {
      cin >> a[i];
      sum+=a[i];
      if(i>1) {
        if(a[i]!=a[i-1]) {
          allsame = false;
        }
      }
    }

    if(allsame) cout << 0 << endl;
    else {
      if(sum%n) cout << -1 << endl;
      else {
        ll avg = sum/n;
        ll count = 0;
        for(ll i=1; i<=n; i++) {
          if(a[i]>avg) count++;
        }
        cout << count << endl;
      }
    }

  }

  return 0;
}
