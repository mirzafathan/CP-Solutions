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

string s, ab, ac, bc, ba, ca, cb;
ll n;
ll pre[200005][3][3];

void solve() {
  ll l, r; cin >> l >> r;
  ll temp[3][3];
  if(l>1) {
    rep(i,0,3) {
      rep(j,0,3) {
        temp[i][j] = pre[r-1][i][j] - pre[l-2][i][j];
      }
    }
  } else {
    rep(i,0,3) {
      rep(j,0,3) {
        temp[i][j] = pre[r-1][i][j];
      }
    }
  }

  ll abc, acb, bac, bca, cba, cab;
  abc = temp[0][1] + temp[0][2] + temp[1][0] + temp[1][2] + temp[2][1] + temp[2][0];
  acb = temp[0][1] + temp[0][2] + temp[1][0] + temp[1][1] + temp[2][2] + temp[2][0];
  bac = temp[0][0] + temp[0][2] + temp[1][1] + temp[1][2] + temp[2][1] + temp[2][0];
  bca = temp[0][0] + temp[0][2] + temp[1][0] + temp[1][1] + temp[2][1] + temp[2][2];
  cab = temp[0][1] + temp[0][0] + temp[1][1] + temp[1][2] + temp[2][2] + temp[2][0];
  cba = temp[0][1] + temp[0][0] + temp[1][2] + temp[1][0] + temp[2][1] + temp[2][2];

  cout << min(abc,min(acb,min(bac,min(bca,min(cab,cba))))) << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll m; cin >> n >> m;
  cin >> s;

  rep(i,0,3) {
    rep(j,0,3) {
      pre[0][i][j] = 0;
    }
  }

  rep(i,0,n) {
    ll num = s[i] - 'a';
    if(i>0) {
      rep(j,0,3) {
        rep(k,0,3) {
          pre[i][j][k] = pre[i-1][j][k];
        }
      }
    }
    pre[i][i%3][num]++;
  }

  while(m--) {
    solve();
  }

  return 0;
}
