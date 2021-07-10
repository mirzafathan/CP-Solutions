// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

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

bool comparef(const pair<ll,ll>&p1, const pair<ll,ll>&p2) {
  if(p1.first==p2.first)
    return p1.second<p2.second;
  return p1.first>p2.first;
}

void solve() {
  ll q; cin >> q;
  set< pair<ll,ll> > first_first;
  set< pair<ll,ll>, decltype(comparef)* > rich_first(comparef);
  ll cust = 1;
  rep(i,1, q+1) {
    ll a; cin >> a;
    if(a==1) {
      ll m;
      cin >> m;
      first_first.insert(mp(cust,m));
      rich_first.insert(mp(m,cust));
      cust++;
    } else if(a==2) {
      set< pair<ll,ll> >::iterator pos = first_first.begin();
      ll served = pos->first;
      cout << served << " ";
      first_first.erase(pos);
      rich_first.erase(mp(pos->second,pos->first));
    } else if(a==3) {
      set< pair<ll,ll> >::iterator pos = rich_first.begin();
      ll served = pos->second;
      cout << served << " ";
      rich_first.erase(pos);
      first_first.erase(mp(pos->second, pos->first));
    }
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
