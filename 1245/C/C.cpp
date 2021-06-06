// https://codeforces.com/problemset/problem/1245/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s; cin >> s;
  ll len = s.length();
  ll ans;
  ll dp[len];
  dp[0] = 1;
  for(ll i=1; i<len; i++) {

    if(s[i]=='m' || s[i]=='w') {
      cout << 0 << endl;
      return 0;
    }


    if((s[i]=='u' && s[i-1]=='u') || (s[i]=='n' && s[i-1]=='n')){
      if(i==1) dp[i] = 2;
      else dp[i] = dp[i-1] + dp[i-2];
    }
    else dp[i] = dp[i-1];
  }

  cout << dp[len-1] << endl;
  return 0;
}
