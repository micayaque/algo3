En muchas aplicaciones se necesita encontrar caminos de peso multiplicativo mínimo en un digrafo $D$ pesado con una función positiva $c : E(G) \to \R_{\gt 1}$ . 

Formalmente, el peso multiplicativo de un camino $v_1 , . . . , v_k$ es la multiplicatoria de los pesos de sus aristas. 

Este tipo de caminos se buscan, por ejemplo, cuando los pesos de las aristas representan probabilidades de eventos independientes y se quiere encontrar una sucesión de eventos con probabilidad máxima/mínima.

Modelar el problema de camino de peso multiplicativo mínimo como un problema de camino mínimo. 

Demostrar que el algoritmo es correcto. 

Ayuda: transformar el peso de cada arista
usando una operación conocida que sea creciente y transforme cualquier multiplicatoria en una sumatoria.

### Transformación Logarítmica:

La transformación clave es usar el logaritmo natural para convertir la multiplicatoria en una sumatoria. 

Para cada arista $(u, v) \in E$ con peso $c(u \to v)$, definimos un nuevo peso:
$$c'(u \to v) = \log c(u \to v)$$

Debido a las propiedades de los logaritmos:
$$\log \left( c(v_1 \to v_2) \cdot c(v_2 \to v_3) \cdot \ldots \cdot c(v_{k-1} \to v_k) \right) = \log c(v_1 \to v_2) + \log c(v_2 \to v_3) + \ldots + \log c(v_{k-1} \to v_k)$$

Por lo tanto, minimizar la multiplicatoria original se convierte en minimizar la sumatoria:
$$\sum_{i=1}^{k-1} \log c(v_i \to v_{i+1})$$

Para cada arista $(u, v) \in E$, reemplaza el peso $c(u \to v)$ por $\log c(u \to v)$.

Usar el algoritmo de Dijkstra para encontrar el camino mínimo desde $s$ a $t$ en el nuevo grafo con pesos transformados $c'(u \to v)$.

El camino mínimo obtenido en el grafo con pesos transformados es equivalente al camino de **peso multiplicativo mínimo** en el grafo original.

Sólo queda al final retornar la función exponencial (anti-logaritmo) al resultado.

### Demostración de la Correctitud:

La función $\log x$ es estrictamente creciente, lo que significa que si $x \gt y$, entonces $\log x \gt \log y$. 

Por lo tanto, minimizar $\log$ de la multiplicatoria es equivalente a minimizar la multiplicatoria misma.

La transformación convierte un problema de multiplicatoria en una sumatoria, lo que permite usar algoritmos de caminos mínimos estándar que trabajan con sumas.

Cualquier camino $P$ en $D$ con el peso multiplicativo mínimo $c(P)$ será transformado de manera que el algoritmo de caminos mínimos lo encontrará como el camino con la suma mínima $\sum \log c(u \to v)$.

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to;
    double weight; //double para permitir la transformación logarítmica
};

vector<double> dijkstra(int n, vector<vector<pair<int, double>>>& adj, int start) {
    vector<double> dist(n, DBL_MAX);
    dist[start] = 0.0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0.0, start});

    while (!pq.empty()) {
        double d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            double weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
```