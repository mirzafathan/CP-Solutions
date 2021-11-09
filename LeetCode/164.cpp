// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
      int len = nums.size();
      if(len==1) return 0;
      if(len==2) return abs(nums[0]-nums[1]);
      int numBucket = len-1;
      int hi = *max_element(nums.begin(), nums.end());
      int lo = *min_element(nums.begin(), nums.end());
      int total_diff = hi - lo;

      if(total_diff==0) return 0;

      int bucketSize = total_diff/numBucket + 1;
      vector<int> bucketMin(numBucket, INT_MAX);
      vector<int> bucketMax(numBucket, INT_MIN);
      vector<bool> filled(numBucket, false);
      
      
      for(int i=0; i<len; i++) {
        int k = (nums[i]-lo)/bucketSize;
        if(nums[i] > bucketMax[k]) bucketMax[k] = nums[i];
        if(nums[i] < bucketMin[k]) bucketMin[k] = nums[i];
        filled[k] = true;
      }

      int ans = 0;
      int i=0;
      while(i<numBucket-1) {
        if(!filled[i]) {
          i++;
          continue;
        }
        int temp = -1;
        for(int j=i+1; j<numBucket; j++) {
          if(filled[j]) {
            temp = bucketMin[j];
            break;
          }
        }
        if(temp<0) {
          i++;
          continue;
        }
        ans = max(ans, temp-bucketMax[i]);
        i++;
      }

      return ans;
    }
};



/*
      for(int i=0; i<numBucket; i++) {
        cout << bucketMax[i] << " ";
      } cout << endl;

      for(int i=0; i<numBucket; i++) {
        cout << bucketMin[i] << " ";
      } cout << endl;

      for(int i=0; i<numBucket; i++) {
        cout << filled[i] << " ";
      } cout << endl;
*/

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> n;
  int in;
  while(true) {
    cin >> in;
    if(in<0) break;
    n.push_back(in);
  }

  Solution solve;
  cout << solve.maximumGap(n) << endl;

  return 0;
}
