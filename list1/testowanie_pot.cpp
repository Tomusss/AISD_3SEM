#include <fstream>
#include <chrono>
#include "funkcje.h"

using namespace std;
using namespace std::chrono;

int main() {
    int powtorzenia = 5;
    int najmn = 100;
    int podstawa = 10;
    int ilosc = 6;
    float *A;
    double time;

    // pusta tablica na czasy
    double* times = new double[ilosc];

    for (int i = 0; i < ilosc; i++) { // zaczynamy od 0
        int el = najmn * (1 << (i + podstawa)); // poprawiony wzór
        A = new float[el];
        time = 0.0;

        for (int j = 0; j < powtorzenia; j++) {
            // randomowe wartosci
            // randArr(A, el);
            sortArr(A, el);

            auto start = high_resolution_clock::now();

            // insertionSort(A, el);
            // heap_sort(A, el);           
            // mergeSort(A, 0, el - 1);
            // double_insertionSort(A, el);
            tripleMergeSort(A, 0, el - 1); // poprawiony zakres
            // heapSortT(A, el);            

            auto end = high_resolution_clock::now();

            auto czas = duration_cast<duration<double>>(end - start);

            time += czas.count();
        }

        // średni czas
        times[i] = time / powtorzenia;

        delete[] A;
    }

    // zapis do pliku
    ofstream plik("timing.dat", ios::out | ios::trunc);
    for (int i = 0; i < ilosc; i++) { // zmiana warunku
        plik << times[i] << "\n";
    }

    delete[] times;

    return 0;
}
