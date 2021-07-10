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
  ll n; cin >> n;
  VI a(n+1);
  ll sum = 0;
  ll in;

  rep(i,1,n+1) {
    cin >> in;
    a[i] = in;
    sum+=in;
  }

  ll k=0;

  while(k<n) {
    if(sum%(n-k)) {
      k++; continue;
    }
    ll aim = sum/(n-k);
    VI ans;
    ll i=1;

    while(i<=n) {
      if(a[i]<aim) {
        bool kfalse = false;
        ll newval = a[i];
        rep(j,i+1,n+1) {
          if(newval+a[j]<aim) {
            newval+=a[j];
            continue;
          }
          if(newval+a[j]>aim) {
            kfalse = true;
            break;
          }
          i=j+1;
          break;
        }
        if(kfalse) {
          break;
        }
        continue;
      }

      if(a[i]>aim) {
        break;
      }
      i++;
    }

    if(i==n+1) {
      cout << k << endl; return;
    }
    k++;
  }

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
