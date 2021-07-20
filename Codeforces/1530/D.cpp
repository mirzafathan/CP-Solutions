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

VI a;
VB visited;
ll n, p;
VI ans;

void generate_rest() {
  queue<ll> rest;

  rep(i,1,n+1) {
    if(!visited[i]) {
      rest.push(i);
    }
  }

  while(true) {
    bool done = true;
    rep(i,1,n+1) {
      if(ans[i]==0) {
        done = false;
        if(rest.front()!=i) {
          ans[i] = rest.front();
          rest.pop();
        }
      }
    }
    if(done) break;
  }
}

void generate_rest_if_one() {
  ll problem, solve;
  rep(i,1,n+1) {
    if(ans[i]==0) {
      problem = i;
      break;
    }
  }

  rep(i,1,n+1) {
    if(ans[i]==a[problem]) {
      solve = i;
      break;
    }
  }

  if(visited[problem]) {
    ll sol;
    rep(i,1,n+1) {
      if(!visited[i]) {
        sol = i;
        break;
      }
    }
    ans[problem] = sol;
    return;
  }
  ans[problem] = a[problem];
  ans[solve] = problem;

}

void solve() {
  cin >> n;
  a.resize(n+1);
  ans.resize(n+1);
  visited.resize(n+1);
  p=0;

  rep(i,0,n+1) {
    ans[i]=0;
    visited[i]=false;
  }

  for(ll i=1; i<=n; i++) {
    cin >> a[i];
  }

  for(ll i=1; i<=n; i++) {
    if(!visited[a[i]]) {
      visited[a[i]] = true;
      ans[i] = a[i];
      p++;
    }
  }

  if((n-p)!=1) generate_rest();
  else generate_rest_if_one();


  cout << p << endl;
  rep(i,1,n+1) {
    cout << ans[i] << " ";
  } cout << endl;

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t; cin >> t;
  while(t--) {
    solve();
    a.clear();
    visited.clear();
    ans.clear();
  }


  return 0;
}
