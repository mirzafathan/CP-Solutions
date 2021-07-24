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


void solve() {
  ll n; cin >> n;
  VI a(n); map<ll,ll> ft;
  rep(i,0,n) {
    cin >> a[i];
    ft[a[i]]++;
  }
  VI sortft;
  map<ll,ll>::iterator it;
  for(it = ft.begin(); it!=ft.end(); it++) {
    sortft.push_back(it->second);
  }
  sort(sortft.begin(), sortft.end());

  ll maxn = sortft.back();

  VI groupbycnt(maxn+1);

  rep(i,0,maxn+1) groupbycnt[i] = 0;

  rep(i,0,sortft.size()) {
    groupbycnt[sortft[i]]+=sortft[i];
  }

  VP suffix(maxn+1);
  VI prefix(maxn+1);

  prefix[0] = 0;

  rep(i,1,maxn+1) {
    prefix[i] = groupbycnt[i] + prefix[i-1];
  }

  suffix[maxn] = mp(groupbycnt[maxn], groupbycnt[maxn]/maxn);
  rrep(i,maxn-1, 0) {
    if(i!=0)
    suffix[i] = mp(suffix[i+1].first + groupbycnt[i], suffix[i+1].second + groupbycnt[i]/i);
    else
    suffix[i] = mp(suffix[i+1].first + groupbycnt[i], suffix[i+1].second);
  }

  cout << endl; 

  ll ans = suffix[1].first;
  rep(i,1,maxn) {
    ll newsol = prefix[i-1] + suffix[i+1].first - (suffix[i+1].second*i);
    if(newsol < ans) ans = newsol;
  }
  cout << min(ans, prefix[maxn-1]) << endl;
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
