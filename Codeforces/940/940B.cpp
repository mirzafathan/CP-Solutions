//https://codeforces.com/problemset/problem/940/B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, k, a, b;
  cin >> n >> k >> a >> b;
  ll ans = 0;

  if(k==1) {
    cout << a*(n-1) << endl;
    return 0;
  }

  while(n!=1) {
    if(!(n%k)) {
      ans += min(b, (n-n/k)*a);
      n = n/k;
    } else {
      if(n-(n%k)>=1) {
        ans += a*(n%k);
        n = n-(n%k);
      } else {
        ans += a*(n-1);
        n = n-(n-1);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
