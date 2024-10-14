Se tiene una grilla con $\text{m × n}$ posiciones, cada una de las cuales tiene un número entero en $\text{[0, k)}$, para un $\text{k} \in \N$ dado. 

Dado un valor objetivo $\text{w} \in \N$ y una posición inicial $(x_1, y_1)$, que tiene un valor inicial $v_1$, queremos determinar la mínima cantidad de movimientos horizontales y verticales que transformen $v_1$ en $\text{w}$, teniendo en cuenta que el i-ésimo movimiento transforma a $v_i$ por $v_{i+1} = (v_i + z) \text{ḿod k}$, donde $\text{z}$ es el valor que se encuentra en la casilla de destino del movimiento. 

Por ejemplo, para la siguiente grilla y $\text{k = 10}$, se puede transformar $v_1 = 1$ en $\text{w = 0}$ con tres movimientos $1 \rightarrow 6 \rightarrow 4 \rightarrow 9$, aunque la solución óptima es vía el camino $1 \rightarrow 3 \rightarrow 6$

Modelar este problema como un problema de grafos que se resuelva usando $\text{BFS}$ en $\text{O(kmn)}$ tiempo.

Sea $\text{G}$ un grafo conexo que construimos con $\text{BFS}$.

Los vértices de G se identifican con estados como una tupla $(x, y, v)$, donde $(x, y)$ es la posición en la grilla y $v$ es el valor actual.

Las aristas de G se definen de la siguiente manera: si $(x, y, v)$ es un vértice de G, entonces $(x', y', v')$ es un vértice adyacente si y solo si $(x', y')$ es una posición adyacente a $(x, y)$ y $v' = (v + z) \text{mod k}$, donde $z$ es el valor en la posición $(x', y')$.

Para resolver el problema, simplemente realizamos una búsqueda en anchura en G desde el vértice $(x_1, y_1, v_1)$ hasta encontrar el vértice $(x_2, y_2, w)$, donde $(x_2, y_2)$ es la posición final.

