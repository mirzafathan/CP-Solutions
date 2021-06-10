#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fact(ll n);

ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
ll fact(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t; cin >> t;

  while(t--) {

    vector<ll> a;
    ll n, l, r;
    cin >> n >> l >> r;

    for(ll i=1; i<=n; i++) {
      ll in; cin >> in;
      a.push_back(in);
    }

    sort(a.begin(), a.end());

    if(a[n-2]+a[n-1]<l) cout << 0 << endl;
    else if(a[0]+a[1]>r) cout << 0 << endl;
    else {
      ll ans = 0;
      ll start=1000000, end=0;
      for(ll i=0; i<n-1; i++) {
        if(a[i]+a[i+1]>=l && a[i]+a[i+1]<=r && i<start) {
          start = i;
          end = i+1;
        }
        if(i+2<=n-1) {
          if(a[i]+a[i+1]>=l && a[i]+a[i+1]<=r && a[i+1]+a[i+2]>r)
            end = i+1;
        }
      }

      for(ll i=0; i<start; i++) {
        ll endpoint = n;
        for(ll j=start; j<endpoint; j++) {
          if(a[i]+a[j]>=l && a[i]+a[j]<=r) {
            ans++;
          }
          if(a[i]+a[j]>r) {
            endpoint = j;
            break;
          }
        }
      }

      for(ll i=end+1; i<n; i++) {
        ll endpoint = end;
        for(ll j=start; j<=endpoint; j++) {
          if(a[i]+a[j]>r) {
            endpoint = j;
            break;
          }
          if(a[i]+a[j]>=l && a[i]+a[j]<=r) ans++;
        }
      }

      cout << ans + nCr(end-start+1,2) << endl;
    }
  }

  return 0;
}
