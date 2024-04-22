<font face="LaTeX">

### <u>MaxiSubconjunto</u>
*Dada una matriz simétrica M de $n × n$ números naturales y un número k, queremos encontrar un subconjunto $I$ de $\{1,..., n\}$ con $|I| = k$ que maximice  $\sum_{i,j∈I} M_{ij}$ .*

---

*a) Diseñar un algoritmo de backtracking para resolver el problema, indicando claramente cómo
se codifica una solución candidata, cuáles soluciones son válidas y qué valor tienen, qué es
una solución parcial y cómo se extiende cada solución parcial.*

*Una solución candidata puede codificarse como un vector $I$ de tamaño $k$ que almacene índices de $1$ a $n$, indicando las filas/columnas seleccionadas de la matriz $M$.*

*Una solución es válida si el tamaño de $I$ es exactamente $k$. Esto significa que hemos seleccionado $k$ elementos únicos de ${1, \ldots, n}$.*

*El valor de una solución válida se calcula sumando todos los elementos $M_{ij}$ para $i, j \in I$ donde $i \neq j$ (ya que la matriz es simétrica y los elementos de la diagonal son $0$).*

*Una solución parcial puede es un vector $I$ con menos de $k$ elementos. Para extender una solución parcial, se añade un nuevo índice a $I$ que no esté ya en el conjunto. Esto se repite hasta que alcanzamos $k$ elementos.*

```python
def MaxiSubconjunto(M, k):
    n = len(M)
    mejor = 0
    mejor_sol = []
    def BT(i, j, suma, sol):
        nonlocal mejor, mejor_sol
        if i == n:
            if j == k:
                if suma > mejor:
                    mejor = suma
                    #sol.copy() para evitar que mejor_sol se modifique cuando sol se modifica, 
                    #ya que las listas en Python son mutables
                    mejor_sol = sol.copy()
        else:
            if j < k:
                sol.append(i)
                suma += sum(M[i][x] for x in sol if x < i)
                BT(i+1, j+1, suma, sol)
                sol.pop()
                BT(i+1, j, suma, sol)
    BT(0, 0, 0, [])
    return mejor, mejor_sol
```

---

*b) Calcular la complejidad temporal y espacial del mismo.*

*La complejidad temporal del algoritmo es $O(2^n)$, ya que cada llamada recursiva se bifurca en dos subproblemas, uno en el que se añade un elemento a la solución parcial y otro en el que no se añade. Como el árbol de recursión tiene $n$ niveles, la complejidad total es $O(2^n)$.*

---

*c) Proponer una poda por optimalidad y mostrar que es correcta.*

*Podemos podar una rama del árbol de recursión si la suma de los elementos de la solución parcial más los elementos que faltan por añadir no supera a la mejor solución encontrada hasta el momento.*

```python
def MaxiSubconjunto(M, k):
    n = len(M)
    mejor = 0
    mejor_sol = []
    def BT(i, j, suma, sol):
        nonlocal mejor, mejor_sol
        if i == n:
            if j == k:
                if suma > mejor:
                    mejor = suma
                    mejor_sol = sol.copy()
        else:
            if j < k:
                sol.append(i)
                suma += sum(M[i][x] for x in sol if x < i)
                if suma + sum(M[i][x] for x in range(i+1, n)) > mejor:
                    BT(i+1, j+1, suma, sol)
                sol.pop()
                BT(i+1, j, suma, sol)
    BT(0, 0, 0, [])
    return mejor, mejor_sol
```

</font>