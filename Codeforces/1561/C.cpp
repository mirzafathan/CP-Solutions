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

void solve() {
  ll n; cin >> n;
  ll max_monster = 0;
  ll total_mons = 0;

  rep(i,0,n) {
    ll k; cin >> k;
    bool not_biggest = true;
    rep(j,0,k) {
      ll a; cin >> a;
      if(a-(j-1)>max_monster) {
        max_monster = a-(j-1);
        not_biggest = false;
      }
    }
    if(not_biggest) {
      total_mons+=k;
    }
  }

  cout << max(max_monster - total_mons, (long long) 1) << endl;

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
