#include <iostream>

using namespace std;

//ustawiamy inf jako max wartosc dla int 
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
    for (i=0; i < n1; i++){
        L[i] = A[i+p];
    }
    for (j=0; j < n2; j++){
        S[j] = A[j+ s1 + 1];
    }
    for (h=0; h < n3; h++){
        R[h] = A[h + s2 +1];
    }

    i = 0;
    j = 0;
    h = 0;

    for (int l = p; l <= k; l++) {
        if (L[i] <= S[j] && L[i] <= R[h]) {
            A[l] = L[i];
            i++;
        } else if (S[j] <= L[i] && S[j] <= R[h]) {
            A[l] = S[j];
            j++;
        } else{
            A[l] = R[h];
            h++;
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
        tripleMergeSort(A,p,s1);
        tripleMergeSort(A,s1+1,s2);
        tripleMergeSort(A,s2+1,k);

        tripleMerge(A,p,s1,s2,k);
    }
}

void mergeSort(float A[], int p, int k){
    if (p < k){
        int s = (k+p)/2;
        mergeSort(A,p,s);
        mergeSort(A,s+1,k);
        
        merge(A,p,s,k);
    }

}

int main(){
    float A[] = {13, 11, -13,22,-1,66, 5, 6,6.66, 7};
    int n = 10 ;

    tripleMergeSort(A,0,n-1);

    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }

} 