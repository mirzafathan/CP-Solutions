// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;
#define fr front
#define pb push_back
#define mp make_pair
typedef long long ll;

/************************/
/* TEMPLATES */
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

/************************/

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  return 0;
}
