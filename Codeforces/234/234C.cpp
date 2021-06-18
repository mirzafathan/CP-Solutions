// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  ll n; cin >> n;
  ll t[n+1];

  for(ll i=1; i<=n; i++) {
    cin >> t[i];
  }

  ll dp[n];
  ll pos=0;
  ll neg=0;
  ll zer=0;
  dp[0] = 0;
  for(ll i=1; i<=n; i++) {
    if(t[i]<0) {
      neg++;
    } else if(t[i]==0) {
      zer++;
    }
  }
  dp[0]=neg+zer+pos;
  for(ll i=1; i<n; i++) {
    if(t[i]>0) {
      pos++;
    } else if(t[i]<0){
      neg--;
    }
    dp[i] = pos+neg+zer;

  }

  cout << *min_element(dp+1, dp+n) << endl;

  return 0;
}
