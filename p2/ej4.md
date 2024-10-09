Teorema Maestro
---
Sea $T(\textcolor{red}{n}) = \textcolor{violet}{a}T(\frac{\textcolor{red}{n}}{\textcolor{purple}{b}}) + f(\textcolor{red}{n})$, con $\textcolor{violet}{a} \geq 1$ y $\textcolor{purple}{b} > 1$, entonces:

* Si $f(\textcolor{red}{n}) = O({\textcolor{red}{n}}^{\log_{\textcolor{purple}{b}}{\textcolor{violet}{a}-\epsilon}})$ para algún $\epsilon > 0$, entonces:
```math
T(\textcolor{red}{n}) = \Theta(n^{\log_{\textcolor{purple}{b}}{\textcolor{violet}{\textcolor{violet}{a}}}})
```
* Si $f(\textcolor{red}{n}) = \Theta({\textcolor{red}{n}}^{\log_{\textcolor{purple}{b}}{\textcolor{violet}{a}}})$, entonces:
```math 
T(\textcolor{red}{n}) = \Theta({\textcolor{red}{n}}^{\log_{\textcolor{purple}{b}}{\textcolor{violet}{a}}}\log {\textcolor{red}{n}})
```
* Si $f({\textcolor{red}{n}}) = \Omega({\textcolor{red}{n}}^{\log_{\textcolor{purple}{b}}{\textcolor{violet}{a}+\epsilon}})$ para algún $\epsilon > 0$, y si $\textcolor{violet}{a}f(\frac{\textcolor{red}{n}}{\textcolor{purple}{b}}) \leq kf(\textcolor{red}{n})$ para alguna constante $k < 1$ y suficientemente grande $\textcolor{red}{n}$, entonces: 
```math
T(\textcolor{red}{n}) = \Theta(f(\textcolor{red}{n}))
```
---

ComplexityQuest
---
Calcule la complejidad de un algoritmo que utiliza $T(n)$ pasos para una entrada de tamaño $n$, donde $T$ cumple:

### $1) T (n) = T (n − 2) + 5$

```math
T(n-2) = T(n-4) + 5 
```
```math
T(n-4) = T(n-6) + 5
```
```math
\dots 
```
```math
T(2) = T(0) + 5 \\
```
```math
T(0) = c
```
```math
T(n) = T(n - 2k) + 5
```
```math
n-2k = 0 \Rightarrow k = \frac{n}{2}
```
---
```math
T(0) = c
```
```math
T(2) = T(0) + 5 = c + 5
```
```math
T(4) = T(2) + 5 = c + 5 + 5 
```
```math
T(6) = T(4) + 5 = c + 5 + 5 + 5 
```
```math
\dots
```
```math
\color{lime}T(n) = c + \frac{n}{2}*5 = O(c + \frac{5n}{2}) = O(n)
```

$2) T (n) = T (n − 1) + n$

$3) T (n) = T (n − 1) + \sqrt{n}$



$4) T (n) = T (n − 1) + n^2$

$5) T (n) = 2T (n − 1)$

$6) T (n) = T (\frac{n}{2}) + n$

$7) T (n) = T (\frac{n}{2}) + \sqrt{n}$

$8) T (n) = T (\frac{n}{2}) + n^2$

$9) T (n) = 2T (n − 4)$

$10) T (n) = 2T (\frac{n}{2}) + log n$

$11) T (n) = 3T (\frac{n}{4})$

$12) T (n) = 3T (\frac{n}{4}) + n$

Intentar estimar la complejidad para cada ítem directamente y luego calcularla utilizando el teorema maestro de ser posible. 

Para simplificar los cálculos se puede asumir que $n$ es potencia o múltiplo de $2$ o de $4$ según sea conveniente.

