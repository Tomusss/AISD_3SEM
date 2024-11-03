#include <iostream>

using namespace std; 

void insertionSort(int A[] ,int n){
    for(int i = 1;i < n;i++){
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j = j-1; 
        }
        A[j+1] = key;
    }
}

void double_insertionSort(int A[], int n) {
    for (int i = 1; i < n; i += 2) {
        int key1, key2;
        if (A[i] < A[i+1]){
            key1 = A[i];
            key2 = A[i + 1];
        } else {
            key1 = A[i + 1];
            key2 = A[i];
        }
        
        //sortowanie mniejszego klucza
        int j = i - 1;
        while (j >= 0 && A[j] > key1) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key1;

        //sortowanie wiekszego klucza
        int j2 = i;
        while (j2 >= j && A[j2] > key2) {
            A[j2 + 1] = A[j2];
            j2--;
        }
        A[j2 + 1] = key2;
    }
}
int main(){
    int A[] = {5, 3, 2, 6,1};
    int n = 5;

    double_insertionSort(A,n);

    for(int i = 0; i<n; i++){
        cout << A[i];
    }

}