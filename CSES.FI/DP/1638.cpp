// Muhammad Mirza Fathan | 2024
// Grid Paths

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define INF8 (ll)(1e17+5)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n; cin >> n;

  int grid[1000 + 5][1000 + 5] = {};

  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < n; j++) {
      if(s[j] == '*') grid[i][j] = 0;
      else grid[i][j] = -1;
    }
  }

  grid[n-1][n-1] = (grid[n-1][n-1] == 0)? 0 : 1;

  for(int i = n-1; i >= 0; i--) {
    for(int j = n-1; j >= 0; j--) {
      if(grid[i][j] >= 0) continue;
      if(i == n-1 && j == n-1) continue;
      grid[i][j] = (grid[i][j+1] + grid[i+1][j])%((int) 1e9 + 7);
    }
  }

  cout << grid[0][0] << endl;

  return 0;
}
