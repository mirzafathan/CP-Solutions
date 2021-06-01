بسم الله الرحمن الرحيم
<br />
Problem: https://codeforces.com/problemset/problem/1472/C
<br />
I solved this problem using the Dynamic Programming, tabulation method specifically. Initialize array score which store score of every single index. Elements of score can be formulized as: <br />
<br />
__score[i] = score[i + a[i]] + a[i]__
<br /> <br />
The solution is the maximum value of array score.
