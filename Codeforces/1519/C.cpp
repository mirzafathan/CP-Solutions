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
#define ll long long
#define ld long double
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define rrep(i,x,y) for(ll i=x;i>=y;i--)
#define debug_stl(x) for(auto i:x){cout<<i<<" ";}cout<<endl;
#define debug_1d(x,a,b) rep(i,a,b){cout<<x[i]<<" ";}cout<<endl;
#define debug_2d(x,a1,b1,a2,b2) rep(i,a1,b1){rep(j,a2,b2){cout<<x[i][j]<<" ";}cout<<endl;}
#define all(x) x.begin(), x.end()
#define MOD (ll)(1e9+7)
#define INF8 (ll)(1e17+5)
#define endl '\n'

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
  VI u(n+1);
  vector< priority_queue < ll, vector<ll>, greater<ll> > > t(n+1);
  VVI prefix(n+1);
  VI sum(n+1);

  rep(i,1,n+1) {
    cin >> u[i];
    sum[i] = 0;
  }

  rep(i,1,n+1) {
    ll in;
    cin >> in;
    t[u[i]].push(in);
    sum[u[i]] += in;
  }

/*  rep(i,1,n+1) {
    cout << sum[i] << " ";
  } cout << endl;
*/
  rep(i,1,n+1) {
    prefix[i].resize(min(n, (ll) t[i].size()));
    ll sz = prefix[i].size();
    rep(j,0,sz) {
      if(j>0) {
        sum[i] -= t[i].top();
        t[i].pop();
      }
      prefix[i][j] = sum[i];
    }
  }

  rep(i,1,n+1) {
    ll ans = 0;
    rep(j,1,n+1) {
      ll sz = prefix[j].size();
      if(i<=sz)
        ans+=prefix[j][sz%i];
    }
    cout << ans << " ";
  }

  cout << endl;

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
