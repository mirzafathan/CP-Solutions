// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

/************************/
/* TEMPLATES */

#define fr front
#define bk back
#define pb push_back
#define mp make_pair
#define sc second
#define fi first
# define ll unsigned long long
# define ld long double
# define rep(i,x,y) for(ll i=x;i<y;i++)
# define rrep(i,x,y) for(ll i=x;i>=y;i--)
# define debug_stl(x) for(auto i:x){cout<<i<<" ";}cout<<endl;
# define debug_1d(x,a,b) rep(i,a,b){cout<<x[i]<<" ";}cout<<endl;
# define debug_2d(x,a1,b1,a2,b2) rep(i,a1,b1){rep(j,a2,b2){cout<<x[i][j]<<" ";}cout<<endl;}
# define all(x) x.begin(), x.end()
# define MOD (ll)(1e9+7)
# define INF8 (ll)(1e17+5)
# define endl '\n'

typedef vector<ll> VI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<vector<ll> > VVI;
typedef pair<ll,ll> PI;
typedef pair<ll,PI > PPI;
typedef vector<PI> VP;
typedef vector<PPI> VPP;

ll mod(ll x) {
  return (x%MOD + MOD)%MOD;
}

ll gcd(ll a, ll b) {
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

ll lcm(ll a, ll b) {
  return (a*b)/gcd(a,b);
}

void solve() {
  ll n; cin >> n;


  ll ans = 0;
  ll lcmi = 1;

  rep(i,2,n+1) {
    ll lcmn = lcm(lcmi,i);
  //  cout << i << " " << i*((n/lcmi)-(n/lcmn)) << endl;
    ans+=i*((n/lcmi)-(n/lcmn));
    ans = mod(ans);
    lcmi = lcmn;
    if(lcmi>n) break;
  }

  if(n==1) {
    cout << 2 << endl;
    return;
  }
  if(n==2) {
    cout << 5 << endl;
    return;
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
