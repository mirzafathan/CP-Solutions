#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000000 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s; cin >> s;
  ll len = s.length();
  ll n[len];
  ll p = 1;
  ll ans = 0;
  ll sum = 0;


  for(ll i=0; i<len; i++) n[i] = s[i] - '0';

  for (ll i = len-1;i>=0;--i) {
    ll k = (i*(i+1)/2%mod * p%mod + sum) % mod;
    sum = (sum + p*(len-i) % mod) % mod;
    p = p * 10 % mod;
    ans = (ans + n[i] * k % mod) % mod;
  }


  cout << ans << endl;

  return 0;
}
