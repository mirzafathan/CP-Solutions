#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000000;
vector<ll> primeList;
bool primes[N+1];

void sieve() {
  primes[0] = false;
  primes[1] = false;
  for(ll i=2; i<=N; i++) primes[i] = true;

  for(ll i=2; i*i<=N; i++) {
    if(primes[i]) {
      for(ll j=i*i; j<=N; j+=i)
        primes[j] = false;
    }
  }
  for(ll i=2; i<=N; i++) {
    if(primes[i]) primeList.push_back(i);
  }

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

void solve() {
    ll a, b, k; cin >> a >>b >> k;
    ll minimum, maximum;
    maximum = 0;

    if(log2(a)+log2(b)<k) {
      cout << "NO" << endl;
      return;
    }

    ll bcopy = b;
    ll acopy = a;

    ll i=0;

    if(a==b) minimum = 0;
    else if(gcd(a,b)==a || gcd(a,b)==b) minimum = 1;
    else minimum = 2;

    if(minimum == k) {
      cout << "YES" << endl;
      return;
    }


    while(bcopy!=1 && i<primeList.size()) {
      if(primeList[i]*primeList[i] > bcopy) {
        maximum++;
        if(k>=minimum && k<=maximum && k!=1) {
          cout << "YES" << endl;
          return;
        }
        break;
      }
      if(bcopy%primeList[i]==0) {
        bcopy/=primeList[i];
        maximum++;
      }
      else i++;
      if(k>=minimum && k<=maximum && k!=1) {
        cout << "YES" << endl;
        return;
      }
    }



    i=0;
    while(acopy!=1 && i<primeList.size()) {
      if(primeList[i]*primeList[i] > acopy) {
        maximum++;
        if(k>=minimum && k<=maximum && k!=1) {
          cout << "YES" << endl;
          return;
        }
        break;
      }
      if(acopy%primeList[i]==0) {
        acopy/=primeList[i];
        maximum++;
      }
      else i++;
      if(k>=minimum && k<=maximum && k!=1) {
        cout << "YES" << endl;
        return;
      }

    }


    cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  sieve();
  ll t; cin >> t;

  while(t--) {
    solve();
  }


  return 0;
}
