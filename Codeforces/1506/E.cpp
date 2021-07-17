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
  VI ans1(n), ans2(n);

  rep(i,0,n) {
    ans1[i] = 0;
    ans2[i] = 0;
  }

  rep(i,1,n+1) {
    rep(j,0,n) {
      if(q[j]>i) {
        if(j>0) {
          if(q[j-1]==q[j] && ans1[j]==0) {
            ans1[j]=i;
            break;
          }
        }
      } else if(q[j]==i) {
        ans1[j]=i;
        break;
      }
    }
  }

  rrep(i,n,1) {
    rep(j,0,n) {
      if(q[j]>i) {
        if(j>0) {
          if(q[j-1]==q[j] && ans2[j]==0) {
            ans2[j]=i;
            break;
          }
        }
      } else if(q[j]==i) {
        ans2[j]=i;
        break;
      }
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
