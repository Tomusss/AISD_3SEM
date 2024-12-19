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
//bucket sort
struct SLel {
    SLel* next;
    float data;
};

SLel* inicjacja() {
    SLel* L = new SLel; // Strażnik
    L->next = new SLel; // Drugi strażnik
    L->next->data = 2147483647;
    L->next->next = NULL;
    return L;
}

void insertion(SLel* L, float v) {
    SLel* e;
    SLel* p;
    for (p=L; v> p->next->data; p = p->next)//szukanie miejsca   
        ;   
    e = new SLel; //nowy wezel
    e->data = v; 
    e->next = p->next; //wskazywanie na nastepny el
    p->next = e; //p wskazuje na nowy el
}
void bucketSort(float A[], int n) {
    SLel** B = new SLel*[n];
    for (int j = 0; j < n; j++) {
        B[j] = inicjacja();
    }

    for (int i = 0; i < n; i++) {
        int b = n*A[i];
        insertion(B[b], A[i]);
    }

    //przepisanie elem do tab 
    int index=0;
    for (int j=0; j<n; j++) {
        SLel* kub = B[j]->next;
        while (kub && kub->data!=2147483647) {
            A[index++] = kub->data;
            SLel* temp = kub;
            kub = kub->next;
            delete temp;
        }
        delete B[j];
    }

    delete[] B;
}

//bucket sort mod

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

void bucketSortMod(float A[], int n) {
    SLel** B = new SLel*[n];
    float min = minwart(A,n);
    float max = maxwart(A,n);
    float przedzial = max-min;
    for (int j=0; j<n; j++) {
        B[j]=inicjacja();
    }

    for (int i = 0; i < n; i++) {
        int b = n*(A[i]-min)/przedzial;
        if(b==n){ 
            b=n-1;
        }
        insertion(B[b],A[i]);
    }

    //przepisanie elem do tab 
    int index=0;
    for (int j=0; j<n; j++) {
        SLel* kub = B[j]->next; //pomijamy pierwszego
        while (kub && kub->data!=2147483647) {
            A[index++] = kub->data;
            SLel* temp = kub;
            kub = kub->next;
            delete temp;
        }
        delete B[j];
    }

    delete[] B;
}
//quick sort
/*
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
        int s = partition(A,p,k);
        quickSort(A,p,s-1);
        quickSort(A,s+1,k);
    }
}
*/
//quick sort mod

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

//radix sort
float maxwartI(int A[], int n) {
    float max = A[0];
    for (int i =1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}
void coutingSort(int A[], int n, int baza, int poz){
    int* C = new int[baza];
    int* B = new int[n]; 
    
    for (int i = 0; i < baza; i++) {
        C[i] = 0;}

    for(int i = 0; i <n;i++){
        int znak = (A[i] / poz) % (baza);
        C[znak]++;
    }
    for(int j=1;j<=baza;j++){
        C[j] += C[j-1];
    }

    for(int i = n-1;i>=0;i--){
        int znak = (A[i] / poz) % (baza);
        B[C[znak]-1]= A[i];
        C[znak]--;
    }

    for (int i=0; i<n; ++i) {
        A[i] = B[i];
    }
}

void radixSort(int* A, int n, int baza) {
    int max = maxwartI(A, n);
    for (int poz = 1; max / poz > 0; poz *= baza) {
        coutingSort(A, n, baza, poz);
    }
}

//radix sort mod

void radixSortMod(int A[], int n, int baza){
    int* U = new int[n];
    int* D = new int[n];
    int j = 0;
    int l = 0;
    for(int i = 0; i<n; i++){ 
        if(A[i] < 0){
            U[j] = -A[i];
            j++;
        }else{
            D[l] = A[i];
            l++;
        } 
    }

    radixSort(D,l,baza);
    radixSort(U,j,baza);

    
    int licz = j;
    for (int i = 0; i < licz; i++) {
        A[i] = -U[j-1];
        j--;
        
    }
    for (int i = licz; i < n; i++) {
        A[i] = D[i - licz];
    }

}

void randArrF(float A[], int n) {
    random_device rd;
    mt19937 e2(rd());
    uniform_real_distribution<> dist(-1000, 1000);

    for (int i = 0; i < n; i++) {
        A[i] = dist(e2);
    }
}
void randArrF01(float A[], int n) {
    random_device rd;
    mt19937 e2(rd());
    uniform_real_distribution<> dist(0, 1);

    for (int i = 0; i < n; i++) {
        A[i] = dist(e2);
    }
}
void randArrI(int A[], int n) {
    random_device rd;
    mt19937 e2(rd());
    uniform_int_distribution<> dist(-1000, 1000);

    for (int i = 0; i < n; i++) {
        A[i] = dist(e2);
    }
}
void randArrID(int A[], int n) {
    random_device rd;
    mt19937 e2(rd());
    uniform_int_distribution<> dist(0, 1000);

    for (int i = 0; i < n; i++) {
        A[i] = dist(e2);
    }
}
