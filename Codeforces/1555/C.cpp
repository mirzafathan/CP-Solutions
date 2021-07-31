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
  ll m; cin >> m;
  VI one(m), two(m);
  VI suf(m), pre(m);
  rep(i,0,m) cin >> one[i];
  rep(i,0,m) cin >> two[i];
  suf[m-1] = one[m-1];
  pre[0] = two[0];
  rrep(i,m-2,0) suf[i] = suf[i+1] + one[i];
  rep(i,1,m) pre[i] = pre[i-1] + two[i];

  VI ans;
  rep(i,0,m) {
    if(i>0)
    ans.push_back(max(suf[i]-one[i], pre[i-1]));
    else
    ans.push_back(suf[i]-one[i]);
  }

  cout << *min_element(ans.begin(), ans.end()) << endl;
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
