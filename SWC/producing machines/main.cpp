#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N, int mId[], int mTime[]);
extern int add(int mId, int mTime);
extern int remove(int K);
extern int produce(int M);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_REMOVE 3
#define CMD_PRODUCE 4

static bool run() {
	int q;
	scanf("%d", &q);

	int n, mid, mtime, k, m;
	int midArr[100], mtimeArr[100];
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				scanf("%d", &n);
				for (int j = 0; j < n; ++j) {
					scanf("%d %d", &midArr[j], &mtimeArr[j]);
				}
				init(n, midArr, mtimeArr);
				okay = true;
				break;
			case CMD_ADD:
				scanf("%d %d %d", &mid, &mtime, &ans);
				ret = add(mid, mtime);
				if (ans != ret)
					okay = false;
				break;
			case CMD_REMOVE:
				scanf("%d %d", &k, &ans);
				ret = remove(k);
				if (ans != ret)
					okay = false;
				break;
			case CMD_PRODUCE:
				scanf("%d %d", &m, &ans);
				ret = produce(m);
				if (ans != ret)
					okay = false;
				break;
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}