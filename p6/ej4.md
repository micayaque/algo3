Proponer un algoritmo lineal que dada una red $N$ y un flujo de valor máximo, encuentre un corte de capacidad mínima de $N$.

Un **corte mínimo** en una red de flujo $N$ es una partición del conjunto de nodos en dos subconjuntos $S$ y $T$ (donde $S \cup T = V$ y $S \cap T = \emptyset$) tal que:

* La fuente $s \in S$.
* El sumidero $t \in T$.
* La **capacidad del corte** ($c(S, T)$) es la suma de las capacidades de las aristas que van de $S$ a $T$:
$$c(S, T) = \sum_{u \in S, v \in T} c(u, v)$$

Un **corte mínimo** es aquel con la capacidad mínima entre todos los posibles cortes.

> El **teorema de flujo máximo-corte mínimo** establece que:

1. El valor del flujo máximo en una red es igual a la capacidad del corte mínimo.
2. Un flujo máximo puede utilizarse para identificar un corte mínimo.

Dado que ya tenemos un flujo máximo $f$, podemos aprovechar la **red residual** para encontrar el corte mínimo.

#### **Entrada**
- La red $N$ con capacidad $c(u, v)$ para cada arista.
- Un flujo $f(u, v)$ que representa el flujo máximo.

#### **Salida**
- Un corte $(S, T)$ con capacidad mínima.

**Construcción de la red residual**:
- Para cada arista $(u, v)$ en la red:  
    - La capacidad residual en el sentido directo es:
    $$r(u, v) = c(u, v) - f(u, v)$$
    - Si $f(u, v) > 0$, añadir una capacidad residual en el sentido inverso:
    $$r(v, u) = f(u, v)$$

**Búsqueda de nodos alcanzables desde $s$**:
Realizar una búsqueda en profundidad (DFS) o en anchura (BFS) partiendo de la fuente $s$ en la red residual.
- Marca todos los nodos que son alcanzables desde $s$ en la red residual. Llamemos a este conjunto $S$.

**Formar el corte**:
- Definir el conjunto complementario $T = V \setminus S$.
- El corte $(S, T)$ separa los nodos alcanzables desde $s$ en la red residual ($S$) de los no alcanzables ($T$).

**Capacidad del corte**:
- Calcular la capacidad del corte como la suma de las capacidades de las aristas que van de $S$ a $T$ en la red original $N$:
$$c(S, T) = \sum_{u \in S, v \in T} c(u, v)$$

* En la red residual, un nodo es alcanzable desde $s$ si y solo si hay un camino desde $s$ con capacidad residual positiva.
* El conjunto de nodos no alcanzables ($T$) es aquel bloqueado por las aristas saturadas, lo que corresponde exactamente al corte mínimo.

### **Complejidad**

- Recorrer todas las aristas ($(m)$) para calcular $r(u, v)$.

- Realizar un BFS o DFS ($O(m)$).

- Verificar todas las aristas $(u, v)$ en la red original ($O(m)$).

**Complejidad total**:  
$$O(m)$$ 
donde $m$ es el número de aristas.