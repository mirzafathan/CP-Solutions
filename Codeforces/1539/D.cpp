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
  deque< pair<ll,ll> > v;

  for(ll i=0; i<n; i++) {
    ll a, b; cin >> a >> b;
    v.pb(mp(b,a));
  }
  sort(v.begin(), v.end());

  ll bought = 0;
  ll ans = 0;

  while(!v.empty()) {
    ll lowest = v.fr().fi;

    if(lowest<=bought) {
      bought+=v.fr().sc;
      ans+=v.fr().sc;
      v.pop_front();
      continue;
    }

    if(lowest-bought<=v.bk().sc) {
      v.bk().sc-=(lowest-bought);
      ans += 2*(lowest-bought);
      bought = lowest;
      if(v.bk().sc==0)
        v.pop_back();
    } else {
      bought+= v.bk().sc;
      ans+= 2*v.bk().sc;
      v.pop_back();
    }

  }

  cout << ans << endl;

  return 0;
}
