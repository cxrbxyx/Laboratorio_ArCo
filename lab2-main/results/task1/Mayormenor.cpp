#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   
#include <omp.h>
#include <cmath>

#define SIZE 1000000000 //Vector size
#define NUM_THREADS 16 //Number of threads

using namespace std;

void obtenerMayorYMenor(const vector<int> &arr, int &mayor, int &menor);
void timestamp();
int main();

void obtenerMayorYMenor(const vector<int> &arr, int &mayor, int &menor)
{
    mayor = arr[0];
    menor = arr[0];
    int n = arr.size();
#pragma omp parallel
    {
        
        int localMayor = arr[0];
        int localMenor = arr[0];

#pragma omp for
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > localMayor)
            {
                localMayor = arr[i];
            }
            if (arr[i] < localMenor)
            {
                localMenor = arr[i];
            }
        }


#pragma omp critical
        {
            if (localMayor > mayor)
            {
                mayor = localMayor;
            }
            if (localMenor < menor)
            {
                menor = localMenor;
            }
        }
    }
}

int main()
{
    
    double wtime = 0;
    int mayor, menor;
    timestamp();
    omp_set_num_threads(NUM_THREADS);
    srand(time(0));

    vector<int> arr(SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % SIZE;
    }

    wtime = omp_get_wtime();
    obtenerMayorYMenor(arr, mayor, menor);
    wtime = omp_get_wtime() - wtime;
    cout << "   Vector size: " << SIZE << "\n";
    cout << "   Used treahds: " << NUM_THREADS << "\n";
    cout << "   Elapsed seconds = " << wtime << "\n";
    cout << "   Max: " << mayor << endl;
    cout << "   Min: " << menor << endl;
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