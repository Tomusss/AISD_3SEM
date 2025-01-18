#include <iostream>
using namespace std;

float maximum(float a, float b){
    if(a>b){
        return a;
    }else{
        return b;
    }  
}
int lcs(char X[], char Y[], int** R,char** S, int m, int n) 
{ 
	if (m==0 or n==0){ 
		return 0;
    } 
    if (R[m][n] != -1) {
        return R[m][n];
    }
	if (X[m- 1] == Y[n-1]) {
		R[m][n] =  1 + lcs(X,Y,R,S,m - 1,n - 1);
        S[m][n] = '-'; 
    }else{
        int dol = lcs(X,Y,R,S,m-1, n);
        int lewo = lcs(X,Y,R,S,m, n-1);
        if(dol>=lewo){
            R[m][n] = dol;
            S[m][n] = '|';
        }else{
            R[m][n] = lewo;
            S[m][n] = '<';
        }
    }
    return R[m][n];
    
}
void print_lcs(char X[], char** S, int m, int n){
    if(m==0 or n==0){
        return;
    }

    if (S[m][n] == '-') {
        print_lcs(X,S, m-1, n-1);
        cout << X[m-1];
    } else if (S[m][n]=='|') {
        print_lcs(X,S, m-1,n);
    } else {
        print_lcs(X,S,m, n-1);
    }
}



int main() 
{ 
	char x[] = {'A','G','G','T','A','B'}; 
	char y[] = {'G','X','T','X','A','Y','B'}; 
	int m = 6; 
	int n = 7; 
    char** s = new char*[m + 1];

    int** r = new int*[m + 1];
    for (int i=0; i<=m; ++i) {
        r[i] = new int[n+1];
        s[i] = new char[n+1];
        for (int j=0; j<=n; ++j) {
            r[i][j]= -1;
            s[i][j] = ' ';
        
        }
    }

	cout <<endl<< lcs(x, y,r,s, m, n)<<endl;; 
    print_lcs(x,s,m,n);
    for (int i=0; i<=m;++i) {
        delete[] s[i];
        delete[] r[i];
    }
    delete[] r;
    delete[] s;

	return 0; 
} 
