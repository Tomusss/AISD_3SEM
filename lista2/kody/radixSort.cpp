#include <iostream>
#include <random>

using namespace std;

void coutingSort(int A[], int n, int baza, int poz){
    int* C = new int[baza];
    int* B = new int[n]; 
    
    for (int i = 0; i < baza; i++) {
        C[i] = 0;}

    for(int i = 0; i <n;i++){
        int znak = (A[i] / poz) % (baza);
        C[znak]++;
    }
    for(int j=1;j<=baza;j++){
        C[j] += C[j-1];
    }

    for(int i = n-1;i>=0;i--){
        int znak = (A[i] / poz) % (baza);
        B[C[znak]-1]= A[i];
        C[znak]--;
    }

    for (int i=0; i<n; ++i) {
        A[i] = B[i];
    }
}

int maxwart(int* A, int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

void radixSort(int* A, int n, int baza) {
    int max = maxwart(A, n);
    for (int poz = 1; max / poz > 0; poz *= baza) {
        coutingSort(A, n, baza, poz);
    }
}

void randArr(int A[], int n) {
    random_device rd;
    mt19937 e2(rd());
    uniform_int_distribution<> dist(0, 1000);

    for (int i = 0; i < n; i++) {
        A[i] = dist(e2);
    }
}

int main() {

    int n = 5;
    int A[n];
    randArr(A,n);
    cout << "przed sortowaniem: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }

    radixSort(A,n,10);

    cout << "Po sortowaniu: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << ' ';
    }
    cout << endl;

    return 0;
}