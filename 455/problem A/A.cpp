#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long n; cin >> n;
  long long a[n];
  for(long long i=0; i<n; i++) cin >> a[i];
  long long maxel = *max_element(a,a+n);
  long long cnt[maxel];
  for(long long i=0; i<maxel; i++) cnt[i] = 0;
  for(long long i=0; i<n; i++) cnt[a[i]-1]++;

  long long ans[maxel+1];
  ans[0] = 0;
  ans[1] = cnt[0];
  for(long long i=2; i<maxel+1; i++) {
    ans[i] = max(ans[i-1], ans[i-2] + i*cnt[i-1]);
  }

  cout << ans[maxel] << endl;
  return 0;
}
