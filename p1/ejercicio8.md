<font face="LaTex">

### CortesEconómicos
*Debemos cortar una vara de madera en varios lugares predeterminados. Sabemos que el costo de realizar un corte en una madera de longitud ℓ es ℓ (y luego de realizar ese corte quedarán 2 varas de longitudes que sumarán ℓ). Por ejemplo, si tenemos una vara de longitud 10 metros que debe ser cortada a los 2, 4 y 7 metros desde un extremo, entonces los cortes se pueden realizar, entre otras maneras, de las siguientes formas:*

* *Primero cortar en la posición 2, después en la 4 y después en la 7. Esta resulta en un costo de 10 + 8 + 6 = 24 porque el primer corte se hizo en una vara de longitud 10 metros, el
segundo en una de 8 metros y el último en una de 6 metros.*

* *Cortar primero donde dice 4, después donde dice 2, y finalmente donde dice 7, con un costo de 10 + 4 + 6 = 20, que es menor.*

*Queremos encontrar el mínimo costo posible de cortar una vara de longitud ℓ.*

---

*a) El mínimo costo de cortar una vara que abarca desde i hasta j con el conjunto C de lugares de corte es j − i mas el mínimo, para todo lugar de corte c entre i y j, de la suma entre el mínimo costo desde i hasta c y el mínimo costo desde c hasta j.*

---

*b) Escribir matemáticamente una formulación recursiva basada en a). Explicar su semántica e indicar cuáles serían los parámetros para resolver el problema.*

<u>Formulación recursiva:</u>

$$ minCosto(i, j, C) = j - i + \min_{c \in C} \{ minCosto(i, c, C) + minCosto(c, j, C) \} $$

La función $ minCost(i, j, C) $ devuelve el mínimo costo de cortar una vara que abarca desde i hasta j con el conjunto C de lugares de corte. Los parámetros para resolver el problema son $ i $, $ j $ y $ C $.

---

*c) Diseñar un algoritmo de PD y dar su complejidad temporal y espacial auxiliar. Comparar cómo resultaría un enfoque top-down con uno bottom-up.*

```python
INF = float('inf')
def minCosto(i, j, C, memo):
    if memo[i][j] != INF: return memo[i][j]

    if j - i <= 1:
        memo[i][j]=0
        return memo[i][j] # Si el rango es vacío, el costo es 0
    
    min_costo = INF
    for c in C: # Iteramos sobre todos los puntos de corte posibles
        costo = j - i + minCosto(i, c, C, memo) + minCosto(c, j, C, memo)
        min_costo = min(min_costo, costo)
    
    memo[i][j] = min_costo
    return memo[i][j]

def calcularMinCosto(l, C):
    memo = [[INF for _ in range(n)] for _ in range(n)]
    # Calcular el mínimo costo desde el inicio (0) hasta el final (l)
    return minCosto(0, l, C, memo)
```

La complejidad temporal de algoritmo es $ O( |C| \cdot l^2) $ y la complejidad espacial auxiliar es $ O(l^2) $.

---

*d) Supongamos que se ordenan los elementos de C en un vector cortes y se agrega un 0 al principio y un ℓ al final. Luego, se considera que el mínimo costo para cortar desde el i-ésimo **punto de corte** en cortes hasta el j-ésimo punto de corte será el resultado buscado si i = 1 y j = |C| + 2.*

* *I) Escribir una formulación recursiva con dos parámetros que esté basada en d) y explicar su semántica.*
* *II) Diseñar un algoritmo de PD, dar su complejidad temporal y espacial auxiliar y compararlas con aquellas de c). Comparar cómo resultaría un enfoque top-down con uno bottom-up.*

I)

$$ minCosto(i, j) = cortes[j] - cortes[i] + \min_{c \in [i+1, j-1]} \{ minCosto(i, c) + minCosto(c, j) \} $$

La función $ minCosto(i, j) $ devuelve el mínimo costo para cortar desde el i-ésimo punto de corte en cortes hasta el j-ésimo punto de corte. Los parámetros para resolver el problema son $ i $ y $ j $.

II)

```python
INF = float('inf')
def minCosto(i, j, cortes, memo):
    if memo[i][j] != INF: return memo[i][j]

    if j - i <= 1:
        memo[i][j]=0
        return memo[i][j] # Si el rango es vacío, el costo es 0
    
    min_costo = INF
    for c in range(i+1, j): # Iteramos sobre todos los puntos de corte posibles
        costo = cortes[j] - cortes[i] + minCosto(i, c, cortes, memo) + minCosto(c, j, cortes, memo)
        min_costo = min(min_costo, costo)
    
    memo[i][j] = min_costo
    return memo[i][j]

def calcularMinCosto(l, C):
    cortes = [0] + sorted(C) + [l]
    n = len(cortes)
    memo = [[INF for _ in range(n)] for _ in range(n)]
    # Calcular el mínimo costo desde el inicio (0) hasta el final (l)
    return minCosto(0, n-1, cortes, memo)
```
---


</font>