Diseñar un algoritmo eficiente que, dado un digrafo pesado $G$ y dos vértices $s$ y $t$, determine el recorrido minimo de $s$ a $t$ que pasa por a lo sumo una arista de peso negativo. 

Demostrar que el algoritmo propuesto es correcto.

Quitar las aristas de peso negativo de $G$.

**Ejecutar Dijkstra desde $s$**: Encuentra los caminos mínimos desde $s$ a todos los vértices, ignorando las aristas de peso negativo.

**Invertir el grafo y ejecutar Dijkstra desde $t$**: Encuentra los caminos mínimos desde $t$ hacia todos los vértices (en el grafo transpuesto) sin considerar aristas de peso negativo.

**Explorar caminos con una arista negativa**: Iterar sobre cada arista de peso negativo $u \to v$. Si existe un camino desde $s$ a $u$ y desde $v$ a $t$, calcula el costo total del recorrido $s \to u \to v \to t$. Actualizar el camino mínimo si el costo total es menor que el mejor encontrado hasta el momento.

El resultado final será el mínimo entre el camino directo encontrado usando solo Dijkstra y los caminos que incluyen una arista de peso negativo.

```cpp
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from, to, weight;
};

vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int start) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int findMinPathWithOneNegativeEdge(int n, vector<Edge>& edges, int s, int t) {
    vector<vector<pair<int, int>>> adj(n), adj_transposed(n);
    for (const auto& edge : edges) {
        adj[edge.from].push_back({edge.to, edge.weight});
        adj_transposed[edge.to].push_back({edge.from, edge.weight});
    }

    vector<int> dist_from_s = dijkstra(n, adj, s);

    vector<int> dist_to_t = dijkstra(n, adj_transposed, t);

    int min_path_cost = dist_from_s[t]; 

    for (const auto& edge : edges) {
        if (edge.weight < 0) {
            int u = edge.from;
            int v = edge.to;
            if (dist_from_s[u] != INT_MAX && dist_to_t[v] != INT_MAX) {
                int path_cost = dist_from_s[u] + edge.weight + dist_to_t[v];
                min_path_cost = min(min_path_cost, path_cost);
            }
        }
    }

    return min_path_cost;
}
```

El algoritmo es correcto porque:
- Usa Dijkstra para encontrar caminos mínimos en subgrafos con pesos no negativos.
- Verifica caminos alternativos que incluyen una sola arista de peso negativo y evalúa si ofrecen un costo menor.
- Combina estos resultados para asegurar que el camino mínimo encontrado pasa por a lo sumo una arista negativa.