<font face="LaTeX">

### RutaMinima
*Dada una matriz D de $n × n$ números naturales, queremos encontrar una permutación $π^1$ de $\{1,...,n\}$ que minimice $D_{π(n)π(1)}$ + $\sum_{i=1}^{n-1} D_{π(i)π(i+1)}$*

---

*a) Diseñar un algoritmo de backtracking para resolver el problema, indicando claramente cómo se codifica una solución candidata, cuáles soluciones son válidas y qué valor tienen, qué es una solución parcial y cómo se extiende cada solución parcial.*

- *Una solución <strong>candidata</strong> puede ser representada como un vector $\pi$ de tamaño $n$, donde cada posición $\pi[i]$ contiene un índice de $1$ a $n$, sin repeticiones, indicando el orden en el que se visitarán las filas/columnas.*

- *Soluciones <strong>válidas</strong>: Una solución es válida cuando el vector $\pi$ contiene todos los números de $1$ a $n$ sin repetir. Esto garantiza que todas las filas y columnas son visitadas exactamente una vez.

- *Valor de una solución: El valor de una solución se calcula sumando $D_{\pi(n)\pi(1)}$ + $\sum_{i=1}^{n-1} D_{\pi(i)\pi(i+1)}$, es decir, el costo de recorrer la matriz según el orden definido por $\pi$, más el costo de volver del último elemento al primero.*

- Solución parcial y su extensión: Una solución parcial es un vector $\pi$ que ha sido llenado hasta la posición $k < n$. Se extiende agregando un número de $1$ a $n$ que no esté ya en el vector $\pi$, en la posición $k+1$.

El algoritmo propuesto consiste en:
* Generar todas las permutaciones posibles de los números del $1$ al $n$.
* Calcular el valor de cada permutación según la fórmula $D_{\pi(n)\pi(1)}$ + $\sum_{i=1}^{n-1} D_{\pi(i)\pi(i+1)}$.
* Mantener un registro del mejor valor encontrado hasta el momento y la permutación asociada.
* Utilizar <strong>backtracking</strong> para generar las permutaciones de manera eficiente.

```python
def calcular_valor_permutacion(perm, matriz):
    n = len(perm)
    valor = matriz[perm[-1]][perm[0]]  # Costo de ir del último al primer elemento
    for i in range(n - 1):
        valor += matriz[perm[i]][perm[i + 1]]  # Costo de ir de un elemento al siguiente
    return valor

def backtrack_permutaciones(matriz, permutacion_actual, mejor_valor, mejor_permutacion):
    n = len(matriz)
    if len(permutacion_actual) == n:  # Si la permutación actual está completa
        valor_actual = calcular_valor_permutacion(permutacion_actual, matriz)
        if valor_actual < mejor_valor:  # Si encontramos una mejor solución
            mejor_valor = valor_actual
            mejor_permutacion = permutacion_actual.copy()
    else:
        for i in range(1, n + 1):
            if i not in permutacion_actual:  # Si el índice no ha sido utilizado aún
                permutacion_actual.append(i)  # Agregamos el índice a la permutación actual
                mejor_valor, mejor_permutacion = backtrack_permutaciones(matriz, permutacion_actual, mejor_valor, mejor_permutacion)
                permutacion_actual.pop()  # Retrocedemos para probar con otros índices 
    return mejor_valor, mejor_permutacion

def ruta_minima(matriz):
    n = len(matriz)
    mejor_valor = float('inf')
    mejor_permutacion = []
    mejor_valor, mejor_permutacion = backtrack_permutaciones(matriz, [], mejor_valor, mejor_permutacion)
    return mejor_permutacion, mejor_valor
```

---


*b) Calcular la complejidad temporal y espacial del mismo.*

- Complejidad temporal: La complejidad temporal del algoritmo propuesto es $O(n!)$, ya que se generan todas las permutaciones posibles de los números del $1$ al $n$. La cantidad de permutaciones posibles de $n$ elementos es $n!$.

---

*c) Proponer una poda por optimalidad y mostrar que es correcta.*

La poda por optimalidad consiste en detener la exploración de una rama del árbol de backtracking si el valor de la solución parcial actual es mayor o igual al valor de la mejor solución encontrada hasta el momento.

Es decir, si el valor de la solución parcial actual es mayor o igual al valor de la mejor solución encontrada hasta el momento, no tiene sentido seguir explorando esa rama, ya que no se encontrará una solución óptima.

Esta poda es correcta porque si el costo parcial ya es mayor que el de una solución completa previamente encontrada, continuar explorando esa rama solo incrementará el costo, imposibilitando que esa ruta sea mejor que la solución óptima.

</font>