// Muhammad Mirza Fathan | 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define INF8 (ll)(1e17+5)

ll combinations(ll n) {
  if(n<0) return 0;
  if(n==0) return 1;
  ll result = 0;
  for(int i=1; i<=6; i++) {
    result += combinations(n-i);
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n; cin >> n;
  cout << combinations(n) << endl;

  return 0;
}
