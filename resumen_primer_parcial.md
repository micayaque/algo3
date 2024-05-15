<u>Fuerza Bruta / Búsqueda exhaustiva</u>

* Para problemas de búsqueda en un conjunto S.
* Queremos hacer algo con los elementos que cumpla una cierta propiedad P.
* La idea más simple: recorremos todo S evaluando P en cada elemento.
* La complejidad en general será Ω(|S|).

Backtracking
---

*(Búsqueda exhaustiva + Podas)*

Dado un problema $\pi$, se puede resolver haciendo una $\color{lightgreen}\text{búsqueda exhaustiva}$ entre sus $\color{lightgreen}\text{soluciones candidatas}$.

La técnica de $\color{lightgreen}\text{backtracking}$ hace una exploración ordenada de este espacio de soluciones por medio de la extensión de $\color{lightgreen}\text{soluciones parciales}$. 

Cada posible extensión de una solución parcial es explorada haciendo $\color{lightgreen}\text{recursión}$ sobre la nueva solución extendida.

Podemos representar visualmente esta exploración como el recorrido en profundidad de un $\color{lightgreen}\text{árbol}$.

Frecuentemente es posible aplicar $\color{lightgreen}\text{podas}$ al árbol para reducir el espacio de búsqueda.

Podemos pensar una solución candidata como una tupla $(x_1, x_2, \ldots, x_k)$, donde $x_i$ es una desición de entre un conjunto $S_i$ de alternativas.

Pensamos la recursión como el problema donde alguna de estas desiciones ya vienen tomadas.

---
---

**Recursión**\
Las recursividad es una técnica que nos permite resolver el problema al reducirlo a operaciones más sencillas que emplean la solución de versiones más pequeñas del mismo.
* “Si es caso chiquito es fácil resolverlo” (Caso base)
* “Si tuviera resueltas estas partes, podría usarlas para resolver mi caso actual” (Caso
recursivo)

En backtracking usamos la recursión como un mecanismo para generar todo el espacio de soluciones.\
En muchos casos podremos saber si las soluciones que generamos no serán factibles u óptimas y evitando resolver el problema para algunas de las instancias recursivas (podas de factibilidad ú optimalidad).

Programación Dinámica
---

*(Búsqueda exhaustiva + solapamiento de subproblemas)*

$\color{lightgreen}\text{Top-Down}$

**Idea**: Si llamo a una función $\color{lightgreen}\text{más de una vez}$ con los mismos parámetros, me conviene computarla una sola vez y guardarme el resultado.

<u>Superposición de problemas</u>\
Decimos que tenemos $\color{lightgreen}\text{superposición de problemas}$ si la cantidad de llamadas recursivas de la función sin memorizar es *mucho mayor* que la cantidad de estados posibles.

