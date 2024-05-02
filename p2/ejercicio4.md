<font face = "LaTeX">

## ComplexityQuest
*Calcule la complejidad de un algoritmo que utiliza T (n) pasos para una entrada de tamaño n, donde T
cumple:*

---

*Intentar estimar la complejidad para cada ítem directamente y luego calcularla utilizando el teorema maestro de ser posible. Para simplificar los cálculos se puede asumir que n es potencia o múltiplo de 2 o de 4 según sea
conveniente.*

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

### 3) T (n) = T (n − 1) + $\sqrt{n} $

Para calcular la complejidad de este algoritmo, se puede utilizar el **método de sustitución**.\
Se puede observar que la función $T(n)$ se llama a sí misma con un parámetro $n-1$.\
Podemos descomponer la recurrencia:\
$T(n) = T(n-1) + \sqrt{n}$\
$T(n-1) = T(n-2) + \sqrt{n-1}$\
$T(n-2) = T(n-3) + \sqrt{n-2}$\
Y así sucesivamente, hasta llegar a un caso base.

Si suponemos que el caso base es $T(0) = T(1) = C$, donde $C$ es una constante (el tiempo de ejecución para el problema más pequeño), podemos ver cómo se construye la solución:\
$T(2) = T(1) + \sqrt{2} = C + \sqrt{2}$\
$T(3) = T(2) + \sqrt{3} = C + \sqrt{2} + \sqrt{3}$\
$T(4) = T(3) + \sqrt{4} = C + \sqrt{2} + \sqrt{3} + \sqrt{4}$

De esta forma, se puede generalizar la función $T(n)$ como $T(n) = T(n-k) + \sqrt{n} + \sqrt{n-1} + \sqrt{n-2} + ... + \sqrt{2}$.

Para encontrar el valor de $k$, se iguala $n-k$ a 0 y se despeja $k$.\
$n-k = 0 \Rightarrow k = n$.\
Entonces, la función $T(n)$ se puede reescribir como $T(n) = T(0) + \sqrt{n} + \sqrt{n-1} + \sqrt{n-2} + ... + \sqrt{2} = C + \sum_{i=2}^{n} \sqrt{i} = \sum_{i=2}^{n} i^{1/2}$.\
Que es la suma geométrica de la raíz cuadrada de los números de 2 a n.\
Por lo tanto la complejidad de la función $T(n) = \frac{1 - n^{3/2}}{1 - n} $ es $O(n^{3/2})$.


---

### 4) T (n) = T (n − 1) + $n^2$

Se puede observar que la función $T(n)$ se llama a sí misma con un parámetro $n-1$.\
Podemos descomponer la recurrencia:\
$T(n) = T(n-1) + n^2$\
$T(n-1) = T(n-2) + (n-1)^2$\
$T(n-2) = T(n-3) + (n-2)^2$\
Y así sucesivamente, hasta llegar a un caso base.

Si suponemos que el caso base es $T(0) = T(1) = C$, donde $C$ es una constante (el tiempo de ejecución para el problema más pequeño), podemos ver cómo se construye la solución:\
$T(2) = T(1) + 2^2 = C + 2^2$\
$T(3) = T(2) + 3^2 = C + 2^2 + 3^2$\
$T(4) = T(3) + 4^2 = C + 2^2 + 3^2 + 4^2$

De esta forma, se puede generalizar la función $T(n)$ como $T(n) = T(n-k) + n^2 + (n-1)^2 + (n-2)^2 + ... + 2^2$.

Para encontrar el valor de $k$, se iguala $n-k$ a 0 y se despeja $k$.\
$n-k = 0 \Rightarrow k = n$.\
Entonces, la función $T(n)$ se puede reescribir como $T(n) = T(0) + n^2 + (n-1)^2 + (n-2)^2 + ... + 2^2 = C + \sum_{i=2}^{n} i^2$.\
Que es es una suma de cuadrados de términos consecutivos.\
Utilizando la fórmula para la suma de los primeros 
𝑛 cuadrados perfectos: $\sum_{i=1}^{n} i^2 = \frac{n(n+1)(2n+1)}{6}$\
Por lo tanto $\sum_{i=2}^{n} i^2 = \frac{n(n+1)(2n+1)}{6} - 1$\
Entonces, la complejidad de la función $T(n)$ es $O(n^3)$.

