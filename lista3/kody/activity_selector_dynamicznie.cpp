#include <iostream>

using namespace std;
int INFINITY = 200000;
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
    cout << endl;
    printActivities(c,act, 0, n);
    

    for (int i=0; i<n+2;i++) {
        delete[] c[i];
        delete[] act[i];
    }
    delete[] c;
    delete[] act;
}

int main() {
    int s[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12,INFINITY};
    int f[] = {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,INFINITY};
    int n=12;
    activity_selector_dynamicznie(s, f, n);

    return 0;
}
