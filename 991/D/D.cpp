// Problem: https://codeforces.com/problemset/problem/991/D
#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s[2]; cin >> s[0]; cin >> s[1];
  long long len = s[0].length();
  long long ans = 0;
  long long all_empty_slot = 0;

  for(long long i=0; i<len; i++) {
    int current_empty_slot = (s[0][i]=='0') + (s[1][i]=='0');
    all_empty_slot += current_empty_slot;
    if(all_empty_slot>=3) {
      ans++;
      all_empty_slot -= 3;
    } else {
      all_empty_slot = current_empty_slot;
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