---

### 5) T (n) = 2T (n − 1)

Para calcular la complejidad de este algoritmo, se puede utilizar el **método de sustitución**.\
Se puede observar que la función $T(n)$ se llama a sí misma con un parámetro $n-1$.\
Podemos descomponer la recurrencia:\
$T(n) = 2T(n-1)$\
Reemplazando $T(n-1)$, tenemos:\
$T(n) = 2*2T(n-2) = 2^2*T(n-2)$\
$T(n) = 2^3T(n-3)$

De esta forma, se puede generalizar la función $T(n)$ como $T(n) = 2^kT(n-k)$.

Para encontrar la relación entre $n$ y $k$, consideramos el caso base.\
Generalmente, el caso base es $T(1)$ o $T(0)$, por lo que si $n-k = 1$, entonces $k = n-1$. Sustituyendo $k$ en la ecuación generalizada, tenemos:

$T(n) = 2^{n-1}T(1)$

Dado que $T(1)$ es un valor constante $C$, podemos ver que la complejidad de este algoritmo es $O(2^{n})$, que es exponencial.

---

**El <u>Teorema Maestro</u> se usa para ecuaciones de recurrencia de la forma $T(n) = aT(n/b) + f(n)$, donde las divisiones de $n$ son explícitas.**

---

### 6) T (n) = T ($\frac{n}{2}$) + n

Se puede observar que la función $T(n)$ se llama a sí misma con un parámetro $n/2$.\
Podemos descomponer la recurrencia:\
$T(n) = T(n/2) + n$\
$T(n/2) = T(n/4) + n/2$\
$T(n/4) = T(n/8) + n/4$\
Y así sucesivamente, hasta llegar a un caso base.

Si suponemos que el caso base es $T(1) = C$, donde $C$ es una constante (el tiempo de ejecución para el problema más pequeño), podemos ver cómo se construye la solución:\
$T(2) = T(1) + 2 = C + 2$\
$T(4) = T(2) + 4 = C + 2 + 4$\
$T(8) = T(4) + 8 = C + 2 + 4 + 8$

De esta forma, se puede generalizar la función $T(n)$ como $T(n) = T(n/2^k) + n + n/2 + n/4 + ... + 2$.\
Para encontrar el valor de $k$, se iguala $n/2^k$ a 1 y se despeja $k$.\
$\frac{n}{2^k}  = 1 \Rightarrow k = \log_2{n}$.\
Entonces, la función $T(n)$ se puede reescribir como:\
$T(n) = T(1) + n + n/2 + n/4 + ... + 2 = C + n + n/2 + n/4 + ... + 2 = C + n(1 + 1/2 + 1/4 + ... + 1/2^{\log_2{n}})$.\
Que es la suma de la serie infinita $1 + 1/2 + 1/4 + ... + 1/2^{\log_2{n}}$.\
Por lo tanto, la complejidad de la función $T(n)$ es $O(n)$.

---


---

Podemos calcular también la complejidad de la función $T(n)$ utilizando el **Teorema Maestro**.\
Para la función $T(n) = T(n/2) + n$, tenemos que $a = 1$, $b = 2$ y $f(n) = n$.\

---
<strong>El factor de división 𝑐 en el Teorema Maestro se refiere a la relación entre 𝑎 y 𝑏. Si $𝑎=𝑏^𝑐$, entonces el Teorema Maestro puede aplicarse directamente. En general, 𝑐 es un parámetro que describe cómo se divide el problema original en subproblemas más pequeños.</strong>

---

Calculamos el valor de $c = \log_b{a} = \log_2{1} = 0$.\
Dado que $f(n) = n = O(n^{0})$, entonces $f(n) = O(n^{c})$.\

