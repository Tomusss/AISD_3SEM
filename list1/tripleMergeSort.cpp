#include <iostream>
#include <random>

using namespace std;

//ustawiamy duza wartosc jako inf
const float inf = 2147483647;

int porownania = 0; 
int przypisania = 0;

void tripleMerge(float A[], int p, int s1, int s2, int k){
    int n1 = s1 - p + 1;
    int n2 = s2 - s1;
    int n3 = k - s2;

    float* L = new float[n1 + 1]; 
    float* S = new float[n2 + 1];
    float* R = new float[n3 + 1];

    L[n1] = inf;
    S[n2] = inf;
    R[n3] = inf;

    int i,j,h;

    przypisania += 12;
    for (i=0; i < n1; i++){
        L[i] = A[i+p];
        przypisania++;
    }
    for (j=0; j < n2; j++){
        S[j] = A[j+ s1 + 1];
        przypisania++;
    }
    for (h=0; h < n3; h++){
        R[h] = A[h + s2 +1];
        przypisania++;
    }

    i = 0;
    j = 0;
    h = 0;
    przypisania+=3;

    for (int l = p; l <= k; l++) {
        if (L[i] <= S[j] && L[i] <= R[h]) {
            A[l] = L[i];
            i++;
            przypisania+=2;
            porownania++;
        } else if (S[j] <= L[i] && S[j] <= R[h]) {
            A[l] = S[j];
            j++;
            przypisania+=2;
            porownania+=2;
        } else{
            A[l] = R[h];
            h++;
            przypisania+=2;
            porownania+=2;
        }
        
    }
    delete[] L;
    delete[] S;
    delete[] R;
}

void tripleMergeSort(float A[], int p, int k){
    if (p < k){
        int s1 = p  + (k-p)/3;
        int s2 = p + 2*(k-p)/3;
        przypisania+=2;
        tripleMergeSort(A,p,s1);
        tripleMergeSort(A,s1+1,s2);
        tripleMergeSort(A,s2+1,k);

        tripleMerge(A,p,s1,s2,k);
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
    
    tripleMergeSort(A,0,n-1);
    
    cout << "po sortowaniu: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }
    cout << "\nLiczba porównań: " << porownania << endl;
    cout << "Liczba przypisań: " << przypisania << endl;
    

} 