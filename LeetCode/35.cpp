// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
      stack<int> stackint;
      stackint.push(-1);
      int len = s.length();
      int ans = 0;
      int complete = -1;

      for(int i=0; i<len; i++) {
        if(s[i] == '(') {
          if(complete>=0) {
            stackint.push(complete);
            complete = -1;
          }
          else stackint.push(i);
        }
        else {
          if(stackint.size() > 1) {
            int first = stackint.top();
            ans = max(ans, (i-first+1));
            stackint.pop();
            complete = first;
          } else complete = -1;
        } 
      }
      
      return ans;

    }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s; cin >> s;
  Solution solve;
  cout << solve.longestValidParentheses(s) << endl;

  return 0;
}
