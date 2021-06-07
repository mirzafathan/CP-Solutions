//http://codeforces.com/problemset/problem/1529/B
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long t; cin >> t;

    for(long long i=0; i<t;i++) {
      long long n; cin >> n;
      long long a[n]; for(long long i=0; i<n; i++) {cin>>a[i];}
      sort(a, a+n);
      long long first_positive;
      if(a[n-1]<=0) {
        cout << n << endl;
      } else {
        int include_positive = 1;
        for(long long i=0; i<n; i++) {
          if(a[i]>0) {
            first_positive = i;
            break;
          }
        }
        for(long long i=0; i<first_positive; i++) {
          if(abs(a[i]-a[i+1]) < a[first_positive]) {
            include_positive = 0;
            break;
          }
        }
        if(include_positive) {
          cout << first_positive + 1 << endl;
        } else {
          cout << first_positive << endl;
        }
      }
    }
    return 0;
}
