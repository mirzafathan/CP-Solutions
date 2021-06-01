بسم الله الرحمن الرحيم
<br />
Problem: https://codeforces.com/problemset/problem/1472/C
<br />
I solved this problem using the Dynamic Programming, tabulation method specifically. Initialize array score which store score of every single index. Apply this: <br />
<br />
**score[i] = score[i + a[i]] + a[i] **<br />
The solution is the maximum value of array score.
