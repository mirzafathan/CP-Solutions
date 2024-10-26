// Muhammad Mirza Fathan | 2024
// Book Shop

#include <iostream>

using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    int h[1005];
    int s[1005];
    
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    long long dp[100005] = {};
    dp[0] = 0;
    
    
    for(int j = 0; j < n; j++) {
        for(int i = x; i >= 1; i--) {
             if(i < h[j]) break;
             dp[i] = max(dp[i], dp[i - h[j]] + s[j]);
         } 
    }
    
    cout << dp[x] << endl;

    
    return 0;
}