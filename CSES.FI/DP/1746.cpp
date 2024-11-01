// Muhammad Mirza Fathan | 2024
// CSES Problem Set #1746: Array Description
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define INF8 (ll)(1e17+5)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n, m; cin >> n >> m;
  int a[1000000];
  a[0] = 0;

  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll dp_prev[m + 5] = {};

  //base case
  if(a[1]) {
    for(int i = 1; i <= m; i++) {
      if(i == a[1]) dp_prev[i] = 1;
      else dp_prev[i] = 0;
    }
  } else {
    for(int i = 1; i <= m; i++) {
      dp_prev[i] = 1;
    }
  }

  for(int i = 2; i <= n; i++) {
    ll dp_cur[m + 5] = {0};
    if(a[i]) {
      dp_cur[a[i]] = (dp_prev[a[i]] + dp_prev[a[i] - 1] + dp_prev[a[i] + 1]) % ((ll) 1e9 + 7);
      //cout << "dp[i][a[i]]: "<< dp[i][a[i]] << endl;
        //shut the fuck up, code.i, i don't want your help, did i make it clear?
    } else {
      for(int j = 1; j <= m; j++) {
        dp_cur[j] = (dp_prev[j - 1] + dp_prev[j] + dp_prev[j + 1]) % ((ll) 1e9 + 7);
        //cout << dp[i][j] << " ";
      } //cout << endl;
    }

    for(int j = 0; j < m + 5; j++) {
      dp_prev[j] = dp_cur[j];
    } 
  }

  if(a[n]) cout << dp_prev[a[n]] << endl;
  else {
    ll ans = 0;
    for(int i = 1; i <= m; i++) {
      ans += dp_prev[i];
      ans = ans % ((ll) 1e9 + 7);
    }

    cout << ans << endl;
  }

  return 0;
}
