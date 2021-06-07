// https://codeforces.com/problemset/problem/1472/C
#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n; cin >> n;
  long long a[n]; long long score[n];
  for(long long i=0; i<n; i++) cin >> a[i];
  for(long long i=n-1; i>=0; i--) {
    if(i+a[i]<n) {
      score[i] = score[i+a[i]] + a[i];
    } else {
      score[i] = a[i];
    }
  }
  cout << *max_element(score, score+n) << endl;
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
