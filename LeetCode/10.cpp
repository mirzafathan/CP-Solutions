// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
  long long len_s = s.length();
  long long len_p = p.length();

  bool dp[len_s][len_p];

  if(s[0]!=p[0] && p[0]!='.') return false;
  else dp[0][0] = true;

  long long j = 1;
  for(long long i=1; i<len_s; i++) {
    if(p[j]=='*') {
      if(j>1) {
        
      } else {

      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s,p; cin >> s >> p;
  cout << isMatch(s,p) << endl;

  return 0;
}
