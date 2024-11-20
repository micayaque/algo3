Sean $r_1 , . . . , r_m$ y $c_1 , . . . , c_n$ números naturales. 

Se quiere asignar los valores de las celdas de una matriz de $m × n$ con números naturales de forma tal que la i-ésima fila sume $r_i$ y la i-ésima columna sume $c_i$.

> $a)$ Modelar el problema de asignación como un problema de flujo.

Queremos llenar una matriz $m \times n$ con números naturales de manera que:
- La suma de los valores de las celdas de cada fila $i$ sea $r_i$.
- La suma de los valores de las celdas de cada columna $j$ sea $c_j$.

**Nodos**:
- Un nodo fuente $s$.
- Un nodo por cada fila $r_i$, $i = 1, \dots, m$.
- Un nodo por cada columna $c_j$, $j = 1, \dots, n$.
- Un nodo sumidero $t$.

**Aristas**:
- Del nodo fuente $s$ a cada nodo de fila $i$, con capacidad igual al valor $r_i$.
- De cada nodo de fila $i$ a cada nodo de columna $c_j$, con capacidad infinita (o suficientemente grande para no limitar el flujo).
- De cada nodo de columna $c_j$ al nodo sumidero $t$, con capacidad igual al valor $c_j$).

El flujo total en esta red es igual a la suma de $r_i$ o $c_j$, ya que la suma total de las entradas debe coincidir con la suma total de las salidas:
$$\text{Flujo total} = \sum_{i=1}^m r_i = \sum_{j=1}^n c_j$$

> $b)$ Dar una interpretación a cada unidad de flujo y cada restricción de capacidad.

- Cada unidad de flujo $f(i, j)$ representa un valor asignado a la celda $(i, j)$ de la matriz.

- **Restricción de capacidad $s \to r_i$** garantiza que la suma de las celdas de la fila $i$ sea $r_i$.

- **Restricción de capacidad $c_j \to t$** garantiza que la suma de las celdas de la columna $j$ sea $c_j$.

- **Conservación de flujo** asegura que el flujo que entra en cada nodo de fila $r_i$ o nodo de columna $c_j$ sea igual al flujo que sale, lo cual asegura que cada celda reciba valores válidos.

> $c)$ Demostrar que el modelo es correcto.

**Correspondencia entre flujo y matriz**:
- Cada unidad de flujo $f(i, j)$ representa el valor asignado a la celda $(i, j)$. Esto asegura que los valores en la matriz correspondan directamente al flujo en las aristas internas.

**Restricción de las filas**:
- Las capacidades $c(s, r_i) = r_i$ aseguran que el flujo total hacia $r_i$ sea exactamente $r_i$, cumpliendo la suma de la fila.

**Restricción de las columnas**:
- Las capacidades $c(c_j, t) = c_j$ aseguran que el flujo total hacia el nodo $t$ desde $c_j$ sea exactamente $c_j$, cumpliendo la suma de la columna.

**Equilibrio global**:
- Por la conservación de flujo, el flujo total hacia $t$ será igual al flujo total desde $s$, que es igual a $\sum r_i = \sum c_j$. Esto asegura que el problema tenga solución si estas sumas coinciden.

Por el **teorema de flujo máximo-corte mínimo**, si el flujo máximo es igual a $\sum r_i$, existe una solución que satisface todas las restricciones.

> $d)$ Determinar la complejidad de resolver el modelo resultante con el algoritmo de Edmonds y Karp.

- Hay $1$ nodo fuente $s$, $m$ nodos para las filas, $n$ nodos para las columnas, y $1$ nodo sumidero $t$.Total: $n + m + 2$.

- Hay $m$ aristas desde $s$ a los nodos de filas.
- Hay $m \times n$ aristas entre los nodos de filas y columnas.
- Hay $n$ aristas desde los nodos de columnas a $t$.
- Total: $m + m \cdot n + n$.

- Usando Edmonds-Karp, la complejidad total es:
$$O(\text{nodos} \cdot \text{aristas}^2) = O((m + n) \cdot (m \cdot n)^2)$$