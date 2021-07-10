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

VI ans;

bool inbetween(ll a, ll b, ll m) {
  return (a>m && m>b) || (a<m && m<b);
}

void solve() {
  cout << endl;
  ll x0, y0; cin >> x0 >> y0;
  ll x1, y1; cin >> x1 >> y1;
  ll fx, fy; cin >> fx >> fy;

  if((fx==x0 && x0==x1 && inbetween(y0,y1,fy)) || (fy==y0 && y0==y1 && inbetween(x0,x1,fx))) {
    ans.pb(abs(y1-y0)+abs(x1-x0)+2);
    return;
  }

  ans.pb(abs(y1-y0)+abs(x1-x0));

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);



  ll t; cin >> t;

  while(t--) {
    solve();
  }

  rep(i,0,ans.size()) {
    cout << ans[i] << endl;
  }



  return 0;
}
