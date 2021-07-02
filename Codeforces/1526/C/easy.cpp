//https://codeforces.com/problemset/problem/1526/B
#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n; cin >> n;
  vector<long long> a(n+1);

  priority_queue<long long,
  vector<long long>,
  greater<long long> > most_neg;

  long long cur_health = 0;
  long long ans = 0;

  for(long long i=1; i<=n; i++) {
    cin >> a[i];
    if(cur_health+a[i]>=0) {
      cur_health+=a[i];
      if(a[i]<0) most_neg.push(a[i]);
      ans++;
    } else {
      if(!most_neg.empty()) {
      if(most_neg.top()<a[i]) {
        cur_health-=most_neg.top();
        most_neg.pop();
        cur_health+=a[i];
        most_neg.push(a[i]);
      }
    }
    }
  }

  cout << ans << endl;

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


    solve();

  return 0;
}
