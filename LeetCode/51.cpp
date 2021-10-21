// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

class Solve {
  public:
  vector< pair<int, int> > solutionList(int n) {
    vector< pair<int, int> > solutions(n), error_return(0);
    if(isSolutionExistRow(0, solutions, n)) return solutions;
    else return error_return;
  }

  private:
  bool isSolutionExistRow(int row, vector< pair<int, int> > solution, int n) {
    bool a;
    if(row==n) {
      return true;
    }

    for(int i=0; i<n; i++) {
      bool valid = true;
      for(int j=0; j<row; j++) {
        if(!isValid(solution[j], make_pair(row, i))) {
          valid = false;
          break;
        }
      }
      if(!valid) continue;
      //cout << i << endl;
      solution[row] = make_pair(row,i);
     // cout << solution[row].first << " " << solution[row].second << endl;
      bool a = isSolutionExistRow(row+1, solution, n);
      cout << a << "a" << row << "row" << endl;
    }

    return a;
  }

  bool isValid(pair<int, int> a, pair<int, int> b) {
    return !(a.first == b.first || a.second == b.second || abs(a.first-a.second) == abs(b.first - b.second) || a.first+a.second == b.first+b.second);
  }


};

class Solution {
  public:
  vector< vector<string> > solveNQueens(int n) {
    Solve solve;
    vector< pair<int,int> > queens;
    queens = solve.solutionList(n);

    vector< vector<string> > solution;
    /*for(int i=0; i<queens.size(); i++) {
      for(int j=0; j<queens[i].length(); j++) {

      }
    }*/
    return solution;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  Solve solve;
  vector< pair<int,int> > ans = solve.solutionList(4);

  cout << ans.size() << endl;
  
  for(int i=0; i<ans.size(); i++)
    cout << ans[i].first << ", " << ans[i].second << endl;

  return 0;
}
