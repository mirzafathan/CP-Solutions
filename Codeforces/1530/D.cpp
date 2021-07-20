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

VVI a;
VI visited;
ll n, p;
VI ans;

ll dfs(ll n, ll k) {
  k++;
  visited[n] = true;
  if(!visited[a[n][0]]) {
    dfs(a[n][0], k);
  }
  return k;
}

ll dfs_all() {
  ll k = 0;
  ll res;
  rep(i,1,n+1) {
    rep(j,1,n+1) visited[j] = false;
    if(dfs(i,0)>k) {
      res = i;
      k = i;
    }
  }
  return res;
}

ll generate_ans(ll x) {
  ll k = 0;
  rep(i,0,visited.size()) visited[i] = false;
  while(true) {
    if(ans[x]==0 && visited[a[x][0]]==false) {
      visited[a[x][0]] = true;
      k++;
      ans[x] = a[x][0];
      x = a[x][0];
    } else break;
  }

  rep(i,1,n+1) {
    if(!visited[a[i][0]] && ans[i]==0) {
      visited[a[i][0]] = true;
      ans[i] = a[i][0];
      cout << i << "aio" << a[i][0] << endl;
      k++;
    }
  }

  return k;
}

void generate_rest() {

  queue<ll> temp;

  rep(i,1,n+1) {
    if(ans[i]==0) {
      temp.push(i);
      if(temp.size()>1) {
        ans[i] = temp.front();
        temp.pop();
      }
    }
  }

  rep(i,1,n+1) {
    if(ans[i]==0) {
      ans[i] = temp.front();
      temp.pop();
      break;
    }
  }
}

void generate_rest_if_one() {
  ll x, y;
  rep(i,1,n+1) {
    if(visited[i]==false) {
      x = i;
      rep(j,1,n+1) {
        if(ans[j]!=0) {
          y = j;
          break;
        }
      }
      break;
    }
  }

  ll temp = ans[y];
  ans[y] = ans[x];
  ans[x] = temp;
}

void solve() {
  cin >> n;
  a.resize(n+1);
  ans.resize(n+1);
  visited.resize(n+1);
  rep(i,1,n+1) {
    ll in;
    cin >> in;
    a[i].pb(in);
    ans[i]=0;
  }
  p = generate_ans(dfs_all());

  cout << p << endl;
  rep(i,1,n+1) cout << ans[i] << ' ';
  cout << endl;
  generate_rest();

  if((n-p)==1) {
    generate_rest_if_one();
  }

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
