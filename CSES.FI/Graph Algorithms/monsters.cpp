// Muhammad Mirza Fathan
#include <bits/stdc++.h>
#define fr front
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
vector< vector<ll> > time_stamp;
vector< vector< pair<ll,ll> > > parents;
vector< pair<ll,ll> > monsters;
ll n, m;

/* MOVES */

pair<ll,ll> left(pair<ll,ll> point) {
	point.second--;
	return point;
}

pair<ll,ll> right(pair<ll,ll> point) {
	point.second++;
	return point;
}

pair<ll,ll> up(pair<ll,ll> point) {
	point.first--;
	return point;
}

pair<ll,ll> down(pair<ll,ll> point) {
	point.first++;
	return point;
}

/* ****** */

/* CHECK MOVE */

bool isValid(pair<ll,ll> point, ll stopwatch) {
	ll y = point.first;
	ll x = point.second;
	if(y<0 || y>=n || x<=0 || x>=m)
		return false;
	if(time_stamp[y][x]<= stopwatch)
		return false;
	return true;
}

/* ****** */

/* MONSTERS BFS */

void monsters_bfs(pair<ll,ll> monster) {

	queue< pair< pair<ll,ll>, ll> > q;
	q.push(mp(monster, 0));
	while(!q.empty()) {
		pair<ll,ll> cur = q.fr().first;
		ll curtime = q.fr().second;
		time_stamp[cur.first][cur.second] = curtime;
		q.pop();
		if(isValid(left(cur), curtime+1))
			q.push(mp(left(cur), curtime+1));
		if(isValid(right(cur), curtime+1))
			q.push(mp(right(cur), curtime+1));
		if(isValid(up(cur), curtime+1))
			q.push(mp(up(cur), curtime+1));
		if(isValid(down(cur), curtime+1))
			q.push(mp(down(cur), curtime+1));
	}

}

/* ****** */

/* ESCAPE ALGORITHM */

bool escape(pair<ll,ll> start) {
	return false;
}

/* ****** */

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


	cin >> n >> m;


	pair<ll,ll> start;


	parents.resize(n);
	time_stamp.resize(n);


	for(ll i=0; i<n; i++) {
		parents[i].resize(m);
		time_stamp[i].resize(m);
	}


	for(ll i=0; i<n; i++) {
		for(ll j=0; j<m; j++) {
			time_stamp[i][j] = LLONG_MAX;
		}
	}


	for(ll i=0; i<n; i++) {
		for(ll j=0; j<m; j++) {
			char yx; cin >> yx;
			if(yx=='#') time_stamp[i][j] = -1;
			if(yx=='M') monsters.pb(mp(i,j));
			if(yx=='A') start = mp(i,j);
		}
	}

	/* MONSTERS PROCESSING */

	for(ll i=0; i<monsters.size(); i++)
		monsters_bfs(monsters[i]);

	/* ****** */

	for(ll i=0; i<n; i++) {
		for(ll j=0; j<m; j++) {
			cout << time_stamp[i][j] << " ";
		} cout << endl;
	}






  return 0;
}
