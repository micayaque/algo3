Sea $G$ un digrafo con pesos positivos que tiene dos vértices especiales $s$ y $t$.

Decimos que una arista $e \in E(G)$ es crítica para $s$ y $t$ cuando $d_G (s, t) \lt d_{G−e} (s, t)$. 

Diseñar un algoritmo eficiente que, dado $G$, determine las aristas de $G$ que son críticas para $s$ y $t$. 

Demostrar que el algoritmo es correcto. 

Ayuda: pensar en el subgrafo $P$ de $G$ que está formado por las aristas de caminos
mínimos de $G$ (el “grafo de caminos mínimos”).

**Construir el grafo de caminos mínimos ($P$):** 

Correr Dijkstra desde $s$, para calcular $d_G(s, v)$ para todos los nodos $v$ del grafo. $O((n+m)log(n))$

Guardar el camino mínimo de $s$ a $t$.

Correr Dijkstra desde $t$, en el grafo traspuesto para calcular $d_G(v, t)$ para todos los nodos $v$ del grafo.

Identificar todas las aristas que pertenecen a algún camino mínimo de $s$ a $t$. Estas aristas formarán el subgrafo $P$ del grafo $G$.

Para cada arista $(u,v)$ chequear si $d_G(s, u) + d_G(v, t) + w(u,v) = d_G(s, t)$, si se cumple, la arista pertenece a algún camino mínimo. $O(m)$

**Determinar aristas críticas:**

Las aristas críticas serán las aristas puentes de $P$. $O(n+m)$

### Demostración:

$e=(u,v)$ arista puente en $P$ ($DAG$ de caminos mínimos en $G$ desde $s$) $\Leftrightarrow$ $e$ es una arista crítica de $G: d_G(s, t) \lt d_{G-e}(s, t)$

$\Rightarrow$ Supongamos que $e$ no es crítica, entonces $d_G(s, t) = d_{G-e}(s, t)$

Notamos que no puede suceder $d_G(s, t) \gt d_{G-e}(s, t)$ pues $d_G(s, t)$ es el camino mínimo entre $s$ y $t$ en $G$, y al quitar una arista, el camino mínimo no puede ser menor.

Luego $d_G(s, t) = d_{G-e}(s, t)$, y como $e$ no es crítica, existe algún camino mínimo de $s$ a $t$ en $G$ que no pasa por $e$.

Lo que implica que $e$ no sería puente en $P$. Absurdo.

$\Leftarrow$ Supongamos que $e$ es una arista crítica de $G$, entonces $d_G(s, t) \lt d_{G-e}(s, t)$

Notamos que no puede suceder $d_G(s, t) \gt d_{G-e}(s, t)$ pues $d_G(s, t)$ es el camino mínimo entre $s$ y $t$ en $G$, y al quitar una arista, el camino mínimo no puede ser menor.

Luego $d_G(s, t) \lt d_{G-e}(s, t)$, y como $e$ es crítica, no existe ningún camino mínimo de $s$ a $t$ en $G$ que no pase por $e$.

Lo que implica que $e$ es puente en $P$.

$\blacksquare$