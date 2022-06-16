class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndexForChar (256, -1);
        int i = 0, res = 0;
        for(int j=0; j<s.length(); j++) {
            i = max(i, lastIndexForChar[s[j]]+1);
            res = max(j-i+1, res);
            lastIndexForChar[s[j]] = j;
        }
        return res;
    }
};