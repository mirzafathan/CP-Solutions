// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
}


void solve() {
  cin >> m >> n;
  vector<int> nums1(m);
  vector<int> nums2(n);
  for(int i=0; i<m; i++) cin >> nums1[i];
  for(int i=0; i<n; i++) cin >> nums2[i];

  cout << findMedianSortedArrays(nums1, nums2) << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  /*
  // for multiple testcase problems

  ll t; cin >> t;
  while(t--) {
    solve();
  }

  */

  solve();

  return 0;
}