$f(n)$, que es $n$, se compara con $n^{log_b a} = n^{log_2 1} = n^0 = 1$.\
Dado que $n$ crece más rápido que $n^0$, estamos en el caso 3 del teorema maestro, donde $f(n)$ es polinomialmente mayor que $n^{log_b a}$.

Para aplicar el caso 3, necesitamos que $f(n)$ sea también  polinomialmente mayor que $n^{log_b a}$ y que cumpla que $af(n/b) \leq kf(n)$ para alguna constante $k < 1$ y suficientemente grande $n$.\
En este caso simple, $f(n) = n$ claramente cumple con ser mayor que $n^0$.

Por lo tanto, por el teorema maestro, la complejidad de $T(n) = T(n/2) + n$ es $O(f(n)) = O(n)$.

---

### 7) T (n) = T ($\frac{n}{2}$) + $\sqrt{n}$

Se puede observar que la función $T(n)$ se llama a sí misma con un parámetro $\frac{n}{2}$.\
Podemos descomponer la recurrencia:\
$T(n) = T(n/2) + \sqrt{n}$\
$T(n/2) = T(n/4) + \sqrt{n/2}$\
$T(n/4) = T(n/8) + \sqrt{n/4}$\
Y así sucesivamente, hasta llegar a un caso base.

Si suponemos que el caso base es $T(1) = C$, donde $C$ es una constante (el tiempo de ejecución para el problema más pequeño), podemos ver cómo se construye la solución:\
$T(2) = T(1) + \sqrt{2} = C + \sqrt{2}$\
$T(4) = T(2) + \sqrt{4} = C + \sqrt{2} + \sqrt{4}$\
$T(8) = T(4) + \sqrt{8} = C + \sqrt{2} + \sqrt{4} + \sqrt{8}$

De esta forma, se puede generalizar la función $T(n)$ como:\
$T(n) = T(n/2^k) + \sqrt{n} + \sqrt{n/2} + \sqrt{n/4} + ... + \sqrt{2}$.\
Para encontrar el valor de $k$, se iguala $\frac{n}{2^k}$ a 1 y se despeja $k$.\

$\frac{n}{2^k} = 1 \Rightarrow k = \log_2{n}$.\
Entonces, la función $T(n)$ se puede reescribir como:\
$T(n) = T(1) + \sqrt{n} + \sqrt{n/2} + \sqrt{n/4} + ... + \sqrt{2} = C + \sqrt{n} + \sqrt{n/2} + \sqrt{n/4} + ... + \sqrt{2}$.\
Que es la suma de la serie infinita $\sqrt{n} + \sqrt{n/2} + \sqrt{n/4} + ... + \sqrt{2}$.\
Por lo tanto, la complejidad de la función $T(n)$ es $O(\sqrt{n})$ dado que es el término más grande de la sumatoria.

---

Podemos calcular también la complejidad de la función $T(n)$ utilizando el **Teorema Maestro**.\
Para la función $T(n) = T(n/2) + \sqrt{n}$, tenemos que $a = 1$, $b = 2$ y $f(n) = \sqrt{n}$.\
Calculamos el valor de $c = \log_b{a} = \log_2{1} = 0$.\
$f(n)$, que es $\sqrt{n}$, se compara con $n^{log_b a} = n^{log_2 1} = n^0 = 1$.\
Dado que $\sqrt{n}$ crece más rápido que $n^0$, estamos en el caso 3 del teorema maestro, donde $f(n)$ es polinomialmente mayor que $n^{log_b a}$.

Para aplicar el caso 3, necesitamos que $f(n)$ sea también  polinomialmente mayor que $n^{log_b a}$ y que cumpla que $af(n/b) \leq kf(n)$ para alguna constante $k < 1$ y suficientemente grande $n$.\
En este caso simple, $f(n) = \sqrt{n}$ claramente cumple con ser mayor que $n^0$.

