#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int INF = 2147483647;

int lcs_rekurencyjnie(char X[], char Y[], int** R,char** S, int m, int n) 
{ 
	if (m==0 or n==0){ 
		return 0;
    } 
    if (R[m][n] != -1) {
        return R[m][n];
    }
	if (X[m- 1] == Y[n-1]) {
		R[m][n] =  1 + lcs_rekurencyjnie(X,Y,R,S,m - 1,n - 1);
        S[m][n] = '-'; 
    }else{
        int dol = lcs_rekurencyjnie(X,Y,R,S,m-1, n);
        int lewo = lcs_rekurencyjnie(X,Y,R,S,m, n-1);
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
void lcs_iteracyjnie(char* X, char* Y, int** C, char** B, int m, int n) {
    

    
    

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
float memorized_cut_rod(float P[], float R[],int S[],int n){
    if (R[n-1]>=0){
        return R[n-1];
    }
    float q;
    if (n==0){
        q = 0;
    }else{
        q = -INF;
        for(int i=1;i<=n;i++){
            float aktualny = P[i-1] + memorized_cut_rod(P,R,S,n-i);
            if(aktualny>q){
                S[n-1]=i;
                q = aktualny;
            }
            
        }
    }
    R[n-1] = q;
    return q;
}

float maximum(float a, float b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

float cut_rod(float P[],int n){
    if (n == 0){
        return 0;
    }
    float q = -INF;
    for(int i=1;i<=n;i++){
        q = maximum(q,P[i-1] + cut_rod(P, n-i));
    }
    return q;
}
void cut_rod_iteracyjnie(float P[],float R[],int S[], int n){
    R[0] = 0;
    for(int j = 1;j<=n;j++){
        float q = -INF;
        for (int i = 1;i<=j;i++){
            if(q<P[i-1]+ R[j-i]){
                q = P[i-1] + R[j-i];
                S[j] = i;
            }
        }
        R[j]=q;
    }
}
void print_solution(int S[], float R[],int n){
    while(n>0){
        cout<<S[n]<<", ";
        n-=S[n];
    }
}
void activity_selector_rekurencyjnie(int s[], int f[], int k, int n,int zajecia[], int& idx) {
    int m = k + 1;
    while (m <= n && s[m] < f[k]) {
        m++;
    }
    if (m <= n) {
        zajecia[idx++] = m;
        activity_selector_rekurencyjnie(s, f, m, n, zajecia, idx);
    }
}
void activity_selector_rekurencyjnie_mod(int s[], int f[], int k, int start, int zajecia[], int& idx) {
    int m = start;
    while (m>=1 && f[m]>s[k]) {
        m--;
    }

    if (m>=1) {
        zajecia[idx++]=m;
        activity_selector_rekurencyjnie_mod(s,f,m,m-1, zajecia,idx);
        
    }
}

void activity_selector_iteracyjnie(int s[], int f[], int n, int zajecia[], int& idx) {
    zajecia[idx++] = 1;
    int k = 1;
    
    for (int m=2; m<=n; m++) {
        if (s[m]>=f[k]) {
            zajecia[idx++] = m;
            k = m;
        }
    }
}
void activity_selector_iteracyjnie_mod(int s[], int f[], int n, int zajecia[], int& idx) {
    zajecia[idx++] = n;
    int k = n;
    
    for (int m=n; m>0; m--) {
        if (s[k]>=f[m]) {
            zajecia[idx++] = m;
            k = m;
        }
    }
}

void printActivities(int** c,int** act, int i, int j) {
    if (c[i][j]>0) {
        int k = act[i][j];
        cout << k << " ";
        printActivities(c,act, i, k);
        printActivities(c,act, k, j);
    }
}

void activity_selector_dynamicznie(int s[], int f[], int n) {
    int** c = new int*[n+2];
    int** act = new int*[n+2];

    for (int i=0; i<n+2;i++) {
        c[i] = new int[n+2]();
        act[i] = new int[n+2]();
    }

    for(int i=0;i<=n;i++){
        c[i][i] = 0;
        c[i][i+1] = 0;
    }
    c[n+1][n+1] = 0;

    for (int l=2; l <= n+1; l++) {
        for (int i=0; i<= n-l+1;i++) {
            int j = i + l;
            c[i][j] = 0;
            int k = j-1;
            
            while (f[i] < f[k]) {
                if (f[i] <= s[k] && f[k] <= s[j] && c[i][k]+c[k][j]+1> c[i][j]) {
                    c[i][j] = c[i][k]+c[k][j]+1;
                    act[i][j] = k;
                }
                k--;
            }
        }
    }
    //cout << endl;
    //printActivities(c,act, 0, n);
    

    for (int i=0; i<n+2;i++) {
        delete[] c[i];
        delete[] act[i];
    }
    delete[] c;
    delete[] act;
}

void random_string(char* str, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        str[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    str[length] = '\0';
}

void random_prices(float* prices, int n, int max_price = 100) {
    for (int i = 0; i < n; i++) {
        prices[i] = rand() % max_price + 1;
    }
}

void generuj_dane(int start[], int finish[],int i) {
    srand(time(0));
    
    for (int j = 1; j <= i; j++) {
        finish[j] = rand() % 10 + 1;
    }
    
    sort(finish + 1, finish + i + 1);

    for (int j = 1; j <= i; j++) {
        if (finish[j] > 1) {
            start[j] = rand() % (finish[j] - 1) + 1;
        } else {
            start[j] = 1;
        }
    }
    
    start[0] = 0;
    finish[0] = 0;
    start[i+1] = INF;
    finish[i+1] = INF;
}

