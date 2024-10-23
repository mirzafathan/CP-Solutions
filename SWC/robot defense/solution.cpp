#define MAX_N 20
#include <iostream>
#include <vector>

using namespace std;
struct sequence {
    int row;
    int col;
    int isHorizontal;
}

vector<int> hash2;
vector<int> hash3;
vector<int> hash4;
vector<int> hash5;

vector<sequence> hash_matrix[6][100];

int visit[MAX_N][MAX_N];

void init(int N, int mMap[MAX_N][MAX_N])
{
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int hash;
            if(j > 0) {
                hash = mMap[i][j] - mMap[i][j-1] + 5;
                hash2.push_back(hash);
                hash_matrix[2][hash].push_back
            }
            if(j > 1) {

            }
            if(j > 2) {

            }
            if(j > 3) {

            }
            if(j > 4) {
                
            }
        }
    }

}

int numberOfCandidate(int M, int mStructure[])
{
    return 0;
}

int maxBlockedRobots(int M, int mStructure[], int mDir)
{
    return 0;
}