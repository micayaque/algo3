Para todo $F \in N$, construir una red con $4$ vértices y $5$ aristas en la que el método de Ford y Fulkerson necesite $F$ iteraciones en peor caso para obtener el flujo de valor máximo (partiendo de un flujo inicial con valor $0$).

Necesitamos diseñar una red que provoque que el algoritmo encuentre caminos aumentantes ineficientes en cada iteración. 

Los caminos aumentantes iniciales tienen pequeñas capacidades (bottleneck), forzando incrementos mínimos del flujo en cada iteración.

Se necesitan exactamente $F$ iteraciones para alcanzar el flujo máximo.

Usamos $4$ vértices ($ s, u, v, t $) y $5$ aristas:
- $s \to u $,
- $ u \to v $,
- $ v \to t $,
- $ s \to v $,
- $ u \to t $.

Definimos las capacidades de las aristas de tal forma que:
* El flujo máximo sea igual a $F$.
* Los caminos aumentantes iniciales permitan solo incrementos de $1$ unidad en cada iteración.

#### **Capacidades de las aristas**
- $c(s \to u) = 1$,
- $c(u \to v) = 1$,
- $c(v \to t) = 1$,
- $c(s \to v) = F$,
- $c(u \to t) = F$.

![image](/img/image%20copy%208.png)

En cada iteración, el algoritmo de Ford-Fulkerson buscará un camino aumentante en la red residual. Si el algoritmo elige los caminos $s \to u \to v \to t$ repetidamente (debido al orden en que explora los caminos), solo podrá enviar $1$ unidad de flujo en cada iteración.

Después de $F$ iteraciones, todas las capacidades $c(s \to u), c(u \to v), c(v \to t)$ estarán saturadas.

Solo entonces podrá enviar $F - 1$ unidades de flujo adicionales a través de los caminos directos $s \to v \to t$ y $u \to t$, completando el flujo máximo.