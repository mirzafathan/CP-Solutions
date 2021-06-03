//https://codeforces.com/problemset/problem/615/B
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long n, m; cin >> n >> m;
  long long u, v;
  long long seg_count[n], tail_length[n];
  vector<vector<int> > a(
    n, vector<int>(n));
  long long ans[n];
  for(long long i=0; i<n; i++) seg_count[i] = 0;
  for(long long i=0; i<m; i++) {
    cin >> u >> v;
    a[u-1][v-1] = 1;
    a[v-1][u-1] = 1;
    seg_count[u-1]++;
    seg_count[v-1]++;
  }

  tail_length[0] = 1;
  ans[0] = seg_count[0] * tail_length[0];
  for(long long i=1; i<n; i++) {
    long long max_tail = 1;
    for(long long j=0; j<i; j++) {
      if(a[i][j]) {
        if(tail_length[j]+1>max_tail) {
          max_tail = tail_length[j]+1;
        }
      }
    }
    tail_length[i] = max_tail;
    ans[i] = max_tail * seg_count[i];
  }
  cout << *max_element(ans, ans+n) << endl;

  return 0;
}
