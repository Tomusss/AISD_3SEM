#include <iostream>
#include <random>
using namespace std;

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
    
    if (l < n && A[l] > A[i]){
        largest = l;
    } else {
        largest = i;
    }

    if (m < n && A[m] > A[largest]){
        largest = m;
    }

    if (r < n && A[r] > A[largest]){
        largest = r;
    }
    if (i != largest){
        float temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        heapify(A,n,largest);
    } 
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

} 