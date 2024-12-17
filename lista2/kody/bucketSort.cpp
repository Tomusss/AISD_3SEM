#include <iostream>
#include <cmath>
#include <random>

using namespace std;

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

// Wstawianie elementu do posortowanej listy
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

void randArr(float A[], int n)
{
    random_device rd;

    mt19937 e2(rd());
    uniform_real_distribution<> dist(0, 1);

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
    
    bucketSort(A,n);
    
    cout << "po sortowaniu: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << ' ';
    }
} 
