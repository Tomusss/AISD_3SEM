#include <iostream>
using namespace std;

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
    
    if (l < n && A[l] > A[i]){
        largest = l;
    } else {
        largest = i;
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
        heapify(A,i,0);
    }
}


int main() {
    float A[] = {13, 11, -13,22,-1,66, 5, 6,6.66, 7};
    int n = 10 ;

    heap_sort(A,n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    

}