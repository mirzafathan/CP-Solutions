// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      int dp[3][n];

      for(int i=0; i<n; i++) dp[0][i] = 0;

      for(int k=1; k<=2; k++) {
        int minm = prices[0];
        for(int i=0; i<n; i++) {
          if(i==0) dp[k][i] = 0;
          else {
            minm = min(minm, prices[i]-dp[k-1][i-1]);
            dp[k][i] = max(dp[k][i-1], prices[i]-minm);
          }
        }
      }

      return dp[2][n-1];
    }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> v;

  int in;
  while(true) {
    cin >> in;
    if(in<0) break;
    v.push_back(in);
  }

  Solution solve;
  cout << solve.maxProfit(v) << endl;

  return 0;
}
