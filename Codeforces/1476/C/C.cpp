//https://codeforces.com/problemset/problem/1476/C
#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n; cin >> n;
  long long c[n], a[n], b[n];
  for(long long i=0; i<n; i++) cin >> c[i];
  for(long long i=0; i<n; i++) cin >> a[i];
  for(long long i=0; i<n; i++) cin >> b[i];
  long long cycle[n];
  cycle[0] = 0;

  for(long long i=1; i<n; i++) {
    long long aminb = abs(a[i]-b[i]);
    if(abs(aminb)) {
      if(aminb<cycle[i-1]-aminb)
        cycle[i] = cycle[i-1] - aminb + (c[i] - 1) + 2; // length of cycle before - abs(a-b) + length of chain + 2 (arms)
      else
        cycle[i] = aminb + (c[i] - 1) + 2;
    } else {
      cycle[i] = 2 + (c[i] - 1); // edge a and b + number of edges in chain
    }
  }

  cout << *max_element(cycle, cycle+n) << endl;
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
