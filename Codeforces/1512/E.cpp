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

ll low(ll k) {
  return (k*(k+1))/2;
}

ll high(ll n, ll k) {
  return (k*((2*n)+1-k))/2;
}

void solve() {
  ll n,l,r,s; cin >> n >> l >> r >> s;
  ll k = r-l+1;

  if(s<low(k) || s>high(n,k)) {
    cout << -1 << endl;
    return;
  }

  VI ans(n+1);

  ll in = l;
  ll out = 1;
  rrep(i,n,1) {
    if(out>=l&&out<=r) {
      out = r+1;
    }
    if(k > 0 && high(i,k)>=s && s-i>=low(k-1)) {
      ans[in] = i;
      in++;
      s-=i;
      k--;
    } else {
      if(out<=n) {
        ans[out] = i;
        out++;
      }
    }
  }

  rep(i,1,n+1) cout << ans[i] << " ";
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
