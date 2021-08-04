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
# define ll long long
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

void solve() {
  ll n; cin >> n;
  VI a(n); rep(i,0,n) cin >> a[i];
  VI d(n-1); rep(i,0,n-1) d[i] = abs(a[i]-a[i+1]);

  ll K = 25;
  ll N = n-1;
  ll st[N][K+1];
  rep(i,0,N) st[i][0] = d[i];

  rep(j,1,K+1)
    for(ll i=0; (i+(1<<j))<=N; i++)
      st[i][j] = gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);

  ll ans = 0;
  rep(i,0,N) {
    ll sol;
    ll last = 0;
    rep(j,0,K+1) {
      last = j;
      if(st[i][j]<=1) break;
    }
    sol = last-1;
    if(last) {
      
    }
    ans = max(sol,ans);
  }
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
