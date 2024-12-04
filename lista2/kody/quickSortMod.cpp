#include <iostream>
#include <random>

using namespace std;

pair<int,int> partitionMod(float A[], int poczatek, int koniec){
    if (A[poczatek] > A[koniec]) {
        float temp = A[poczatek];
        A[poczatek] = A[koniec];
        A[koniec] = temp;
    }
    float x = A[poczatek];
    float x2 = A[koniec];
    
    int i = poczatek+1;
    int j = poczatek+1;
    int k = koniec-1;

    while (j <= k) {
        if(A[j] < x){
            float temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
        } else if(A[j] > x2){
            float temp = A[k];
            A[k] = A[j];
            A[j] = temp;
            k--;
            j--;
        }
        j++;
    }

    float temp = A[poczatek];
    A[poczatek] = A[i-1];
    A[i-1] = temp;

    temp = A[koniec];
    A[koniec] = A[k+1];
    A[k+1] = temp;

    return {i-1,k+1};
    }

void quickSortMod(float A[],int p, int k){
    if(p < k){
        auto[s1,s2] = partitionMod(A,p,k);
        quickSortMod(A,p,s1-1);
        quickSortMod(A,s1+1,s2-1);
        quickSortMod(A,s2+1,k);
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
    
    quickSortMod(A,0,n-1);
    
    cout << "po sortowaniu: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }
}