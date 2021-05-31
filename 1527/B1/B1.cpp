//https://codeforces.com/problemset/problem/1527/B1
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long t; cin >> t;
    for(int i=0; i<t; i++) {
      long long n; cin >> n;
      string s; cin >> s;
      if(n%2==1) {
        if(s[floor(n/2)]!='1' && n>1) { cout << "ALICE" << endl; }
        else { cout << "BOB" << endl; }
      } else cout << "BOB" << endl;
    }
    return 0;
}
