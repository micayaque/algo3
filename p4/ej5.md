Un árbol generador $\text{T}$ de un grafo $\text{G}$ es $\text{v-geodésico}$ si la distancia entre $\text{v}$ y $\text{w}$ en $\text{T}$ es igual a la distancia entre $\text{v}$ y $\text{w}$ en $\text{G}$ para todo $\text{w} \in \text{V (G)}$.

Demostrar que todo árbol $\text{BFS}$ de $\text{G}$ enraizado en $\text{v}$ es $\text{v-geodésico}$.

Dar un contraejemplo para la vuelta, i.e., mostrar un árbol generador $\text{v-geodésico}$ de un grafo $\text{G}$ que no pueda ser obtenido cuando $\text{BFS}$ se ejecuta en $\text{G}$ desde $\text{v}$.


Por absurdo.

Suponemos que existe algún vértice $\text{w} \in \text{V(G)}$ tal que la distancia entre $\text{v}$ y $\text{w}$ en $\text{T}$ es distinta a la distancia entre $\text{v}$ y $\text{w}$ en $\text{G}$.

Tenemos dos casos:

$\color{violet}\text{Caso distancia(v, w) en T < distancia(v, w) en G}$

Es absurdo porque la distancia la distancia entre $\text{v}$ y $\text{w}$ en $\text{G}$ es la mínima.

$\color{violet}\text{Caso distancia(v, w) en T > distancia(v, w) en G}$

Por definición de $\text{BFS}$ sabemos que $\text{v}$ es el nodo raíz de $\text{T}$, por lo que es el primer vértice visitado en el algoritmo $\text{BFS}$, la distancia entre $\text{v}$ y $\text{v}$ es $\text{0}$.

Luego, los nodos adyacentes a $\text{v}$ son los nodos que están a distancia $\text{1}$ de $\text{v}$ en $\text{G}$, por lo que la distancia entre $\text{v}$ y sus adyacentes es $\text{1}$.

De manera general, recorremos a $\text{N(v)}$ y para cada nodo $\text{w} \in \text{N(v)}$ la distancia entre $\text{v}$ y $\text{w}$ es la distancia entre $\text{v}$ y el padre de $\text{w + 1}$.

Por lo tanto, la distancia entre $\text{v}$ y $\text{w}$ en $\text{T}$ es igual a la distancia entre $\text{v}$ y $\text{w}$ en $\text{G}$ para todo $\text{w} \in \text{V(G)}$.

$\square$
