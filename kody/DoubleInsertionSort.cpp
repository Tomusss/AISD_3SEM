#include <iostream>
#include <random>

using namespace std;

int porownania = 0; 
int przypisania = 0;

void double_insertionSort(float A[], int n) {
    
    for (int i=1;i<n-1; i+=2) {
        float key1, key2;
        if (A[i] < A[i+1]) {
            porownania++;
            key1 = A[i];
            key2 = A[i+1];
            przypisania += 2;
        } else {
            porownania++;
            key1 = A[i+1];
            key2 = A[i];
            przypisania += 2;
        }
        
        // sortowanie mniejszego klucza
        int j = i-1;
        while (j >= 0 && A[j] > key1) {
            porownania+=2;
            A[j + 1] = A[j];
            przypisania++;
            j--;
        }
        porownania++;
        A[j + 1] = key1;
        przypisania++;
        
        // sortowanie większego klucza
        int j2 = i;
        while (j2 > j && A[j2] > key2) {
            porownania+=2;
            A[j2 + 1] = A[j2];
            przypisania++;
            j2--;
        }
        porownania+=2;
        A[j2 + 1] = key2;
        przypisania++;
    }
    
    // obsługa parzystej tablicy
    if (n % 2 == 0) {
        porownania++;
        float ost = A[n-1];
        przypisania++;
        int k = n-2;
        while (k >= 0 && A[k] > ost) {
            porownania+=2;
            A[k + 1] = A[k];
            k = k - 1;
            przypisania+=2;
        }
        porownania+=2;
        A[k + 1] = ost;
        przypisania++;
    }

}

void randArr(float A[], int n) {
    random_device rd;
    mt19937 e2(rd());
    uniform_real_distribution<> dist(-10000, 10000);

    for (int i = 0; i < n; i++) {
        A[i] = dist(e2);
    }
}

int main() {
    int n = 10;
    float A[10];
    randArr(A, n);
    
    cout << "przed sortowaniem: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << ' ';
    }
    cout << endl;
    
    double_insertionSort(A, n);
    
    cout << "po sortowaniu: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << ' ';
    }
    cout << endl;

    cout << "\nLiczba porównań: " << porownania << endl;
    cout << "Liczba przypisań: " << przypisania << endl;
}
