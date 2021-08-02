// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

/************************/
/* fLATES */

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
const int N = 2e5 + 5;

void solve() {
  ll n,m; cin >> n >> m;
  VI total(n+1);
  ll ans = 0;
  rep(i,0,n+1) total[i] = 0;
  rep(i,0,m) {
    ll u,v; cin >> u >> v;
    if(v>u) total[u]++;
    else total[v]++;
  }

  rep(i,1,n+1) {if(total[i]==0) ans++;}

  ll q; cin >> q;
  rep(i,0,q) {
    ll a, u, v; cin >> a;
    if(a==1) {
      cin >> u >> v;
      if(u<v) {
        total[u]++;
        if(total[u]==1) ans--;
      } else if (u>v) {
        total[v]++;
        if(total[v]==1) ans--;
      }
    } else if(a==2) {
      cin >> u >> v;
      if(u<v) {
        total[u]--;
        if((total[u])==0) ans++;
      } else if(u>v) {
        total[v]--;
        if((total[v])==0) ans++;
      }
    } else {
      cout << ans << endl;
    }
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
