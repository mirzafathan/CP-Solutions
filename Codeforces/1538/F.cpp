#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll l, r; cin >> l >> r;

  ll changes = 0;

  while(r-l>0) {
    changes+= r - l;
    r/=10;
    l/=10;
  }

  cout << changes << endl;
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
