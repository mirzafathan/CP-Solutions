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
  ll n;
  cin >> n;
  VI a;
  map< ll, pair<ll,ll> > occa;
  map< ll, pair<ll,ll> > occb;
  ll maxm = 0;

  rep(i,0,n){
    ll in;
    cin >> in;
    a.pb(in);
    if(i%2) occa[in].fi++;
    else occa[in].sc++;
    if(in>maxm) maxm = in;
  }

  sort(a.begin(),a.end());

  rep(i,0,n){
    if(i%2) occb[a[i]].fi++;
    else occb[a[i]].sc++;
  }

  rep(i,0,maxm+1) {
    if((occb[i].fi!=occa[i].fi) ||(occb[i].sc!=occa[i].sc)) {
      cout << "NO" << endl; return;
    }
  }

  cout << "YES" << endl;

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
