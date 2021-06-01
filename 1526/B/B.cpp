//https://codeforces.com/problemset/problem/1526/B
#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long x; cin >> x;
  long long a, b, c, rem;
  for(long long i=0; i<=10; i++) {

    if(i>0) {
      if(x%(i*111)==0) {
        cout << "YES" << endl;
        return;
      }
    }

    rem = x - i*111;

    if(rem%11==0) {
      long long per_eleven = rem/11;
      for(long long j=0; j<=floor(per_eleven/111); j++) {
        long long k = 0;
        while((j*111+k)<=per_eleven) {
          if((j*111)+k==per_eleven) {
            cout << "YES" << endl;
            return;
          } k++;
        }
      }
    }
  }

  cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long t; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
