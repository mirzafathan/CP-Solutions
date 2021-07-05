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

bool sortByVal(const pair<ll, ll> &a,
               const pair<ll, ll> &b)
{
    return (a.second < b.second);
}

void solve() {
  ll n; cin >> n;
  VP a;
  VI pref(n);

  rep(i,0,n) {
    ll in; cin >> in;
    a.pb(mp(i+1,in));
  }

  sort(all(a), sortByVal);

  rep(i,0,n) {
    pref[i]=a[i].second;
    if(i>0) pref[i]+=pref[i-1];
  }

  VI ans;
  ans.pb(a.bk().first);

  rrep(i,n-2,0) {
    if(pref[i]>=a[i+1].second) ans.pb(a[i].first);
    else break;
  }

  ll len = ans.size();
  sort(all(ans));
  cout << len << endl;
  rep(i,0,len) {
    cout << ans[i] << " ";
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
