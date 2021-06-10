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
    for(ll i=0; i<len-1; i++) {
      if(s[i]==s[i+1]) i++;
      else{
        res.push_back(s[i]);
        if(i==len-2) {
          res.push_back(s[len-1]);
        }
        sort(res.begin(), res.end());
      }
    }
    for(ll i=0; i<res.size(); i++) {
      cout << res[i];
      if(i<res.size()-1) {
        if(res[i]==res[i+1]) i++;
      }
    }
    cout << endl;
  }


  return 0;
}
