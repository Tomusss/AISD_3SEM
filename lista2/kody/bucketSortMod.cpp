#include <iostream>
#include <random>

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
float maxwart(float A[], int n) {
    float max = A[0];
    for (int i =1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}
float minwart(float A[], int n) {
    float min = A[0];
    for (int i =1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
        }
    }
    return min;
}

void bucketSort(float A[], int n){
    float** B = new float*[n];
    float min = minwart(A,n);
    float max = maxwart(A,n);
    float przedzial = max-min;

    for(int j=0;j<n;j++){
        B[j] = new float[n];
    }

    int* dlugosci = new int[n]();
    for(int i=0;i<n;i++){
        int b = n*(A[i]-min)/przedzial;
        if(b == n){ 
            b = n-1;
        }
        B[b][dlugosci[b]] = A[i];
        dlugosci[b]++;
    }

    for(int i=0;i<n;i++){
        insertionSort(B[i],dlugosci[i]);
    }

    int i = 0;
    for(int j=0;j<n;j++){
        for(int k =0; k<dlugosci[j]; k++){
            A[i] = B[j][k];
            i++;
        }
    }

    delete[] dlugosci;
    for (int i = 0; i < n; i++) {
        delete[] B[i];
    }
    delete[] B;
}



void randArr(float A[], int n)
{
    random_device rd;

    mt19937 e2(rd());
    uniform_real_distribution<> dist(-1000, 1000);

    for (int i = 0; i < n; i++) {
        A[i] = dist(e2);
    }
}

int main(){
    int n = 10;
    float A[n];
    randArr(A,n);
    cout << "przed sortowaniem: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
    
    bucketSort(A,n);
    
    cout << "po sortowaniu: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }
} 