Sea $G$ un digrafo con pesos positivos que tiene dos vértices especiales $s$ y $t$. Para una arista $e \notin E(G)$ con peso positivo, definimos $G + e$ como el digrafo que se obtiene de agregar $e$ a $G$.

Decimos que $e$ mejora el camino de $s$ a $t$ cuando $d_G (s, t) \gt d_{G+e} (s, t)$. 

Diseñar un algoritmo eficiente que, dado un grafo $G$ y un conjunto de aristas $E \notin E(G)$ con pesos positivos, determine cuáles aristas de $E$ mejoran el camino de $s$ a $t$ en $G$. 

Demostrar que el algoritmo es correcto.


**Encontrar el camino mínimo de $s$ a $t$ en $G$**: Utilizar el algoritmo de Dijkstra para calcular la distancia mínima $d_G(s, t)$ desde $s$ a $t$ en el grafo original $G$.

Ejecutar Dijkstra desde $s$ para obtener $d_G(s, v)$ para todos los nodos $v$ en $G$.

Ejecutar Dijkstra desde $t$ en el grafo transpuesto para obtener $d_G(v, t)$ para todos los nodos $v$.

**Evaluar cada arista de $E$**: Para cada arista $e = (u, v) \in E$ con peso $w(e)$, verifica si $e$ puede mejorar el camino de $s$ a $t$. Esto se logra comprobando si la distancia $d_G(s, u) + w(e) + d_G(v, t)$ es menor que $d_G(s, t)$.

Una arista $e = (u, v)$ mejora el camino si:

$$d_G(s, u) + w(e) + d_G(v, t) < d_G(s, t)$$

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

vector<Edge> findImprovingEdges(int n, vector<Edge>& edges, int s, int t) {
    vector<vector<pair<int, int>>> adj(n), adj_transposed(n);
    for (const auto& edge : edges) {
        adj[edge.from].push_back({edge.to, edge.weight});
        adj_transposed[edge.to].push_back({edge.from, edge.weight});
    }

    vector<int> dist_from_s = dijkstra(n, adj, s);

    vector<int> dist_to_t = dijkstra(n, adj_transposed, t);

    int original_distance = dist_from_s[t];

    vector<Edge> improving_edges;

    for (const auto& edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int weight = edge.weight;

        if (dist_from_s[u] != INT_MAX && dist_to_t[v] != INT_MAX) {
            int new_distance = dist_from_s[u] + weight + dist_to_t[v];
            if (new_distance < original_distance) {
                improving_edges.push_back(edge);
            }
        }
    }

    return improving_edges;
}
```

**Dijkstra garantiza caminos mínimos**: El algoritmo de Dijkstra encuentra correctamente las distancias mínimas desde \$s$ y $t$ (en el grafo transpuesto) para todos los nodos.

**Condición de mejora**: Verificar que $d_G(s, u) + w(e) + d_G(v, t) < d_G(s, t)$ asegura que la arista $e$ proporciona un camino más corto que el original.