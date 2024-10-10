DistanciaMáxima
---
Dado un $\text{árbol\ binario}$ cualquiera, diseñar un algoritmo de dividir y conquistar que devuelva la $\textcolor{violet}{\text{máxima\ distancia\ entre\ dos\ nodos}}$ (es decir, máxima cantidad de ejes a atravesar). 

El algoritmo no debe hacer recorridos innecesarios sobre el árbol.

**Hint**: para saber el camino más largo de un árbol, posiblemente necesite conocer
más que sólo los caminos más largos de sus subárboles.

```C++
int distancia_maxima(Nodo* arbol) {
    if (arbol == nullptr) {
        return 0;
    } else {
        int izq = distancia_maxima(arbol->izq);
        int der = distancia_maxima(arbol->der);
        int medio = altura(arbol->izq) + altura(arbol->der) + 1;
        return max(izq, der, raiz);
    }
}
```