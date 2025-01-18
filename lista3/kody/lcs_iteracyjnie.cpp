#include <iostream>
using namespace std;

void print_solution(char** B, char* X, int i, int j) {
    if (i >0 && j> 0) {
        if (B[i][j] == '-') {
            print_solution(B,X,i-1, j-1);
            cout << X[i - 1];
        } else if (B[i][j] == '|') {
            print_solution(B,X,i-1,j);
        } else {
            print_solution(B,X,i,j- 1);
        }
    }
}

void lcs(char* X, char* Y, int** C, char** B, int m, int n) {
    

    for (int i = 0; i <= m; ++i) {
        C[i] =new int[n + 1];
        B[i] =new char[n + 1];
    }
    for (int i = 0; i <= m; ++i) {
        C[i][0] = 0;
    }
    for (int j = 0; j <= n; ++j) {
        C[0][j] = 0;
    }

    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n;++j) {
            if (X[i-1] == Y[j-1]) {
                C[i][j] = C[i-1][j-1] + 1;
                B[i][j] = '-';
            }else{
                if(C[i-1][j] >= C[i][j - 1]) {
                    C[i][j] = C[i - 1][j];
                    B[i][j] ='|';
                }else{
                    C[i][j] = C[i][j-1];
                    B[i][j]='<';
                }
            }
        }
    }

}

int main() {
    char X[] = {'A', 'G', 'G', 'T', 'A', 'B'};
    char Y[] = {'G', 'X', 'T', 'X', 'A', 'Y', 'B'};
    int m = 6;
    int n = 7;
    int** C = new int*[m+1];
    char** B = new char*[m+1];

    lcs(X, Y,C,B,m, n);
    cout << endl << C[m][n] << endl;
    print_solution(B, X, m, n);

    for (int i = 0; i <= m; ++i) {
        delete[] C[i];
        delete[] B[i];
    }
    delete[] C;
    delete[] B;

    return 0;
}
