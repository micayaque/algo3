
```python
def izquierda_dominante(arr):
    def _izquierda_dominante(arr, start, end):
        if start == end - 1:
            return arr[start] > arr[end]
        m = (start + end) // 2
        left = _izquierda_dominante(arr, start, m - 1)
        right = _izquierda_dominante(arr, m, end)
        if left and right:
            return sum(arr[start:m]) > sum(arr[m:end + 1])
        return False
    return _izquierda_dominante(arr, 0, len(arr) - 1)
```

![algoritmo_ejemplo](./img/algoritmo_ejercicio1.png)

A esta altura del algoritmo llegamos a todos los casos base y retornamos en todos los casos true porque se cumplen.\
Luego de hacer todas las llamadas recursivas y llegar a estos casos base, se retorna el resultado de la comparación de las sumas de las mitades.
Entonces "volvemos para arriba en la recursión" y vamos comparando las sumas de las mitades de los subarreglos que se van formando.\
Si en algún momento no se cumple la condición de que la suma de la mitad izquierda sea mayor a la de la derecha, se retorna False y se corta la recursión.

Entonces sumamos 8+6=14 y 7+4=11, 14>11, luego sumamos 5+1=6 y 3+2=5, 6>5 y finalmente sumamos 8+6+7+4=25 y 5+1+3+2=11, 25>11.\
Por lo tanto, el algoritmo retorna True para el ejemplo de la izquierda.

En el caso de la derecha, los casos base tambien dan todos True, pero en la comparación de las sumas de las mitades de los subarreglos que se van formando, no se cumple la condición de que la suma de la mitad izquierda sea mayor a la de la derecha.\
Entonces sumamos 8+4=12 y 7+6=13, 12<13, entonces el algoritmo retorna False para el ejemplo de la derecha.

</font>