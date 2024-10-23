#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int C, int N, int mX[], int mY[]);
extern int add(int mStudent, int mX, int mY);
extern int remove(int mStudent);
extern int status(int mSchool);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_REMOVE 3
#define CMD_STATUS 4

static bool run() {
	int q;
	scanf("%d", &q);

	int n, mstudent, mschool, mx, my;
	int mcapa, mxArr[10], myArr[10];
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				scanf("%d %d", &mcapa, &n);
				for (int j = 0; j < n; ++j) {
					scanf("%d %d", &mxArr[j], &myArr[j]);
				}
				init(mcapa, n, mxArr, myArr);
				okay = true;
				break;
			case CMD_ADD:
				scanf("%d %d %d %d", &mstudent, &mx, &my, &ans);
				ret = add(mstudent, mx, my);
				if (ans != ret)
					okay = false;
				break;
			case CMD_REMOVE:
				scanf("%d %d", &mstudent, &ans);
				ret = remove(mstudent);
				if (ans != ret)
					okay = false;
				break;
			case CMD_STATUS:
				scanf("%d %d", &mschool, &ans);
				ret = status(mschool);
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

void init(int C, int N, int mX[], int mY[]) {
	return;
}

int add(int mStudent, int mX, int mY) {
	return 0;
}

int remove(int mStudent) {
	return 0;
}

int status(int mSchool) {
	return 0;
}