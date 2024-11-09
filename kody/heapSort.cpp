#include <iostream>
#include <random>

using namespace std;

int porownania = 0; 
int przypisania = 0;

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


void randArr(float A[], int n)
{
    random_device rd;

    mt19937 e2(rd());
    uniform_real_distribution<> dist(-10000, 10000);

    for (int i = 0; i < n; i++) {
        A[i] = dist(e2);
    }
}

bool czyPosortowane(float A[], int n){
    for (int i=0; i<n-1; i++){
        if (A[i] > A[i + 1]){
            return false;
        }
    }
    return true;
}

int main(){
    int n = 100000;
    float A[n];
    randArr(A,n);
    /*cout << "przed sortowaniem: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
    
    heap_sort(A,n);
    
    cout << "po sortowaniu: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }
    cout << "\nLiczba porównań: " << porownania << endl;
    cout << "Liczba przypisań: " << przypisania << endl;
    */
   heap_sort(A,n);
   cout << czyPosortowane(A,n) << endl;

} 