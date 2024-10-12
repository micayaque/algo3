Equilibrio Digrafo
---
Demostrar, usando inducción en la cantidad de aristas, que todo digrafo $D$ satisface:

```math
\sum_{v\in V(D)}^{} d_{in}(v) = \sum_{v\in V(D)}^{} d_{out}(v) = |E(D)|
```

`Caso base: |E(D)|=1`

Si tenemos una sola arista, hay un vértice desde donde sale y otro donde llega, por lo que:

```math
\sum_{v\in V(D)}^{} d_{in}(v) = 1 = \sum_{v\in V(D)}^{} d_{out}(v) = 1 = 1
```

```math
1 = 1 = 1
```

$\therefore$ el caso base se cumple

`Paso inductivo: |E(D)|=k+1`

Hipótesis inductiva:

```math
\sum_{v\in V(D)}^{} d_{in}(v) = \sum_{v\in V(D)}^{} d_{out}(v) = k
```

Queremos demostrar que:

```math
\sum_{v\in V(D)}^{} d_{in}(v) = \sum_{v\in V(D)}^{} d_{out}(v) = k+1
```

Si agregamos una arista al digrafo con $k$ aristas vamos a tener otro digrafo $D_{k+1}$ en donde haya dos vértices unidos por esa arista nueva, entonces:

```math
\sum_{v\in V(D_{k+1})}^{} d_{in}(v) = \sum_{v\in V(D_{k+1})}^{} d_{out}(v) = |E(D_{k+1})|
```

Una arista está formada por un nodo $s$ y un nodo $t$ y de esta forma $d(u)$ y $d(v)$ van a incrementarse en $1$ por lo que si le sacamos la arista $<s,t>$ al digrafo $D_{k+1}$::

```math
\sum_{v\in V(D_{k})}^{} d_{in}(v) + 1 = \sum_{v\in V(D_{k})}^{} d_{out}(v) + 1 = k+1
```

```math
\sum_{v\in V(D)}^{} d_{in}(v) = \sum_{v\in V(D)}^{} d_{out}(v) = k
```

Vale por hipótesis inductiva. $\square$

