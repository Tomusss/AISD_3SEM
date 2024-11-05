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


void randArr(float A[], int n)
{
    random_device rd;

    mt19937 e2(rd());
    uniform_real_distribution<> dist(-10000, 10000);

    for (int i = 0; i < n; i++) {
        A[i] = dist(e2);
    }
}

int main(){
    int n = 10;
    float A[10];
    randArr(A,n);
    cout << "przed sortowaniem: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
    
    insertionSort(A,n);
    
    cout << "po sortowaniu: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }

} 