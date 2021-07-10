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


string reverse(string s) {
  string t;
  rrep(i,s.length()-1,0) {
    t.pb(s[i]);
  }
  return t;
}

void solve() {
  ll n; cin >> n;
  VI c(n+1);
  VS lex(n+1);

  rep(i,1,n+1) cin >> c[i];
  rep(i,1,n+1) cin >> lex[i];

  VVI dp(n+1);
  rep(i,0,n+1) dp[i].resize(2);

  dp[1][0] = 0;
  dp[1][1] = c[1];

  rep(i,2,n+1) {
    dp[i][0] = INF8;
    dp[i][1] = INF8;
  }

  rep(i,2,n+1) {
    bool tes = false;
    if(lex[i]>=lex[i-1]) {
      dp[i][0] = min(dp[i][0],dp[i-1][0]);
      tes = true;
    }
    if(lex[i]>=reverse(lex[i-1])) {
      dp[i][0] = min(dp[i][0],dp[i-1][1]);
      tes = true;
    }
    if(reverse(lex[i])>=lex[i-1]) {
      dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);
      tes = true;
    }

    if(reverse(lex[i])>=reverse(lex[i-1])) {
      dp[i][1] = min(dp[i][1], dp[i-1][1]+c[i]);
      tes = true;
    }
    if(!tes ||(dp[i-1][0]>=INF8&&dp[i-1][1]>=INF8)) {
      cout << "-1" << endl;
      return;
    }
  }

  cout << min(dp[n][0], dp[n][1]) << endl;

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();

  return 0;
}
