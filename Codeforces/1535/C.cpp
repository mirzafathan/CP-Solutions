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
  string s; cin >> s;
  ll len = s.length();
  ll ans = 0;
  ll contigous = 0;
  queue<ll> cq;

  for(ll i=0; i<len; i++) {
    if(i%2==0) {
      if(s[i]=='1') {
        ans += (contigous*(contigous+1))/2;
        contigous = 0;
      } else {
        contigous++;
      }
    } else {
      if(s[i]=='0') {
        ans += (contigous*(contigous+1))/2;
        contigous = 0;
      } else {
        contigous++;
      }
    }
  }

  ans += (contigous*(contigous+1))/2;

  contigous = 0;

  for(ll i=0; i<len; i++) {
    if(i%2==0) {
      if(s[i]=='0') {
        ans += (contigous*(contigous+1))/2;
        contigous = 0;
      } else {
        contigous++;
      }
    } else {
      if(s[i]=='1') {
        ans += (contigous*(contigous+1))/2;
        contigous = 0;
      } else {
        contigous++;
      }
    }
  }

  ans += (contigous*(contigous+1))/2;

  contigous = 0;

  for(ll i=0; i<len; i++) {
    if(s[i]=='?') contigous++;
    else {
      if(contigous>0) {
        cq.push(contigous);
        contigous = 0;
      }
    }
  }

  if(contigous>0) cq.push(contigous);

  while(!cq.empty()) {
    ll a = cq.fr();
    ans-= (a*(a+1))/2;
    cq.pop();
  }

  cout << ans << endl;
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
