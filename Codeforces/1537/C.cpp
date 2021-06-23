// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n; cin >> n;
  vector<ll> h(n);
  for(ll i=0; i<n; i++) cin >> h[i];
  sort(h.begin(),h.end());
  ll mindif = LLONG_MAX;
  ll idxlast=1;
  for(ll i=1; i<n; i++) {
    if(h[i]-h[i-1]<mindif) {
      mindif = h[i] - h[i-1];
      idxlast = i;
    }
  }

  for(ll i=idxlast-1; i<n; i++) {
    if(i==idxlast) continue;
    cout << h[i] << " ";
  }

  for(ll i=0; i<idxlast+1; i++) {
    if(i==idxlast-1) continue;
      cout << h[i] << " ";
  } cout << endl;
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