Por lo tanto, por el teorema maestro, la complejidad de $T(n) = T(n/2) + \sqrt{n}$ es $O(f(n)) = O(\sqrt{n})$.

---

### 8) T (n) = T ($\frac{n}{2}$) + $n^2$

Se puede observar que la función $T(n)$ se llama a sí misma con un parámetro $n/2$.\
Podemos descomponer la recurrencia:\
$T(n) = T(\frac{n}{2}) + n^2$\
$T(\frac{n}{2}) = T(\frac{n}{4}) + (\frac{n}{2})^2$\
$T(\frac{n}{4}) = T(\frac{n}{8}) + (\frac{n}{4})^2$\
Y así sucesivamente, hasta llegar a un caso base.

Si suponemos que el caso base es $T(1) = C$, donde $C$ es una constante (el tiempo de ejecución para el problema más pequeño), podemos ver cómo se construye la solución:\
$T(2) = T(1) + 2^2 = C + 2^2$\
$T(4) = T(2) + 4^2 = C + 2^2 + 4^2$\
$T(8) = T(4) + 8^2 = C + 2^2 + 4^2 + 8^2$

De esta forma, se puede generalizar la función $T(n)$ como:\
$T(n) = T(\frac{n}{2^k}) + n^2 + (\frac{n}{2})^2 + (\frac{n}{4})^2 + ... + 2^2$.\
Para encontrar el valor de $k$, se iguala $\frac{n}{2^k}$ a 1 y se despeja $k$.\
$\frac{n}{2^k} = 1 \Rightarrow k = \log_2{n}$.\
Entonces, la función $T(n)$ se puede reescribir como:\
$T(n) = T(1) + n^2 + (\frac{n}{2})^2 + (\frac{n}{4})^2 + ... + 2^2 = C + n^2 + (\frac{n}{2})^2 + (\frac{n}{4})^2 + ... + 2^2$.\ 
Que es la suma de la serie infinita $n^2 + (\frac{n}{2})^2 + (\frac{n}{4})^2 + ... + 2^2$.\
Por lo tanto, la complejidad de la función $T(n)$ es $O(n^2)$ dado que es el término más grande de la sumatoria.

---

Podemos calcular también la complejidad de la función $T(n)$ utilizando el **Teorema Maestro**.\
Para la función $T(n) = T(\frac{n}{2}) + n^2$, tenemos que $a = 1$, $b = 2$ y $f(n) = n^2$.\
Calculamos el valor de $c = \log_b{a} = \log_2{1} = 0$.\
$f(n)$, que es $n^2$, se compara con $n^{log_b a} = n^{log_2 1} = n^0 = 1$.\
Dado que $n^2$ crece más rápido que $n^0$, estamos en el caso 3 del teorema maestro, donde $f(n)$ es polinomialmente mayor que $n^{log_b a}$.

Para aplicar el caso 3, necesitamos que $f(n)$ sea también  polinomialmente mayor que $n^{log_b a}$ y que cumpla que $af(n/b) \leq kf(n)$ para alguna constante $k < 1$ y suficientemente grande $n$.\
En este caso simple, $f(n) = n^2$ claramente cumple con ser mayor que $n^0$.

Por lo tanto, por el teorema maestro, la complejidad de $T(n) = T(\frac{n}{2}) + n^2$ es $O(f(n)) = O(n^2)$.

---

### 9) T (n) = 2T (n − 4)

Para calcular la complejidad de este algoritmo, se puede utilizar el **método de sustitución**.\
Se puede observar que la función $T(n)$ se llama a sí misma con un parámetro $n-4$.\
Podemos descomponer la recurrencia:\
$T(n) = 2T(n-4)$\
Reemplazando $T(n-4)$, tenemos:\
$T(n) = 2*2T(n-8) = 2^2*T(n-8)$\
$T(n) = 2^3T(n-12)$

De esta forma, se puede generalizar la función $T(n)$ como $T(n) = 2^kT(n-4k)$.

