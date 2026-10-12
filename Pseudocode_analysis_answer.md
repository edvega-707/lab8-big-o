# Lab 8 — Part D Pseudocode Analysis

## D1 — Search and scan pseudocode
**Answer:**
La primera parte del codigo utiliza Binary Search para encontrar un ID.
Su complejidad es O(log n), porque en cada paso elimina aproximadamente
la mitad de los IDs que quedan por revisar.

Despues, el programa utiliza un ciclo para contar las actividades
activas. Esta parte tiene complejidad O(n), porque tiene que revisar
todas las actividades una por una.

La complejidad total es O(n), ya que contar las actividades requiere
mas trabajo cuando la lista crece.

Los costos no se multiplican porque las dos operaciones se hacen
por separado, una despues de la otra, y no hay un ciclo dentro del otro.
## D2 — Potential-conflict pseudocode
**Answer:**
El segundo ciclo comienza en first + 1 para evitar comparar una
actividad con ella misma y para no repetir comparaciones que ya
se hicieron.

La operacion que se cuenta es comparar las horas de inicio de
dos actividades para verificar si son iguales.

Su complejidad es O(n^2), porque utiliza dos ciclos, uno dentro
del otro, para revisar los diferentes pares.

Por ejemplo, con 4 actividades se hacen 6 comparaciones y con
8 actividades se hacen 28.

Esto demuestra que al duplicar la cantidad de actividades,
las comparaciones aumentan casi cuatro veces.

Por eso, cuando la lista crece, el programa necesita hacer
muchas mas comparaciones.