### OptiPago
---
Tenemos un multiconjunto $B$ de valores de **billetes** y queremos comprar un producto de costo $c$ de una máquina que no da vuelto. 

Para poder adquirir el producto debemos cubrir su costo usando un subconjunto de nuestros billetes. El objetivo es pagar con el **mínimo exceso** posible a fin de minimizar nuestra pérdida. Más aún, queremos gastar el **menor tiempo** posible poniendo billetes en la máquina. 

Por lo tanto, entre las opciones de mínimo exceso posible, queremos una con la menor cantidad de billetes. 

Por ejemplo, si $c = 14$ y $B = (2, 3, 5, 10, 20, 20)$, la solución es pagar $15$, con exceso $1$, insertando sólo dos billetes: uno de $10$ y otro de $5$.

#### a) Considerar la siguiente estrategia por backtracking para el problema, donde $B = (b_1 , . . . , b_n )$.

#### Tenemos dos posibilidades: o agregamos el billete $b_n$, gastando un billete y quedando por pagar $c − b_n$ , o no agregamos el billete $b_n$, gastando 0 billetes y quedando por pagar c.

#### Escribir una función recursiva $cc(B, c)$ para resolver el problema, donde $cc(B, c) = (c′ , q)$ cuando el mínimo costo mayor o igual a c que es posible pagar con los billetes de B es c′ y la cantidad de billetes mínima es q.

Asumiendo que $i$ es un iterador de $B$

```math
 cc(B_i, c, q) =  \begin{cases} (\infty,\infty) & \text{si } i = n \ \land \ c \gt 0 \\ (c,q) & \text{si } i = n+1 \ \land \ c \leq \ 0 \\ (\pi_1 (cc(B_{i+1}, c, q)), min\{ \pi_2 (cc(B_{i+1}, c, q)),\ \pi_2(cc(B_{i+1}, c − b_n, q+1 )) \}) & \text{si $\pi_1 (cc(B_{i+1}, c, q)) = \pi_1(cc(B_{i+1}, c − b_n, q+1))$} \\ (max \{ \pi_1 (cc(B_{i+1}, c, q)), \pi_1(cc(B_{i+1}, c − b_n, q+1 )), \ q) & \text{sino} \end{cases}
```

#### b) Implementar la función de a) en un lenguaje de programación imperativo utilizando una función recursiva con parámetros $B, i, j$ que compute $cc((b_1 , . . . , b_i), j)$. ¿Cuál es la complejidad del algoritmo?

```C++
int min_cantidad_billetes = INT_MAX;
int cc(int B[], int i, int c, int q) {
    if (n == 0 && c > 0) return INT_MAX;
    if (n == 0 && c <= 0){
        min_cantidad_billetes = min(min_cantidad_billetes, q);
        return c;
    }
    int use = cc(B, i+1, c-B[i], q+1);
    int not_use = cc(B, i+1, c, q);
    return max(use, not_use);
}
```

La complejidad del algoritmo es $O(2^n)$.

#### c) Reescribir $cc$ como una función recursiva $cc’B (i, j) = cc(\{b_1 , . . . , b_i \}, j)$ que implemente la idea anterior dejando fijo el parámetro B. A partir de esta función, determinar cuándo $cc’B$ tiene la propiedad de superposición de subproblemas.

$cc’B$ tiene la propiedad de superposición de subproblemas cuando $2^n >> c*i $

#### d) Definir una estructura de memoización para $cc’B$ que permita acceder a $cc’B (i, j)$ en $O(1)$ tiempo para todo $0 ≤ i ≤ n \ , \ 0 ≤ j ≤ k$.

```C++
vector<vector<int>> memoizacion(n+1, vector<int>(c+1, -1));
```

#### e) Adaptar el algoritmo de b) para incluir la estructura de memoización.

```C++
int min_cantidad_billetes = INT_MAX;
int cc(int B[], int i, int c, int q) {
    if (memoizacion[i][c] != -1) return memoizacion[i][c];
    if (n == 0 && c > 0){
        memoizacion[i][c] = INT_MAX;
        return memoizacion[i][c];
    }
    if (n == 0 && c <= 0){
        min_cantidad_billetes = min(min_cantidad_billetes, q);
        memoizacion[i][c] = c;
        return memoizacion[i][c];
    }
    int use = cc(B, i+1, c-B[i], q+1);
    int not_use = cc(B, i+1, c, q);
    memoizacion[i][c] = max(use, not_use);
    return memoizacion[i][c];
}
```

#### f) Indicar cuál es la llamada recursiva que resuelve nuestro problema y cuál es la complejidad del nuevo algoritmo.

La llamada recursiva que resuelve nuestro problema es $cc(B, c)$. La complejidad del nuevo algoritmo es $O(n \cdot c)$.

