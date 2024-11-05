#include <iostream>
#include <random>

using namespace std;

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
    //obsluga parz tablic
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
    
    double_insertionSort(A,n);
    
    cout << "po sortowaniu: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }

} 