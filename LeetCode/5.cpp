// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

/************************/
/* TEMPLATES */

#define fr front
#define bk back
#define pb push_back
#define mp make_pair
#define sc second
#define fi first
# define ll long long
# define ld long double
# define rep(i,x,y) for(ll i=x;i<y;i++)
# define rrep(i,x,y) for(ll i=x;i>=y;i--)
# define debug_stl(x) for(auto i:x){cout<<i<<" ";}cout<<endl;
# define debug_1d(x,a,b) rep(i,a,b){cout<<x[i]<<" ";}cout<<endl;
# define debug_2d(x,a1,b1,a2,b2) rep(i,a1,b1){rep(j,a2,b2){cout<<x[i][j]<<" ";}cout<<endl;}
# define all(x) x.begin(), x.end()
# define MOD (ll)(1e9+7)
# define INF8 (ll)(1e17+5)
# define endl '\n'

typedef vector<ll> VI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<vector<ll> > VVI;
typedef pair<ll,ll> PI;
typedef pair<ll,PI > PPI;
typedef vector<PI> VP;
typedef vector<PPI> VPP;

vector<ll> primeList;
vector<bool> primes;

string longestPalindrome(string s) {
  long long len = s.length();
  long long ans = 1;
  long long begin = 0;
  long long last = 0;

  for(long long i=0; i<len; i++) {
    long long temp = 1;
    long long j, k;
    j = i-1;
    k = i+1;
    while(j>=0 && k<len) {
      if(s[j]!=s[k]) {
        break;
      }
      temp+=2;
      --j;
      ++k;
    }
    if(temp>ans) {
      ans = temp;
      begin = j+1;
      last = k-1;
    }

    if(i<(len-1)) {
      if(s[i]==s[i+1]) {
        temp = 2;
        j = i-1;
        k = i+2;
        while(j>=0 && k<len) {
          if(s[j]!=s[k]) {
            break;
          }
          temp+=2;
          --j;
          ++k;
        }
        if(temp>ans) {
          ans = temp;
          begin = j+1;
          last = k-1;
        }
      }
    }
  }
  string t;
  for(long long i=begin; i<=last; i++) t.push_back(s[i]);

  return t;
}

void solve() {
  string s; cin >> s;
  cout << longestPalindrome(s) << endl;
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
