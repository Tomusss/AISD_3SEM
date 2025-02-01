#include <iostream>
using namespace std;

const int INFINITY = 20123123;

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

int main() {
    int s[] = {0, 0, 1, 3, 5, 5, 6, 8, 8, 12, INFINITY}; 
    int f[] = {0, 6, 4, 5, 7, 9, 10, 11, 12, 14, INFINITY}; 
    int n = 9;

    int zajecia[n];
    int idx = 0;

    activity_selector_rekurencyjnie_mod(s, f, n + 1, n, zajecia, idx);

    cout << "Rekurencyjnie: ";
    for (int i = 0; i < idx; ++i) {
        cout << zajecia[i] << " ";
    }
    cout << endl;

    return 0;
}
