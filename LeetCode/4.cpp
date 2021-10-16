// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
  int m = nums1.size();
  int n = nums2.size();
  int total_length = m+n;
  if(m>n) return findMedianSortedArrays(nums2, nums1);
  int partition = total_length/2;
  int k = m/2;
  int l = 1;
  int r = m;

  if(m==0) {
    if(n%2) {
      return (double) nums2[partition];
    } else {
      return ((double) (nums2[partition] + nums2[partition-1]))/2;
    }
  }

  if(m==1) {
    if(nums1[0] > nums2[partition-1]) {
      if((m+n)%2) return (double) (min(nums1[0], nums2[partition]));
      else return (double) (nums2[partition-1] + min(nums1[0], nums2[partition])) / 2;
    } else {
      if((m+n)%2) return (double) (nums2[partition-1]);
      else return (double) (max(nums1[0], nums2[partition-2]) + nums2[partition-1]) / 2;
    }
  }
  return -1;
/*
  while(true) {
    if(k==1 || k==m) {

    }
    if(nums1[k-1] > nums2[partition-k]) {
      r = k;
      k = (l+k)/2;
      continue;
    } else if(nums1[k] < nums2[partition-k-1]) {
      l = k;
      k = (r+k)/2;
      continue;
    } else {

    }
  }


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
      if(n%2){
        return nums2[partition];
      } else {
        return ((double) (nums2[partition-1] + min(nums2[partition], nums1[0])) / 2);
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

  } */
}


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
