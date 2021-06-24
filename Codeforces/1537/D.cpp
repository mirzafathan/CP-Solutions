// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string op(string s, ll k) {
  while(s.length() < k) {
    s += s;
  }
  while(s.length() > k) {
    s.pop_back();
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, k; cin >> n >> k;
  string s; cin >> s;

  string prefix = "";
  prefix += s[0];

  string ans = op(prefix, k);

  for(ll i=1; i<s.length(); i++) {
    prefix += s[i];
    ans = min(ans, op(prefix, k));
  }

  cout << ans << endl;

  return 0;
}
