<font face = "LaTeX">

### CazadorDeFalsos

*Se tiene una matriz booleana A de n × n y una operación conjunciónSubmatriz que toma O(1) tiempo y que dados 4 enteros $i_0 , i_1 , j_0 , j_1$ devuelve la conjunción de todos los elementos en la submatriz que toma las filas $i_0$ hasta $i_1$ y las columnas $j_0$ hasta $j_1$ . Formalmente:*

$conjunciónSubmatriz(i_0 , i_1 , j_0 , j_1 ) = \bigwedge_{i_0 ≤i≤i_1 ,j_0 ≤j≤j_1}^{} A[i,j]$

---

*1. Dar un algoritmo de complejidad temporal estrictamente menor que $O(n^2 )$ que calcule la posición de algún false, asumiendo que hay al menos uno. Calcular y justificar la complejidad del algoritmo.*

---

Podemos utilizar una estrategia de división y conquista, similar a la búsqueda binaria, pero aplicada en dos dimensiones.

Comenzamos verificando la mitad de las filas y columnas con conjunciónSubmatriz.\
Si el resultado es false, significa que hay al menos un false en esa submatriz. Divide esa área en partes más pequeñas y repite.\
Si el resultado es true, significa que todos son true en esa área, así que verifica las otras áreas de la matriz.
    
```python
def cazadorDeFalsos(A):
    n = len(A)
    i0, i1, j0, j1 = 0, n-1, 0, n-1
    while i0 < i1 and j0 < j1:
        im = (i0 + i1) // 2
        jm = (j0 + j1) // 2
        if not conjunciónSubmatriz(i0, im, j0, jm):
            i1, j1 = im, jm
        elif not conjunciónSubmatriz(i0, im, jm+1, j1):
            i1, j0 = im, jm+1
        elif not conjunciónSubmatriz(im+1, i1, j0, jm):
            i0, j1 = im+1, jm
        else:
            i0, j0 = im+1, jm+1
    return i0, j0
```

La complejidad de este algoritmo es $O(\log n)$, ya que en cada iteración se divide la matriz en 4 submatrices de tamaño $\frac{n}{2} \times \frac{n}{2}$.

---

*2. Modificar el algoritmo anterior para que cuente cuántos false hay en la matriz. Asumiendo que hay a lo sumo 5 elementos false en toda la matriz, calcular y justificar la complejidad del algoritmo. Esto se puede lograr con complejidad menor a $O(n^2 )$.*

---


</font>