// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n; cin >> n;
  ll trees[n+1];
  ll height[n+1];

  trees[0] = height[0] = 0;

  for(ll i=1; i<=n; i++)
    cin >> trees[i] >> height[i];

  ll dpl[n+1], dps[n+1], dpr[n+1];

  for(ll i=0; i<=n; i++) {
    dpl[i] = dps[i] = dpr[i] = 0;
  }

  for(ll i=1;i<n;i++) {
    dps[i] = max(max(dpl[i-1],dps[i-1]),dpr[i-1]);
    if(i==1) {
      dpl[i] = 1;
      continue;
    }
    if(trees[i]-trees[i-1]>height[i]) {
      dpl[i] = max(dps[i-1], dpl[i-1])+1;
    }
    if(trees[i]-trees[i-1]-height[i-1]>height[i]) {
      dpl[i] = max(max(dpl[i], dpr[i-1]+1), dps[i-1]+1);
    }
    if(trees[i+1]-trees[i]>height[i]) {
      dpr[i] = max(max(dpl[i-1],dps[i-1]),dpr[i-1])+1;
    }
  }

  dpr[n] = max(max(dps[n-1], dpr[n-1]), dpl[n-1])+1;

  cout << dpr[n] << endl;



  return 0;
}
