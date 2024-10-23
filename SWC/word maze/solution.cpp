#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <string>
#include <set>

using namespace std;

extern void init();
extern void addRoom(int mID, char mWord[], int mDirLen[]);
extern void setCurrent(char mWord[]);
extern int moveDir(int mDir);
extern void changeWord(char mWord[], char mChgWord[], int mChgLen[]);

/////////////////////////////////////////////////////////////////////////

#define INIT	0
#define ADD		1
#define SET		2
#define MOVE	3
#define CHANGE	4

#define MAX_LENGTH	(11 + 1)

static bool run()
{
	int cmd, ans, ret, mid;
	int dir[3];
	char mWord[MAX_LENGTH];
	char mRetWord[MAX_LENGTH];

	int Q = 0;
	bool okay = false;

	scanf("%d", &Q);
	for (int q = 0; q < Q; ++q)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case INIT:
			init();
			okay = true;
			break;

		case ADD:
			scanf("%d %s %d %d %d", &mid, mWord, &dir[0], &dir[1], &dir[2]);
			addRoom(mid, mWord, dir);
			break;

		case SET:
			scanf("%s", mWord);
			setCurrent(mWord);
			break;

		case MOVE:
			scanf("%d %d", &dir[0], &ans);
			ret = moveDir(dir[0]);
			if (ret != ans) {
				okay = false;
			}
			break;

		case CHANGE:
			scanf("%s %s %d %d %d", mWord, mRetWord, &dir[0], &dir[1], &dir[2]);
			changeWord(mWord, mRetWord, dir);
			break;

		default:
			okay = false;
		}
	}

	return okay;
}


int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}


struct room {
	string word;
	string substring[3];
} rooms[30001];

struct cmp {
	bool operator() (int a, int b) const {
		return rooms[a].word < rooms[b].word;
	}
};

int current;
int last_id;
unordered_map<string, int> room_map;
unordered_map<string, set<int, cmp>> dir_map[3];

void init()
{
	room_map.clear();
	dir_map[0].clear();
	dir_map[1].clear();
	dir_map[2].clear();
	last_id = 0;
	current = 0;
}

void add_dir_map(int id) {
	string cur = rooms[id].word;

	dir_map[0][cur.substr(0, 4)].insert(id);
	dir_map[0][cur.substr(0, 2)].insert(id);

	dir_map[1][cur.substr(4, 3)].insert(id);

	dir_map[2][cur.substr(7, 4)].insert(id);
	dir_map[2][cur.substr(9, 2)].insert(id);
}

void addRoom(int mID, char mWord[], int mDirLen[])
{
	last_id++;
	rooms[mID].word = mWord;
	rooms[mID].substring[0] = rooms[mID].word.substr(0, mDirLen[0]);
	rooms[mID].substring[1] = rooms[mID].word.substr(4, mDirLen[1]);
	rooms[mID].substring[2] = rooms[mID].word.substr(11-mDirLen[2], mDirLen[2]);

	room_map[mWord] = mID;

	add_dir_map(mID);
}



void setCurrent(char mWord[])
{
	current = room_map[mWord];
}

int moveDir(int mDir)
{
	//set<int, cmp> temp = dir_map[2-mDir].find(rooms[current].substring[mDir]);
	if(dir_map[2-mDir].find(rooms[current].substring[mDir]) == dir_map[2-mDir].end()) {
		return 0;
	}

	for(set<int, cmp>::iterator it = dir_map[2-mDir][rooms[current].substring[mDir]].begin(); it!=dir_map[2-mDir][rooms[current].substring[mDir]].end(); ++it) {
		if(*it != current) {
			current = *it;
			return current;
		}
	}

	return 0;
}

void changeWord(char mWord[], char mChgWord[], int mChgLen[])
{
	int id = room_map[mWord];
	
	
	dir_map[0][rooms[id].word.substr(0,2)].erase(id);
	dir_map[0][rooms[id].word.substr(0,4)].erase(id);
	dir_map[1][rooms[id].word.substr(4,3)].erase(id);
	dir_map[2][rooms[id].word.substr(9,2)].erase(id);
	dir_map[2][rooms[id].word.substr(7,4)].erase(id);

	room_map.erase(mWord);

	addRoom(id, mChgWord, mChgLen);
	last_id--;
}


