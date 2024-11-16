Diseñar un algoritmo eficiente que, dado un digrafo $G$ con pesos no negativos, dos vértices $s$ y $t$ y una cota $c$, determine una arista de peso máximo de entre aquellas que se encuentran en algún recorrido de $s$ a $t$ cuyo peso (del recorrido, no de la arista) sea a lo sumo $c$. Demostrar que el algoritmo propuesto es correcto.

Correr Dijkstra para encontrar todos los caminos de $s$ a $t$ con peso total a lo sumo $c$. Durante el recorrido, mantener un registro de la arista de peso máximo vista en cada camino.
   
Usar una cola de prioridad para explorar los caminos de menor costo a mayor costo. Registrar el camino actual y la arista de mayor peso encontrada hasta ese punto.

Inicializar una cola de prioridad $PQ$ con el par $(s, 0, -\infty)$, donde $0$ es la distancia acumulada y $-\infty$ representa el peso máximo de la arista (inicialmente no hay ninguna).

Para cada nodo que se extrae de $PQ$ revisa todas las aristas salientes y actualiza la distancia si se encuentra un camino válido (con peso total $\leq c$).

Actualiza el peso máximo de la arista si la arista actual tiene un peso mayor que el registrado.

Termina cuando todos los nodos han sido procesados o la cola está vacía.

```cpp
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to, weight;
};

struct State {
    int node, cost, maxEdgeWeight;
    bool operator<(const State& other) const {
        //la cola de prioridad debe ser un min-heap basado en el costo
        return cost > other.cost;
    }
};

int findMaxEdgeInPath(vector<vector<Edge>>& graph, int s, int t, int c) {
    int n = graph.size();
    vector<int> minCost(n, INT_MAX);
    minCost[s] = 0;

    priority_queue<State> pq;
    pq.push({s, 0, -1});

    int maxEdgeWeight = -1;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (current.node == t) {
            maxEdgeWeight = max(maxEdgeWeight, current.maxEdgeWeight);
            continue;
        }

        for (const Edge& edge : graph[current.node]) {
            int newCost = current.cost + edge.weight;
            int newMaxEdgeWeight = max(current.maxEdgeWeight, edge.weight);

            if (newCost <= c && newCost < minCost[edge.to]) {
                minCost[edge.to] = newCost;
                pq.push({edge.to, newCost, newMaxEdgeWeight});
            }
        }
    }

    return (maxEdgeWeight == -1) ? -1 : maxEdgeWeight;
}
```