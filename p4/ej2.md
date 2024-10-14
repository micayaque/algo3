Una arista de un grafo G es $\color{violet}\text{puente}$ si su remoción aumenta la cantidad de componentes conexas
de $\text{G}$.

Sea $\text{T}$ un árbol $\text{DFS}$ de un grafo conexo $\text{G}$.


### $\text{a)}$ Demostrar que $\text{vw}$ es un puente de $\text{G}$ si y solo si $\text{vw}$ no pertenece a ningún ciclo de $\text{G}$.

Queremos demostrar que:

$\text{vw}$ es un puente de $\text{G} \Leftrightarrow \text{vw}$ no pertenece a ningún ciclo de $\text{G}$

$\Rightarrow$)

$\text{vw}$ es un puente de $\text{G} \Rightarrow \text{vw}$ no pertenece a ningún ciclo de $\text{G}$

Podemos probarlo usando reducción al absurdo.

Idea: Para probar que $\alpha \rightarrow \beta$ vamos a asumir que valen $\alpha \text{ y } \neg \beta$, para ver luego que esto contradice algún resultado previo.

Supongamos que $\text{vw}$ es puente de $\text{G}$ y que $\text{vw}$ pertenece a un ciclo de $\text{G}$.

Si $\text{vw}$ pertenece a un ciclo de $\text{G}$, supongamos que para formar al grafo $\text{G}$ tenemos al conjunto de vértices que tiene un camino hacia $\text{v}$ $G_1$, a los vértices que tienen un camino hacia $\text{w}$ $G_2$ y a los vértices que pertenecen al ciclo de $\text{vw}$. 

Al remover $\text{vw}$ de $\text{G}$, como $\text{vw}$ pertenece a un ciclo, los vértices de $G_1$ que tienen un camino hacia $\text{v}$, seguirán teniéndo conexión con el vértice $\text{w}$, y los vértices de $G_2$ que tienen un camino hacia $\text{w}$, seguirán teniéndo conexión con el vértice $\text{v}$ simplemente porque pueden tomar alguna otra arista del ciclo.

Pero si al quitar $\text{vw}$ de $\text{G}$, el grafo sigue teniendo caminos entre todo par de vértices entonces $\text{vw}$ no es puente de $\text{G}$, lo cual es una contradicción.

$\Leftarrow$)

$\text{vw}$ no pertenece a ningún ciclo de $\text{G} \Rightarrow \text{vw}$ es un puente de $\text{G}$

(Por absurdo de nuevo)

Supongamos que $\text{vw}$ no pertenece a ningún ciclo de $\text{G}$ y que $\text{vw}$ no es puente de $\text{G}$.

Si $\text{vw}$ no es puente de $\text{G}$, entonces al remover $\text{vw}$ de $\text{G}$, el grafo sigue siendo conexo.

Pero sabemos que $\text{vw}$ no pertenece a ningún ciclo de $\text{G}$, entonces al quitar $\text{vw}$ de $\text{G}$, los vértices que tenían un camino a $\text{v}$ van a dejar de tener conexión con $\text{w}$ y los vértices que tenían un camino a $\text{w}$ van a dejar de tener conexión con $\text{v}$.

Por lo tanto, si $\text{vw}$ no es puente debería haber más de un camino hacia $\text{v}$ o hacia $\text{w}$, lo cual es una contradicción porque $\text{vw}$ no pertenece a ningún ciclo.

$\square$

### $\text{b)}$ Demostrar que si $\text{vw} \in \text{E(G)} \backslash \text{E(T)}$, entonces $\text{v}$ es un ancestro de $\text{w}$ en $\text{T}$ o viceversa ($\text{w}$ es un ancestro de $\text{v}$).

Sea $\text{T}$ un árbol $\text{DFS}$ de un grafo conexo $\text{G}$.

