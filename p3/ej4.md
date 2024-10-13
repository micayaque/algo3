ArteConexo
---

Un vértice $v$ de un grafo $G$ es un **punto de articulación** si $G − v$ tiene más componentes conexas que $G$.

Por otro lado, un grafo es **biconexo** si es conexo y no tiene puntos de articulación.

a) Demostrar, usando $\color{violet}\text{inducción en la cantidad de vértices}$, que todo grafo de $n$ vértices que tiene más de $\frac{(n − 1)(n − 2)}{2}$ aristas es conexo.

Caso base: $n=2$ con $1$ arista. $G$ es conexo.

Caso inductivo: $n \gt 2$. 

Hipótesis inductiva: Todo grafo $G_n$ de $n$ vértices y más de $\frac{(n-1)(n-2)}{2} = m$  aristas, es conexo.

Queremos demostrar que todo grafo $G_{n+1}$ con $n+1$ vértices y más de $\frac{n(n-1)}{2} = m'$ aristas es conexo.

Sabemos que $m' \gt \frac{n(n-1)}{2}$

Si eliminamos un vértice $v$ de $G_{n+1}$, obtenemos un grafo $G_n$ con $n$ vértices y $m''$ aristas, donde $m'' = m' - d(v)$, siendo $d(v)$ el grado del vértice $v$.

Por lo tanto, tenemos dos casos:

$\color{lime}\text{Caso: } m'' \gt \frac{(n-1)(n-2)}{2}$

Por hipótesis inductiva, $G_n$ es conexo.

$\color{lime}\text{Caso: } m'' \le \frac{(n-1)(n-2)}{2}$

Entonces $m' \le \frac{n(n-1)}{2}$, no cumple las hipótesis. Por lo tanto, la propiedad también es verdadera en este caso.

Por lo tanto, todo grafo de $n$ vértices que tiene más de $\frac{(n − 1)(n − 2)}{2}$ aristas es conexo. $\square$