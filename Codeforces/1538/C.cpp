#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a;

ll binser(ll x, ll l, ll r)
{
    if (r >= l) {
        ll mid = l + (r - l) / 2;
        if(r==a.size()-1) {
          if(a[r]<=x) return r+1;
        }
        if (a[mid] <= x && a[mid+1] > x)
            return mid+1;
        if (a[mid] > x)
            return binser(x, l, mid-1);
        return binser(x, mid+1, r);
    }
    return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t; cin >> t;

  while(t--) {

    ll n, l, r;
    cin >> n >> l >> r;

    for(ll i=1; i<=n; i++) {
      ll in; cin >> in;
      a.push_back(in);
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    for(ll i=0; i<a.size()-1; i++){
      //cout << "l-1 " << l-1-a[i]<< endl;
    //  cout << "r " << binser(r-a[i], i+1, a.size()-1) << endl;
  //    cout << "l " << binser(l-1-a[i], i+1, a.size()-1) << endl;

      ans += max(binser(r-a[i], i+1, a.size()-1) - i-1, (ll) 0) -
      max(binser(l-1-a[i], i+1, a.size()-1) - i-1, (ll) 0);

    }
  a.clear();
  cout << ans<< endl;

  }

  return 0;
}
