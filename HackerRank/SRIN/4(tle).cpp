#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<vector<int> > Key;
void setup_matrix(int n) {
    for(int i=0;i <n; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++) {
            temp.push_back(-1);
        }
        Key.push_back(temp);
    }
}
/*
 * Complete the 'setup_kunci' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER L
 *  3. STRING_ARRAY langkah
 */
/*
voir rotator(vector<>) {
    for (int i=0;i<n/2;i++) { 
        for (int j=i;j<n-i-1;j++) { 
            int temp=arr[i][j]; 
            arr[i][j]=arr[n-1-j][i]; 
            arr[n-1-j][i]=arr[n-1-i][n-1-j]; 
            arr[n-1-i][n-1-j]=arr[j][n-1-i]; 
            arr[j][n-1-i]=temp; 
        } 
    }
}*/
void setup_kunci(int N, int L, vector<string> langkah) {
    int x;
    int y;
    for(int i=0; i<L; i++) {
      //  cout << langkah[i] << endl;
       // cout << langkah[i][0] <<"a"<<  langkah[i][1] << "b" << endl;
        string a = "";
        string b = "";
        bool before = true;
        for(int j=0; j<langkah[i].size(); j++) {
            if(langkah[i][j] == ' ') {
                before = false;
                continue;
            }
            if(before) {
                a = a+langkah[i][j];
            } else {
                b = b+langkah[i][j];
            }
        }
        x = stoi(a);
        y = stoi(b);
        
        Key[x][y] = i+1;
    }
    
}

bool isEqual(vector<vector<int> > a, vector<vector<int> > b) {
    int M = a.size();
    
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            if(a[i][j]!=b[i][j]) return false;
        }
    }
    
    return true;
    
}

/*
 * Complete the 'otentikasi' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER L
 *  3. STRING_ARRAY langkah
 */

string otentikasi(int N, int L, vector<string> langkah) {
    vector<vector<int> > arr;
    for(int i=0;i <N; i++) {
        vector<int> temp;
        for(int j=0; j<N; j++) {
            temp.push_back(-1);
        }
        arr.push_back(temp);
    }
    int x;
    int y;
    for(int i=0; i<L; i++) {
      //  cout << langkah[i] << endl;
       // cout << langkah[i][0] <<"a"<<  langkah[i][1] << "b" << endl;
        string a = "";
        string b = "";
        bool before = true;
        for(int j=0; j<langkah[i].size(); j++) {
            if(langkah[i][j] == ' ') {
                before = false;
                continue;
            }
            if(before) {
                a = a+langkah[i][j];
            } else {
                b = b+langkah[i][j];
            }
        }
        int prevx;
        int prevy;
        if(i>0) {
            prevx = x;
            prevy = y;
        }
        x = stoi(a);
        y = stoi(b);
        
        if(i>0) {
            if((abs(x-prevx)>1) || (abs(y-prevy)>1)) return "salah";
        }

        
        arr[x][y] = i+1;
    }
    
    cout << "arr" << endl;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }
    if(isEqual(arr, Key)) return "berhasil";
    
    for (int i=0;i<N/2;i++) { 
        for (int j=i;j<N-i-1;j++) { 
            int temp=arr[i][j]; 
            arr[i][j]=arr[N-1-j][i]; 
            arr[N-1-j][i]=arr[N-1-i][N-1-j]; 
            arr[N-1-i][N-1-j]=arr[j][N-1-i]; 
            arr[j][N-1-i]=temp; 
        } 
    }
    if(isEqual(arr, Key)) return "berhasil";
    
    for (int i=0;i<N/2;i++) { 
        for (int j=i;j<N-i-1;j++) { 
            int temp=arr[i][j]; 
            arr[i][j]=arr[N-1-j][i]; 
            arr[N-1-j][i]=arr[N-1-i][N-1-j]; 
            arr[N-1-i][N-1-j]=arr[j][N-1-i]; 
            arr[j][N-1-i]=temp; 
        } 
    }
    if(isEqual(arr, Key)) return "berhasil";
    
    for (int i=0;i<N/2;i++) { 
        for (int j=i;j<N-i-1;j++) { 
            int temp=arr[i][j]; 
            arr[i][j]=arr[N-1-j][i]; 
            arr[N-1-j][i]=arr[N-1-i][N-1-j]; 
            arr[N-1-i][N-1-j]=arr[j][N-1-i]; 
            arr[j][N-1-i]=temp; 
        } 
    }
    if(isEqual(arr, Key)) return "berhasil";

    return "gagal";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));
    setup_matrix(N);
 
    
    string L_temp;
    getline(cin, L_temp);

    int L = stoi(ltrim(rtrim(L_temp)));

    vector<string> pola_kunci(L);

    for (int i = 0; i < L; i++) {
        string pola_kunci_item;
        getline(cin, pola_kunci_item);

        pola_kunci[i] = pola_kunci_item;
    }
    
    for (int i = 0; i < L; i++) {
        cout << pola_kunci[i] << endl;
    }

    setup_kunci(N, L, pola_kunci);
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << Key[i][j] << " ";
        } cout << endl;
    }

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {

        vector<string> kunci_masuk(L);

        for (int i = 0; i < L; i++) {
            string kunci_masuk_item;
            getline(cin, kunci_masuk_item);

            kunci_masuk[i] = kunci_masuk_item;
        }

        string status = otentikasi(N, L, kunci_masuk);

        fout << status << "\n";
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
