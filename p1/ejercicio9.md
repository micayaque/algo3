<font face="LaTeX">

### Travesía Vital
*Hay un terreno, que podemos pensarlo como una grilla de m filas y n columnas, con trampas y pociones. Queremos llegar de la esquina superior izquierda hasta la inferior derecha, y desde cada casilla sólo podemos movernos a la casilla de la derecha o a la de abajo. Cada casilla $i,j $ tiene un número entero $A_{i,j} $ que nos modificará el nivel de vida sumándonos el número $A_{i,j} $ (si
es negativo, nos va a restar $| A_{i,j} | $ de vida). Queremos saber el mínimo nivel de vida con el que
debemos comenzar tal que haya un camino posible de modo que en todo momento nuestro nivel
de vida sea al menos 1.*

---

a) Idea de un algoritmo de backtracking:

```python
def backtracking(i, j, vida, min_vida):
    if i == m - 1 and j == n - 1:
        min_vida = min(min_vida, vida)
    if i < m - 1 and j == n - 1:
        min_vida = backtracking(i + 1, j, vida + A[i+1][j], min_vida)
    if j < n - 1 and i == m - 1:
        min_vida = backtracking(i, j + 1, vida + A[i][j + 1], min_vida)
    if i < m - 1 and j < n - 1:
        min_vida = min(backtracking(i + 1, j, vida + A[i+1][j], min_vida), backtracking(i, j + 1, vida + A[i][j+1], min_vida))
    return min_vida
```

---

*b) Excepto que estemos en los límites del terreno, la mínima vida necesaria al llegar a la posición $i, j $ es el resultado de restar al mínimo entre la mínima vida necesaria en $i+1, j $ y aquella en $i, j+1 $, el valor $A_{i,j} $ , salvo que eso fuera menor o igual que 0, en cuyo caso sería $1 $.*

---

*c) Escribir una formulación recursiva basada en b). Explicar su semántica e indicar cuáles serían los parámetros para resolver el problema.*

```python
def min_vida(i, j):
    if i == m - 1 and j == n - 1:
        return max(1, 1 - A[i][j])
    if i < m - 1 and j == n - 1:
        return max(1, min_vida(i+1, j) - A[i][j])
    if j < n - 1 and i == m - 1:
        return max(1, min_vida(i, j+1) - A[i][j])
    return max(1, min(min_vida(i+1, j), min_vida(i, j+1)) - A[i][j])
```

*Semántica: `min_vida(i, j)` devuelve la mínima vida necesaria para llegar a la posición $i, j $.*

*Parámetros para resolver el problema: `min_vida(0, 0)`.*

---

*d) Diseñar un algoritmo de PD y dar su complejidad temporal y espacial auxiliar. Comparar cómo resultaría un enfoque top-down con uno bottom-up.*


*En un enfoque top-down, se calcula la mínima vida necesaria para llegar a la posición $i, j $ a partir de las mínimas vidas necesarias para llegar a las posiciones $i+1, j $ y $i, j+1 $. En un enfoque bottom-up, se calcula la mínima vida necesaria para llegar a la posición $i, j $ a partir de las mínimas vidas necesarias para llegar a las posiciones $i-1, j $ y $i, j-1 $.*

```python
INF = float('inf')
def min_vida():
    memo = [[INF for _ in range(n)] for _ in range(m)]
    def min_vida(i, j):
        if memo[i][j] != INF:
            return memo[i][j]
        if i == m-1 and j == n-1:
            memo[i][j] = max(1, 1 - A[i][j])
        if i < m - 1 and j == n - 1:
            memo[i][j] = max(1, min_vida(i+1, j) - A[i][j])
        if j < n-1 and i == m-1:
            memo[i][j] = max(1, min_vida(i, j+1) - A[i][j])
        if i < m-1 and j < n-1:
            memo[i][j] = max(1, min(min_vida(i+1, j), min_vida(i, j+1)) - A[i][j])
        return memo[i][j]
    return min_vida(0, 0)
```

*Complejidad temporal: $O(mn) $.*

*Complejidad espacial auxiliar: $O(mn) $.*

![Enfoque Top-Down](./img/enfoque_top_down.png)

---

*e) Dar un algoritmo bottom-up cuya complejidad temporal sea O(m · n) y la espacial auxiliar sea $O(mı́n(m, n)) $.*

```python
def min_vida():
    memo = [INF for _ in range(min(m, n))]
    memo[-1] = max(1, 1 - A[-1][-1])
    for i in range(m-1, -1, -1):
        for j in range(n-1, -1, -1):
            if i == m-1 and j == n-1:
                memo[j] = max(1, 1 - A[i][j])
            if i < m-1 and j == n-1:
                memo[j] = max(1, memo[j] - A[i][j])
            if j < n-1 and i == m-1:
                memo[j] = max(1, memo[j+1] - A[i][j])
            if i < m-1 and j < n-1:
                memo[j] = max(1, min(memo[j], memo[j+1]) - A[i][j])
    return memo[0]
```

*Complejidad temporal: $O(mn) $.*

*Complejidad espacial auxiliar: $O(mı́n(m, n)) $.*

![Enfoque Bottom-Up](./img/enfoque_bottom_up.png)


---


</font>