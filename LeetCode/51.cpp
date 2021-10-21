// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

class Solve {
  public:
  vector<vector< pair<int, int> > > solutionList(int n) {
    vector< pair<int, int> > solutions(n);
    vector< vector< pair<int, int> > > result;
    for(int i=0; i<n; i++) {
      if(isSolutionExistRow(0, solutions, n, i)) {
        result.push_back(solutions);
        solutions.clear();
      }
    }
    return result;
  }

  private:
  bool isSolutionExistRow(int row, vector< pair<int, int> > &solution, int n, int i) {
    if(row==n) {
      return true;
    }

    bool valid = true;
    for(int j=0; j<row; j++) {
      if(!isValid(solution[j], make_pair(row, i))) {
        valid = false;
        break;
      }
    }
    cout << i << " " << valid << endl;
    cout << "row: " << row << endl;
    if(valid) {
      solution[row] = make_pair(row,i);
      if(isSolutionExistRow(row+1, solution, n, i)) {
        return true;
      }
    }
      return false;
    
  }

  bool isValid(pair<int, int> a, pair<int, int> b) {
    return !(a.first == b.first || a.second == b.second || (a.first-a.second) == (b.first - b.second) || (a.first+a.second) == (b.first+b.second));
  }

};

class Solution {
  public:
  vector< vector<string> > solveNQueens(int n) {
    Solve solve;
    vector< vector< pair<int, int> > > queens;
    queens = solve.solutionList(n);
    vector< vector<string> > solution;
/*
    vector< vector<string> > solution;
    for(int i=0; i<queens.size(); i++) {
      for(int j=0; j<queens[i].size(); j++) {
        cout << queens[i].first << " " << queens[i].second << endl;
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
  vector<vector< pair<int,int> > > ans = solve.solutionList(4);

  cout << ans.size() << endl;
  
  for(int i=0; i<ans.size(); i++) {
    for(int j=0; j<ans[i].size(); j++) {
      cout << ans[i][j].first << ", " << ans[i][j].second << endl;
    }
    cout << endl;
  }
  return 0;
}
