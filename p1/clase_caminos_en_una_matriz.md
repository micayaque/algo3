Se tiene una matriz M de m × n números naturales.\
Se quiere llegar desde la posición (0, 0) de la matriz a la (m − 1, n − 1), y sólo se pueden hacer movimientos para abajo o para la derecha en cada paso.\
Calcular el camino de la posición (0, 0) a la (m − 1, n − 1) cuya suma de casilleros sea mínima.

$$ camino(i, j) =  \begin{cases} M[i][j] & \text{si } i = m-1 \land j = n-1 \\ camino(i+1, j) + M[i][j] & \text{si } i < m-1 \land j = n-1
\\ camino(i, j+1) + M[i][j] & \text{si } i = m-1 \land j < n-1 \\
min \\ \{camino(i+1, j) + M[i][j],
camino(i, j+1) + M[i][j]\} & \text{sino } \end{cases}$$

---

<u> Demostración por inducción </u>

<u> Caso base </u>

Si estamos en la posición (m-1, n-1), entonces el único movimiento posible es quedarse en el mismo lugar, y la suma de casilleros sería simplemente el valor de M[m-1][n-1], entonces camino(i, j) = M[i][j].

---

<u> Paso inductivo: </u>

<u> Hipótesis inductiva </u> Supongamos que la función recursiva nos da la suma de casilleros minima para todas las posiciones (i', j') tales que i' > i y j' > j (abajo a la derecha).

Queremos demostrar que también lo hace para la posición (i, j).

---

Dado que la función recursiva considera dos movimientos posibles:\
hacia **abajo** (i+1, j) y hacia la **derecha** (i, j+1),\
debemos demostrar que, seleccionar el mínimo entre estos dos casos nos lleva al camino con la suma mínima hasta la posición (i, j).

---

* Si i = m-1 y j < n-1:\
Solo se puede mover hacia la derecha.\
La suma mínima hasta la posición (i, j) sería la suma mínima hasta la posición (i, j+1) + M[i][j].\
Como por HI la función nos da la suma mínima para la posición (i, j+1), este paso es válido.

* Si i < m-1 y j = n-1:\
En este caso, solo se puede mover hacia abajo.\
La suma mínima hasta la posición (i, j) sería la suma mínima hasta la posición (i+1, j) + M[i][j].\
Como por HI la función nos da la suma mínima para la posición (i+1, j), este paso también es válido.

---

* Si i < m-1 y j < n-1:\
En este caso, se puede elegir entre moverse hacia abajo o hacia la derecha.\

*Principio de optimalidad (Bellman)*: establece que una secuencia de decisiones es óptima globalmente si, al tomar cualquier subsecuencia de decisiones, el resto de las decisiones también son óptimas con respecto a la subsecuencia tomada.

Al tomar el mínimo entre los dos casos en la posición (i, j), estamos asegurando que la suma acumulada hasta ese punto sea mínima, entonces al tomar el mínimo, nos aseguramos de elegir la opción que sigue el camino óptimo global.

Nuevamente, esto se basa en la hipótesis inductiva de que la función es correcta para las posiciones (i+1, j) y (i, j+1).

---

Dado que hemos demostrado que la función recursiva es correcta para el caso base y que el paso inductivo mantiene la propiedad, podemos concluir que la función recursiva dada es correcta para todas las posiciones (i, j) en la matriz M.