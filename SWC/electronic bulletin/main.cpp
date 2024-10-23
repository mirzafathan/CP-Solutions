#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT				(100)
#define CMD_WRITE_MESSAGE		(200)
#define CMD_COMMENT_TO			(300)
#define CMD_ERASE				(400)
#define CMD_GET_BEST_MESSAGES	(500)
#define CMD_GET_BEST_USERS		(600)

#define MAXL	(10)	

extern void init();
extern int writeMessage(char mUser[], int mID, int mPoint);
extern int commentTo(char mUser[], int mID, int mTargetID, int mPoint);
extern int erase(int mID);
extern void getBestMessages(int mBestMessageList[]);
extern void getBestUsers(char mBestUserList[][MAXL + 1]);

static int mstrcmp(char a[], char b[])
{
	int idx = 0;
	while (a[idx] != '\0' && a[idx] == b[idx])
		++idx;
	return a[idx] - b[idx];
}

static bool run()
{
	int Q;
	int mID, mTargetID, mPoint;
	char mUser[MAXL + 1];
	char mBestUserList[5][MAXL + 1];
	int mBestMessageList[5];

	int ret = -1, ans;

	scanf("%d", &Q);

	bool okay = false;

	for (int q = 0; q < Q; ++q)
	{
		int cmd;
		scanf("%d", &cmd);
		switch(cmd)
		{
		case CMD_INIT:
			init();
			okay = true;
			break;
		case CMD_WRITE_MESSAGE:
			scanf("%s %d %d", mUser, &mID, &mPoint);
			ret = writeMessage(mUser, mID, mPoint);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		case CMD_COMMENT_TO:
			scanf("%s %d %d %d", mUser, &mID, &mTargetID, &mPoint);
			ret = commentTo(mUser, mID, mTargetID, mPoint);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		case CMD_ERASE:
			scanf("%d", &mID);
			ret = erase(mID);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		case CMD_GET_BEST_MESSAGES:
			getBestMessages(mBestMessageList);
			for (int i = 0; i < 5; ++i)
			{
				scanf("%d", &ans);
				if (mBestMessageList[i] != ans)
					okay = false;
			}
			break;
		case CMD_GET_BEST_USERS:
			getBestUsers(mBestUserList);
			for (int i = 0; i < 5; ++i)
			{
				scanf("%s", mUser);
				if (mstrcmp(mBestUserList[i], mUser) != 0)
					okay = false;
			}
			break;
		default:
			okay = false;
			break;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample.txt", "r", stdin);

	int TC, MARK;

	scanf("%d %d", &TC, &MARK);
	for (int tc = 1; tc <= TC; ++tc)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}