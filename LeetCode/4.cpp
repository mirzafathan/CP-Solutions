// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

int m,n;

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
  int total_length = m+n;
  if(m>n) return findMedianSortedArrays(nums2, nums1);
  
  int partition = total_length/2;
  int k = m/2;
  int l = 1;
  int r = m;

  if(k==1) {
    if(nums1[k-1] <= nums2[partition-k]) {
      if(total_length%2) {
        if(m>1) return min(nums1[0], nums2[partition-k]);
        else return nums2[partition-k];
      } else {
        if(m>1) return (((double) (max(nums1[0], nums2[partition-k-1]) + min(nums1[1], nums2[partition-k]))/2));
        else return (((double) (max(nums1[0], nums2[partition-k-1]) + nums2[partition-k])/2));
      }
    } else {
      if(n%2)
      if(partition < ) {

      }
    }
  } else if(k==m) {
    if(nums1[k-1] <= nums2[partition-k]) {
      if(total_length%2) {
        if(m>1) return min(nums1[0], nums2[partition-k]);
        else return nums2[partition-k];
      } else {
        if(m>1) return (((double) (max(nums1[0], nums2[partition-k-1]) + min(nums1[1], nums2[partition-k]))/2));
        else return (((double) (max(nums1[0], nums2[partition-k-1]) + nums2[partition-k])/2));
      }
    }
  }

  if(nums1[k-1] > nums2[partition-k]) {
    r = k;
    k = (l+k)/2;
  } else if(nums1[k] < nums2[partition-k-1]) {
    l = k;
    k = (k+r)/2;
  } else if(k==1) {

  } else if(k==m) {

  } else {

  }
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
