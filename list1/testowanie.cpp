#include <fstream>
#include <chrono>
#include "funkcje.h"

using namespace std;
using namespace std::chrono;

int main() {
    int powtorzenia = 5;
    int najmn = 10;
    int najw = 100010;
    int krok = 1000;
    float *A;
    double time;

    // pusta tablica na czasy
    double* times = new double[(najw-najmn)/krok + 1];

    for (int i = najmn; i <= najw; i+= krok) {
        A = new float[i];
        time = 0.0;

        for (int j = 0; j < powtorzenia; j++) {
            // randomowe wart
            randArr(A, i);

            auto start = high_resolution_clock::now();

            //insertionSort(A, i);
            //heap_sort(A,i);           
            //mergeSort(A,0,i-1);
            //double_insertionSort(A,i);
            tripleMergeSort(A,0,i-1);
            //heapSortT(A,i);            

            auto end = high_resolution_clock::now();

            auto czas = duration_cast<duration<double>>(end - start);

            time += czas.count();
        }
        // sredni czas
        times[(i-najmn)/krok] = time/powtorzenia;


        delete[] A;
    }

    // zapis do pliku
    ofstream plik("timing.dat", ios::out | ios::trunc);
    for (int i = 0; i < (najw-najmn)/krok; i++) {
        plik << times[i] << "\n";
    }

    delete[] times;

    return 0;
}