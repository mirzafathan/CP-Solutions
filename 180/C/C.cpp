//https://codeforces.com/problemset/problem/180/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isUpper(char c) {
  return (c<='Z' && c>='A');
}

bool isLower(char c) {
  return (c<='z' && c>='a');
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s; cin >> s;
  ll len = s.length();
  ll l[len], r[len];
  l[0] = 0;
  r[len-1] = 0;

  //lowercase on the left
  for(ll i=1; i<len; i++) {
    l[i] = l[i-1];
    if(isLower(s[i-1])) l[i]++;
  }

  //uppercase on the right
  for(ll i=len-2; i>=0; i--) {
    r[i] = r[i+1];
    if(isUpper(s[i+1])) r[i]++;
  }

  ll ans = len;
  for(ll i=0; i<len; i++) ans = min(ans, r[i]+l[i]);

  cout << ans << endl;

  return 0;
}
