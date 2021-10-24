// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector< vector<string> > solveNQueens(int n) {

    vector< vector<string> > solution;
    vector<string> queens;
    for(int i=0; i<n; i++) {
      string temp;
      for(int j=0; j<n; j++) {
        temp.push_back('.');
      }
      queens.push_back(temp);
    }
    solveNQueens(solution, queens, 0, n);

    return solution;
  }
  private:
  void solveNQueens(vector< vector<string> > &solution, vector<string> &queens, int row, int n) {
    if(row==n) {
      solution.push_back(queens);
      return;
    }

    for(int i=0; i<n; i++) {
      if(isValid(queens, row, i)) {
        queens[row][i] = 'Q';
        solveNQueens(solution, queens, row+1, n);
        queens[row][i] = '.';
      }
    }

  }
  bool isValid(vector<string> queens, int row, int col) {
    int sum = row+col;
    int dif = row-col;

    for(int i=0; i<row; i++) {
      if(queens[i][col]=='Q') return false;
      
      if((sum-i)>=0) {
        if(queens[i][sum-i] == 'Q') return false;
      }
      
      if((i-dif)>=0) {
        if(queens[i][i-dif] == 'Q') return false;
      }
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n; cin >> n;
  Solution solve;
  vector< vector<string> > solutions = solve.solveNQueens(n);
  
  for(int i=0; i<solutions.size(); i++) {
    for(int j=0; j<solutions[i].size(); j++) {
      cout << solutions[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
