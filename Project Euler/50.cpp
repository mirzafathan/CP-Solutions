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


void solve() {
  ll ans = 0;
  ll sum = 0;
  ll cons = 0;
  ll anscons = 0;

  rep(i,0,primeList.size()) {
    sum+=primeList[i];
    cons++;
    if(sum>=primes.size()) {
      cout << sum << endl;
      ll temp = sum;
      ll tc = cons;
      ll j = i;
      while(temp>0 && j>=0) {
        temp-=primeList[j];
        tc--;
        if(tc<anscons) break;
        if(temp<primes.size()) {
          if(primes[temp] && tc > anscons) {
            cout << "one" << temp  << endl;
            ans = temp;
            anscons = tc;
            cout << tc << endl;
            break;
          }
        }
        j--;
      }
      temp = sum;
      tc = cons;
      j = 0;
      while(temp>0 && j<=i) {
        temp-=primeList[j];
        tc--;
        if(tc<anscons) break;
        if(temp<primes.size()) {
          if(primes[temp] && tc > anscons) {
            cout << "two" << temp  << endl;
            ans = temp;
            anscons = tc;
            break;
          }
        }
        j++;
      }
      break;
    }
    if(primes[sum] && cons >= anscons) {
      ans = sum;
      anscons = cons;
      cout << "ans" << ans << endl;
      cout << anscons << "anscons" << endl;

    }
  }

  //rep(i,0,primeList.size()) cout << primeList[i] << " ";
  //cout << endl;

  cout << ans << endl;

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  primes.resize(1000001);
  sieve();

  solve();

  return 0;
}
