### Problemas de modelado I: caminos disjuntos en un grafo

Sea $G$ un digrafo con dos vértices $s$ y $t$.

> $a)$ Proponer un modelo de flujo para determinar la máxima cantidad de caminos disjuntos en aristas que van de $s$ a $t$.

El objetivo es encontrar la **máxima cantidad de caminos disjuntos en aristas** que conecten $s$ y $t$.

El problema puede modelarse como un problema de flujo máximo en una red:

1. Construir una red de flujo $G$ con:
   - Los mismos nodos del digrafo $G$.
   - Las mismas aristas de $G$, cada una con capacidad $c(u, v) = 1$.

2. Definir un flujo $f(u, v)$ en cada arista:
   - $0 \leq f(u, v) \leq c(u, v) = 1$.
   - Para cada nodo $v \neq s, t$, la suma del flujo entrante es igual a la suma del flujo saliente:
    $$\sum_{u \in V} f(u, v) = \sum_{w \in V} f(v, w)$$

3. El flujo total $F$, que queremos maximizar, es:

$$F = \sum_{(s, v) \in E} f(s, v)$$
es decir, la suma del flujo saliente de $s$.

Este modelo asegura que cada unidad de flujo corresponde a un camino de $s$ a $t$ y que cada arista puede usarse como máximo una vez.

> $b)$ Dar una interpretación a cada unidad de flujo y cada restricción de capacidad.

Cada unidad de flujo $f(u, v) = 1$ representa una arista utilizada en un camino de $s$ a $t$.

Por lo tanto, el flujo total $F$ corresponde al número de caminos disjuntos en aristas que conectan $s$ y $t$.

**La restricción de capacidad $0 \leq f(u, v) \leq 1$** garantiza que cada arista se utilice como máximo una vez en todos los caminos disjuntos.

- **La restricción de conservación de flujo** asegura que los caminos sean válidos, es decir, que el flujo que entra a un nodo también salga de él, excepto en $s$ (fuente) y $t$ (sumidero).

> $c)$ Demostrar que el modelo es correcto.

**Correspondencia entre flujo y caminos disjuntos**:
- Un flujo de valor $F$ en esta red garantiza $F$ caminos disjuntos en aristas porque:
    - La capacidad de cada arista es $1$, por lo que cada arista puede usarse en un único camino.
     - La conservación de flujo asegura que las unidades de flujo forman caminos completos desde $s$ a $t$.

**Máximo flujo = Máximo número de caminos disjuntos**:
   - Por el **teorema de flujo máximo-corte mínimo**, el flujo máximo en la red es igual al valor del corte mínimo.
   - En este modelo, un corte mínimo corresponde a las aristas críticas que separan $s$ de $t$, lo cual también define el número máximo de caminos disjuntos posibles.

Por lo tanto, el modelo captura correctamente el problema de determinar la máxima cantidad de caminos disjuntos en aristas de $s$ a $t$.

> $d)$ Determinar la complejidad de resolver el modelo resultante con el algoritmo de Edmonds y Karp.

El algoritmo de Edmonds-Karp tiene una complejidad de $O(nm^2)$, donde:
- $n$: Número de nodos.
- $m$: Número de aristas.

En cada iteración, Edmonds-Karp realiza una búsqueda en anchura (BFS) para encontrar un camino aumentante.

Dado que cada arista tiene capacidad $1$, el flujo total $F$ estará acotado por el número de aristas salientes desde $s$, es decir, $F \leq m$.

Por lo tanto, el número de iteraciones es $O(nm)$, y el costo por iteración es $O(m)$.

**Complejidad total**:
$$O(nm^2)$$