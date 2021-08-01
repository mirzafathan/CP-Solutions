// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

/************************/
/* fLATES */

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
const int N = 2e5 + 5;

void solve() {
  ll n,m; cin >> n >> m;
  vector< set<ll> > f(n+1);
  rep(i,0,m) {
    ll u,v; cin >> u >> v;
    f[u].insert(v);
    f[v].insert(u);
  }
  ll q; cin >> q;
  rep(i,0,q) {
    ll a, u, v; cin >> a;
    if(a==1) {
      cin >> u >> v;
      f[u].insert(v);
      f[v].insert(u);
    } else if(a==2) {
      cin >> u >> v;
      f[u].erase(v);
      f[v].erase(u);
    } else {
      bool visited[N];
      VI lower(n+1);
      VI total(n+1);
      rep(j,0,N) visited[j] = false;
      ll ans = 0;
      queue<ll> tovisit;
      rep(j,1,n+1) {
        if(f[j].empty()) {
          total[j]=0;
          lower[j]=0;
          continue;
        }
        set<ll>::iterator it = f[j].lower_bound(j);
        if(it == f[j].end()) {
          lower[j] = f[j].size();
          total[j] = 0;
        } else {
          if(*it > j) it--;
          lower[j] = (ll)(it - f[j].begin());
          total[j] = f[j].size()-lower[j];
        }
        if(lower[j]==0) {
          tovisit.push(j);
          visited[j]=true;
        }
      }

  //    rep(i,0,lower.size()) { cout << lower[i] << " ";}
    //  cout << endl;

      while(!tovisit.empty()) {
        ll cur = tovisit.front();
        visited[cur] = true;
        tovisit.pop();
        ans++;
        for(set<ll>::iterator it=f[cur].begin(); it!=f[cur].end(); it++) {
          if(!visited[*it] && lower[*it]!=0 && total[*it]) {
            lower[*it]--;
            if(lower[*it]==0) tovisit.push(*it);
          }
        }
//        rep(i,0,lower.size()) { cout << lower[i] << " ";}
  //      cout << endl;
      }

      cout << n-ans << endl;
    }
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
