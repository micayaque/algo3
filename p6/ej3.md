Determinar la complejidad del algoritmo de Edmonds y Karp para encontrar el flujo máximo de
una red $N$ cuando:

> $a)$ no hay información acerca de las capacidades de las aristas de $N$.

Si no conocemos las capacidades de las aristas, el análisis general se aplica porque no hay restricciones adicionales sobre las capacidades. En este caso, el algoritmo puede requerir hasta $O(nm)$ iteraciones y la complejidad total será:

$$O(nm^2)$$

#### **Pasos del algoritmo**

1. **Buscar un camino aumentante (BFS):**
   - En cada iteración, se realiza una búsqueda en anchura (BFS) en la red residual.
   - La complejidad de un BFS es $O(m)$, donde $m$ es el número de aristas. Esto se debe a que BFS recorre todas las aristas una vez.

2. **Incrementar el flujo:**
   - Se determina el **bottleneck** del camino aumentante (la capacidad residual mínima en el camino encontrado) y se actualizan las capacidades residuales.
   - Esta operación también es $O(m)$, ya que involucra recorrer las aristas del camino.

3. **Repetir el proceso:**
   - Este proceso se repite hasta que no se encuentren más caminos aumentantes en la red residual.

#### **Número de iteraciones (análisis general)**

El número de iteraciones del algoritmo está limitado por $O(nm)$. Esto se debe a lo siguiente:

1. En cada iteración, el flujo en alguna arista del camino aumentante se incrementa hasta alcanzar su capacidad.
2. El flujo total máximo en una red no puede exceder la suma de las capacidades de las aristas que salen de la fuente $s$ o entran al sumidero $t$, denotado como $F$.
3. Cada vez que el algoritmo encuentra un camino aumentante, el flujo enviado a lo largo de ese camino incrementa en al menos $1$ unidad.
4. En el peor caso, pueden ocurrir $O(nm)$ iteraciones porque cada camino aumentante puede saturar una arista, y hay a lo sumo $nm$ actualizaciones posibles.

#### **Complejidad total**

Como cada iteración realiza un BFS y hay a lo sumo $O(nm)$ iteraciones, la complejidad total es:
$$O(nm^2)$$

- El término $O(m)$ viene del costo de ejecutar el BFS en cada iteración.
- El término $O(nm)$ representa el número de iteraciones en el peor caso, que depende de cuántas veces se pueda encontrar un camino aumentante antes de saturar todas las aristas.

> $b)$ todas las aristas de $N$ tienen capacidad a lo sumo $q ≪ n$.

Cuando las capacidades de todas las aristas están acotadas por $q$:

Cada iteración del algoritmo (es decir, cada BFS) sigue teniendo complejidad $O(m)$.

Sin embargo, el número de iteraciones está acotado por el flujo máximo $F$, que ahora está limitado por $q \cdot n$ (la suma de las capacidades en las aristas incidentes a $s$ o $t$).

Esto implica que el número de iteraciones es $O(qn)$, lo que reduce la complejidad total:

$$O(qnm)$$

Todas las capacidades $c(u, v)$ están acotadas por $q$, con $q \ll n$.

$q$ es mucho más pequeño que el número de nodos $n$.

El algoritmo de Edmonds-Karp sigue buscando caminos aumentantes mediante BFS y actualizando el flujo hasta alcanzar el flujo máximo.

En cada iteración, el algoritmo encuentra un camino aumentante que incrementa el flujo en al menos $1$ unidad (el **bottleneck** del camino aumentante será un número entero entre 1 y $q$).

El flujo máximo $F$ está limitado por la suma de las capacidades de las aristas que salen del nodo fuente $s$.

Dado que cada arista tiene capacidad como máximo $q$, y que puede haber hasta $n-1$ aristas saliendo de $s$, el flujo máximo $F$ está acotado por:
$$F \leq q \cdot (n-1) = O(qn)$$

Cada iteración aumenta el flujo en al menos $1$ unidad.

Por lo tanto, el número total de iteraciones está acotado por $F$, que es $O(qn)$.

En cada iteración, se realiza un BFS en la red residual para encontrar un camino aumentante.

El BFS tiene una complejidad de $O(m)$, donde $m$ es el número de aristas.

### **Complejidad total**
$O(\text{iteraciones}) \cdot O(\text{BFS}) = O(qn) \cdot O(m)$

Dado que $m \leq n^2$:
$$O(qnm)$$

* El término $q$ controla el límite superior del flujo máximo, ya que cada arista tiene capacidad a lo sumo $q$. Si $q \ll n$, este límite superior implica que la complejidad total será mucho menor que en el caso general ($O(nm^2)$).

> $c)$ el flujo máximo de $N$ tiene un valor $F ≪ mn$.

Si el flujo máximo $F$ está acotado por $F \ll mn$, esto implica que el número de iteraciones estará limitado por $F$, ya que cada iteración aumenta el flujo en al menos $1$ unidad.

Número de iteraciones: $O(F)$.

Cada BFS tiene una complejidad $O(m)$.

Por lo tanto, la complejidad total es:

$$O(Fm)$$

El algoritmo de Edmonds-Karp es una implementación específica del algoritmo de Ford-Fulkerson que utiliza búsqueda en anchura (BFS) para encontrar caminos aumentantes en la red residual. 

### **Complejidad general del algoritmo de Edmonds-Karp**

En cada iteración, BFS tiene una complejidad de $O(m)$, donde $m$ es el número de aristas. Se puede demostrar que el algoritmo realiza a lo sumo $O(nm)$ iteraciones, donde $n$ es el número de nodos.

**Complejidad total:**  
$$ O(nm^2)$$

Esto es porque cada camino aumentante reduce la capacidad residual de alguna arista saturada en la red residual, lo que garantiza que el número total de iteraciones sea acotado por $O(nm)$.