Para cada una de las siguientes sentencias sobre el problema de flujo máximo en una red $N$:
demostrar que es verdadera o dar un contraejemplo.

> $a)$ Si la capacidad de cada arista de $N$ es par, entonces el valor del flujo máximo es par.

El flujo en una red es la **suma** de los flujos en las aristas que conducen hacia el nodo sumidero.

Si todas las capacidades de las aristas son números pares, cualquier flujo que las respete será la suma de múltiplos de 2 (ya que no puede superar estas capacidades). 

Por lo tanto, la suma total del flujo también será un múltiplo de 2, es decir, par.

$\blacksquare$

> $b)$ Si la capacidad de cada arista de $N$ es par, entonces existe un flujo máximo en el cual el flujo sobre cada arista de $N$ es par.

Si las capacidades $c(u, v)$ son todas pares, cualquier flujo factible $f(u, v)$ que respete las restricciones de capacidad $0 \leq f(u, v) \leq c(u, v)$ puede ajustarse en términos de pares, porque:
* Las operaciones sobre $f(u, v)$ (como aumentos a lo largo de caminos) no romperán la paridad si se realizan en múltiplos de $2$.
* Al final, existe una forma de distribuir el flujo en valores pares respetando las capacidades.

Se comienza con un flujo inicial $f(u, v) = 0$, que evidentemente es par para todas las aristas.

Al usar el algoritmo de Ford-Fulkerson o Edmonds-Karp, se buscan caminos aumentantes para incrementar el flujo.

Las capacidades residuales en la red residual también serán pares, ya que $c(u, v)$ es par y los aumentos se realizan en múltiplos de $2$.

En cada paso, el flujo en las aristas es incrementado por un valor par (bottleneck de capacidad residual en un camino aumentante). Esto asegura que el flujo máximo obtenido será tal que el flujo sobre cada arista es par.

**Dado que el flujo inicial y todos los incrementos son pares, el flujo final en cada arista será par**. Así, construimos explícitamente un flujo máximo donde el flujo sobre cada arista es par.

> $c)$ Si la capacidad de cada arista de $N$ es impar, entonces el valor del flujo máximo es impar.

#### **Contraejemplo:**
Consideramos un grafo simple con nodos $s, v, t$ y las siguientes aristas:
- $s \to v$ con capacidad $3$,
- $v \to t$ con capacidad $3$,
- $s \to t$ con capacidad $3$.

Un flujo máximo es 6:
- $3$ unidades a través de $s \to v \to t$,
- $3$ unidades directamente a través de $s \to t$.

Aunque todas las capacidades sean impares, la suma del flujo máximo puede ser par.

> $d)$ Si la capacidad de cada arista de $N$ es impar, entonces existe un flujo máximo en el cual el flujo sobre cada arista de $N$ es impar.

Mismo contraejemplo que en $c$.

> $e)$ Si todas las aristas de $N$ tienen capacidades racionales, entonces el flujo máximo es racional.

El algoritmo de Ford-Fulkerson, modificado para manejar capacidades racionales, garantiza que los flujos incrementales sean racionales.

La suma finita de números racionales es un número racional.

Por lo tanto, el flujo máximo será racional.