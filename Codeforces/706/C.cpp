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


ll mod(ll x) {
  return (x%MOD + MOD)%MOD;
}

ll power(ll x, ll y) {
  ll res = 1;
  x = x%MOD;
  if (x == 0) return 0;
  while (y > 0) {
    if (y&1) res = mod(res * x);
    y >>= 1; x = mod(x * x);
  }
  return res;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
      return b;
    if (b == 0)
      return a;

    if (a == b)
      return a;
    if (a > b)
        return gcd(a%b, b);
    return gcd(a, b%a);
}

void sieve() {
  primes[0] = false;
  primes[1] = false;
  for(ll i=2; i<primes.size(); i++) primes[i] = true;

  for(ll i=2; i*i<primes.size(); i++) {
    if(primes[i]) {
      for(ll j=i*i; j<primes.size(); j+=i)
        primes[j] = false;
    }
  }
  for(ll i=2; i<primes.size(); i++) {
    if(primes[i]) primeList.push_back(i);
  }

}

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

string reverse(string s) {
  string t;
  rrep(i,s.length()-1,0) {
    t.pb(s[i]);
  }
  return t;
}


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
  ll n; cin >> n;
  VI c(n+1);
  VS lex(n+1);

  rep(i,1,n+1) cin >> c[i];
  rep(i,1,n+1) cin >> lex[i];

  VVI dp(n+1);
  rep(i,1,n+1) dp[i].resize(2);

  dp[1][0] = 0;
  dp[1][1] = c[1];

  rep(i,2,n+1) {
    dp[i][0] = INF8;
    dp[i][1] = INF8;
  }

  rep(i,2,n+1) {
    bool tes = false;
    if(lex[i]>=lex[i-1]) {
      dp[i][0] = dp[i-1][0];
      tes = true;
    }
    if(reverse(lex[i])>=lex[i-1]) {
      dp[i][1] = dp[i-1][0] + c[i];
      tes = true;
    }
    if(lex[i]>=reverse(lex[i-1])) {
      dp[i][0] = min(dp[i][0], dp[i-1][1]);
      tes = true;
    }
    if(reverse(lex[i])>=reverse(lex[i-1])) {
      dp[i][1] = min(dp[i][1], dp[i-1][1]+c[i]);
      tes = true;
    }
    if(!tes) {
      cout << "-1" << endl;
      return;
    }
  }

  cout << min(dp[n][0], dp[n][1]) << endl;

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
