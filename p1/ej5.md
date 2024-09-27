### SumaDinámica

En este ejercicio vamos a resolver el problema de suma de subconjuntos usando la técnica de
programación dinámica.

#### a) Sea $n = |C|$ la cantidad de elementos de $C$. Considerar la siguiente función recursiva

$ss’_C(i,j) : \{0,...,n\} × \{0,...,k\} → \{V, F\}$ (donde V indica verdadero y F falso) tal que:

$$ss'_C(i,j) =  \begin{cases} j==0 & \text{si } i = 0 \\ ss'_C(i-1,j) & \text{si si i $\neq$ 0 ∧ C[i] > j} \\ ss’C (i−1, j) ∨ ss’C (i−1, j−C[i]) & \text{sino} \end{cases}$$

#### Convencerse de que esta es una definición equivalente de la función $ss$ del inciso e) del Ejercicio 1, observando que $ss(C, k) = ss’C (n, k)$. El algoritmo del inciso $f)$ es una implementación por backtracking de la función $ss’C$. $O(2^n)$ llamadas recursivas de $ss’C$ son suficientes para resolver el problema.

#### b) Observar que, como C no cambia entre llamadas recursivas, existen $O(n*k)$ posibles entradas para $ss’_C$. Concluir que, si $k ≪ \frac{2^n}{n}$, entonces necesariamente algunas instancias de $ss’_C$ son calculadas muchas veces por el algoritmo del inciso $f)$. Mostrar un ejemplo donde se calcule varias veces la misma instancia.

Ejemplo: $C = [6, 12, 6]$ y $k = 12$

Llamados recursivos:

1. $ss’_C(3, 12)$
2. $ss’_C(2, 6)$
3. $ss’_C(2, 12)$
4. $ss’_C(1, -6)$
5. $ss’_C(1, 6)$
6. $ss’_C(1, 0)$
7. $ss’_C(1, 12)$
8. $ss’_C(0, -12)$
9. $\textcolor{red}{ss’_C(0, -6)}$
10. $ss’_C(0, 0)$
11. $\textcolor{red}{ss’_C(0, -6)}$
12. $ss’_C(0, 6)$
13. $ss’_C(0, 12)$

#### c) Considerar la estructura de memoización (i.e., el diccionario) $M$ implementada como una matriz de $(n + 1) × (k + 1)$ tal que $M [i, j]$ o bien tiene un valor indefinido $⊥$ o bien tiene el valor $ss’_C (i, j)$, para todo $0 ≤ i ≤ n$ y $0 ≤ j ≤ k$. Convencerse de que el siguiente algoritmo top-down mantiene un estado válido para $M$ y computa $M [i, j] = ss’_C (i, j)$ cuando se invoca $ss’_C (i, j)$.


`subset_sum(C, i, j)`: Implementa $ss({c_1,...,c_i, j}) = ss’C(i, j)$ usando memoización.

```
1) Inicializar M[i][j] = ⊥ para todo 0≤i≤n y 0≤j≤k
subset_sum(C, i, j): 
    Si j<0 retornar falso
    Si i = 0 retornar (j = 0)
    Si M [i, j] = ⊥:
        Poner M[i][j] = subset_sum(C,i −1,j) ∨subset_sum(C,i −1,j −C[i])
    retornar M [i][j]
```

#### d) Concluir que `subset_sum(C, n, k)` resuelve el problema. Calcular la complejidad y compararla con el algoritmo `subset_sum` del inciso $f)$ del Ejercicio 1. ¿Cuál algoritmo es mejor cuando $k ≪ 2n$? ¿Y cuándo $k ≫ 2^n$?

La complejidad de este algoritmo es $ O(nk) $, ya que se calculan $n*k$ valores en la matriz $M$.

El algoritmo del inciso $f)$ del Ejercicio $1$ tiene una complejidad de $O(2^n)$, por lo que este algoritmo es mejor cuando $k ≪ 2^n$.

Por otro lado, cuando $k ≫ 2^n$, el algoritmo del inciso $f)$ del Ejercicio $1$ es mejor, ya que la complejidad de este algoritmo es $O(2^n)$.

#### e) Supongamos que queremos computar todos los valores de $M$ . Una vez computados, por definición, obtenemos que 
### $M [i,j] = ss’_C (i,j) = ss’_C(i−1, j) ∨ ss’_C(i−1, j−[i]) = M [i−1, j] ∨ M [i−1, j−C[i]]$ 
#### cuando $i > 0$, asumiendo que $M[i−1, j−C[i]]$ es falso cuando $j−C[i] < 0$. 
#### Por otra parte, $M[0, 0]$ es verdadero, mientras que $M[0, j]$ es falso para $j > 0$. A partir de esta observación, concluir que el siguiente algoritmo bottom-up computa $M$ correctamente y, por lo tanto, $M[i, j]$ contiene la respuesta al problema de la suma para todo $\{c_1 ,...,c_i \}$ y $j$.

```
1) subset_sum(C,k): // computa M[i,j] para todo 0 ≤ i ≤ n y 0 ≤ j ≤ k.
2) Inicializar M[0,j] := (j = 0) para todo 0 ≤j ≤k.
3) Para i = 1,...,n y para j = 0,...,k:
4) Poner M[i,j] := M[i −1,j] ∨(j −C[i] ≥0 ∧M[i −1,j −C[i]]
```

