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
# define INFD (double)(1e17+5)
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
  ll W, H; cin >> W >> H;
  ll x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
  ll w, h; cin >> w >> h;
  ll xl, xr, yd, yu;
  xl = x1;
  xr = W - x2;
  yd = y1;
  yu = H - y2;
  if(((xr+xl)<w) && ((yd+yu)<h) ) {
    cout << -1 << endl;
    return;
  }
  double ans = 0.0;
  if((xr>=w) || (xl>=w) || (yu>=h) || (yd>=h)) {
    cout << fixed << setprecision(6) << ans << endl;
    return;
  }
  ans = 100000000000000.0;
  if((xr+xl)>=w) ans = (double) min(w-xr, w-xl);
  if((yu+yd)>=h) ans = min(ans, (double) min(h-yu, h-yd));
  cout << fixed << setprecision(6) << ans << endl;/*
  ans = min(min(w-xr,w-xl), min(h-yu,h-yd));
  cout << w-xr << endl;
  cout << w-xl << endl;
  cout << h-yu << endl;
  cout << h-yd << endl;

  cout << ans << endl;*/
  //cout << xl+xr << " " << yd+yu << endl;
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
