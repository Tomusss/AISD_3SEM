#include <fstream>
#include <chrono>
#include "funkcje.h"

using namespace std;
using namespace std::chrono;

int main() {
    int powtorzenia = 3;
    int najmn = 10;
    int najw = 30020;
    int krok = 1000;
    float *A;
    //int *A;
    double time;

    // pusta tablica na czasy
    double* times = new double[(najw-najmn)/krok + 1];

    for (int i = najmn; i <= najw; i+= krok) {
        float* A = new float[i];
        //int* A = new int[i];
        time = 0.0;

        for (int j = 0; j < powtorzenia; j++) {
            char** binaryArray = new char*[i];
            //char** quaternaryArray = new char*[i];
            // randomowe wart
            randArrF(A, i);
            //randArrF01(A, i);
            //randArrID(A, i);
            //randArrI(A, i);
            auto start = high_resolution_clock::now();

            //bucketSort(A,i); //f01
            bucketSortMod(A,i); //f
            //quickSort(A,0,i-1);  //f
            //quickSortMod(A,0,i-1);  //f    
            //radixSortMod(A,i,10);  //int
            //radixSort(A,i,10);     //int+
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