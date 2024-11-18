El algoritmo de **Floyd-Warshall** encuentra las **distancias mínimas** entre **todos los pares de nodos** en un grafo dirigido (o no dirigido) con pesos que pueden ser positivos o negativos (pero sin ciclos negativos).

El algoritmo de Floyd-Warshall utiliza una técnica de **programación dinámica**. 

Dado un grafo con $n$ nodos, se construye una matriz $D$ donde $D[i][j]$ representa la longitud del camino más corto desde el nodo $i$ hasta el nodo $j$. 

El algoritmo actualiza iterativamente esta matriz considerando cada nodo como un **intermediario** en posibles caminos.

Para cada par de nodos $i$ y $j$, el algoritmo verifica si existe un camino más corto que pase por un nodo intermedio $k$. 

Si tal camino existe, actualiza la distancia. Formalmente, la fórmula es:

$$D[i][j] = \min(D[i][j], D[i][k] + D[k][j])$$

$D[i][k]$ es la distancia del nodo $i$ al nodo intermedio $k$, y $D[k][j]$ es la distancia del nodo $k$ al nodo $j$.

- Se inicializa la matriz $D$ de forma que:
    - $D[i][i] = 0$ para todos los nodos $i$ (la distancia de un nodo a sí mismo es cero).
    - $D[i][j]$ se inicializa con el peso de la arista entre $i$ y $j$ si existe, o con $\infty$ si no hay arista directa entre ellos.

- Se recorre cada nodo $k$ de 1 a $n$ como un posible nodo intermedio.
    - Para cada par de nodos $i$ y $j$, se actualiza $D[i][j]$ usando la fórmula mencionada:
    $$D[i][j] = \min(D[i][j], D[i][k] + D[k][j])$$

- Después de $n$ iteraciones, la matriz $D$ contendrá las distancias más cortas entre todos los pares de nodos.

```cpp
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void floydWarshall(int n, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
```

### Complejidad

**Temporal**: $O(n^3)$, donde $n$ es el número de nodos. Esto se debe al uso de tres bucles anidados para actualizar la matriz de distancias.

**Espacial**: $O(n^2)$, debido a la matriz de distancias.