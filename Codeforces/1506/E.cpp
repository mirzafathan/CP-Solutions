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
  VI q(n); rep(i,0,n) cin >> q[i];
  set<ll> a, b;
  VI ans1(n), ans2(n);

  rep(i,1,n+1) {
    a.insert(i);
    b.insert(i);
  }

  rep(i,0,n) {
    ans1[i] = 0;
    ans2[i] = 0;
  }

  ans1[0]=q[0];
  a.erase(q[0]);
  rep(i,1,n) {
    if(q[i]==q[i-1]) {
      ans1[i]=*(a.begin());
      a.erase(a.begin());
    } else {
      ans1[i]=q[i];
      a.erase(q[i]);
    }
  }

  ans2[0] = q[0];
  b.erase(q[0]);
  rep(i,1,n) {
    if(q[i]==q[i-1]) {
      set<ll>::iterator it = --b.lower_bound(q[i]);
      ans2[i]=(*it);
      b.erase(it);
    } else {
      ans2[i]=q[i];
      b.erase(q[i]);
    }
  }

  rep(i,0,n) cout << ans1[i] << " ";
  cout << endl;

  rep(i,0,n) cout << ans2[i] << " ";
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
