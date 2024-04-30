<font face="LaTeX">

### SumaSelectiva

Dado un conjunto $ X $ con $ |X|  = n $ y un entero $ k ≤ n $ queremos encontrar el máximo valor que pueden sumar los elementos de un subconjunto $ S $ de $ X $ de tamaño $ k $. \
Más formalmente, queremos calcular:\
$$ \max_{S \subseteq X, |S| = k} \sum_{s \in S} s $$

---

*a) Proponer un algoritmo greedy que resuelva el problema, demostrando su correctitud.\
Extender el algoritmo para que también devuelva uno de los subconjuntos S que maximiza la suma.*

Para resolver el problema, se puede utilizar un algoritmo greedy que selecciona los $ k $ elementos más grandes de $ X $. Para ello, se puede ordenar los elementos de $ X $ de mayor a menor y seleccionar los $ k $ primeros elementos.\

**Demostración de correctitud:**

Sea $ S $ el subconjunto de $ X $ que maximiza la suma de sus elementos en nuestra solución golosa.\
Sea $ O $ el subconjunto de $ X $ que maximiza la suma de sus elementos en una solución óptima.\

* $S_k$ es nuestra solución parcial después de seleccionar los $ k $ elementos más grandes de $ X $.
* $O_k$ es la solución parcial después de seleccionar los $ k $ elementos más grandes de $ X $ en una solución óptima.

Supongamos que $ S_k < O_k $.\
Entonces, podemos reemplazar el elemento más pequeño de $ S_k $ por el elemento más grande de $ O_k $ para obtener un subconjunto $ S_k' $ con una suma mayor.\
Pero por como está formada nuestra solución golosa sabemos que ya tiene a los $ k $ elementos más grandes de $ X $ entonces no hay ningún elemento de $ O_k $ que pueda maximizar $ S_k $ y esto contradice la suposición de que $ S_k < O_k $\
$\therefore$ $ S_k \geq O_k $.

---

*b) Dar una implementación del algoritmo del inciso a) con complejidad temporal O(n log n).*

Para implementar el algoritmo con complejidad temporal $ O(n \log n) $, se puede utilizar el método `sort` de Python.\
Este método ordena la lista en $ O(n \log n) $ y selecciona los $ k $ primeros elementos en $ O(k) $.\
Por lo tanto, la complejidad temporal total del algoritmo es $ O(n \log n) $.

```python
def suma_selectiva(X, k):
    X.sort(reverse=True)
    S = X[:k]
    return sum(S)
```

---

*c) Dar una implementación del algoritmo del inciso a) con complejidad temporal O(n log k).*

Para implementar el algoritmo con complejidad temporal $ O(n \log k) $, se puede utilizar una cola de prioridad.\
La cola de prioridad se puede implementar con un heap, que permite insertar y extraer elementos en $ O(\log k) $.\
Para ello, se puede utilizar la función `heapq.nlargest` de Python, que selecciona los $ k $ elementos más grandes de una lista en $ O(n \log k) $.\
Por lo tanto, la complejidad temporal total del algoritmo es $ O(n \log k) $.

```python
import heapq

def suma_selectiva(X, k):
    S = heapq.nlargest(k, X)
    return sum(S)
```



</font>