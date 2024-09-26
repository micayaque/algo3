MaxiSubconjunto
---

Dada una matriz simétrica $M$ de $n × n$ números naturales y un número $k$, queremos encontrar un subconjunto $I$ de $\{1,..., n\}$ con $|I| = k$ que maximice  $\sum_{i,j∈I} M_{ij}$ .

**a)** Diseñar un algoritmo de backtracking para resolver el problema, indicando claramente cómo se codifica una $\textcolor{purple}{solución \ candidata}$, cuáles soluciones son $\textcolor{purple}{válidas}$ y qué valor tienen, qué es una solución parcial y cómo se extiende cada $\textcolor{purple}{solución \ parcial}$.

Una solución candidata puede codificarse como un vector $I$ de tamaño $k$ que almacene índices de $1$ a $n$, indicando las filas/columnas seleccionadas de la matriz $M$.*

Una solución es válida si el tamaño de $I$ es exactamente $k$ y maximiza la suma. Esto significa que hemos seleccionado $k$ elementos únicos de ${1, \ldots, n}$.\
El valor de una solución válida se calcula sumando todos los elementos $M_{ij}$ para $i, j \in I$ donde $i \neq j$ (ya que la matriz es simétrica y los elementos de la diagonal son $0$).

Una solución parcial puede es un vector $I$ con menos de $k$ elementos. Para extender una solución parcial, se añade un nuevo índice a $I$ que no esté ya en el conjunto. Esto se repite hasta que alcanzamos $k$ elementos.

```C++
int max_subset(int i, int k, vector<int> subset, vector<int>& partial_sol, vector<int>& curr_sol) {
    int n = subset.size();

    if(k==0){
        if(matrix_sum(curr_sol, m) < matrix_sum(partial_sol, m)){
            curr_sol = partial_sol;
            return matrix_sum(partial_sol, m);
        } 
    }

    if(i==n) return 0;

    vector<int> new_sol = partial_sol.pushback(subset[i]);
    return max(max_subset(i+1, k, subset, partial_sol), max_subset(i+1, k-1, subset, new_sol));
    new_sol.pop_back();
}
```

```C++
int matrix_sum(vector<int> subset, vector<vector<int>> matrix){
    int res=0;
    for(int i=0; i<subset.size()-2; i++){
        for(int j=i+1; j<subset.size()-1; j++){
            res+=matrix[subset[i]][subset[j]];
        }
    }
}
```

---

**b)** Calcular la complejidad temporal y espacial del mismo.

La complejidad temporal del algoritmo es exponencial, ya que cada llamada recursiva se bifurca en dos subproblemas, uno en el que se añade un elemento a la solución parcial y otro en el que no se añade.

---

**c)** Proponer una poda por optimalidad y mostrar que es correcta.

Podemos podar una rama del árbol de recursión si la suma de los elementos de la solución parcial más los elementos que faltan por añadir no supera a la mejor solución encontrada hasta el momento.

