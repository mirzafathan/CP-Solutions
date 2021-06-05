// https://codeforces.com/problemset/problem/44/H
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s; cin >> s;
  ll len = s.length();
  ll dif_one = 1;
  ll dp[10][len];

  for(ll i=0; i<10; i++) dp[i][0] = 1;
  for(ll i=1; i<len; i++) {
    for(ll j=0; j<10; j++) {
      dp[j][i] = 0;
    }
  }

  for(ll i=1; i<len; i++) {
    ll ai = s[i];
    if(abs(s[i]-s[i-1])>1) dif_one = 1;
    for(ll j=0; j<10; j++) {
      dp[(ai+j)/2][i] += dp[j][i-1];
      if((ai+j)%2) dp[(ai+j+1)/2][i] += dp[j][i-1];
    }
  }

  for(ll i=0; i<len-1; i++) {
    dp[9][len] += dp[i][len];
  }

  if(dif_one) dp[9][len]--;

  cout << dp[9][len] << endl;
  
  return 0;
}
