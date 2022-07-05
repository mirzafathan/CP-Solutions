#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'hitung' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY P as parameter.
 */

int hitung(vector<int> P) {
    // Write your code here
    vector<int> count(51, 0);
    int N = P.size();
    for(int i=0; i<N; i++) {
        count[P[i]]++;
    }
    
    int ans = 0;
    for(int i=0; i<51; i++) {
        ans += (count[i]/2);
    }
    
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    vector<int> P(N);

    for (int i = 0; i < N; i++) {
        string P_item_temp;
        getline(cin, P_item_temp);

        int P_item = stoi(ltrim(rtrim(P_item_temp)));

        P[i] = P_item;
    }

    int result = hitung(P);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