Queremos demostrar que $\text{vw} \in \text{E(G)} \backslash \text{E(T)} \Rightarrow \text{v}$ es un ancestro de $\text{w}$ en $\text{T}$ o viceversa ($\text{w}$ es un ancestro de $\text{v}$).

Si $\text{vw}$ no está en el árbol $\text{DFS}$, entonces es porque $\text{vw}$ forma un ciclo en el grafo $\text{G}$.

Entonces existe un camino simple $\text{C}$ en $\text{G}$ que conecta a $\text{v}$ con $\text{w}$ y que no pasa por $\text{vw}$.

Supongamos que el $\text{DFS}$ visitó primero al vértice $\text{v}$. El otro caso es análogo.

Como existe el camino simple $\text{C}$ entre $\text{v}$ y $\text{w}$, el $\text{DFS}$ va a explorar este camino hasta encontrar una hoja o hasta encontrar una backedge.

En el proceso puede suceder que primero visitamos otros vértices vecinos de $\text{v}$ antes de continuar por el camino $\text{C}$.

Pero solo nos interesa observar que cada vez que avanzamos por alguna arista de $\text{C}$, estamos en la misma rama del árbol.

Por lo tanto, $\text{v}$ es un ancestro de $\text{w}$ en $\text{T}$.

$\square$

### c) Sea $\text{vw} \in \text{E(G)}$ una arista tal que el nivel de $\text{v}$ en $\text{T}$ es menor o igual al nivel de $\text{w}$ en $\text{T}$.

### Demostrar que $\text{vw}$ es puente si y solo si $\text{v}$ es el padre de $\text{w}$ en $\text{T}$ y ninguna arista de $\text{G} \backslash \{\text{vw}\}$ une a un descendiente de $\text{w}$ (o a $\text{w}$) con un ancestro de $\text{v}$ (o con $\text{v}$).

Queremos demostrar que $\text{vw}$ es puente $\Leftrightarrow$ $\text{v}$ es el padre de $\text{w}$ en $\text{T}$ y ninguna arista de $\text{G} \backslash \{\text{vw}\}$ une a un descendiente de $\text{w}$ (o a $\text{w}$) con un ancestro de $\text{v}$ (o con $\text{v}$).

Dichas aristas se llaman backedges.

$\Rightarrow$)

Queremos demostrar que: $\text{vw}$ es puente $\Rightarrow$ $\text{v}$ es el padre de $\text{w}$ en $\text{T}$ y ninguna arista de $\text{G} \backslash \{\text{vw}\}$ une a un descendiente de $\text{w}$ (o a $\text{w}$) con un ancestro de $\text{v}$ (o con $\text{v}$).

Suponemos que existe una arista de $\text{G} \backslash \{\text{vw}\}$ que une a un descendiente de $\text{w}$ (o a $\text{w}$) con un ancestro de $\text{v}$ (o con $\text{v}$) (osea una backedge).

Entonces existe un camino simple entre $\text{v}$ y $\text{w}$ que no pasa por $\text{vw}$.

Osea que existe un ciclo $\text{C}$ en $\text{G}$ que contiene a $\text{vw}$.

Absurdo porque $\text{vw}$ es puente así que no puede ser parte de un ciclo.

Por lo tanto como $\text{vw}$ es puente, $\text{vw} \in \text{T}$ y $\text{v}$ es el padre de $\text{w}$ en $\text{T}$.

$\Leftarrow$)

Queremos demostrar que: $\text{v}$ es el padre de $\text{w}$ en $\text{T}$ y ninguna arista de $\text{G} \backslash \{\text{vw}\}$ une a un descendiente de $\text{w}$ (o a $\text{w}$) con un ancestro de $\text{v}$ (o con $\text{v}$) $\Rightarrow$ $\text{vw}$ es puente.

Supongamos que $\text{vw}$ no es puente.

Entonces, $\text{vw}$ pertenece a un ciclo.

Como no existen las backedges, necesariamente existe un camino simple que conecta a $\text{v}$ con $\text{w}$ que no pasa por $\text{vw}$.

