// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
  long long len_s = s.length();
  long long len_p = p.length();

  bool dp[len_s+1][len_p+1];

  dp[0][0] = true;
  dp[0][1] = false;

  for(long long i = 1; i<len_p; i++) {
    dp[0][i+1] = false;
    if(p[i]=='*') {
      dp[0][i+1] = dp[0][i-1] || (i==1);
    }
  }
  for(long long i = 0; i<len_s; i++) {
    dp[i+1][0] = false;
  }

  for(long long i = 0; i<len_s; i++) {
    for(long long j = 0; j<len_p; j++) {
      dp[i+1][j+1] = false;
      if(p[j]=='*') {
        if(p[j-1]==s[i] || (p[j-1]=='.')) {
          dp[i+1][j+1] = dp[i][j+1];
          if(j>1 && !dp[i+1][j+1]) {
            dp[i+1][j+1] = dp[i+1][j-1];
          }
        } else if(j>1) {
          dp[i+1][j+1] = dp[i+1][j-1];
        }
      } else if((p[j]=='.') || (p[j]==s[i])) {
        dp[i+1][j+1] = dp[i][j];
      }
    }
  }
  return dp[len_s][len_p];
}

/* debug
  for(long long i=0; i<=len_s; i++) {
    for(long long j=0; j<=len_p; j++) {
      cout << dp[i][j] << " ";
    } cout << endl;
  }
*/

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s,p; cin >> s >> p;
  cout << isMatch(s,p) << endl;

  return 0;
}
