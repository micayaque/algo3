PotenciaSum
---
Suponga que se tiene un método $\color{violet}\text{potencia}$ que, dada un matriz cuadrada $\text{A}$ de orden $4 × 4$ y un número $\text{n}$, computa la matriz $A^n$.

Dada una matriz cuadrada $\text{A}$ de orden $4 × 4$ y un número natural $\text{n}$ que es $\text{potencia}$ de $2$ (i.e., n = $2^k$ para algun $k \geq 1$), desarrollar, utilizando la  técnica de dividir y conquistar y el método $\text{potencia}$,
un algoritmo que permita calcular 

```math
\color{violet}A^1 + A^2 + A^3 + . . . + A^n
```

Procure que el algoritmo propuesto aplique el método $\text{potencia}$, sume y haga productos de matrices una cantidad estrictamente menor que $\text{O(n)}$ veces.

Propiedades sobre la multiplicación de matrices y sus potencias:

$(1)\ A(B + C) = AB + AC$

$(2)\ A^i × A^j = A^{i+j}$

```math
\color{violet}A^1 + A^2 + A^3 + . . . + A^n = A^1 + A^2 + A^3 + . . . + A^{\frac{n}{2}} + A^{\frac{n}{2}+1} + . . . + A^n
```
Usando las propiedades $(1)$ y $(2)$:
```math
A^{\frac{n}{2}} + A^{\frac{n}{2}+1} + . . . + A^n = A^{\frac{n}{2}} * (A^1 + A^2 + A^3 + . . . + A^{\frac{n}{2}})
```
Por lo tanto:
```math
\color{violet}A^1 + A^2 + A^3 + . . . + A^n = A^1 + A^2 + A^3 + . . . + A^{\frac{n}{2}} + A^{\frac{n}{2}} * (A^1 + A^2 + A^3 + . . . + A^{\frac{n}{2}})
```

```C++
#include <armadillo>
using namespace arma;

mat potencia_sum(mat A, int n) {
    if (n == 1) return A;
    
    mat mitad_izq = potencia_sum(A, n / 2);

    mat A_n_2 = potencia(A, n/2);

    return mitad_izq + (A_n_2 * mitad_izq);
}
```