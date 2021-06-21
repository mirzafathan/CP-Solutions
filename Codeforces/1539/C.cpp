// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, k, x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  vector<ll> difarr;
  for(ll i=0; i<n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  ll ans = 0;

  for(ll i=1; i<n; i++) {
    ll dif = a[i] - a[i-1];
    if(dif>x) {
      difarr.push_back((ll) ceil((double)dif/(double)x)-1);
      ans++;
    }
  }

  sort(difarr.begin(), difarr.end());

  ll newstud = 0;
  ll i=0;
  while(k>0 && i<difarr.size()) {
    k-=difarr[i];
    i++;
    if(k>=0) newstud++;
  }

  cout << ans - newstud + 1<< endl;

  return 0;
}
