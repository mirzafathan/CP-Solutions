// Muhammad Mirza Fathan | 2024
// Removing Digits

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define INF8 (ll)(1e17+5)

int maxDigit(int n) {
  int a, b, c, d, e, f, g;

  a = n%10;
  n = n/10;
  b = n%10;
  n = n/10;
  c = n%10;
  n = n/10;
  d = n%10;
  n = n/10;
  e = n%10;
  n = n/10;
  f = n%10;
  n = n/10;
  g = n%10;

  return max(a, max(b, max(c, max(d, max(e, max(f, g))))));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n; cin >> n;
  int dp[1000000 + 5];

  for(int i = 1; i <= 9; i++) {
    dp[i] = 1;
  }

  for(int i = 10; i <= n; i++) {
    dp[i] = 1 + dp[i - maxDigit(i)];
  }

  cout << dp[n] << endl;
  return 0;
}
