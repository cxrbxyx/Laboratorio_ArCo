/* Programa serie para calcular pi */ 
#include <math.h> 
#include <stdio.h> 
#include <omp.h> 

#define NUM_THREADS 8
#define N 1000000000
int main() 
{
	omp_set_num_threads(NUM_THREADS);  
	int n,i; 
	double xi,a,z; 
	double pi16ds = 3.1415926535897932; // con 25 decimales 3.141592653589793238462643 
	double sum = 0.0; 
	printf("\nSe utilizarán %d hilos\n", NUM_THREADS);
	printf("Se utilizarán %d intervalos\n", N);
	n=N;
	a = omp_get_wtime(); 

	double h = 1.0 / (double)n; // tamaño intervalo 

	     // centro del primer intervalo 
	#pragma omp parallel for private(xi) reduction(+:sum)
	for (i = 0; i < n; i++) { 
		xi = h * (i+0.5);
		sum += (4.0 / (1.0 + xi*xi)); 
		 // xi: centro del siguiente intervalo 
	} 

	double pi = sum * h; 

	printf("El valor aproximado de PI es %0.16f con un error de %0.16f\n", pi, fabs(pi-pi16ds)); 

	z = omp_get_wtime(); 

	printf("El programa ha tardado %0.10f segundos \n", z-a); 
	return 0;
} 