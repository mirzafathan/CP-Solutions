//https://codeforces.com/problemset/problem/1513/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (ll)(1e9+7)
# define INF8 (ll)(1e17+5)

ll mod(ll x) {
  return (x%MOD + MOD)%MOD;
}

ll fact(ll x) {
  if(x<1) {
    return 1;
  }
  if(x==1) {
    return 1;
  } else {
    ll ans = 1;
    ll i=1;
    while(i<=x) {
      ans = ans*i;
      ans = mod(ans);
      i++;
    }
    return ans;
  }
}

void solve() {
  ll n; cin >> n;
  vector<ll> a(n);

  ll minm = INF8;
  ll cnt = 0;

  for(ll i=0; i<n; i++) {
    cin >> a[i];
    if(a[i]<minm) {
      cnt = 1;
      minm = a[i];
      continue;
    }
    if(a[i]==minm) {
      cnt++;
    }
  }

  if(cnt<2) {
    cout << 0 << endl;
    return;
  }

  bool supermask = true;
  for(ll i=0; i<a.size(); i++) {
    if((a[i]&minm)!=minm) supermask = false;
  }

  if(supermask) {
    cout << mod((cnt)*(cnt-1)*(fact(n-2))) << endl;
  } else {
    cout << 0 << endl;
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long t; cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}
