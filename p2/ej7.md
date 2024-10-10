DesordenSort
---
La cantidad de $\color{violet}\text{parejas\ en\ desorden}$ de un arreglo $A[1 . . . n]$ es la cantidad de parejas de $\color{violet}\text{posiciones}$ $1 \leq i \lt j \leq n$ tales que $A[i] \gt A[j]$.

Dar un algoritmo que calcule la cantidad de parejas en desorden de un arreglo
y cuya complejidad temporal sea estrictamente mejor que $O(n^2)$ en el peor caso.

**Hint**: Considerar hacer una modificación de un algoritmo de sorting.

```C++
int parejas_en_desorden(vector<int> A, int inicio, int fin) {
    if (inicio == fin) return 0;

    int mitad = (inicio + fin) / 2;
    int izq = parejas_en_desorden(A, inicio, mitad);
    int der = parejas_en_desorden(A, mitad + 1, fin);
    
    int ambos = 0;

    int i= inicio, j = mitad;
    while (i < mitad){
        while (j < fin and A[i] > A[j]){
            j++;
            ambos++;
        }
        i++;
    }
    return izq + der + ambos;
}
```


En cada paso dividimos el arreglo en dos mitades y contamos las parejas en desorden del medio en $O(n)$, por lo tanto la complejidad temporal del algoritmo es $O(n \log n)$ en el peor caso.
 