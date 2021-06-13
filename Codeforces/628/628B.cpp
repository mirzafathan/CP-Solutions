// https://codeforces.com/problemset/problem/628/B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s; cin >> s;
  ll len = s.length();
  ll ans = 0;

  for(ll i=0; i<len; i++) {
    if((s[i]-'0')%4==0) ans++;
    if(i<len-1) {
      if(((s[i]-'0')*10+(s[i+1]-'0'))%4==0) ans+= (i+1);
    }
  }

  cout << ans << endl;

  return 0;
}
