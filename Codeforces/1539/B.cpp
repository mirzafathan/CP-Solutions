// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  ll n; cin >> n;
  ll q; cin >> q;
  string s; cin >> s;
  ll y[n];

  y[0] = (s[0]-'a') + 1;
  for(ll i=1; i<n; i++) {
    y[i] = y[i-1] + (s[i] - 'a') +1;
  }

  while(q--) {
    ll l, r; cin >> l >> r;
    if(l==1) {
      cout << y[r-1] << endl;
      continue;
    }
    cout << y[r-1]-y[l-2] << endl;
  }


  return 0;
}
