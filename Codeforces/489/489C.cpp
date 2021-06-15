#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll m, s;
  cin >> m >> s;
  vector<ll> ansmin;
  vector<ll> ansmax;

  if((s==0 && m>1)|| s>m*9) {
    cout << -1 << " " << -1 << endl;
    return 0;
  }

  ll sum = s;
  for(ll i=0; i<m; i++) {
    for(ll j=9; j>=0; j--) {
      if((sum-j) > 0 && i<m-1) {
        ansmin.push_back(j);
        sum-=j;
        break;
      }
      if((sum-j) == 0 && i==m-1) {
        ansmin.push_back(j);
        sum-=j;
        break;
      }
    }
  }

  for(ll i=0; i<m; i++) {
    for(ll j=9; j>=0; j--) {
      if((s-j) >= 0) {
        ansmax.push_back(j);
        s-=j;
        break;
      }
    }
  }

  for(ll i=ansmin.size()-1; i>=0; i--) {
    cout << ansmin[i];
  } cout << " ";


  for(ll i=0; i<ansmax.size(); i++) {
    cout << ansmax[i];
  } cout << endl;


  return 0;
}
