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
  ll n;
  cin >> n;
  VS a(n);
  rep(i,0,n) cin >> a[i];

  VI A(n), B(n), C(n), D(n), E(n);
  rep(i,0,n) {
    A[i] = -1 * (a[i].size());
    B[i] = -1 * (a[i].size());
    C[i] = -1 * (a[i].size());
    D[i] = -1 * (a[i].size());
    E[i] = -1 * (a[i].size());
  }

  rep(i,0,n) {
    ll len = a[i].length();
    rep(j,0,len) {
      if(a[i][j]=='a') A[i]+=2;
      if(a[i][j]=='b') B[i]+=2;
      if(a[i][j]=='c') C[i]+=2;
      if(a[i][j]=='d') D[i]+=2;
      if(a[i][j]=='e') E[i]+=2;
    }
  }

  sort(A.begin(), A.end(), greater<int>());
  sort(B.begin(), B.end(), greater<int>());
  sort(C.begin(), C.end(), greater<int>());
  sort(D.begin(), D.end(), greater<int>());
  sort(E.begin(), E.end(), greater<int>());

  ll val_a, val_b, val_c, val_d, val_e;
  val_a = val_b = val_c = val_d = val_e = 0;
  ll i;
  ll sum_a = A[0];
  val_a += (sum_a>0);
  i = 1;
  while(sum_a>0 && i<n) {
    sum_a += A[i];
    if(sum_a>0) val_a++;
    i++;
  }

  ll sum_b = B[0];
  val_b += (sum_b>0);
  i = 1;
  while(sum_b>0 && i<n) {
    sum_b += B[i];
    if(sum_b>0) val_b++;
    i++;
  }

  ll sum_c = C[0];
  val_c += (sum_c>0);
  i = 1;
  while(sum_c>0 && i<n) {
    sum_c += C[i];
    if(sum_c>0) val_c++;
    i++;
  }

  ll sum_d = D[0];
  val_d += (sum_d>0);
  i = 1;
  while(sum_d>0 && i<n) {
    sum_d += D[i];
    if(sum_d>0) val_d++;
    i++;
  }

  ll sum_e = E[0];
  val_e += (sum_e>0);
  i = 1;
  while(sum_e>0 && i<n) {
    sum_e += E[i];
    if(sum_e>0) val_e++;
    i++;
  }

  //rep(x,0,n) cout << A[x] << " ";
  //cout << endl;

  cout << max(val_a, max(val_b, max(val_c, max(val_d, val_e)))) << endl;


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
