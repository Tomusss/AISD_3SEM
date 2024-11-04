#include <iostream>

using namespace std; 

void insertionSort(float A[] ,int n){
    for(int i = 1;i < n;i++){
        float key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j = j-1; 
        }
        A[j+1] = key;
    }
}

void double_insertionSort(float A[], int n) {
    for (int i=1;i<n-1; i+=2) {
        float key1,key2;
        if (A[i] < A[i+1]){
            key1 = A[i];
            key2 = A[i+1];
        } else {
            key1 = A[i+1];
            key2 = A[i];
        }
        
        //sortowanie mniejszego klucza
        int j = i-1;
        while (j>=0 && A[j]>key1) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key1;

        //sortowanie wiekszego klucza
        int j2=i;
        while (j2 >j && A[j2]>key2) {
            A[j2 + 1] = A[j2];
            j2--;
        }
        A[j2 + 1] = key2;
    }
    if (n%2 == 0){
        float ost = A[n-1];
        int k = n-2;
        while(k >= 0 && A[k] > ost){
            A[k+1] = A[k];
            k = k-1; 
        }
        A[k+1] = ost;

    }
}
int main(){
    float A[] = {5.23,-1,5.22,3, 6,1,-1};
    int n = 7;

    double_insertionSort(A,n);
    //insertionSort(A,n);

    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }

}