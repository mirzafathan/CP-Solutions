// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  ll k; cin >> k;
  while(k--) {
    ll n, x, t; cin >> n >> x >> t;
    if(x>t) {
      cout << 0 << endl;
      continue;
    }
    if(x==t) {
      cout << n-1 << endl;
      continue;
    }
    if(x<t) {
      if(t/x>=n) {
        cout << n*(n-1)/2 << endl;
        continue;
      } else {
        ll div = t/x;
        cout << (div)*n - (div+1)*(div)/2 << endl;
        continue;
      }
    }
  }


  return 0;
}
