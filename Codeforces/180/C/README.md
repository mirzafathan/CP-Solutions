بسم الله الرحمن الرحيم
<br />
Problem: https://codeforces.com/problemset/problem/180/C <br/>
<br/>
The idea is by computing the number of uppercases in the right side of a every letter, added by the number of lowercases in the left side that letter. I used the DP technique to compute them. If _l[i]_ denote the number of lowercases on the left side of letter _s[i]_ from string _s_. Initiate _l[0]_ with _0_. Then _l[i+1] = l[i]_ will apply iff s[i-1] is a lowercase letter, else _l[i+1] = l[i]_ will apply. The same technique is used to compute the number of uppercases which appear on the right side of every letter.
