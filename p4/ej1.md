Recorridos en profundidad
---

#### Sea $\text{T}$ un árbol generador de un grafo (conexo) $\text{G}$ con raíz $\text{r}$, y sean $\text{V}$ y $\text{W}$ los vértices que están a $\color{violet}\text{distancia par e impar de r}$, respectivamente.

#### a) Observar que si existe una arista $\text{vw} \in \text{E(G) } \backslash \text{E(T) tal que v, w} \in \text{ V o v, w} \in \text{W, entonces el único ciclo de T} \cup \{vw\} \text{ tiene longitud impar}$.

![alt text](/img/image19.png)

(La demostración no se pedía en el enunciado pero sería algo como esto:)

Tenemos que probar dos cosas:
Una es que el $\color{violet}\text{ciclo es único}$ y la otra es que la $\color{cyan}\text{longitud del ciclo es impar}$.

Para probar que el $\color{violet}\text{ciclo es único}$, sabemos que $\text{T es un árbol generador}$ de un grafo $\text{G}$. 

Por lo tanto, las aristas que no están en $\text{T}$ son las que $\text{forman ciclos}$. 

Si tomamos una arista $\text{vw}$ que no está en $\text{T}$ vamos a formar un ciclo en $\text{T} \cup \text{vw}$. 

Y este $\color{violet}\text{ciclo es único}$ porque si hubiera otro ciclo, entonces $\text{T}$ no sería un árbol generador.

Ahora para probar que $\color{cyan}\text{longitud del ciclo es impar}$ vamos a hacer un análisis por casos.

$\color{red} \text{Caso v, w} \in \text{V:}$

La distancia entre $\text{r}$ y $\text{v}$ es $\text{par}$ y la distancia entre $\text{r}$ y $\text{w}$ es par.

Sabemos que $\text{v}$ tiene un camino a $\text{r}$ por lo que $\text{r}$ forma parte del ciclo. 

Lo mismo pasa con $\text{w}$.

Por lo tanto, el ciclo tiene $\text{longitud = distancia(v, r) + distancia(r, w) + 1 = par + par + 1 = impar}$.

Se suma $\text{1}$ porque nos falta unir a la arista $\text{vw}$.


$\color{red}\text{Caso v, w} \in \text{W:}$

La distancia entre $\text{r}$ y $\text{v}$ es impar y la distancia entre $\text{r}$ y $\text{w}$ es impar. 

Sabemos que $\text{v}$ tiene un camino a $\text{r}$ por lo que $\text{r}$ forma parte del ciclo. 

Lo mismo pasa con $\text{w}$. 

Por lo tanto, el ciclo tiene $\text{longitud = distancia(v, r) + distancia(r, w) + 1 = impar + impar + 1 = impar}$.


#### b) Observar también que si toda arista de $\text{E(G)} \backslash \text{E(T)}$ une un vértice de $\text{V}$ con otro de $\text{W}$, entonces $\text{(V, W)}$ es una bipartición de $\text{G}$ y, por lo tanto, $\text{G}$ es $\color{violet}\text{bipartito}$.

Es la definición de bipartito.

Un grafo es bipartito si y solo si sus vértices se pueden dividir en dos conjuntos disjuntos tales que no hay aristas que unan dos vértices del mismo conjunto.

Los conjuntos $\text{V}$ y $\text{W}$ representan estos dos conjuntos disjuntos, dado que uno contiene vértices a distancia par de la raíz $\text{r}$ y el otro a distancia impar.

#### c) A partir de las observaciones anteriores, diseñar un algoritmo lineal para determinar si un grafo conexo $\text{G}$ es bipartito.
#### En caso afirmativo, el algoritmo debe retornar una bipartición de $\text{G}$.
#### En caso negativo, el algoritmo debe retornar un ciclo impar de $\text{G}$.
#### Explicitar cómo es la implementación del algoritmo; no es necesario incluir el código.

Propiedad del grafo bipartito: 

Dada la estructura de $\text{V}$ y $\text{W}$, cualquier ciclo en el grafo debe alternar entre vértices de estos conjuntos, lo cual es posible únicamente si el ciclo tiene longitud par. 

La existencia de una arista que conecte vértices dentro del mismo conjunto ($\text{V}$ o $\text{W}$) introduciría un ciclo impar, contradiciendo la premisa de que todas las aristas fuera del árbol generador conectan $\text{V}$ con $\text{W}$.

Definition (Lema): Sean $\text{u, v} \in \text{V : (u, v) } \in E$.

G es bipartito $\Leftrightarrow$ no hay ningún ciclo impar.

Podemos aplicar una modificación de DFS para construir una bipartición $\text{(V, W)}$ o detectar un ciclo impar en caso de que no sea bipartito. 

Inicialización:
   - Crear dos conjuntos vacíos $\text{V}$ y $\text{W}$, los cuales almacenarán los vértices a distancia par e impar de la raíz respectivamente.
   - Asignar una etiqueta inicial a la raíz $\text{r}$ del grafo.
   - Crear un arreglo $\text{colores[]}$ para mantener el estado del color de cada vértice (0, 1 o no visitado).

DFS:
   - Iniciar DFS desde la raíz $\text{r}$, coloreándola en 0 (distancia par).
   - Para cada vértice $\text{v}$, si el vértice adyacente $\text{u}$ aún no ha sido visitado, coloréalo con el color opuesto al de $\text{v}$ y realizar la llamada recursiva para $\text{u}$.
   - Si se encuentra una arista entre dos vértices con el mismo color, entonces hay un ciclo impar. Se devuelve este ciclo y se concluye que el grafo no es bipartito.

Finalización:
   - Si terminas el recorrido sin encontrar aristas que unan vértices del mismo conjunto, $\text{G}$ es bipartito, y podes devolver la bipartición $\text{(V, W)}$.

```C++
#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;

vector<int> ciclo;  // para almacenar el ciclo impar si lo encontramos

bool dfs(int v, int color, vector<int>& colores, const vector<vector<int>>& G, vector<int>& predecesor, set<int>& V, set<int>& W) {
    colores[v] = color;
    if (color == 0) V.insert(v);
    else W.insert(v);

    for (int vecino : G[v]) {
        if (colores[vecino] == -1) {  // si el vecino no ha sido visitado
            predecesor[vecino] = v; 
            if (!dfs(vecino, 1 - color, colores, G, predecesor, V, W)) {
                return false;
            }
        } else if (colores[vecino] == colores[v]) {  // si encontramos un vecino con el mismo color (ciclo impar)
            // reconstruir el ciclo impar
            ciclo.push_back(vecino);
            for (int actual = v; actual != vecino; actual = predecesor[actual]) {
                ciclo.push_back(actual);
            }
            ciclo.push_back(vecino);  // cerramos el ciclo
            return false;
        }
    }
    return true;
}

pair<bool, vector<int>> es_bipartito(const vector<vector<int>>& G) {
    int n = G.size();
    vector<int> colores(n, -1);
    vector<int> predecesor(n, -1);
    set<int> V, W;

    for (int v = 0; v < n; ++v) {
        if (colores[v] == -1) {  // si no ha sido visitado
            if (!dfs(v, 0, colores, G, predecesor, V, W)) {
                return {false, ciclo};
            }
        }
    }

    return {true, vector<int>{}};
}
```