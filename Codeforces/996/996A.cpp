// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n; cin >> n;

  ll res = 0;

  while(n) {
    if(n/100>0) {
      res+=n/100;
      n = n%100;
    }
    else if(n/20>0) {
      res+=n/20;
      n = n%20;
    }
    else if(n/10>0) {
      res+=n/10;
      n = n%10;
    }
    else if(n/5>0) {
      res+=n/5;
      n = n%5;
    }
    else {
      res+=n;
      n = 0;
    }
  }

  cout << res << endl;

  return 0;
}
