#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t; cin >> t;

  while(t--) {
    string s; cin >> s;
    ll len = s.length();
    ll ans = 0;
    vector<ll> a;
    for(ll i=0; i<len-2; i++) {
      if(i+4<len) {
        if(s[i]=='t' && s[i+1]=='w'
        && s[i+2]=='o' && s[i+3]=='n' && s[i+4]=='e') {
          ans++;
          a.push_back(i+3);
          i = i+4;
        }
      }
      if(s[i]=='o' && s[i+1]=='n' && s[i+2]=='e') {
        ans++;
        a.push_back(i+2);
        i = i+2;
      }
      if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o') {
      //  cout << "ju" << endl;
      //  cout << "ok"<< endl;
      //  cout << i << endl;
        ans++;
        a.push_back(i+2);
        i = i+2;
      }

    }
    //cout << a.size()<< endl;
    cout << ans << endl;
    if(a.size()==0) {
      cout << endl;
    }
    else {
      for(ll i=0; i<a.size(); i++) {
        cout << a[i];
        if(i==a.size()-1) cout << endl;
        else cout << " ";
      }
    }
  }

  return 0;
}
