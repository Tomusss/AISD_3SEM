#include <iostream>
using namespace std;



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

int main() {
    int s[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12}; 
    int f[] = {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int n = 11;
    int idx = 0;
    int zajecia[n]; 
    activity_selector_rekurencyjnie(s, f, 0, n,zajecia, idx);

    cout << "Optymalny zestaw zajęć: ";
    for (int i = 0; i < idx; i++) {
        cout << zajecia[i] << " ";
    }
    cout << endl;

    return 0;
}
