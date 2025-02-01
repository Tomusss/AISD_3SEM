#include <iostream>
using namespace std;

int INFINITY = 20123123;
void activity_selector_iteracyjnie(int s[], int f[], int n, int zajecia[], int& idx) {
    zajecia[idx++] = n;
    int k = n;
    
    for (int m=n; m>0; m--) {
        if (s[k]>=f[m]) {
            zajecia[idx++] = m;
            k = m;
        }
    }
}

int main() {
    int s[] = {0, 0, 1, 3, 5, 5, 6, 8, 8, 12, INFINITY}; 
    int f[] = {0, 6, 4, 5, 7, 9, 10, 11, 12, 14, INFINITY}; 
    int n = 9;
    int zajecia[n];
    int idx = 0;
    
    activity_selector_iteracyjnie(s, f, n, zajecia, idx);

    cout << "Optymalny zestaw zajęć: ";
    for (int i = 0; i < idx; i++) {
        cout << zajecia[i] << " ";
    }
    cout << endl;

    return 0;
}
