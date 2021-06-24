// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
#define fr front
#define pb push_back
#define mp make_pair
typedef long long ll;

/************************/
/* TEMPLATES */
ll gcd(ll a, ll b)
{
    if (a == 0)
      return b;
    if (b == 0)
      return a;

    if (a == b)
      return a;
    if (a > b)
        return gcd(a%b, b);
    return gcd(a, b%a);
}

/************************/


void solve() {
  ll n; cin >> n;
  string s; cin >> s;
  ll d=0, k=0;
  map<pair<ll,ll>, ll> hash;

  for(ll i=0; i<s.length(); i++) {
    if(s[i]=='D') d++;
    else k++;
    ll x = gcd(d,k);
    cout << ++hash[mp(d/x, k/x)] << " ";
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
