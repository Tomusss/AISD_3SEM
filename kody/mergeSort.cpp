#include <iostream>
#include <random>

using namespace std;

//ustawiamy duza wartosc jako inf
const float inf = 2147483647;

void merge(float A[], int p, int s, int k){
    int n1 = s - p + 1;
    int n2 = k - s;

    float* L = new float[n1 + 1]; 
    float* R = new float[n2 + 1];

    L[n1] = inf;
    R[n2] = inf;
    
    int i = 0;
    int j = 0;

    for (i;i<n1;i++){
        L[i] = A[i+p];
    }
    for (j;j<n2;j++){
        R[j] = A[j+s+1];
    }

    i = 0;
    j = 0;

    for (int l = p; l <= k; l++) {
        if (L[i] <= R[j]) {
            A[l] = L[i];
            i++;
        } else {
            A[l] = R[j];
            j++;
        }
    }

    delete[] L;
    delete[] R;

}



void mergeSort(float A[], int p, int k){
    if (p < k){
        int s = (k+p)/2;
        mergeSort(A,p,s);
        mergeSort(A,s+1,k);
        
        merge(A,p,s,k);
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
    
    mergeSort(A,0,n-1);
    
    cout << "po sortowaniu: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }

} 