// Muhammad Mirza Fathan
#include <bits/stdc++.h>
#define fr front
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
vector< vector<int> > time_stamp;
map< pair<int,int>, pair<int,int> > parents;
vector< pair<int,int> > monsters;
pair<int,int> start;
pair<int,int> finish;
vector< <pair<int,int> > moves;
int n, m;

/* MOVES */}

/* ****** */

/* CHECK MOVE */

bool isValid(int y int x, int stopwatch) {
	if(y<0 || y>=n || x<0 || x>=m)
		return false;
	if(time_stamp[y][x]<= stopwatch)
		return false;
	return true;
}

/* ****** */

/* MONSTERS BFS */

void monsters_bfs() {

	queue< pair< pair<int,int>, int> > q;
	for(int i=0; i<monsters.size(); i++) {
		q.push(mp(monsters[i], 0));
	}
	while(!q.empty()) {
    int y = q.fr().first.first;
    int x = q.fr().first.second;
		int curtime = q.fr().second;
		time_stamp[y][x] = curtime;

		q.pop();

    for(ll j=0; j<4; i++) {
      ll newy = y+moves[j].first;
      ll newx = x+moves[j].second;
      if(isValid(newy, newx, curtime+1))
        q.push(mp(mp(newy,newx), curtime+1));
    }

	}

}

/* ****** */

/* ESCAPE ALGORITHM */

bool escape(pair<int,int> start) {
	queue< pair< pair<int,int>,int > > q;
	q.push(mp(start, 0));
	while(!q.empty()) {
    int y = q.fr().first.first;
    int x = q.fr().first.second;
		int curtime = q.fr().second;
		time_stamp[y][x] = curtime;

		q.pop();

    if(y==0 || y==n-1 || x==0 || x==m-1) {
	//		cout << "ok" << endl;
			finish = cur;
			return true;
		}

    for(ll j=0; j<4; i++) {
      ll newy = y+moves[j].first;
      ll newx = x+moves[j].second;
      if(isValid(newy, newx, curtime+1)) {
        parents[mp(newy,newx)] = cur;
        q.push(mp(mp(newy,newx), curtime+1));
      }
    }

//		cout << curtime << " " << time_stamp[cur.first][cur.second] << endl;
		//cout << cur.first<<" "<<cur.second << endl;
	}
	return false;
}

/* ****** */

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  moves.pb(mp(1,0));
  moves.pb(mp(-1,0));
  moves.pb(mp(0,1));
  moves.pb(mp(0,-1));

	cin >> n >> m;


	vector< pair<int,int> > path;


	time_stamp.resize(n);


	for(int i=0; i<n; i++) time_stamp[i].resize(m);


	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			time_stamp[i][j] = INT_MAX;
		}
	}


	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			char yx; cin >> yx;
			if(yx=='#') time_stamp[i][j] = -1;
			if(yx=='M') monsters.pb(mp(i,j));
			if(yx=='A') start = mp(i,j);
		}
	}

	/* MONSTERS PROCESSING */
	monsters_bfs();

	/* ****** */

	/* ESCAPE!! */
	if(escape(start)) {
		time_stamp.clear();
		monsters.clear();
		cout << "YES" << endl;
	//	cout << finish.first << " " << finish.second << endl;
		//cout << start.first << " " << start.second << endl;
/*		for(map< pair<int,int>, pair<int,int> > ::const_iterator it = parents.begin();
    it != parents.end(); ++it)
{
    std::cout << it->first.first << " " << it->first.second << "->" << it->second.first << " " << it->second.second << "\n";
}*/
		while(finish!=start) {
			path.pb(finish);
		//	cout << finish.first << " " << finish.second << endl;
			finish = parents[finish];
		//	cout << finish.first << " " << finish.second << endl;
		}
		path.pb(start);
		int len = path.size();
		cout << len-1 << endl;
		for(int i=len-2; i>=0; i--) {
			int ychange = path[i].first - path[i+1].first;
			int xchange = path[i].second - path[i+1].second;
			if(ychange==1) {
				cout << 'D';
			} else if(ychange==-1) {
				cout << 'U';
			} else if(xchange==1) {
				cout << 'R';
			} else if(xchange==-1) {
				cout << 'L';
			}
		} cout << endl;
		return 0;

	}

	cout << "NO" << endl;

  return 0;
}
