#include <iostream>
using namespace std;


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

int main() {
    int s[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int f[] = {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int n = 11;
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
