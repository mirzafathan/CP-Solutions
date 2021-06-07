//https://codeforces.com/problemset/problem/1527/B1
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long t; cin >> t;
    for(int i=0; i<t; i++) {
      long long n; cin >> n;
      string s; cin >> s;
      long long len = s.length();
      bool zero_more_than_one = 0;
      for(int j=0; j<(len-1)/2; j++) {
        if(s[j]=='0') {zero_more_than_one = 1; break;}
      }
      if(len%2==1 && s[(len-1)/2]!='1' && len>1 && zero_more_than_one) cout << "ALICE" << endl;
      else cout << "BOB" << endl;
    }
    return 0;
}
