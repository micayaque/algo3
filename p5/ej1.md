Dado un digrafo $D$ con pesos $c : E(D) \to N$ y dos vértices $s$ y $t$, decimos que una arista $v \to w$ es $\text{st-eficiente}$ cuando $v \to w$ pertenece a algún camino mínimo de $s$ a $t$. 

Sea $d(·, ·)$ la función que indica el peso de un camino mínimo entre dos vértices.

$a.$ Demostrar que $v \to w$ es $\text{st-eficiente}$ si y sólo si $d(s, v) + c(v \to w) + d(w, t) = d(s, t)$.

Queremos ver que $v \to w$ es $\text{st-eficiente} \Leftrightarrow d(s, v) + c(v \to w) + d(w, t) = d(s, t)$.

$\Rightarrow)$

Supongamos que $v \to w$ es $\text{st-eficiente}$. Esto significa que existe un camino mínimo $P$ de $s$ a $t$ que pasa por $v \to w$.

Podemos descomponer este camino $P$ como $P = P_1 \cup (v \to w) \cup P_2$, donde $P_1$ es el subcamino de $s$ a $v$ y $P_2$ es el subcamino de $w$ a $t$.

Por definición de camino mínimo, tenemos que $d(s, t) = d(s, v) + c(v \to w) + d(w, t)$.

$\Leftarrow)$

Supongamos que $d(s, v) + c(v \to w) + d(w, t) = d(s, t)$.

Entonces existe un camino de $s$ a $t$ que pasa por $v \to w$ y tiene el mismo costo que el camino mínimo de $s$ a $t$.

Por lo tanto, $v \to w$ forma parte de al menos un camino mínimo de $s$ a $t$.

Es decir, es `st-eficiente`.

$b.$ Usando el inciso anterior, proponga un algoritmo eficiente que encuentre el mínimo de los caminos entre $s$ y $t$ que no use aristas $\text{st-eficiente}$. 

Si dicho camino no existe, el algoritmo retorna $\bot$.

1. Ejecutar Dijkstra desde $s$ para obtener $d(s, v)$ para todos los vértices $v$.

2. Ejecutar Dijkstra desde $t$ en el grafo transpuesto para obtener $d(w, t)$ para todos los vértices $w$.

3. Recorrer cada arista $v \to w$ del digrafo $D$. Si $\color{red}d(s, v) + c(v \to w) + d(w, t) = d(s, t)$, marcar $v \to w$ como $\color{red}\text{st-eficiente}$.

3. Crear un nuevo grafo $D'$ eliminando todas las aristas marcadas como $\text{st-eficiente}$.

5. Ejecutar Dijkstra en $D'$ desde $s$ para encontrar el camino mínimo a $t$. Si $t$ es alcanzable desde $s$ en $D'$, devuelve el camino y su peso. Si $t$ no es alcanzable, devuelve $bot$.

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

void remove_st_efficient_edges(vector<Edge>& edges, vector<int>& d_s, vector<int>& d_t, int d_st) {
    edges.erase(
        remove_if(edges.begin(), edges.end(), [&](Edge& e) {
            return d_s[e.from] + e.weight + d_t[e.to] == d_st;
        }),
        edges.end()
    );
}

int main() {
    int n, m, s, t;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n), adj_transposed(n);
    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj_transposed[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    cin >> s >> t;

    //dijkstra desde s
    vector<int> d_s = dijkstra(n, adj, s);

    //dijkstra desde t en el grafo transpuesto
    vector<int> d_t = dijkstra(n, adj_transposed, t);

    //identificar y eliminar aristas st-eficientes
    int d_st = d_s[t];
    remove_st_efficient_edges(edges, d_s, d_t, d_st);

    //reconstruir el grafo sin aristas st-eficientes
    vector<vector<pair<int, int>>> adj_prime(n);
    for (const auto& e : edges) {
        adj_prime[e.from].push_back({e.to, e.weight});
    }

    //buscar el camino mínimo en el grafo modificado
    vector<int> d_prime_s_t = dijkstra(n, adj_prime, s);
    if (d_prime_s_t[t] == INT_MAX) {
        cout << char(194) << endl;
    } else {
        cout << d_prime_s_t[t] << endl;
    }

    return 0;
}
```