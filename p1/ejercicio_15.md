<font face="LaTeX">

## Suma Golosa

Queremos encontrar la suma de los elementos de un multiconjunto de números naturales. Cada suma se realiza exactamente entre dos números $ x $ e $ y $ y tiene costo $ x + y $.\
Queremos encontrar la forma de sumarlos que tenga costo mínimo.

---

*a) Explicitar una estrategia golosa para resolver el problema.*

Podemos ordenar los elementos de forma creciente. Para recorrerlos de izquierda a derecha minimizando en cada paso el costo de la suma de <u>cada elemento</u>.

```python
def sumaGolosa(multiconjunto):
    costo = multiconjunto[0] + multiconjunto[1]
    for i in range(2, len(multiconjunto):
        costo += multiconjunto[i]
    return costo
```

*b) Demostrar que la estrategia propuesta resuelve el problema.*

Para demostrar la correctitud de un algoritmo greedy, debemos asegurarnos de que la elección greedy (en este caso, elegir sumar los elementos de menor a mayor para minimizar el costo que es el resultado de la suma de los elementos) es siempre óptima. La estrategia se basa en dos principios fundamentales de los algoritmos greedy: la propiedad greedy y la elección óptima local.

* Propiedad Greedy: Necesitamos demostrar que al hacer la elección greedy, aún podemos llegar a una solución óptima global. Para este problema, elegir sumar a partir de los elementos más chicos disponibles en cada paso asegura que la suma parcial de los costos sea lo más chica posible en cada etapa, acercándonos al mínimo global.

* <u>Elección Óptima Local</u>: Tenemos que demostrar que hacer la elección óptima local (en este caso, sumar el mínimo valor disponible que aún no ha sido seleccionado) nos llevará a la **solución óptima global**. Esto se puede demostrar por contradicción: si **suponemos que hay una solución óptima que no incluye la elección greedy** (es decir, no incluye sumar los valores más chicos al principio minimizando los costos en cada paso), siempre podríamos reemplazar uno de los valores en esta solución **"óptima"** por uno de los valores elegidos por el algoritmo greedy, decrementando así la suma total, lo que contradice la suposición de que la solución original era óptima.

`{1, 2, 5}`costo = (1+2) = 3 + (3+5) = 8 => = 11

`{1, 5, 2}`costo = (1+5) = 6 + (6+2) = 8 => = 14

`{2, 5, 1}`costo = (2+5) = 7 + (7+1) = 8 => = 15

    
c) Implementar esta estrategia en un algoritmo iterativo. Nota: el mejor algoritmo simple que
conocemos tiene complejidad O(n log n) y utiliza una estructura de datos que implementa
una secuencia ordenada.

**HeapSort** 

</font>