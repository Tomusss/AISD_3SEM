#include <iostream>
#include <random>

using namespace std;

int partition(float A[], int poczatek, int koniec){
    float x = A[koniec];
    int i = poczatek - 1;
    for(int j=poczatek; j<koniec ;j++){
        if(A[j]<= x){
            i++;
            float temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    float temp = A[i+1];
    A[i+1] = A[koniec];
    A[koniec] = temp;
    return i+1;
}

void quickSort(float A[],int p, int k){
    if(p < k){
        int s = partition(A,p-1,k-1);
        quickSort(A,p,s-1);
        quickSort(A,s+1,k);
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
    float A[n];
    randArr(A,n);

    cout << "przed sortowaniem: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
    
    quickSort(A,1,n);
    
    cout << "po sortowaniu: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }
}