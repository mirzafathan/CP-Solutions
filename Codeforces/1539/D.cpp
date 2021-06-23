// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
#define fr front
#define bk back
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n; cin >> n;
  vector< pair<ll,ll> > v;

  for(ll i=0; i<n; i++) {
    ll a, b; cin >> a >> b;
    v.pb(mp(b,a));
  }
  sort(v.begin(), v.end());

  ll bought = 0;
  ll ans = 0;

  while(!v.empty()) {
    if(v.bk().sc==0) {
      v.pop_back();
      continue;
    }
    vector< pair<ll,ll> >::it = lower_bound(v.begin(), v.end(), bought)
    if(it!=v.end()) {
      ans++;
      bought++;
      it.sc--;
      continue;
    }
    v.bk().sc--;
    bought++;
  }



  return 0;
}
