//Problem: https://codeforces.com/problemset/problem/1525/B
#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  long long t; cin >> t;
  while(t--) {
  solve();
  }

    return 0;
}

void solve() {
  long long n; cin >> n; long long a[n];
  long long minIdx = 0; long long minVal = 100000;
  long long maxIdx = 0; long long maxVal = 0;
  bool isSorted = true;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    if(a[i]<minVal) {
      minVal = a[i];
      minIdx = i;
    }
    if (a[i]>maxVal) {
      maxVal = a[i];
      maxIdx = i;
    }
    if(i>0 && a[i]<a[i-1]) isSorted = false;
  }
  if(isSorted) {
    cout << 0 << endl;
    return;
  }
  if(minIdx==0 || maxIdx==n-1) {
    cout << 1 << endl;
    return;
  }
  if(minIdx==n-1 && maxIdx==0) {
    cout << 3 << endl;
    return;
  }
  cout << 2 << endl;
}
