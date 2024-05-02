<font face = "LaTeX">

### DesordenSort

*La cantidad de parejas en desorden de un arreglo A[1 . . . n] es la cantidad de parejas de posiciones 1 ≤ i < j ≤ n tales que A[i] > A[j].\
Dar un algoritmo que calcule la cantidad de parejas en desorden de un arreglo
y cuya complejidad temporal sea estrictamente mejor que $O(n^2 )$ en el peor caso.\
Hint: Considerar hacer una modificación de un algoritmo de sorting.*

---

* Se puede resolver el problema de contar la cantidad de parejas en desorden de un arreglo A[1 . . . n] de la siguiente manera:
    1. Se divide el arreglo en dos mitades.
    2. Se cuentan las parejas en desorden de cada mitad.
    3. Se cuentan las parejas en desorden que involucran elementos de ambas mitades.
    4. La cantidad de parejas en desorden es la suma de las parejas en desorden de cada mitad y las parejas en desorden que involucran elementos de ambas mitades.

```python
def desordenSort(A):
    if len(A) == 1:
        return 0
    else:
        mitad = len(A) // 2
        izq = desordenSort(A[:mitad])
        der = desordenSort(A[mitad:])
        ambos = 0
        for i in range(len(A)):
            for j in range(i + 1, len(A)):
                if A[i] > A[j]:
                    ambos += 1
        return izq + der + ambos
```

Donde `A[:mitad]` es la sublista de `A` que va desde la posición 0 hasta `mitad` y `A[mitad:]` es la sublista de `A` que va desde la posición `mitad` hasta el final.

La complejidad temporal del algoritmo es $O(n \log n)$ en el peor caso.

</font>