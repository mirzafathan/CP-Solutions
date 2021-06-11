#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  ll n; cin >> n;
  while(n--) {
    cin >> s;
    ll len = s.length();
    vector<char> res;
    if(len==1) {
      cout << s[0] << endl;
      continue;
    }
    for(ll i=0; i<len; i++) {
      if(i<len-1 && s[i]==s[i+1]) i++;
      else{
        res.push_back(s[i]);
        if(i==len-2) {
          res.push_back(s[i+1]);
        }
        sort(res.begin(), res.end());
      }
    }
    //cout << res.size();
    for(ll i=0; i<res.size(); i++) {
      if(i>0) {
        if(res[i-1]!=res[i]) cout << res[i];
      } else cout << res[i];
    }
    cout << endl;
  }


  return 0;
}
