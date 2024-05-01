<font face="LaTeX">

## DadosSuma

*Se arrojan simultáneamente $n $ dados, cada uno con $k $ caras numeradas de $1 $ a $k $. Queremos calcular todas las maneras posibles de conseguir la suma total $s ∈ N $ con una sola tirada.\
Tomamos dos variantes de este problema.*

*(A) Consideramos que los dados son distinguibles, es decir que si $ n = 3 $ y $ k = 4 $, entonces existen 10 posibilidades que suman $s = 6 $:*
1) *4 posibilidades en las que el primer dado vale 1*
2) *3 posibilidades en las que el primer dado vale 2*
3) *2 posibilidades en las que el primer dado vale 3*
4) *Una posibilidad en la que el primer dado vale 4* 

*(B) Consideramos que los dados son indistinguibles, es decir que si n = 3 y k = 4, entonces existen 3 posibilidades que suman s = 6:*
1) *Un dado vale 4, los otros dos valen 1*
2) *Un dado vale 3, otro 2 y otro 1*
3) *Todos los dados valen 2*

---
*a) Definir en forma recursiva la función $f : N^2 → N $ tal que $f (n, s) $ devuelve la respuesta para el escenario $(A) $(fijado $ k $).*


La función $f(n, s) $ devuelve el número de maneras posibles de obtener la suma $s $ con $n $ dados.\
Se puede observar que la suma de $n $ dados es igual a la suma de $n - 1 $ dados más la suma de un dado.\

$$f(n, s) =  \begin{cases} 1 & \text{si } s=0 \land n=0  \\ 0 & \text{si } s<0  \\  \sum_{i=1}^{k} f(n - 1, s - i)  & \text{sino } \end{cases}$$

---

*b) Definir en forma recursiva la función $g : N^3 → N $ tal que $f (n, s, k) $ devuelve la respuesta para el escenario $(B) $.*

La función $g(n, s, k) $ devuelve el número de maneras posibles de obtener la suma $s $ con $n $ dados de $k $ caras para el escenario $(B) $.\
Se puede observar que la suma de $n $ dados es igual a la suma de $n - 1 $ dados más la suma de un dado.\
Además, se puede observar que la suma de $n $ dados de $k $ caras es igual a la suma de $n $ dados de $k - 1 $ caras más la suma de un dado de $k $ caras.\

$$g(n, s, k) =  \begin{cases} 1 & \text{si } s=0 \land n=0  \\ 0 & \text{si } s>0 \land n=0  \\ 0 & \text{si } s<0  \\  \sum_{i=1}^{k} g(n - 1, s - i, k-1)  & \text{sino } \end{cases}$$

---

*c) Demostrar que f y g poseen la propiedad de superposición de subproblemas.*

Para demostrar que las funciones $f $ y $g $ poseen la propiedad de superposición de subproblemas, es necesario demostrar que los subproblemas se resuelven más de una vez.\
Para ello, se puede observar que en ambas funciones, la suma de $n $ dados es igual a la suma de $n - 1 $ dados más la suma de un dado.\
Por lo tanto, al calcular la función $f(n, s) $ o $g(n, s, k) $, se resuelven subproblemas de menor tamaño que ya han sido calculados previamente.\
Esto demuestra que las funciones $f $ y $g $ poseen la propiedad de superposición de subproblemas.

---

*d) Definir algoritmos top-down para calcular f (n, s) y g(n, s, k) indicando claramente las estructuras de datos utilizadas y la complejidad resultante.*

Para calcular $f(n, s) $ y $g(n, s, k) $ en tiempo $O(n*k * mı́n\{s, n*k\}) $, se puede utilizar la técnica de programación dinámica con memoización.\
Para ello, se puede utilizar una matriz tridimensional donde los índices representan los valores actuales de $n $, $s $, y $k $ respectivamente.\
Almacenando los resultados de los subproblemas ya calculados, se evitan recalculaciones innecesarias y se logra una complejidad de tiempo eficiente.\
De esta manera, se pueden calcular $f(n, s) $ y $g(n, s, k) $ en tiempo $ O(n*k * mı́n\{s, n*k\}) $.

---

*e) Escribir el (pseudo-)código de los algoritmos top-down resultantes.\
<u>Nota:</u> Una solución correcta de este ejercicio debería indicar cómo se computa tanto $f (n, s) $
como $g(n, s, k) $ en tiempo $O(n*k * mı́n\{s, n*k\})$.*

```python
def f(n, s, k, memo):
    if memo[n][s] is not None:
        return memo[n][s]
    if n == 0 and s == 0:
        memo[n][s] = 1
        return memo[n][s]
    if n == 0 or s < 0:
        return 0
    memo[(n, s)] = sum(f(n - 1, s - i, k, memo) for i in range(1, k + 1))
    return memo[(n, s)]

memo_f = [[None] * s for _ in range(n)]
```

```python
def g(n, s, k, memo):
    if memo[n][s][k] is not None:
        return memo[n][s][k]
    if n == 0 and s == 0:
        memo_g[n][s][k] = 1
        return memo_g[n][s][k]
    if n == 0 or s < 0:
        return 0
    memo[n][s][k] = sum(g(n - 1, s - i, k - 1, memo) for i in range(1, k + 1))
    return memo[n][s][k]

memo_g = [[[None] * s for _ in range (k)] for _ in range(n)]
```

</font>