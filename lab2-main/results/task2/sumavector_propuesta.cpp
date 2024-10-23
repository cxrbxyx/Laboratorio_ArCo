/* Programa secuencial que calcula la suma de los elementos de un vector v[i] * y la almacena en la variable sum */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>
#include <cmath>

#define N 1000000 // Probar distintos tamaños de vector
#define NUM_THREADS 8

using namespace std;

void timestamp();
int main();

int main()
{
    timestamp();
    int i, sum = 0;
    int v[N];
    double wtime = 0;
    omp_set_num_threads(NUM_THREADS);
    // Damos valores aleatorios al vector (entre 0 y 99)
    srand(time(NULL)); // Semilla de números aleatorios
    for (i = 0; i < N; i++)
        v[i] = rand() % 100;

// Cálculo del sumatorio
    wtime=omp_get_wtime();
#pragma omp parallel for reduction(+ : sum)
    for (i = 0; i < N; i++)
        sum += v[i];
    wtime = omp_get_wtime() - wtime;
    // Como comprobación, se visualizan los valores del vector y la suma
    
    printf("    La suma es: %d \n", sum);
    cout << "   Used treahds: " << NUM_THREADS << "\n";
    cout << "   Elapsed seconds = " << wtime << "\n";
    timestamp();


    cout << endl;
    return 0;
}

void timestamp()
{
#define TIME_SIZE 40

    static char time_buffer[TIME_SIZE];
    const struct std::tm *tm_ptr;
    size_t len;
    std::time_t now;

    now = std::time(NULL);
    tm_ptr = std::localtime(&now);

    len = std::strftime(time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr);

    std::cout << time_buffer << "\n";

    return;
}