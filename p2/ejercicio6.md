<font face = "LaTeX">

### DistanciaMáxima

*Dado un árbol binario cualquiera, diseñar un algoritmo de dividir y conquistar que devuelva la máxima distancia entre dos nodos (es decir, máxima cantidad de ejes a atravesar). El algoritmo no debe hacer recorridos innecesarios sobre el árbol.\
Hint: para saber el camino más largo de un árbol, posiblemente necesite conocer
más que sólo los caminos más largos de sus subárboles.*

---

* Si el árbol es vacío, la distancia máxima es 0.
* Si el árbol no es vacío, se calcula la distancia máxima de la siguiente manera:
    1. Se calcula la distancia máxima de los subárboles izquierdo y derecho.
    2. Se calcula la distancia máxima que pasa por la raíz del árbol.
    3. La distancia máxima es el máximo entre las distancias máximas de los subárboles y la distancia máxima que pasa por la raíz.

```python
def distanciaMaxima(arbol):
    if arbol is None:
        return 0
    else:
        izq = distanciaMaxima(arbol.izq)
        der = distanciaMaxima(arbol.der)
        raiz = altura(arbol.izq) + altura(arbol.der) + 1
        return max(izq, der, raiz)
```

Donde `altura` es una función que calcula la altura de un árbol.

</font>