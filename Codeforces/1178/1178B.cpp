// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s; cin >> s;
  ll a=0, b=0, c=0;

  for(ll i=0; i<s.length(); i++) {
    if(s[i]=='o') {
      b+=a;
    } else if(s[i-1]=='v' && i>=1) {
      a++;
      c+=b;
    }
  }

  cout << c << endl;


  return 0;
}
