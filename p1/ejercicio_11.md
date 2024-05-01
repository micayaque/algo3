<font face="LaTeX">

## OperacionesSeq

*Sea $v = (v_1 , v_2 , . . . v_n ) $ un vector de números naturales, y sea $w ∈ N $. Se desea <u>intercalar</u> entre los elementos de $v $ las operaciones $+ $ (suma), $× $ (multiplicación) y $↑ $ (potenciación) de tal manera que al evaluar la expresión obtenida el resultado sea $w $. Para evaluar la expresión se opera de **izquierda a derecha** ignorando la precedencia de los operadores. Por ejemplo, si $v = (3, 1, 5, 2, 1) $, y las operaciones elegidas son $+ $, $× $, $↑ $ y $× $ (en ese orden), la expresión obtenida es $3+1×5 ↑ 2×1 $,
que se evalúa como $(((3 + 1) × 5) ↑ 2) × 1 = 400 $.*

---
*a) Escribir una formulación recursiva que sea la base de un algoritmo de PD que, dados $v $ y $w $, encuentre una secuencia de operaciones como la deseada, en caso de que tal secuencia exista. Explicar su semántica e indicar cuáles serían los parámetros para resolver el problema.*

$$opSeq(\{v_1,...,v_n\}, i, w, r, s) =  \begin{cases} w=r & \text{si } i = n \\ False & \text{si } r > w \\  opSeq(\{v_1, . . . , v_n\}, i+1, w, r + v[i], s++(+)) ∨ \\ opSeq(\{v_1 , . . . , v_n \}, i+1, w, r * v[i], s++(×)) \lor \\ opSeq(\{v_1 , . . . , v_n \}, i+1, w, r↑v[i], s++(↑))  & \text{sino } \end{cases}$$

La función recursiva toma como parámetros el índice (i) actual en el vector (v), el resultado acumulado hasta el momento (r), y el objetivo (w). La idea es llamar a esta función comenzando desde el índice 0 y con un resultado acumulado inicial el primer valor de (v).

Si llegamos al final del vector (v) (es decir, el índice actual es igual a la longitud de (v), i == n) y el resultado acumulado es igual a (w), entonces encontramos una secuencia de operaciones válida y retornamos true. Si el resultado acumulado no es (w), retornamos false.

$opSeq(v, 2, w, v_1, s) $

---
*b) Diseñar un algoritmo basado en PD con la formulación de a) y dar su complejidad temporal y espacial auxiliar. Comparar cómo resultaría un enfoque top-down con uno bottom-up.*

 Para cada elemento en (v) a partir del índice actual, intentamos realizar cada una de las operaciones permitidas ($+$, $\times$, $\uparrow$) y llamamos a la función recursivamente con el nuevo resultado acumulado y el próximo índice. Para evitar recalcular resultados para el mismo índice y resultado acumulado, almacenamos los resultados ya calculados en una estructura de datos (memo), y antes de realizar el cálculo, verificamos si el resultado ya está almacenado.

 La función retorna true y la secuencia de operaciones si se encuentra una solución, o false y la lista vacía si no se encuentra ninguna al explorar todas las posibilidades.

```python
def opSeq(v, w):
    n = len(v)
    memo = [[False for _ in range(w)] for _ in range(n)]
    def opSeqRec(i, r, s):
        if memo[i][r]: return (memo[i][r], s)
        if i == n:
            memo[i][r] = r == w
            if memo[i][r] : return (memo[i][r], s)
            else : return (memo[i][r], [])
        if r > w:
            memo[i][r] = False
            return (memo[i][r], [])
        memo[i][r] = opSeqRec(i+1, r+v[i], s+['+']) or 
                        opSeqRec(i+1, r*v[i], s+['*']) or 
                            opSeqRec(i+1, r**v[i], s+['^'])
        if memo[i][r] : return (memo[i][r], s)
        else : return (memo[i][r], [])
    return opSeqRec(0, v[0], [])
```

La complejidad temporal y espacial auxiliar del algoritmo es $O(n*w)$.

</font>