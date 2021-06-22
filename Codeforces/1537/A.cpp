// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll n; cin >> n; ll a[n+1];
  ll sum = 0;
  for(ll i=0; i<n; i++) {
    cin >> a[i];
    sum+=a[i];
  }

  if(sum%n==0 && sum/n==1) {
    cout << 0 << endl;
    return;
  }

  if(sum/n<1) {
    cout << 1 << endl;
    return;
  }

  cout << sum-n << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t; cin >> t;
  while(t--) {
    solve();
  }


  return 0;
}
