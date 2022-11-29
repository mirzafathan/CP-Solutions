#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bullsAndCows' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. STRING X
 *  3. STRING S
 */

string bullsAndCows(int N, string X, string S) {
    // Write your code here
    vector<bool> exist(10, false);
    int bull = 0;
    int cow = 0;
    for(int i=0; i<N; i++) {
        int digit = (int) X[i];
        exist[digit] = 1;
    }
    
    for(int i=0; i<N; i++) {
        int digit = (int) S[i];
        if(S[i] == X[i]) bull++;
        else if(exist[digit]) cow++;
    }
    
    return to_string(bull) + 'A' + to_string(cow) + 'B';
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int N = stoi(first_multiple_input[0]);

        string X = first_multiple_input[1];

        string S = first_multiple_input[2];

        string result = bullsAndCows(N, X, S);

        fout << result << "\n";
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
