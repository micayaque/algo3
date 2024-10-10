Indice Espejo
---
Tenemos un arreglo $a = [a_1 , a_2 , . . . , a_n ]$ de $n$ enteros distintos (positivos y negativos) en $\color{violet}orden$ estrictamente creciente.

Queremos determinar si existe una posición i tal que $a_i = i$. 

Por ejemplo, dado el arreglo $a = [−4, −1, 2, 4, 7]$, $i = 4$ es esa posición.

Diseñar un algoritmo dividir y conquistar eficiente (de complejidad de orden estrictamente menor que lineal) que resuelva el problema.

Calcule y justifique la complejidad del algoritmo dado.

El arreglo está ordenado por lo tanto podemos usar $\color{violet}búsqueda\ binaria$ para encontrar el elemento que buscamos.

```C++
bool indice_espejo(vector<int>& arr, int start, int end) {
    if (start == end) return arr[start] == start + 1;

    int m = (start + end) / 2;

    if (arr[m] == m + 1) return true;

    if (arr[m] > m + 1) return indice_espejo(arr, start, m - 1);

    return indice_espejo(arr, m + 1, end);
}
```

Llamado que resuelve el problema: `indice_espejo(arr, 0, arr.size() - 1)`

La complejidad es la misma que en la búsqueda binaria: $O(\log n)$.