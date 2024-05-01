<font face = "LaTeX">

## ComplexityQuest
*Calcule la complejidad de un algoritmo que utiliza T (n) pasos para una entrada de tamaño n, donde T
cumple:*

---

### 1) T (n) = T (n − 2) + 5
Para calcular la complejidad de este algoritmo, se puede utilizar el **método de sustitución**.\
Se puede observar que la función $T(n)$ se llama a sí misma con un parámetro $n-2$.\
Podemos descomponer la recurrencia:\
$T(n) = T(n-2) + 5$\
$T(n-2) = T(n-4) + 5$\
$T(n-4) = T(n-6) + 5$\
Y así sucesivamente, hasta llegar a un caso base.


Si suponemos que el caso base es $T(0) = T(1) = C$, donde $C$ es una constante (el tiempo de ejecución para el problema más pequeño), podemos ver cómo se construye la solución:\
$T(2) = T(0) + 5 = C + 5$\
$T(4) = T(2) + 5 = C + 5 + 5 = C + 2 \cdot 5$\
$T(6) = T(4) + 5 = C + 3 \cdot 5$

De esta forma, se puede generalizar la función $T(n)$ como $T(n) = T(n-2k) + 5k$.

Para encontrar el valor de $k$, se iguala $n-2k$ a 0 y se despeja $k$.\
$n-2k = 0 \Rightarrow k = n/2$.\
Entonces, la función $T(n)$ se puede reescribir como $T(n) = T(0) + 5n/2 = C + 5n/2$.\
La complejidad de la función $T(n)$ es $O(n)$.

---

### 2) T (n) = T (n − 1) + n

Para calcular la complejidad de este algoritmo, se puede utilizar el **método de sustitución**.\
Se puede observar que la función $T(n)$ se llama a sí misma con un parámetro $n-1$.\
Podemos descomponer la recurrencia:\
$T(n) = T(n-1) + n$\
$T(n-1) = T(n-2) + n-1$\
$T(n-2) = T(n-3) + n-2$\
Y así sucesivamente, hasta llegar a un caso base.

Si suponemos que el caso base es $T(0) = T(1) = C$, donde $C$ es una constante (el tiempo de ejecución para el problema más pequeño), podemos ver cómo se construye la solución:\
$T(2) = T(1) + 2 = C + 2$\
$T(3) = T(2) + 3 = C + 2 + 3 = C + 3 + 2$\
$T(4) = T(3) + 4 = C + 3 + 2 + 4 = C + 4 + 3 + 2$

De esta forma, se puede generalizar la función $T(n)$ como $T(n) = T(n-k) + n + (n-1) + (n-2) + ... + 2$.\
Para encontrar el valor de $k$, se iguala $n-k$ a 0 y se despeja $k$.\
$n-k = 0 \Rightarrow k = n$.\
Entonces, la función $T(n)$ se puede reescribir como $T(n) = T(0) + n + (n-1) + (n-2) + ... + 2 = C + n(n+1)/2$.\
La complejidad de la función $T(n)$ es $O(n^2)$.

---


</font>