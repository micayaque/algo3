<u>Caminos en una matriz</u>

Se tiene una matriz M de m × n números naturales. Se quiere llegar desde la posición $(0, 0)$ de la matriz a la $(m − 1, n − 1)$, y sólo se pueden hacer movimientos para abajo o para la derecha en cada paso.\
Calcular el camino de la posición (0, 0) a la (m − 1, n − 1) cuya suma de casilleros sea mínima.

---

$$ camino(i, j) =  \begin{cases} M[i][j] & \text{si } i = m-1 \land j = n-1 \\ camino(i+1, j) + M[i][j] & \text{si } i < m-1 \land j = n-1
\\ camino(i, j+1) + M[i][j] & \text{si } i = m-1 \land j < n-1 \\
min \\ \{camino(i+1, j) + M[i][j],
camino(i, j+1) + M[i][j]\} & \text{sino } \end{cases}$$

<u>Demostración de correctitud</u>

Para demostrar la correctitud de la solución, se puede utilizar el principio de inducción en la estructura del camino.\
Para ello, se puede probar que el camino de suma mínima desde la posición $(0, 0)$ a la $(m − 1, n − 1)$ es el camino que se obtiene al aplicar la fórmula recursiva.

Sea P un camino de costo mínimo de (i, j) a (m, n).\
Queremos ver que camino(i,j) = costo(P).\
Si P tiene más de un elemento, llamamos Q al sufijo de P de longitud |P| − 1.\
Es decir, si la longitud de P es k, entonces Q es el camino de (i, j) a (m, n) que se obtiene al quitar el último paso de P.\

Tenemos que probar que los 4 casos de la fórmula recursiva son correctos:

Para el **caso base**, si i = m-1 y j = n-1:\
camino(i, j) = M[i][j] = costo(P). $\blacksquare$

Para el caso en que **i < m-1 y j = n-1**:\
camino(i, j) = camino(i+1, j) + M[i][j] = costo(Q) + M[i][j] = costo(P). $\blacksquare$

Para el caso en que **i = m-1 y j < n-1**:\
Por definición del problema, el siguiente elemento de P debe ser (i, j + 1) ya que sólo podemos movernos a la derecha, lo mejor (lo único) que podemos hacer es movernos a la derecha.\
camino(i, j) = camino(i, j+1) + M[i][j] = costo(Q) + M[i][j] = costo(P). $\blacksquare$

Por hipótesis inductiva, camino(i, j + 1) es el costo de Q.\
Además, el costo de P es el costo de Q + M[i][j], que es exactamente
minCamino(i,j).

---

Para el caso en que: **i < m-1 y j < n-1**:\
camino(i, j) = min{camino(i+1, j) + M[i][j], camino(i, j+1) + M[i][j]} = min{costo(Q1) + M[i][j], costo(Q2) + M[i][j]} = costo(P). $\blacksquare$

El camino P puede tener como siguiente elemento una de dos cosas: (i + 1, j), o (i, j + 1).\
El subcamino Q tendrá como primer elemento el siguiente elemento de
P, sea cual sea.\
Q es de costo mínimo entre los que van desde su primer elemento hasta (m-1, n-1).\
Por hipótesis inductiva, entonces, su costo es o camino(i + 1, j), o
camino(i, j + 1).\
Por lo tanto, por definición de costo, el costo de P es igual o a M[i][j] + camino(i + 1, j), o
a M[i][j] + camino(i, j + 1).\
Por otro lado, existen caminos con esos costos.\
Los mismos son formados agregándole el elemento (i,j) a los caminos óptimos desde (i + 1, j) y (i, j + 1), respectivamente.\
Esto quiere decir que el costo de P, al ser un camino mínimo, debe ser menor o igual a los costos de estos dos caminos.\
Como el costo de P debe ser uno de los dos costos anteriores, y debe ser menor o igual a los dos, forzosamente debe ser el menor de los dos.\
Entonces:\
costo(P)
= min{Mfila,col + minCamino(fila + 1, col, M),
Mfila,col + minCamino(fila, col + 1, M)}
= Mfila,col + min{minCamino(fila + 1, col, M),
minCamino(fila, col + 1, M)}
= minCamino(fila, col, M)

---

Por lo tanto, demostramos que la fórmula recursiva es correcta.

