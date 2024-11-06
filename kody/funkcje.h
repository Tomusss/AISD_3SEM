#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

int przypisania = 0;
int porownania = 0;
const float inf = 2147483647;


void randArr(float A[], int n)
{
    random_device rd;

    mt19937 e2(rd());
    uniform_real_distribution<> dist(-10000, 10000);

    for (int i = 0; i < n; i++) {
        A[i] = dist(e2);
    }
}


void insertionSort(float A[] ,int n){
    for(int i = 1;i < n;i++){
        float key = A[i];
        przypisania++;
        int j = i-1;
        while(j >= 0 && A[j] > key){
            porownania += 2;
            A[j+1] = A[j];
            j = j-1;
            przypisania+=2 ;
        }
        A[j+1] = key;
    }
}

void double_insertionSort(float A[], int n) {
    
    for (int i=1;i<n-1; i+=2) {
        float key1, key2;
        if (A[i] < A[i+1]) {
            porownania++;
            key1 = A[i];
            key2 = A[i+1];
            przypisania += 2;
        } else {
            porownania++;
            key1 = A[i+1];
            key2 = A[i];
            przypisania += 2;
        }
        
        // sortowanie mniejszego klucza
        int j = i-1;
        while (j >= 0 && A[j] > key1) {
            porownania+=2;
            A[j + 1] = A[j];
            przypisania++;
            j--;
        }
        porownania++;
        A[j + 1] = key1;
        przypisania++;
        
        // sortowanie większego klucza
        int j2 = i;
        while (j2 > j && A[j2] > key2) {
            porownania+=2;
            A[j2 + 1] = A[j2];
            przypisania++;
            j2--;
        }
        porownania+=2;
        A[j2 + 1] = key2;
        przypisania++;
    }
    
    // obsługa parzystej tablicy
    if (n % 2 == 0) {
        porownania++;
        float ost = A[n-1];
        przypisania++;
        int k = n-2;
        while (k >= 0 && A[k] > ost) {
            porownania+=2;
            A[k + 1] = A[k];
            k = k - 1;
            przypisania+=2;
        }
        porownania+=2;
        A[k + 1] = ost;
        przypisania++;
    }

}

void merge(float A[], int p, int s, int k){
    int n1 = s - p + 1;
    int n2 = k - s;

    float* L = new float[n1 + 1]; 
    float* R = new float[n2 + 1];

    L[n1] = inf;
    R[n2] = inf;
    
    int i = 0;
    int j = 0;

    przypisania += 8;

    for (i;i<n1;i++){
        L[i] = A[i+p];
        przypisania++;
    }
    for (j;j<n2;j++){
        R[j] = A[j+s+1];
        przypisania++;
    }

    i = 0;
    j = 0;
    przypisania+=2;

    for (int l = p; l <= k; l++) {
        if (L[i] <= R[j]) {
            A[l] = L[i];
            i++;
            przypisania+=2;
        } else {
            A[l] = R[j];
            j++;
            przypisania+=2;
        }
        porownania++;
    }

    delete[] L;
    delete[] R;

}



void mergeSort(float A[], int p, int k){
    if (p < k){
        porownania++;
        int s = (k+p)/2;
        przypisania++;
        mergeSort(A,p,s);
        mergeSort(A,s+1,k);
        
        merge(A,p,s,k);
    }

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

int left(int i){
    return 2 * i + 1;
    
}
int right(int i){
    return 2 * i + 2;
}

void heapify(float A[], int n, int i){
    int largest;
    int l = left(i);
    int r = right(i);
    przypisania += 3;
    
    if (l < n && A[l] > A[i]){
        largest = l;
    } else {
        largest = i;
    }
    porownania+=2;
    przypisania++;

    if (r < n && A[r] > A[largest]){
        largest = r;
        przypisania++;
    }
    porownania += 2;
    if (i != largest){
        float temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        heapify(A,n,largest);
        przypisania+=3;
    }
    porownania++;
}

void build_heap(float A[],int n){
    for (int i = (n/2)-1; i >= 0; i--){
        heapify(A,n,i);
    }
}

void heap_sort(float A[],int n){
    build_heap(A,n);
    for (int i = n-1; i >= 1; i--){
        float temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        przypisania+=3;
        heapify(A,i,0);
    }
}

int leftT(int i){
    return 3 * i + 1;
}
int middleT(int i){
    return 3 * i + 2;
}
int rightT(int i){
    return 3 * i + 3;
}

void heapifyT(float A[], int n, int i){
    int largest;
    int l = leftT(i);
    int m = middleT(i);
    int r = rightT(i);
    przypisania += 4;
    
    if (l < n && A[l] > A[i]){
        largest = l;
    } else {
        largest = i;
    }
    porownania+=2;
    przypisania++;

    if (m < n && A[m] > A[largest]){
        largest = m;
        przypisania++;
    }

    if (r < n && A[r] > A[largest]){
        largest = r;
        przypisania++;
    }
    porownania+=4;
    if (i != largest){
        float temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        przypisania+=3;
        heapifyT(A,n,largest);
    } 
    porownania++;
}
void build_heapT(float A[],int n){
    for (int i = (n/3)-1; i >= 0; i--){
        heapifyT(A,n,i);
    }
}

void heapSortT(float A[],int n){
    build_heapT(A,n);
    for (int i = n-1; i >= 1; i--){
        float temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        przypisania+=3;
        heapifyT(A,i,0);
    }
}