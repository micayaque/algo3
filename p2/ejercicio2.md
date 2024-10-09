<font face = "LaTeX">

### IndiceEspejo

*Tenemos un arreglo $a = [a_1 , a_2 , . . . , a_n ]$ de n enteros distintos (positivos y negativos) en orden **estrictamente creciente**.\
Queremos determinar si existe una posición i tal que $a_i = i$.\
Por ejemplo, dado el arreglo a =
[−4, −1, 2, 4, 7], i = 4 es esa posición.\
Diseñar un algoritmo dividir y conquistar eficiente (de complejidad de orden estrictamente menor que lineal)
que resuelva el problema.\
Calcule y justifique la complejidad del algoritmo dado.*

---

Para resolver este problema, proponemos un algoritmo de complejidad $O(\log n)$ muy parecido a una busqueda binaria aprovechando que tenemos a los elementos del arreglo ordenados en forma creciente,  que divide el arreglo en dos mitades y busca en cada una de ellas si existe un índice $i$ tal que $a_i = i$.\
Si no lo encuentra, busca en la mitad correspondiente.

```python
def indice_espejo(arr):
    def _indice_espejo(arr, start, end):
        if start == end:
            return arr[start] == start + 1
        m = (start + end) // 2
        if arr[m] == m+1:
            return True
        if arr[m] > m+1:
            return _indice_espejo(arr, start, m - 1)
        return _indice_espejo(arr, m, end)
    return _indice_espejo(arr, 0, len(arr) - 1)
```

La complejidad de este algoritmo es $O(\log n)$ ya que en cada llamada recursiva se divide el arreglo en dos mitades y se descarta una de ellas.

</font>