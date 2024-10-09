<font face = "LaTeX">

### PotenciaSum

*Suponga que se tiene un método potencia que, dada un matriz cuadrada A de orden 4 × 4 y un número n, computa la matriz $A^n$.\
Dada una matriz cuadrada A de orden 4 × 4 y un número natural n que es potencia de 2 (i.e., n = $2^k$ para algun k ≥ 1), desarrollar, utilizando la  técnica de dividir y conquistar y el método potencia,
un algoritmo que permita calcular $A^1 + A^2 + A^3 + . . . + A^n$.\
Procure que el algoritmo propuesto aplique el método potencia, sume y haga productos de matrices una cantidad estrictamente menor que O(n) veces.* 

---

Se puede observar que la suma de las potencias de una matriz $A$ hasta $A^n$ se puede descomponer en la suma de las potencias de $A$ hasta $A^{n/2}$ y la suma de las potencias de $A^{n/2+1}$ hasta $A^n$.\
De esta forma, se puede reescribir la suma de las potencias de $A$ hasta $A^n$ como:

$A^1 + A^2 + A^3 + . . . + A^n = A^1 + A^2 + A^3 + . . . + A^{n/2} + A^{n/2+1} + . . . + A^n$

Dado que $(n = 2^k )$ para algún $( k \geq 1 )$, podemos aprovechar la propiedad de que ( n ) es potencia de 2 para reducir el número de veces que necesitamos aplicar el método potencia, apuntando a una complejidad menor que $O(n)$.

Podemos observar que \
$A^1+A^2+...+A^n=(A^1+A^2+...+A^{n/2})+A^{n/2}*(A^1 + A^2 + \ldots + A^{n/2}).$ \
Esto se debe a la propiedad de las potencias de matrices, donde:
$A^{n/2+1} = A^{n/2} * A^1, A^{n/2+2} = A^{n/2} * A^2 )$, etc.


```python
def potenciaSum(A, n):
    if n == 1:
        return potencia(A,1)
    m = n//2
    return potenciaSum(A, m) + (potencia(A, m)*potenciaSum(A, m+1))
```

Otra forma de resolver el ejercicio agregando parámetros:
    
```python
def potenciaSum(A, d, h):
    if d == h:
        return potencia(A, d)
    m = (d+h)/2
    return potencia(A, m) + potenciaSum(A, d, m-1) + potenciaSum(A, m+1, h)
```
</font>

