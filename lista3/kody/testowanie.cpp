#include <fstream>
#include <chrono>
#include "funkcje.h"

using namespace std;
using namespace std::chrono;

    int main() {
    int powtorzenia = 3;
    int najmn = 10;
    int najw = 100000;
    int krok = 1000;
    //int *A;
    double time;
    // pusta tablica na czasy
    double* times = new double[(najw-najmn)/krok + 1];

    for (int i = najmn; i <= najw; i+= krok) {
          
        time = 0.0;
        /*
        char* X = new char[i];
        char* Y = new char[i];
        int** A = new int*[i + 1];
        char** B = new char*[i + 1];
        
            
        for (int k = 0; k <= i; ++k) {
            A[k] =new int[i + 1];
            B[k] =new char[i + 1];
        }

        for (int k = 0; k <= i; ++k) {
            A[k][0] = 0;
        }
        for (int k = 0; k <= i; ++k) {
            A[0][k] = 0;
        }  
        for (int k=0; k<=i; ++k) {
        A[k] = new int[i+1];
        B[k] = new char[i+1];
            for (int j=0; j<=i; ++j) {
                A[k][j]= -1;
                B[k][j] = ' ';
            
                }
        }
        
        
        float* P= new float[i];
        float* R = new float[i+1];
        int* S = new int[i+1];
        
        int** C = new int*[i + 1];
        
        */
       
        /*
        
        
        
        */
        int* start_times = new int[i+2];
        int* finish_times = new int[i+2];
        int* activities = new int[i+2];
        int idx = 0;
        for (int j = 0; j < powtorzenia; j++) {
            //random_string(X, i-1);
            //random_string(Y, i-1);
            //random_prices(P, i);
            generuj_dane(start_times, finish_times, i);
            
            auto start = high_resolution_clock::now();
            
            // Wykonanie funkcji
            //lcs_iteracyjnie(X, Y, A, B, i, i);
            //lcs_rekurencyjnie(X, Y, A, B, i, i);
            //memorized_cut_rod(P, R, S, i);
            //cut_rod_iteracyjnie(P, R, S, i);
            //cut_rod(P,i);
            //activity_selector_dynamicznie(start_times, finish_times, i);
            //activity_selector_iteracyjnie_mod(start_times, finish_times, i, activities, idx);
            activity_selector_rekurencyjnie_mod(start_times, finish_times, 0, i, activities, idx);
            
            auto end = high_resolution_clock::now();
            auto czas = duration_cast<duration<double>>(end - start);
            time += czas.count();
            cout << time;
        }
        
        // Średni czas
        times[(i - najmn) / krok] = time / powtorzenia;
        cout << time / powtorzenia<<endl;
        
        delete[] start_times;
        delete[] finish_times;
        delete[] activities;
        // Dealokacja pamięci
        /*
        delete[] P;
        delete[] R;
        delete[] S;
        for (int j = 0; j <= i; ++j) {
            delete[] A[j];
            delete[] B[j];
        }
        delete[] A;
        delete[] B;
        delete[] X;
        delete[] Y;
        */
    }

    // zapis do pliku
    ofstream plik("timing.dat", ios::out | ios::trunc);
    for (int i = 0; i < (najw-najmn)/krok; i++) {
        plik << times[i] << "\n";
    }

    delete[] times;

    return 0;
}