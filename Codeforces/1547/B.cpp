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

/* From hu_tao:

        Random stuff to try when stuck:
           -if it's 2C then it's dp
           -for combo/probability problems, expand the given form we're interested in
           -make everything the same then build an answer (constructive, make everything 0 then do something)
           -something appears in parts of 2 --> model as graph
           -assume a greedy then try to show why it works
           -find way to simplify into one variable if multiple exist
           -treat it like fmc (note any passing thoughts/algo that could be used so you can revisit them)
           -find lower and upper bounds on answer
           -figure out what ur trying to find and isolate it
           -see what observations you have and come up with more continuations
           -work backwards (in constructive, go from the goal to the start)
           -turn into prefix/suffix sum argument (often works if problem revolves around adjacent array elements)
           -instead of solving for answer, try solving for complement (ex, find n-(min) instead of max)
           -draw something
           -simulate a process
           -dont implement something unless if ur fairly confident its correct
           -after 3 bad submissions move on to next problem if applicable
           -do something instead of nothing and stay organized
           -write stuff down
        Random stuff to check when wa:
           -if code is way too long/cancer then reassess
           -switched N/M
           -int overflow
           -switched variables
           -wrong MOD
           -hardcoded edge case incorrectly
        Random stuff to check when tle:
           -continue instead of break
           -condition in for/while loop bad
        Random stuff to check when rte:
           -switched N/M
           -long to int/int overflow
           -division by 0
           -edge case for empty list/data structure/N=1
     */

/************************/

void solve() {
  string s; cin >> s;
  ll len = s.length();

  bool valid = false;
  ll apos=0;
  while(true) {
    if(s[apos]=='a') {
      valid = true;
      break;
    }
    if(apos==len) {
      break;
    }
    apos++;
  }

  if(!valid) {
    cout << "NO" << endl;
    return;
  }

  ll i, j; i = j = apos;

  ll itr = 1;

  while(itr<len) {
    if(i<len-1) {
    if(s[i+1]-s[i]==1 && s[i+1]=='a'+itr) {
      i++;
      itr++;
      continue;
    }
    if(s[i+1]-s[j]==1 && s[i+1]=='a'+itr) {
      i++;
      itr++;
      continue;
    }
    }
    if(j>0){
    if(s[j-1]-s[j]==1 && s[j-1]=='a'+itr) {
      j--;
      itr++;
      continue;
    }

    if(s[j-1]-s[i]==1 && s[j-1]=='a'+itr) {
      j--;
      itr++;
      continue;
    }
    }
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t; cin >> t;
  while(t--) {
    solve();
  }



  return 0;
}
