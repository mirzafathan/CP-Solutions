// Muhammad Mirza Fathan | 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
vector< vector< pair<ll,ll> > > path;
vector< vector<bool> > vis;
ll xo, yo, xi, yi;
pair<ll,ll> moves[4];

bool Valid(ll a, ll b) {
  if(a<0 || a>=n || b<0 || b>=m)
    return false;
  if(vis[a][b])
    return false;
  return true;
}

void bfs() {
  queue<pair<ll,ll> > q;
  q.push(make_pair(yo, xo));
  while(!q.empty()) {
    ll xcurr = q.front().second;
    ll ycurr = q.front().first;
    q.pop();
    for(ll i=0; i<4; i++) {
      ll xmove = moves[i].second;
      ll ymove = moves[i].first;
      if(Valid(ycurr+ymove, xcurr+xmove)) {
        q.push(make_pair(ycurr+ymove, xcurr+xmove));
        vis[ycurr+ymove][xcurr+xmove] = true;
        path[ycurr+ymove][xcurr+xmove] = make_pair(ymove, xmove);
      }
    }
  }

  if(!vis[yi][xi])  {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;

    vector<char> ans;
    pair<ll,ll> end = make_pair(yi, xi);
    while(end.first!=yo || end.second!=xo) {
      ll y = path[end.first][end.second].first;
      ll x = path[end.first][end.second].second;
      if(y==1 && x==0) ans.push_back('D');
      else if(y==-1 && x==0) ans.push_back('U');
      else if(y==0 && x==1) ans.push_back('R');
      else if(y==0 && x==-1) ans.push_back('L');

      end.first -= y;
      end.second -= x;
    }
    cout << ans.size() << endl;
    for(ll i=ans.size()-1; i>=0; i--) {
      cout<< ans[i];
    } cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  moves[0] = make_pair(-1,0);
  moves[1] = make_pair(0,-1);
  moves[2] = make_pair(1,0);
  moves[3] = make_pair(0,1);

  cin >> n >> m;
  path.resize(n);
  vis.resize(n);

  for(ll i=0; i<n; i++) {
    path[i].resize(m);
    vis[i].resize(m);
  }

  for(ll i=0; i<n; i++) {
    string s; cin >> s;
    for(ll j=0; j<m; j++) {
      path[i][j] = make_pair(-1, -1);
      vis[i][j] = (s[j]=='#');
      if(s[j]=='A') {
        xo = j; yo = i;
      }
      if(s[j]=='B') {
        xi = j; yi = i;
      }
    }
  }

  bfs();

  return 0;
}
