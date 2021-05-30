//http://codeforces.com/problemset/problem/1529/A
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;

    cin >> t;

    for(int i=0; i<t; i++) {
      cin >> n;
      int a[n];
      for(int i=0; i<n; i++) {
        cin >> a[i];
      }
      int min = *min_element(a, a+n);
      int count_min = 0;
      for(int i=0; i<n; i++) {
        if(min == a[i]) {
          count_min++;
        }
      }
      cout << n-count_min << endl;
    }


    return 0;
}