$$\Omega(\# llamadasRecursivas) >> O(\# estados)$$

Entonces sabemos que vale la pena aplicar programación dinámica.

Nos interesarı́a resolver todos los subproblemas ya calculados en O(1).\
¿Cómo podemos hacerlo?\
Con una estructura de $\color{lightgreen}\text{memorización}$.\
Vamos a guardar todos los valores ya calculados en una estructura y leerlos cuando los volvamos a necesitar.

¿Pagamos algo por esta mejora en complejidad temporal?\
Estamos guardando más información en la memoria.\
Es decir, aumentó nuestra complejidad espacial.

<u>Pasos para evaluar superposición de subproblemas</u>

$\color{lightgreen}\text{Paso 1. Llamados recursivos}$\
¿cuántos llamados recursivos hace nuestra funciíon en peor caso?
$\color{lightgreen}\text{Paso 2. Cantidad de subproblemas a resolver}$\
¿cuántos subproblemas distintos tiene el problema? (¿cuántos estados distintos tiene el problema?)
Esto depende de la cantidad de parámetros que tenga la función y los posibles valores que puedan tomar.\
$\color{lightgreen}\text{Paso 3. Comparar las cotas}$
Si la cantidad de llamados recursivos es mucho mayor que la cantidad de subproblemas distintos, entonces vale la pena aplicar programación dinámica.

¿Qué estructura de memorización podemos usar para guardar los subproblemas ya resueltos?\
La solución suele ser una $\color{lightgreen}\text{matriz}$ con una dimensión para cada parámetro de entrada.

---
---

**Top-down**: Ir de lo **más general** a lo **más específico**.\
**Bottom-up**: Ir de lo **más específico** a lo **más general**.

Diferencias:

**Top-down**
* Recursivo en general
* A veces más fácil de programar (agarrás el backtracking, le agregás memorización y listo)

**Bottom-up**
* Iterativo en general
* A veces usa menos memoria
* A veces es más rápido en la práctica (recursión vs. iteración).

$\color{lightgreen}\text{Bottom-Up}$

En lugar de usar recursión usamos iteración.\
Iterativamente resolvemos todos los subproblemas, guardando los resultados en la estructura de memoización.\
En qué orden?

¿Cómo se piensan estos problemas?
* Identificar casos borde.
* Definir una función de recurrencia f.
* Demostrar que efectivamente f resuelve el problema.
* Implementarla y deducir la complejidad.

---
---

Dividir y conquistar
---
*(Partir subproblemas hasta que son resolubles de una manera más simple)*

* Dividir un problema en subproblemas del mismo tipo que el original.
* Resolver los problemas más pequeños.
* Combinar las soluciones.

* Las subpartes tienen que ser más pequeñas.
* Y ser el mismo tipo de tarea.
* Dividir y combinar pueden no ser nulas, pero no tienen que ser demasiado costosas.

**F(X)**
* Si X es suficientemente chico o simple, solucionar de manera ad hoc.
* Si no,
    * Dividir a X en $X_1 , X_2 , . . ., X_k$
    * $\forall i \leq k$, hacer $Y_i = F(X_i)$
    * Combinar los $Y_i$ en un Y que es una solución para X.
    * Devolver Y

$\color{lightgreen}\text{Teorema Maestro}$

Permite resolver relaciones de recurrencia de la forma:

$$ T(n) =  \begin{cases} aT(\frac{n}{c}) + f(n) & \text{si } n > 1 \\ 1 & \text{si } n = 1 \end{cases}$$

Si $f(n) = O(n^{\log_c a - \epsilon})$ para algún $\epsilon > 0$, entonces $T(n) = \Theta(n^{\log_c a})$.

Si $f(n) = \Theta(n^{\log_c a})$, entonces $T(n) = \Theta(n^{\log_c a} \log n)$.

Si $f(n) = \Omega(n^{\log_c a + \epsilon})$ para algún $\epsilon > 0$, y si $a f(\frac{n}{c}) < k f(n)$ para algún $k < 1$ y $n$ suficientemente grande, entonces $T(n) = \Theta(f(n))$. 

---
---

Algoritmos Greedy
---

*(Heurı́stica con la mejor opción local)*

Venimos viendo problemas cuyas soluciones se construyen tomando desiciones una a una.\
En cada elección, potencialmente hay una opción que localmente es la más atractiva.\
Es como tomar el árbol de backtracking y, en vez de comparar las ramas, elegir una según algún criterio.\
Frecuentemente, implica ordenar los elementos del input de alguna manera específica.

El algoritmo greedy para un problema dado nos proveerá una $\color{lightgreen}\text{solución candidata}$.\
La pregunta es si esa solución es $\color{lightgreen}\text{correcta}$ (por ejemplo, si es óptima).\
Es común que los algoritmos greedy no sean complejos de implementar y la dificultad esté en probar que son correctos.

En general hay dos formas de ver que un algoritmo goloso es óptimo:
* Demostrar que nuestro algoritmo siempre se mantiene ”adelante” de cualquier otra solución óptima $\color{lightgreen}\text{(Greedy stays ahead)}$.
* Mostrar que podemos agarrar una solución óptima y modificarla sin incrementar su costo y llevarla a la de nuestro algoritmo goloso $\color{lightgreen}\text{(Exchange argument)}$.

---
---



$\color{lightgreen}\text{}$