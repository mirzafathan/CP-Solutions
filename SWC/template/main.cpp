#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_N (3000)

void init(int, int[]);
void newLine(int, int[], int[]);
void changeLimitDistance(int);
int findCity(int, int[]);


#define CMD_INIT (100)
#define CMD_ADD  (200)
#define CMD_FIND (300)

static int N;
static int M;
static int mDownTown[3];
static int city_id_list[MAX_N + 5];
static int distance_list[MAX_N + 5];
static int downtown_list[4];


static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ret, ans;
    bool ok = false;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);

        if (query == CMD_INIT)
        {
            scanf("%d", &N);
            for (int i = 0; i < 3; i++)
            {
                scanf("%d", &mDownTown[i]);
            }
            init(N, mDownTown);
            ok = true;
        }
        else if (query == CMD_ADD)
        {
            int mLimitDistance;

            scanf("%d%d", &M, &mLimitDistance);
            for (int i = 0; i < M; i++)
            {
                scanf("%d", city_id_list + i);
            }
            for (int i = 0; i < M - 1; i++)
            {
                scanf("%d", distance_list + i);
            }
            newLine(M, city_id_list, distance_list);
            changeLimitDistance(mLimitDistance);
        }
        else if (query == CMD_FIND)
        {
            int mOpt;
            scanf("%d", &mOpt);

            for (int i = 0; i < mOpt; i++)
            {
                scanf("%d", downtown_list + i);
            }
            ret = findCity(mOpt, downtown_list);
            scanf("%d", &ans);

            if (ans != ret)
            {
                ok = false;
            }
        }
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
//    freopen("sample_input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}
