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

void solve() {
  ll n; cin >> n;
  ll total_mons = 0;
  ll kmax = INF8;
  vector<pair<long long, long long> > b;

  rep(i,0,n) {
    ll k; cin >> k;
    ll max_monster = 0;
    rep(j,0,k) {
      ll a; cin >> a;
      if(a-(j-1)>=max_monster) {      
        max_monster = a-(j-1);
        if(k<kmax) kmax = k;
      }
    }
    total_mons+=k;
    b.push_back(make_pair(max_monster, k));
  }

  sort(b.begin(), b.end());

  ll ans = b[0].first;
  ll kbefore = b[0].second;
  rep(i,1,b.size()) {
    ll p = b[i].first - kbefore;
    if(p>ans) ans = p;
    kbefore += b[i].second;
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