Para encontrar la relación entre $n$ y $k$, consideramos el caso base.\
Generalmente, el caso base es $T(1)$ o $T(0)$, por lo que si $n-4k = 1$, entonces $k = (n-1)/4$. Sustituyendo $k$ en la ecuación generalizada, tenemos:

$T(n) = 2^{\frac{(n-1)}{4}}*T(1)$

Dado que $T(1)$ es un valor constante $C$, podemos ver que la complejidad de este algoritmo es $O(2^{(n-1)/4})$, que es exponencial.

---

**El <u>Teorema Maestro</u> se usa para ecuaciones de recurrencia de la forma $T(n) = aT(n/b) + f(n)$, donde las divisiones de $n$ son explícitas.**

---

### 10) T (n) = 2T ($\frac{n}{2}$) + log n

Se puede observar que la función $T(n)$ se llama a sí misma con un parámetro $\frac{n}{2}$.\
Podemos descomponer la recurrencia:\
$T(n) = 2T(\frac{n}{2}) + \log{n}$\
$T(\frac{n}{2}) = 2T(\frac{n}{4}) + \log{\frac{n}{2}}$\
$T(\frac{n}{4}) = 2T(\frac{n}{8}) + \log{\frac{n}{4}}$\
Y así sucesivamente, hasta llegar a un caso base.

Si suponemos que el caso base es $T(1) = C$, donde $C$ es una constante (el tiempo de ejecución para el problema más pequeño), podemos ver cómo se construye la solución:\
$T(2) = 2T(1) + \log{2} = 2C + \log{2}$\
$T(4) = 2T(2) + \log{4} = 2(2C + \log{2}) + \log{4}$\  
$T(8) = 2T(4) + \log{8} = 2(2(2C + \log{2}) + \log{4}) + \log{8}$

De esta forma, se puede generalizar la función $T(n)$ como:\
$T(n) = 2T(\frac{n}{2^k}) + \log{n} + \log{\frac{n}{2}} + \log{\frac{n}{4}} + ... + \log{2}$.\
Para encontrar el valor de $k$, se iguala $\frac{n}{2^k}$ a 1 y se despeja $k$.\
$\frac{n}{2^k} = 1 \Rightarrow k = \log_2{n}$.\
Entonces, la función $T(n)$ se puede reescribir como:\
$T(n) = 2T(1) + \log{n} + \log{\frac{n}{2}} + \log{\frac{n}{4}} + ... + \log{2} = C + \log{n} + \log{\frac{n}{2}} + \log{\frac{n}{4}} + ... + \log{2}$.\
Que es la suma de la serie infinita $\log{n} + \log{\frac{n}{2}} + \log{\frac{n}{4}} + ... + \log{2}$.\
Por lo tanto, la complejidad de la función $T(n)$ es $O(\log{n})$ dado que es el término más grande de la sumatoria.

---

Podemos calcular también la complejidad de la función $T(n)$ utilizando el **Teorema Maestro**.\
Para la función $T(n) = 2T(\frac{n}{2}) + \log{n}$, tenemos que $a = 2$, $b = 2$ y $f(n) = \log{n}$.\
Calculamos el valor de $c = \log_b{a} = \log_2{2} = 1$.\
$f(n)$, que es $\log{n}$, se compara con $n^{log_b a} = n^{log_2 2} = n^1 = n$.\
Dado que $\log{n}$ crece más lentamente que $n$, estamos en el caso 3 del teorema maestro, donde $f(n)$ es polinomialmente menor que $n^{log_b a}$.

Para aplicar el caso 3, necesitamos que $f(n)$ sea también  polinomialmente menor que $n^{log_b a}$ y que cumpla que $af(n/b) \leq kf(n)$ para alguna constante $k > 1$ y suficientemente grande $n$.\
En este caso simple, $f(n) = \log{n}$ claramente cumple con ser menor que $n$.

Por lo tanto, por el teorema maestro, la complejidad de $T(n) = 2T(\frac{n}{2}) + \log{n}$ es $\theta(\log n)$.

---




</font>

