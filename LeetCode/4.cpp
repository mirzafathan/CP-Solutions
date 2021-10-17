// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
  int m = nums1.size();
  int n = nums2.size();
  if(m>n) return findMedianSortedArrays(nums2, nums1);
  int total_length = m+n;
  int partition = total_length/2;

  if(m==0) {
    if(n%2) {
      return (double) nums2[partition];
    } else {
      return ((double) (nums2[partition] + nums2[partition-1]))/2;
    }
  }

  if(m==1) {
    if(nums1[0] > nums2[partition-1]) {
      if(total_length%2) return (double) (min(nums1[0], nums2[partition]));
      else {
        if(m==n) return ((double) (nums1[0]+nums2[0])) / 2;
        return (double) (nums2[partition-1] + min(nums1[0], nums2[partition])) / 2;
        }
    } else {
      if(total_length%2) return (double) (nums2[partition-1]);
      else {
        if(m==n) return (double) (nums1[0]+nums2[0])/2;
        return (double) (max(nums1[0], nums2[partition-2]) + nums2[partition-1]) / 2;
        }
    }
  }

  int k = m/2;
  int l = 1;
  int r = m;

  while(true) {
    if(nums1[k-1] > nums2[partition-k]) {
      if(k==1) {
        if(total_length%2) return (double) (min(nums1[k-1], nums2[partition]));
        else {
          if(m==n) {
            return (double) (nums2[partition-1] + nums1[k-1]) / 2;
          }
          return (double) (nums2[partition-1] + min(nums1[k-1], nums2[partition])) / 2;
        }
      }
      r = k;
      k = (l+k)/2;
      continue;
    } else if(nums1[k] < nums2[partition-k-1]) {
      if(k==(m-1)) {
        k++;
        if(total_length%2) return (double) (nums2[partition-k]);
        else {
          if(m<n) return (double) (max(nums1[k-1], nums2[partition-k-1]) + nums2[partition-k]) / 2;
          else return (double) (nums1[k-1] + nums2[0])/2; 
        }
      } 
      l = k;
      if((r+k)%2) k++;
      k = (r+k)/2;
      continue;
    } else {
      if(total_length%2) return (double) (min(nums1[k], nums2[partition-k]));
      else return (double) (max(nums1[k-1], nums2[partition-k-1]) + min(nums1[k], nums2[partition-k])) / 2;
    }
  }
}

/*
[100001]
[100000]
*/
void solve() {
  int a, b;
  cin >> a >> b;
  vector<int> nums1(a);
  vector<int> nums2(b);
  for(int i=0; i<a; i++) cin >> nums1[i];
  for(int i=0; i<b; i++) cin >> nums2[i];

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
