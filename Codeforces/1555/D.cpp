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

void solve() {
  ll l, r; cin >> l >> r;
  ll a, b, c, d, e, f;
  a = b = c = d = e = f = 0;
  rep(i, l-1, r) {
    if(ab[i]!=s[i]) {
      a++;
    }
    if(ac[i]!=s[i]) {
      b++;
    }
    if(ba[i]!=s[i]) {
      c++;
    }
    if(bc[i]!=s[i]) {
      d++;
    }
    if(ca[i]!=s[i]) {
      e++;
    }
    if(cb[i]!=s[i]) {
      f++;
    }
  }

  cout << min(a,min(b,min(c,min(d,min(e,f))))) << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll m; cin >> n >> m;
  cin >> s;

  rep(i, 0, n) {
    if(i%3==0) {
      ab.push_back('a');
      ac.push_back('a');
      bc.push_back('b');
      ba.push_back('b');
      ca.push_back('c');
      cb.push_back('c');
    }
    if(i%3==1) {
      ab.push_back('b');
      ac.push_back('c');
      bc.push_back('c');
      ba.push_back('a');
      ca.push_back('a');
      cb.push_back('b');
    }
    if(i%3==2) {
      ab.push_back('c');
      ac.push_back('b');
      bc.push_back('a');
      ba.push_back('c');
      ca.push_back('b');
      cb.push_back('a');
    }
  }

  while(m--) {
    solve();
  }

  return 0;
}
