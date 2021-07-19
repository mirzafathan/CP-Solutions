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
  VI a(n+1);
  VI b(n+1);
  VI prefix(n+2);
  VI suffix(n+2);

  rep(i,1,n+1) cin >> a[i];
  rep(i,1,n+1) cin >> b[i];

  prefix[0] = 0;
  prefix[n+1] = 0;
  rep(i,1,n+1) prefix[i] = prefix[i-1] + a[i]*b[i];

  suffix[0] = 0;
  suffix[n+1] = 0;
  rrep(i,n,1) suffix[i] = suffix[i+1] + a[i]*b[i];

  VI ans;
  ll solution = prefix[n];
  rep(i,1,n) {
    rep(j,i+1,n+1) {
      if((i+1)==(j-1)) {
        ans.pb(a[i]*b[j] + a[i+1]*b[j-1] + a[j]*b[i]);
        ll newsol = prefix[i-1] + suffix[j+1] + ans.bk();
        ll k = i-1;
        ll l = j+1;
        while(k>=1 && l<=n) {
          ll prev = ans.bk();
          ans.pb(prev + a[k]*b[l] + a[l]*b[k]);
          if((prefix[k-1] + suffix[l+1] + ans.bk())>newsol) newsol = prefix[k-1] + suffix[l+1] + ans.bk();
          k--;
          l++;
        }
        if(newsol>solution) solution = newsol;
      } else if(abs(i-j)==1) {
        ans.pb(a[i]*b[j] + a[j]*b[i]);
        ll newsol = prefix[i-1] + suffix[j+1] + ans.bk();
        ll k = i-1;
        ll l = j+1;
        while(k>=1 && l<=n) {
          ll prev = ans.bk();
          ans.pb(prev + a[k]*b[l] + a[l]*b[k]);
          if((prefix[k-1] + suffix[l+1] + ans.bk())>newsol) newsol = prefix[k-1] + suffix[l+1] + ans.bk();
          k--;
          l++;
        }
        if(newsol>solution) solution = newsol;
      } else {
        break;
      }
    }
  }

  cout << solution << endl;

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);



  solve();

  return 0;
}
