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
  ll n, l, r;
  cin >> n >> l >> r;

  map<ll,ll> left;
  map<ll,ll> right;
  map<ll,ll>::iterator itr;

  rep(i,0,l) {
    ll in; cin >> in;
    left[in]++;
  }

  rep(i,l,n) {
    ll in; cin >> in;
    right[in]++;
  }

  for(itr=left.begin(); itr!=left.end(); itr++) {
    ll sub = min(itr->second, right[itr->first]);
    left[itr->first]-=sub;
    right[itr->first]-=sub;
  }

  ll ans = 0;

  ll sizeright = 0;
  ll sizeleft = 0;

  for(itr=left.begin(); itr!=left.end(); itr++) {
    sizeleft+=(itr->second);
  }

  for(itr=right.begin(); itr!=right.end(); itr++) {
    sizeright+=(itr->second);
  }

  if(sizeleft>sizeright) {
  for(itr=left.begin(); itr!=left.end(); itr++) {
    if(itr->second > 1) {
      ll num = itr->second/2;
      ll dif = sizeleft-sizeright;

      if(num<dif) {
        ans+=num;
        sizeleft-=(num*2);
        left[itr->first]-=(num*2);

      } else {
        ans+=dif;
        sizeleft-=(dif*2);
        left[itr->first]-=(dif*2);
      }
    }
    if(sizeleft==sizeright) break;
  }
  }

  if(sizeright>sizeleft) {
  for(itr=right.begin(); itr!=right.end(); itr++) {
    if(itr->second > 1) {
      ll num = itr->second/2;
      ll dif = sizeright-sizeleft;

      if(num<dif) {
        ans+=num;
        sizeright-=(num*2);
        right[itr->first]-=(num*2);

      } else {
        ans+=(dif/2);
        sizeright-=(dif);
        right[itr->first]-=(dif);
      }
    }
    if(sizeleft==sizeright) break;
  }
  }

//  cout << "left" << sizeleft << endl;
  //cout << "right" << sizeright << endl;

//  cout << ans << endl;

  if(sizeleft==sizeright) ans+=sizeleft;
  else {

    ll dif = max(sizeleft,sizeright) - min(sizeleft,sizeright);
    ans+=min(sizeleft,sizeright);

//cout << "here " << ans << endl;
    ans+=(dif);
  }

  cout << ans << endl;
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
