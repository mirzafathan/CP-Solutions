//https://codeforces.com/problemset/problem/877/B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string s; cin >> s;
	ll n=s.size();
	ll a1=0, a2=0, a3=0;
	for(ll i=0;i<n;i++){
		if(s[i]=='a'){
			a1++;
			a3++;
		} else a2++;
		a1 = max(a1,a2);
		a2 = max(a2,a3);
	}
	cout << a1 << endl;
	return 0;
}
