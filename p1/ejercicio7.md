<font face="LaTeX">

### AstroTrade
***Astro Void** se dedica a la compra de asteroides. Sea $ p ∈ N^n $ tal que $ p_i $ es el precio de un asteroide
el i-ésimo día en una secuencia de n días. Astro Void quiere comprar y vender asteroides durante esos n días de manera tal de obtener la **mayor ganancia** neta posible. Debido a las dificultades que existen en el transporte y almacenamiento de asteroides, Astro Void puede comprar a lo sumo **un asteroide cada día**, puede vender a lo sumo un asteroide cada día y comienza sin asteroides. Además, el Ente Regulador Asteroidal impide que Astro Void venda un asteroide que no haya comprado. Queremos encontrar la máxima ganancia neta que puede obtener Astro Void respetando las restricciones indicadas. Por ejemplo, si p = (3, 2, 5, 6) el resultado es 6 y si p = (3, 6, 10) el resultado es 7. Notar que **en una solución óptima, Astro Void debe terminar sin
asteroides**.*

---

*a) La máxima ganancia neta (m.g.n.), si Astro Void tiene c asteroides al fin del día j, es:*
* ***indefinido** (i.e., −∞) si c < 0 o c > j,* 
* *o el máximo entre:*
    * *la m.g.n. de finalizar el día j − 1 con c − 1 asteroides y comprar uno en el día j,*
    * *la m.g.n. de finalizar el día j − 1 con c + 1 asteroides y vender uno en el día j,*
    * *la m.g.n. de finalizar el día j − 1 con c asteroides y no operar el día j.*

---

*b) Escribir matemáticamente la **formulación recursiva** enunciada en a). Dar los valores de los casos base en función de la restricción de que comienza sin asteroides.*


<u>Formulación recursiva:</u>

$$ mgn(j, c) = \begin{cases} 0 & \text{si } j=0 \ \text{o} \ c = 0\\ -\infty & \text{si } j=0 \ \text{y} \ c \gt 0\\ 
      -\infty & \text{si } c < 0 \text{ o } c > j \\ 
      \max \{ mgn(j-1, c-1) - p_j, mgn(j-1, c+1) + p_j, mgn(j-1, c) \} & \text{en otro caso}
   \end{cases} $$

---

Los valores de los casos base en función de la restricción de que comienza sin asteroides son:

$$ mgn(0, c) = \begin{cases} 0 & \text{si } c = 0 \\ -\infty & \text{si } c \gt 0 \end{cases} $$

---

*c) Indicar qué dato es la respuesta al problema con esa formulación recursiva.*

La respuesta al problema es $ mgn(n, 0) $, donde $ n $ es la cantidad de días.

---

*d) Diseñar un algoritmo de PD top-down que resuelva el problema y explicar su complejidad temporal y espacial auxiliar.*

```python
-INF = float('-inf')
def mgn(p):
    n = len(p)
    memo = [[None for _ in range(n)] for _ in range(n)]
    
    def mgn_rec(j, c):
        if memo[j][c] is not None:
            return memo[j][c]
        if j == 0 and c > 0:
            m[i][j] = -INF
            return m[j][c] 
        if c < 0 or c > j:
            m[i][j] = -INF
        if j == 0 or c == 0:
            memo[j][c] = 0
            return memo[j][c]
        memo[j][c] = max(mgn_rec(j-1, c-1) - p[j-1], mgn_rec(j-1, c+1) + p[j-1], mgn_rec(j-1, c))
        return memo[j][c]
    return mgn_rec(n, 0)
```

La complejidad temporal del algoritmo es $ O(n^2) $ y la complejidad espacial auxiliar es $ O(n^2) $.

</font>