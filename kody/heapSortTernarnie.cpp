#include <iostream>
#include <random>
using namespace std;

int porownania = 0; 
int przypisania = 0;

int left(int i){
    return 3 * i + 1;
}
int middle(int i){
    return 3 * i + 2;
}
int right(int i){
    return 3 * i + 3;
}

void heapify(float A[], int n, int i){
    int largest;
    int l = left(i);
    int m = middle(i);
    int r = right(i);
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
        heapify(A,n,largest);
    } 
    porownania++;
}
void build_heap(float A[],int n){
    for (int i = (n/3)-1; i >= 0; i--){
        heapify(A,n,i);
    }
}

void heapSort(float A[],int n){
    build_heap(A,n);
    for (int i = n-1; i >= 1; i--){
        float temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        przypisania+=3;
        heapify(A,i,0);
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
    
    heapSort(A,n);
    
    cout << "po sortowaniu: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }
    cout << "\nLiczba porównań: " << porownania << endl;
    cout << "Liczba przypisań: " << przypisania << endl;

} 