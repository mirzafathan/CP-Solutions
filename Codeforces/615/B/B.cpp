//https://codeforces.com/problemset/problem/615/B
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long u, v;
  long long n, m; cin >> n >> m;
  vector< vector<long long> > a(n);
  long long seg_count[n], tail_length[n];
  long long ans[n];
  for(long long i=0; i<n; i++) seg_count[i] = 0;
  for(long long i=0; i<m; i++) {
    cin >> u >> v;
    a[u-1].push_back(v);
    a[v-1].push_back(u);
    seg_count[u-1]++;
    seg_count[v-1]++;
  }

  tail_length[0] = 1;
  ans[0] = seg_count[0];
  for(long long i=1; i<n; i++) {
    long long max_tail = 1;
    for(long long j=0; j<a[i].size(); j++) {
      if(i>a[i][j]-1) {
        if(tail_length[a[i][j]-1]+1>max_tail) {
          max_tail = tail_length[a[i][j]-1]+1;
        }
      }
    }
    tail_length[i] = max_tail;
    ans[i] = max_tail * seg_count[i];
  }

  cout << *max_element(ans, ans+n) << endl;

  return 0;
}
