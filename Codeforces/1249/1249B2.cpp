#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n; cin >> n;
  vector<ll> p;
  for(ll i=0; i<n; i++) {
    ll in; cin >> in;
    p.push_back(in);
  }
  ll result[p.size()];
  for(ll i=0; i<p.size(); i++)
    result[i] = 1;

  vector<ll> cycle;
  for(ll i=0; i<p.size(); i++) {
    //cout << "a " << endl;
    ll ans=1;
    if(result[i]!=1) continue;
    ll pos = p[i]-1;
    while (pos!=i) {
//      cout << i << "i" << endl;
  //    cout << pos << endl;
      pos = p[pos]-1;
      cycle.push_back(pos);
    //  cout << pos << "pos" << endl;
      ans++;
    }
    for(ll j=0; j<cycle.size(); j++) {
      result[cycle[j]] = ans;
      //cout << cycle[j] << " ";
    }
    cycle.clear();
  }
  for(ll i=0; i<p.size(); i++) {
    cout << result[i];
    if(i==p.size()-1) cout << endl;
    else cout << " ";
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll q; cin >> q;
  while(q--) {
    solve();
  }

  return 0;
}
