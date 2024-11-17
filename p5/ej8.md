Un sistema de restricciones de diferencias (SRD) es un sistema $S$ que tiene $m$ inecuaciones y $n$ incógnitas $x_1 , . . . , x_n$. 

Cada inecuación es de la forma $x_i − x_j \leq c_{ij}$ para una constante $c_{ij} \in R$; por cada par $i, j$ existe a lo sumo una inecuación (por qué?). 

> Para cada SRD $S$ se puede definir un digrafo pesado $D(S)$ que tiene un vértice $v_i$ por cada incógnita $x_i$ de forma tal que $v_j \to v_i$ es una arista de peso $c_{ij}$ cuando $x_i − x_j \leq c_{ij}$ es una inecuación de $S$. 

> Asimismo, $S$ tiene un vértice $v_0$ y una arista $v_0 \to v_i$ de peso $0$ para todo $1 \leq i \leq n$.

$a.$ Demostrar que si $D(S)$ tiene un ciclo de peso negativo, entonces $S$ no tiene solución.

Supongamos que $D(S)$ tiene un ciclo de peso negativo. Esto implica que existe un camino cerrado $C$ tal que la suma de los pesos de sus aristas es negativa: $\sum_{(u, v) \in C} c_{uv} < 0$.

Si $S$ tuviera una solución $\{x_1, x_2, \ldots, x_n\}$ que satisface todas las restricciones, entonces al recorrer el ciclo $C$, se tendría:
$$x_{i_1} - x_{i_2} \leq c_{i_1 i_2}, \quad x_{i_2} - x_{i_3} \leq c_{i_2 i_3}, \quad \ldots, \quad x_{i_k} - x_{i_1} \leq c_{i_k i_1}$$

Sumando estas desigualdades, se obtiene:
$$ 0 \leq \sum_{(u, v) \in C} c_{uv}$$

Sin embargo, esto contradice el hecho de que $C$ es un ciclo de peso negativo, ya que la suma de sus pesos es negativa ($\sum_{(u, v) \in C} c_{uv} < 0$).

La existencia de un ciclo de peso negativo en $D(S)$ implica que no es posible asignar valores a $x_1, \ldots, x_n$ que satisfagan todas las inecuaciones, por lo tanto, $S$ no tiene solución.


$b.$ Demostrar que si $D(S)$ no tiene ciclos de peso negativo, entonces $\{x_i = d(v_0, v_i) | 1 \leq i \leq n\}$ es una solución de $D(S)$. Acá $d(v_0 , v_i )$ es la distancia desde $v_0$ a $v_i$ en $D(S)$.

Si $D(S)$ no tiene ciclos de peso negativo, se puede usar el algoritmo de Bellman-Ford desde el vértice $v_0$ para calcular la distancia mínima $d(v_0, v_i)$ a cada $v_i$.

Definimos $x_i = d(v_0, v_i)$ para todo $1 \leq i \leq n$.

Por la definición de las aristas en $D(S)$, para cada arista $v_j \to v_i$ con peso $c_{ij}$, la inecuación $x_i - x_j \leq c_{ij}$ se corresponde con:
$$d(v_0, v_i) \leq d(v_0, v_j) + c_{ij}$$

Esta desigualdad se cumple ya que $d(v_0, v_i)$ es la distancia mínima calculada, y cualquier otro camino no puede dar un valor menor.

Si $D(S)$ no tiene ciclos de peso negativo, entonces las distancias mínimas desde $v_0$ proporcionan una solución que satisface todas las inecuaciones de $S$.


$c.$ A partir de los incisos anteriores, proponer un algoritmo que permita resolver cualquier SRD. En caso de no existir solución, el algoritmo debe mostrar un conjunto de inecuaciones contradictorias entre sí.

Crear un grafo dirigido con $n+1$ vértices, incluyendo el vértice adicional $v_0$.

Añadir una arista $v_0 \to v_i$ de peso 0 para cada $i$.

Para cada inecuación $x_i - x_j \leq c_{ij}$, añadir una arista $v_j \to v_i$ con peso $c_{ij}$.

Ejecutar el algoritmo de Bellman-Ford desde $v_0$ para calcular las distancias $d(v_0, v_i)$ y verificar la existencia de ciclos de peso negativo.

Si el algoritmo detecta un ciclo de peso negativo, devolver que el sistema no tiene solución e identificar un subconjunto de inecuaciones que forman un ciclo contradictorio.

Si no hay ciclos de peso negativo, devolver la solución $x_i = d(v_0, v_i)$ para todo $1 \leq i \leq n$.

```python
def solve_SRD(graph, num_vertices):
    distances = [inf] * num_vertices
    distances[0] = 0
    
    # Bellman-Ford algorithm
    for _ in range(num_vertices - 1):
        for u, v, weight in graph.edges:
            if distances[u] + weight < distances[v]:
                distances[v] = distances[u] + weight

    for u, v, weight in graph.edges:
        if distances[u] + weight < distances[v]:
            return "No solution, cycle detected", find_negative_cycle(graph)

    return {i: distances[i] for i in range(1, num_vertices)}
```