Sean $\text{u}$ y $\text{z}$ los vértices que están adyacentes a $\text{v}$ y $\text{w}$ en el ciclo y que además están en otra rama del árbol.

Como $\text{uv}$ no está en el árbol, entonces $\text{u}$ es un ancestro de $\text{v}$ o viceversa. (inciso b))

Absurdo porque $\text{u}$ y $\text{z}$ están en otra rama del árbol.

Por lo tanto, $\text{vw}$ es puente.

$\square$

### d) Dar un algoritmo lineal basado en $\text{DFS}$ para encontrar todas las aristas puente de $\text{G}$.

### Ayuda: el algoritmo puede hacer un uso inteligente de un único DFS. Conceptualmente, y a los efectos de este ejercicio, puede convenir separar el algoritmo en dos fases.

Una arista es puente si al sacarla aumenta la cantidad de
componentes conexas

Una back-edge nunca puede ser puente

Las aristas que son puentes son aquellas tree-edges que no tienen una back-edge que las “cubra”

![alt text](/img/image17.png)

Primero debemos convencernos de que la cantidad de backedges que cubren la arista entre $\text{v}$ y su padre se puede calcular de la siguiente manera:

```math
\text{cubren(v) = backEdgesConExtremoInferiorEn(v)
− backEdgesConExtremoSuperiorEn(v) +}
\sum_{w \in hijos(v)} \text{cubren(w)}
```
Veamos un ejemplo.

Los números al lado de los nodos indican el valor de cubren en dicho nodo.

Si cubren de un nodo $\text{v}$ es $\text{0}$ significa que la arista de $\text{v}$ al padre es puente.

Ahora si corremos un $\text{DFS}$ que de alguna manera calcule para cada nodo `backConExtremoInferiorEn` y `backConExtremoSuperiorEn`. 

Puede ser algo asi:

```C++
vector<vector<int>> treEdges;   //init en []
...
void dfs(int v, int p=-1){
    estado[v] = 1 = EMPECE_A_VER;
    for(int u : aristas[v]){
        if(estado[u] == NO_LO_VI){
            treEdges[v].push_back(u);
            dfs(u, v);
        } else if(u != p){
            backConExtremoInferiorEn[v]++;
            backConExtremoSuperiorEn[u]++;
        }
    }
    estado[v] = TERMINE_DE_VER;
}
```

En este $\text{DFS}$ si ya pasé por un nodo y no es el padre entonces sumo una backedge.

Notar que en esta implementación de $\text{DFS}$ se asume que los nodos tienen tres estados: no lo vi, empecé a ver y terminé de ver

Hacemos un algoritmo que calcule cubren con programación dinámica ya que tenemos superposición de subproblemas (siempre para cubren de $\text{v}$ necesito cubren de los hijos).

```C++
vector<int> memo;   //init en -1
int cubren(int v, int p=-1){
    if(memo[v] != -1) return memo[v];
    int res = 0;
    res += backConExtremoInferiorEn[v];
    res -= backConExtremoSuperiorEn[v];
    for(int hijo : treEdges[v]){
        if(hijo != p){
            res += cubren(hijo, v);
        }
    }
    memo[v] = res;
    return res;
}
```

Y ahora finalmente solo necesito calcular cuántos puentes nos quedan, que es la cantidad de nodos $\text{v}$ tal que $\text{cubren(v) = 0}$.

```C++
int puentes = 0;
for(int i = 0; i < n; i++){
    if(cubren(i) == 0){
        puentes++;
    }
}
```

OJO nos falta restar la cantidad de componentes ya que como vimos en los ejemplos la raı́z de los árboles también tiene $\text{cubren = 0}$.

`puentes -= componentesConexas`

Complejidad?

DFS: $\text{O(n+m)}$

cubren: $\text{O(n)}$ ya que como máximo llenamos el vector de
memoización

puentes: $\text{O(n)}$ porque recorro el vector cubren que tiene longitud `cant nodos`
