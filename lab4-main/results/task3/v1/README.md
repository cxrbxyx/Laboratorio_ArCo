# Paralelización con OpenMP

En base al análisis realizado en las dos tareas anteriores es momento de realizar las paralelizaciones que consideres oportunas en el código.

Para cada paralelización completa la siguiente plantilla de resultados:

## Paralelización 1

### Análisis previo
Indica en qué te has basado para paralelizar esta región de código, apoya tu argumentación con capturas de Intel Advisor.
    He paralelizado el site "Third stage block for", ya que es, según advisor, el site con mayor mejora prevista gracias a la paralelización.

### Paralelización
Explica las modificaciones realizadas sobre el código original
    La modificación del código ha sido la [siguiente](captura1.png).
¿Has tenido que modificar cómo se calcula alguna variable para evitar dependencias de tipo inter-loop?
    No, no se ha modificado el cálculo de variables.

### Análisis posterior
Compara el código original con el mejorado y realiza tablas de comparación aumentando el número de hilos.

* ¿Coinciden los resultados con el valor predecido por la herramienta?
    Comparando con la [captura](captura_sin_paralelizar.png) realizada antes de la paralelización de la sección, se puede ver que la predicción no es 100% efectiva, ya que no se obtiene esa mejora, pero sí se obtiene mejora de tiempo como podemos ver en esta otra [captura](captura3.png)
* ¿Cómo has comparado los resultados para verificar la correción del programa paralelo?
    He comparado el elapsed time del programa sin paralelizar, siendo este [7.20s](captura3.png), con el elapsed time del programa con la mejora de la paralelización, siendo un tiempo de [3.18s](captura4.png), a parte de comparar el total serial time de las capturas anteriores.

### Resultados
Por cada mejora guarda los resultados y el código junto a su makefile en results/task3/vX donde X indica el orden en que has paralelizado.

Cada carpeta de resultados tiene que ser ejecutable, es decir, el profesor podrá realizar un make y make run en dichas carpetas
para comprobar cada mejora parcial.

## Mejora combinada
Una vez paralelizado cada región por separado, combina los resultados y completa la plantilla anterior.

---

# Parallelization with OpenMP

Based on the analysis carried out in the previous two tasks, it is time to perform the parallelizations you consider appropriate in the code.

For each parallelization, complete the following results template:

## Parallelization X

### Preliminary Analysis
Indicate what you based your decision on to parallelize this region of code, support your argument with screenshots from Intel Advisor.

### Parallelization
Explain the modifications made to the original code.

Did you have to modify how any variable is calculated to avoid inter-loop dependencies?

### Post Analysis
Compare the original code with the improved one and create comparison tables by increasing the number of threads.

* Do the results match the value predicted by the tool?
* How did you compare the results to verify the correctness of the parallel program?

### Results
For each improvement, save the results and the code along with its makefile in results/task3/vX where X indicates the order in which you parallelized.

Each results folder must be executable, meaning the professor should be able to run make and make run in those folders to check each partial improvement.

## Combined Improvement
Once each region has been parallelized separately, combine the results and complete the previous template.