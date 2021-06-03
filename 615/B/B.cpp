//https://codeforces.com/problemset/problem/615/B
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long n, m; cin >> n >> m;
  long long seg_count[n], tail_length[n];
  long long a[m][m];
  for(long long i=0; i<n; i++) seg_count[i] = 0;
  for(long long i=0; i<m; i++) {
    cin >> a[0][i] >> a[1][i];
    seg_count[a[0][i]-1]++;
    seg_count[a[1][i]-1]++;
  }

  tail_length[0] = 1;
  for(long long i=1; i<n; i++) {
    long long max_tail = 0;
    for(long long j=0; j<m; j++) {
      if((a[0][j]==(i+1) && (i+1)>a[1][j])) {
        if(tail_length[a[1][j]-1]+1>max_tail) {
          max_tail = tail_length[a[1][j]-1]+1;
        }
      } else if ((a[1][j]==i+1) && (i+1>a[0][j])) {
        if(tail_length[a[0][j]-1]+1>max_tail) {
          max_tail = tail_length[a[0][j]-1]+1;
        }
      }
    }
    tail_length[i] = max_tail;
  }
  long long ans[n];
  for(long long i=0; i<n; i++) ans[i] = tail_length[i]*seg_count[i];

  cout << *max_element(ans, ans+n) << endl;

  return 0;
}
