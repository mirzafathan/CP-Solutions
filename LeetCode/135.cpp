// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int candy(vector<int>& ratings) {
    int len = ratings.size();
    vector<int> s(len);
    int ans = 0;
    
    for(int i=0; i<len; i++) s[i] = 1;
    
    for(int i=0; i<len; i++) {
      if(i>0) {
        if(ratings[i] > ratings[i-1]) {
          s[i] = s[i-1] + 1;
        }
      }
      if(i<len-1) {
        if(ratings[i] > ratings[i+1]) {
          int j = i;
          int cnt = 1;
          while(j<len-1) {
            if(ratings[j] > ratings[j+1]) { 
              cnt++;
              j++;
            } else break;
          }
          int temp = cnt;
          int k = j;
          while(k>=i) {
            if((temp - cnt + 1) > s[k]) {
              s[k] = temp - cnt + 1;
            }
            k--;
            cnt--;
          }
          i = j;
        }
      }
    }

    for(int i=0; i<len; i++) ans += s[i];
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> ratings;
  int n; cin >> n;
  for(int i=0; i<n; i++) {
    int in; cin >> in;
    ratings.push_back(in);
  }

  Solution test;
  cout << test.candy(ratings) << endl;

  return 0;
}
