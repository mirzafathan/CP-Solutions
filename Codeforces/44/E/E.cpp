// https://codeforces.com/problemset/problem/44/H
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll k, a, b; cin >> k >> a >> b;
  string s; cin >> s;
  ll len = s.length();

  ll line = len/k;
  ll mod = len%k;

  if(floor((double)len/(double)k)<a||ceil((double)len/(double)k)>b) {
    cout << "No solution" << endl;
    return 0;
  }

  if(mod==0) {
    for(ll i=0; i<len; i++) {
      cout << s[i];
      if((i+1)%line==0) cout << endl;
    }
    return 0;
  }

  ll idstart = 0;
  for(ll i=0; i<k; i++) {

    if(mod==0) {
      cout << s.substr(idstart, line) << endl;
      idstart += line;
    } else {
      cout << s.substr(idstart, line+1) << endl;
      mod--;
      idstart += line+1;
    }
  }

  return 0;
}
