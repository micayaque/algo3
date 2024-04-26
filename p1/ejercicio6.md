<font face="LaTeX">

### <u>OptiPago</u>
---
*Tenemos un multiconjunto B de valores de **billetes** y queremos comprar un producto de costo c de una máquina que no da vuelto. Para poder adquirir el producto debemos cubrir su costo usando un subconjunto de nuestros billetes. El objetivo es pagar con el **mínimo exceso** posible a fin de minimizar nuestra pérdida. Más aún, queremos gastar el **menor tiempo** posible poniendo billetes en la máquina. Por lo tanto, entre las opciones de mínimo exceso posible, queremos una con la menor cantidad de billetes. Por ejemplo, si c = 14 y B = {2, 3, 5, 10, 20, 20}, la solución es pagar 15, con exceso 1, insertando sólo dos billetes: uno de 10 y otro de 5.*

---

*a) Considerar la siguiente estrategia por backtracking para el problema, donde $B = \{b_1 , . . . , b_n \}$.
Tenemos dos posibilidades: o agregamos el billete $b_n$, gastando un billete y quedando por pagar $c − b_n$ , o no agregamos el billete $b_n$, gastando 0 billetes y quedando por pagar c.*

*Escribir una función recursiva $cc(B, c)$ para resolver el problema, donde $cc(B, c) = (c′ , q)$ cuando el mínimo costo mayor o igual a c que es posible pagar con los billetes de B es c′ y
la cantidad de billetes mínima es q.*


$$ cc(B= \{b_1 , . . . , b_n \}, c, q) =  \begin{cases} (\infty,\infty) & \text{si } n = 0 \ \land \ c \gt 0 \\ (|c|,q) & \text{si } n = 0 \ \land \ c \leq \ 0 \\ min \{ \pi_1 (cc(\{b_1, . . . , b_{n−1}\}, c, q)), \pi_1(cc(\{b_1 , . . . , b_{n−1} \}, c − b_n, q+1 )) \} & \text{sino } \end{cases}$$


---

*b) Implementar la función de a) en un lenguaje de programación imperativo utilizando una
función recursiva con parámetros $B, i, j$ que compute $cc(\{b_1 , . . . , b_i \}, j)$. ¿Cuál es la complejidad del algoritmo?*

```python
def cc(B, c):
    n = len(B)
    def cc_aux(B, i, j):
        if i == 0 and j > 0:
            return (float('inf'), float('inf'))
        if i == 0 and j <= 0:
            return (abs(j), 0)
        use = cc_aux(B, i-1, j-B[i-1])[0], cc_aux(B, i-1, j-B[i-1])[1]+1
        not_use = cc_aux(B, i-1, j)[0], cc_aux(B, i-1, j)[1]
        return min(use, not_use)
    return cc_aux(B, n, c)
```

La complejidad del algoritmo es $O(2^n)$.

---

*c) Reescribir cc como una función recursiva $cc’B (i, j) = cc(\{b_1 , . . . , b_i \}, j)$ que implemente la
idea anterior dejando fijo el parámetro B. A partir de esta función, determinar cuándo $cc’B$ tiene la propiedad de superposición de subproblemas.*

$$ cc'(B= \{b_1 , . . . , b_n \}, c, i, q) =  \begin{cases} (\infty,\infty) & \text{si } i = 0 \ \land \ c \gt 0 \\ (|c|,q) & \text{si } i = 0 \ \land \ c \leq \ 0 \\ min \{ \pi_1 (cc'(\{b_1, . . . , b_{n}\}, c, i-1, q)), \pi_1(cc'(\{b_1 , . . . , b_{n} \}, c − b_n, i-1, q+1 )) \} & \text{sino } \end{cases}$$

$cc’B$ tiene la propiedad de superposición de subproblemas cuando $i$ es fijo. En este caso, se repiten los mismos subproblemas para distintos valores de $j$. Por ejemplo, si $cc'B(3, 10)$ y $cc'B(3, 15)$ tienen el mismo subproblema $cc'B(2, 10)$. 

---

*d) Definir una estructura de memoización para $cc’B$ que permita acceder a $cc’B (i, j)$ en $O(1)$ tiempo para todo $0 ≤ i ≤ n \ , \ 0 ≤ j ≤ k$.*

```python
    n = len(B)
    memo = [[None for _ in range(c+1)] for _ in range(n+1)]
```

---

*e) Adaptar el algoritmo de b) para incluir la estructura de memoización.*

```python
def cc(B, c):
    n = len(B)
    memo = [[None for _ in range(c+1)] for _ in range(n+1)]
    def cc_aux(B, i, j):
        if memo[i][j] is not None:
            return memo[i][j]
        if i == 0 and j > 0:
            m[i][j] = (float('inf'), float('inf'))
            return m[i][j]
        if i == 0 and j <= 0:
            m[i][j] = (abs(j), 0)
            return m[i][j]
        use = cc_aux(B, i-1, j-B[i-1])[0], cc_aux(B, i-1, j-B[i-1])[1]+1
        not_use = cc_aux(B, i-1, j)[0], cc_aux(B, i-1, j)[1]
        memo[i][j] = min(use, not_use)
        return memo[i][j]
    return cc_aux(B, n, c)
```


---


*f) Indicar cuál es la llamada recursiva que resuelve nuestro problema y cuál es la complejidad del nuevo algoritmo.*

La llamada recursiva que resuelve nuestro problema es $cc(B, c)$. La complejidad del nuevo algoritmo es $O(n \cdot c)$.

---


</font>