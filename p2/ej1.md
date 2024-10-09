IzquierdaDominante
---
Escriba un algoritmo con dividir y conquistar que determine si un arreglo de tamaño $\color{violet}{potencia\ de\ 2}$ es más a la izquierda, donde “más a la izquierda” significa que:
* La $\color{violet}{suma}$ de los elementos de la mitad izquierda superan los de la mitad derecha.
* Cada una de las mitades es a su vez “más a la izquierda”.

Por ejemplo, el arreglo $[8, 6, 7, 4, 5, 1, 3, 2]$ es “más a la izquierda”, pero $[8, 4, 7, 6, 5, 1, 3, 2]$ no lo es.

Intente que su solución aproveche la técnica de modo que la complejidad del algoritmo sea estrictamente menor a $O(n^2)$.

```C++
bool izquierda_dominante(vector<int> arr) {
    vector<int> izq = vector<int>(arr.begin(), arr.begin() + arr.size() / 2);   //O(n)

    vector<int> der = vector<int>(arr.begin() + arr.size() / 2, arr.end());     //O(n)
    
    if (izq.size() == 1) return izq[0] > der[0];    //O(1)
    
    return izquierda_dominante(izq) and izquierda_dominante(der) and accumulate(izq.begin(), izq.end(), 0) > accumulate(der.begin(), der.end(), 0);
}
```

La complejidad final del algoritmo es $O(n*log(n))$.
