#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t; cin >> t;
  ll n;
  while(t--){
    cin >> n;
    ll idxmin = 0;
    ll idxmax = 0;
    ll minimum = 101;
    ll maximum = 0;
    ll a[n+1];

    for(ll i=1; i<=n; i++) {
      cin >> a[i];
      if(a[i]>maximum) {
        idxmax = i;
        maximum = a[i];
      }
      if(a[i]<minimum) {
        idxmin = i;
        minimum = a[i];
      }
    }
    ll small = min(idxmin,idxmax);
    ll big = max(idxmin,idxmax);

    cout << min(min(big, n-small+1), small+n-big+1) << endl;
  }


  return 0;
}
