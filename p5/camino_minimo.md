# Dijkstra

Nos da los caminos mı́nimos de uno a todos en (di)grafos con pesos en las aristas, por lo que también nos da los de uno a uno

* Sirve cuando no hay aristas de peso negativo
* Su complejidad es $O(min\{m log (n), n^2 \})$

# Bellman-Ford

* También nos da los caminos mı́nimos de uno a todos en
(di)grafos pesados.
* Bellman-Ford detecta los ciclos de peso negativo
* Su complejidad es $O(mn)$

## Recorrido Mı́nimo:

## BFS
## Dijkstra
## Bellman-Ford

> Sea $G = (V , E )$ un (di)grafo con una función de costo para las aristas $c : E \to R$, y $v$ un vértice de $G$. 

> Para todo $w \in V$, encontrar la mı́nima suma del costo de las aristas de un recorrido desde $v$ a $w$.

¿Se puede resolver con **BFS**?

El costo tiene que ser el mismo para todas las aristas.

¿Complejidad? $O(|V | + |E |)$ sobre lista de adyacencias.

¿Se puede resolver con **Dijkstra**?

El costo tiene que ser $\geq 0$.

¿Complejidad? $O(min\{|E | log |V |, |V |^2 \})$ sobre lista de adyacencias.

¿Se puede resolver con **Bellman-Ford**? Sı́!

¿Qué pasa si hay un ciclo con suma de costos negativa? 

Te lo dice.

¿Complejidad? $O(|V ||E |)$ sobre lista de adyacencias.

# Ejercicios

## Policı́as

> La nueva reglamentación de una ciudad establece que toda esquina debe estar a lo sumo a $5$ cuadras de una estación de policı́a. 

> Dada la lista de esquinas $\{v_1 , . . . , v_n \}$ de la ciudad, la lista $\{p_1 , . . . , p_k \}$ de esquinas donde hay $\text{policı́as}^2$ , y la lista $E$ de calles, debemos indicar si la normativa se cumple, y en caso contrario cuáles esquinas son las que quedan “desprotegidas”.

> $\text{}^2$ O sea, asumimos que la policı́a siempre se ubica en una esquina.

## Resolución

Primero el modelado: en este caso es bastante directo, las esquinas son los nodos, y las calles los ejes.

Entonces lo que nos pide el enunciado es que todo nodo esté a una distancia menor o igual a 5 de un nodo policı́a.

¿Conocemos algún algoritmo que nos permita resolver este
problema?

Podemos correr un **BFS** desde cada vértice $v$ y ver la
distancia de cada uno a la estación de policı́a más cercana.

La complejidad de esto es $O(|v | (m + n))$. ¿Se puede
mejorar?

Si pudiésemos correr un **BFS** desde todas las estaciones de policia a la vez y cortarlo cuando la distancia es mayor a 5, guardándonos los nodos a los que puedo llegar nos estarı́amos guardando todos los vértices que cumplen.

Pero hay una manera mucho más simple.

Cambiemos un poquito nuestro modelo: agregamos un `nodo
fantasma` $z$ al grafo y lo conectamos con todos los policı́as.

En este nuevo grafo el problema va a ser un poco distinto.

Corriendo **BFS** desde $z$ y viendo qué nodos están a distancia mayor a $6$ nos alcanza para resolverlo (y con complejidad $O(m + n)$).

Recapitulando entonces:
1. Definimos el grafo $G = (\{v_1 , . . . , v_n \}, E)$ como lista de adyacencias. Complejidad: $O(n + m)$.
2. Definimos el grafo $G'$ como el resultado de agregar un vértice fantasma a $G$ adyacente a todos los vértices $\{p_1 , . . . , p_k\}$. Complejidad: $O(k)$.
3. Corremos **BFS** en $G'$ desde el nodo fantasma, guardando las distancias a cada vértice. Complejidad: $O(n + m)$.
4. Restamos $1$ a todas las distancias. Complejidad: $O(n)$.

5. Si no hay vértices con distancia mayor a $5$, decimos que la normativa se cumple. De lo contrario, enumeramos los vértices con distancia mayor a $5$. Complejidad: $O(n)$.

Complejidad total: $O(n + m + k) = O(n + m)$.

Ahora solo nos queda demostrar que lo que hicimos vale y da la misma respuesta que en el grafo original. Es decir, hay que probar el siguiente lema:

> Un nodo $v$ está a distancia menor o igual a $5$ de un policı́a si y solamente si $v$ está a distancia menor o igual a $6$ de $z$.

### Demostración

En lugar de demostrar ese lema vamos a demostrar algo un poco más fuerte: lo vamos a probar para todo problema de camino mı́nimo con múltiples orı́genes. 

Es decir, sea $z$ el nodo fantasma y $S$ el conjunto de orı́genes queremos ver que $\forall v\ d(z, v ) = min_{s \in S} \{d(s, v )\} + 1 $

$\forall v\ d(z, v) = min_{s \in S} \{d(z, s) + d(s, v) \} + 1 $ ya que $z$ solo está conectado a los nodos $S$.

$\{d(z, s)\} = 1$ ya que $z$ está conectado a todos los orı́genes con una arista. 

Por lo tanto $\forall v\ d(z, v ) = min_{s\in S} \{d(s, v ) + 1\}$

Si sacamos el $1$ hacia afuera queda $\forall v\ d(z, v) = min_{s\in S} \{d(s, v)\} + 1$ tal como querı́amos probar.

## 2. Martín y los Mares

Martín es un conocido comerciante marítimo. Planea cruzar el Mar Tortugoso empezando desde la isla Anastasia, parando en algunas islas para comerciar y descansar, y llegando a la isla Betuna. 

Sabe que la mayor amenaza a su barco no son los piratas: son los percebes que se enganchan y pudren la madera. 

También sabe qué camino entre las piedras debe usar para pasar de una isla a otra, y tiene tan estudiadas las rutas que sabe exactamente cuántos percebes van a engancharse a su barco en cada ruta.

En algunas de esas rutas, sin embargo, ocurre lo contrario: tortugas marinas vienen y se comen un porcentaje de los percebes que tenga el barco.

Lamentablemente, Martín sabe que es muy peligroso pasar por dos de estas rutas, ya que las tortugas a veces muerden de más. 

Por lo tanto, quiere pasar por máximo una sola de las rutas con tortugas.

Martín cursó TDA pero hace muuucho tiempo, y entonces les pregunta a ustedes cuál es la mínima cantidad de percebes con la que puede alcanzar el otro lado del Mar Tortugoso.

## Resolución

Por simplicidad, llamemos $A$ y $B$ a Anastasia y Betuna, respectivamente. Podríamos empezar
modelando un digrafo $D$ con vértices $A$, $B$, y las islas intermedias, y con aristas correspondiendo a
las rutas, con costo $c(u, v)$ para los que suman percebes, y con porcentaje $t(u, v)$ (representado como
fracción) para los que multiplican por un porcentaje.

Uno entonces pensaría quizá encontrar el camino mínimo desde $A$ hasta $B$ con algún algoritmo que conozcamos. 

Esto tiene dos problemas:
1. Los costos no son todos sumados al costo de un camino: algunos son un producto por una fracción.
2. El camino puede pasar por máximo una arista de tortugas, y no estamos restringiendo eso de ninguna manera acá.

Tenemos que pensar un poco más.

Antes de poder usar alguno de los algoritmos que conocemos tenemos que pensar qué hacemos con las aristas de tortugas, que me dividen. 

En principio vamos a sacarlas y despues vemos cómo las agregamos nuevamente. 

Trabajamos sobre el digrafo $D'$ que es igual al $D$ sacando las aristas con tortugas.

Usando Dijkstra vamos a aplicar una técnica que se usa bastante para este tipo de problemas: en lugar de correr una sola vez el algoritmo de camino mínimo vamos a correrlo dos veces. 

Pero, ¿desde qué nodos? Estamos intentando llegar de un vértice $A$ a otro $B$ así que seguramente tengamos que correrlo desde $A$. 

¿Podemos correr Dijkstra desde $B$? Quizás así nomás no pero si damos vuelta la orientación de las aristas del digrafo (trasponemos el digrafo) puede servir. Veámoslo de a pasitos:

Primero corremos Dijkstra desde $A$, por lo que obtenemos los pesos de los caminos desde $A$ a todos los nodos del digrafo $D'$. 

Luego trasponemos el digrafo y hacemos un Dijkstra pero desde $B$, lo que nos da los pesos de todos a $B$ en el digrafo $D'$. 

Pero, ¿para qué nos sirve esto? En este momento es cuando vuelven a aparecer las aristas que sacamos, ya que para cada arista $(u, v)$ que sacamos podemos calcular cuál sería el costo mínimo de un recorrido que tiene a esa arista. 

La cuenta que hacemos para cada arista va a ser: $w(A, u) ∗ (1 − t(u, v)) + w(v, B)$ (siendo $w(·, ·)$ el peso del camino mínimo y $t(·, ·)$ el porcentaje removido en una arista tortuga). 

Recordemos que el costo de las aristas con tortugas es el porcentaje de percebes que comen, por eso no es solo sumar el costo de la arista.

Repasemos los pasos del algoritmo:
1. Corremos Dijkstra desde $A$. Complejidad: $O(min\{mlog(n), n^2 \})$.
2. Trasponemos el digrafo. Complejidad: $O(m + n)$.
3. Corremos Dijkstra desde $B$. Complejidad: $O(min\{mlog(n), n^2\})$.
4. Para cada “arista tortuga” calculamos el peso del recorrido que la usa con $w(A, u)∗(1−t(u, v))+ w(v, B)$ y devolvemos el camino con menor peso. Complejidad: $O(m)$.

Entonces la complejidad del algoritmo es $O(min\{mlog(n), n^2\} + n)$.

## Demostración de correctitud
Para la demostración queremos ver que el algortimo devuelve la solución óptima, donde la solución óptima y lo que devuelve el algoritmo son:

$min(\text{\color{red}Pesos de todos los caminos que no tienen aristas tortuga}, \text{\color{violet}Pesos de los caminos con exactamente una arista tortuga})$.

Para facilitar la notación será $min(\text{\color{red}P}_{\color{red}sin} , \text{\color{violet}P}_{\color{violet}con})$.

Algoritmo:

$min(\{\text{\color{lime}Peso mínimo de camino sin aristas tortuga}\}, \{\color{cyan}w(A, u) ∗ (1 − t(u, v)) + w(v, B) | (u, v) es una arista tortuga\})$.

Para facilitar la notación será $min({\color{lime}P'_{sin}}, {\color{cyan}P'_{con})}$. 

$\color{lime}P'_{sin}$ debo considerarlo para el caso que convenga pasar por $0$ aristas tortuga.

Ver que $min({\color{red}P_{sin}}) = min({\color{lime}P'_{sin}})$ es trivial ya que $min({\color{red}P_{sin}})$ es exactamente el peso mínimo de camino sin aristas tortuga, pero ¿cómo veo que $min({\color{violet}P_{con}}) = min({\color{cyan}P'_{con}})$?

Lo vamos a probar viendo que $min({\color{cyan}P_{con}}) \geq min({\color{violet}P_{con}})$ y que $min({\color{cyan}P'_{con}}) \leq min({\color{violet}P_{con}} )$:

* $min({\color{cyan}P'_{con}}) \geq min({\color{violet}P_{con}})$: como en $\color{cyan}P'_{con}$ tenemos los pesos de los caminos con una arista tortuga tal que los costos de $A$ a $u$ y de $v$ a $B$ son mínimas, sabemos que estará incluido en los pesos de todos los caminos que tienen exactamente $1$ arista tortuga (aunque no tengamos los mínimos) entonces ${\color{cyan}P'_{con}} \subseteq {\color{violet}P_{con}}$.

    Además, sabemos que ${\color{cyan}P'_{con}} \subseteq {\color{violet}P_{con}} \Rightarrow min({\color{cyan}P'_{con}}) \geq min({\color{violet}P_{con}})$ pues como todo elemento en $\color{cyan}P'_{con}$ está en $\color{violet}P_{con}$ , el mínimo de $\color{violet}P_{con}$ será al menos tan chico como el mínimo de $\color{cyan}P'_{con}$ que tiene menos elementos, con lo que probamos que $min({\color{cyan}P'_{con}}) \geq min({\color{violet}P_{con}})$.

* $min({\color{cyan}P'_{con}}) \leq min({\color{violet}P_{con}})$: sabemos que $w(A, u)$ es mínimo y $w(v, B)$ también, por lo que $w(A, u)$ es menor o igual al peso de cualquier camino de $A$ a $u$ que no use aristas tortuga, y $w(v, B)$ es menor o igual al peso de cualquier camino de $v$ a $B$ que no use aristas tortuga. Como $t(u, v) \geq 0$, tenemos que $min({\color{cyan}w(A, u) ∗ (1 − t(u, v)) + w(v, B)}) ≤ min({\color{violet} \text{Pesos de los caminos con exactamente una arista tortuga}})$ (ya que los costos de las aristas tortugas son los mismos en $\color{violet}P_{con}$ y $\color{cyan}P'_{con}$), que es equivalente a $min({\color{cyan}P'_{con}}) \leq min({\color{violet}P_{con}})$.

$\Rightarrow$ Solución = algoritmo.

### Joaquı́n y los Monstruos

Joaquı́n estaba aburrido en la clase de TDA, ası́ que se puso a programar un juego. 

Quiere hacer que el jugador pase por distintos
mundos pasando por portales unidireccionales, matando los monstruos de los mundos por los que pasa. 

Cada portal $i$ por el que logra pasar le da $p_i \in R$ puntos. 

El objetivo del juego es llegar desde el mundo $m_1$ hasta el mundo $m_n$ con la mayor cantidad de puntos posible.

A Joaco le preocupa que el juego esté balanceado, ası́ que quiere saber cuál es la máxima cantidad de puntos que puede generar un
jugador dada la cantidad de mundos, los portales que hay, y cuántos puntos da cada portal. 

Además, quiere saber cuál es la mı́nima cantidad de portales que podrı́a estar tomando el jugador que hiciese la máxima cantidad de puntos posible.

Resolución Puntaje Máximo

Empecemos con el modelado:

Tenemos mundos que se conectan entre otros a través de portales, donde cada portal tiene un puntaje asignado ¿Cómo podemos modelar el problema?

Armamos un digrafo $G$ donde los nodos son los mundos, los ejes dirigidos los portales que llevan de un mundo a otro, y los
pesos de las aristas son el puntaje del portal.

Algunas consideraciones:

¿Qué serı́a una partida desde el punto de vista del grafo? Un recorrido $R$ que empieza desde el nodo $m_1$ y termina en el $m_n$.

Para el resto del problema asumamos que no hay ejes salientes de $m_n$ (¿Por qué es esto válido?).

¿Hay alguna cota para el máximo puntaje? Depende de si existe un ciclo $C$ de longitud positiva alcanzable por $m_1$ y que luego alcanza $m_n$. Lo tenemos que demostrar.

La puntuación máxima de las partidas no está acotada $\Leftrightarrow$ existe un ciclo $C$ de longitud positiva alcanzable por $m_1$ que luego alcanza $m_n$.

$\Leftarrow)$

Si existe un ciclo $C$ de longitud positiva alcanzable por $m_1$ que luego alcanza $m_n$, entonces un jugador podría partir de $m_1$, y tomar el ciclo tantas veces como quiera para luego ir a $m_n$ y terminar el juego. 

Por lo tanto, podría llegar con un puntaje arbitrariamente grande, y la puntuación no estaría acotada.

$\Rightarrow)$

Sabemos que la puntuación máxima no está acotada, o sea, para todo $s \in N$ existe un recorrido entre $m_1$ y $m_n$ cuya puntuación es mayor a $s$. 

Tomemos un $s$ gigante tal que no haya camino
simple que pueda sumar eso. 

Por ejemplo, tomemos que $s$ es la suma de todas las aristas positivas del digrafo. 

Como cada arista no puede aparecer más de una vez en un camino, es claro que ningún camino puede puntuar más que $s$. 

Por lo tanto, todo recorrido $R$ que puntúe más que $s$ repetirá alguna arista. 

Con esto es suficiente para decir que $R$, siendo un recorrido cualquiera que puntúe más que $S$, tiene un ciclo (¿Por qué?).

Supongamos que $R$ no contiene ningún ciclo positivo. Es decir, todos los ciclos que contiene suman algo negativo o $0$. 

Cada ciclo $C$ adentro de $R$ comenzará y terminará en el mismo vértice, digamos $v$. 

Podemos entonces tomar como $R'$ el resultado de eliminar el ciclo $C$ de $R$, y $R'$ será
un recorrido válido. 

Como $R$ debe tener una cantidad finita de ciclos, y eliminar un ciclo de un recorrido no genera nuevos ciclos, si realizamos esta operación hasta no poder más, el resultado
será un camino. 

Además, como ningún ciclo es positivo, eliminar cada ciclo de $R$ resulta en una
puntuación mayor o igual a la anterior. 

Al final, entonces, tendremos un camino con puntuación mayor o igual a la de $R$. 

Pero $R$ tenía una puntuación mayor a $s$, y por lo tanto el camino también la tendrá. ABSURDO! , ya que dijimos antes que ningún camino podría tener puntaje mayor a $s$. ¿Y dónde está lo que supusimos que nos llevó a la contradicción? Está en que dijimos que $R$ no tenía ningún ciclo positivo. 

Por lo tanto, $R$ sí tiene un ciclo positivo. Además, este ciclo positivo es alcanzable desde $m_1$ y alcanza $m_n$, porque hay un recorrido $R$ que va de $m_1$ a $m_n$ que lo alcanza. 

Finalmente, el ciclo pertenece al digrafo, y entonces llegamos al consecuente.

¿Cómo podemos hacer ahora para resolver un problema de recorrido máximo?

¡Si multiplicamos todos los pesos por -1 lo convertimos en un problema de recorrido mı́nimo!

Además los ”ciclos positivos” pasan a ser ciclos negativos.

¿Esto ya se parece más a un problema que podemos resolver, no?

No del todo, porque a nosotros solo nos importan los ciclos negativos que están en medio de un recorrido de $m_1$ a $m_n$, y
no sabemos cómo detectar solamente estos casos.

¿Cómo lo podemos solucionar? Necesitamos olvidarnos la parte de que los ciclos “alcancen a $m_n$”, para ello lo que podemos hacer es borrar todos los nodos
que no alcazan a $m_n$ y ya. (¿Por qué?)

Para ello alcanza con correr DFS desde $m_n$ en $G_t$ para ver que nodos no son alcanzables y eliminarlos.

Ahora sı́, definamos cómo quedarı́a el algoritmo:
1. Armamos el modelo.
2. Multiplicamos los pesos de las aristas por -1.
3. Eliminamos todos los nodos que no llegan a $m_n$ mediante DFS.
4. Ejecutamos Bellman-Ford desde $m_1$, y devolvemos infinito si encuentra un ciclo, y sino el opuesto del valor del recorrido
mı́nimo entre $m_1$ y $m_n$.

Pasemos ahora a la segunda parte del problema. 

Queremos saber cuál es la mínima cantidad de
portales que podría estar tomando el jugador que hiciese la máxima cantidad de puntos posible. Esta pregunta solo tiene sentido en el caso en el que no hubiera ciclos de puntaje positivo en algún camino entre $m_1$ y $m_n$, ya que sino no existiría tal puntaje máximo.

Para ello nos sería muy útil tener una noción de cuáles son todos los caminos posibles de puntaje máximo, y luego quedarnos con el más corto de todos ellos. ¿Cómo podemos conseguir algo así?

Lo que podemos hacer es obtener el “DAG de caminos mínimos” del grafo que representa nuestro problema. 

Esto es, un digrafo acíclico que contenga solamente las aristas que pertenezcan a algún
camino mínimo desde un nodo $s$ a un nodo $t$. En este caso nos interesaría el DAG de camino mínimo de $m_1$ a $m_n$.

¿Cómo lo conseguimos? Lo que podemos hacer es lo siguiente:

1. Corremos Bellman-Ford desde $m_1$ y obtenemos la distancia mínima de $m_1$ a todos los nodos, y nos la guardamos en un vector `DistanciaAm1`.
2. Corremos Bellman-Ford desde $m_n$ en $G_t$ (el grafo traspuesto) y obtenemos la distancia
mínima de todos los nodos a $m_n$, y nos la guardamos en un vector `DistanciaAmn`.
3. Armamos un DAG con los mismos nodos de $G$ pero (todavía) sin aristas.
4. Luego, para cada arista $(u, v) \in E$ Si $DistanciaA_{m_1} [u] + peso(u,v) + DistanciaA_{m_n} [v] = DistanciaA_{m_1} [m_n ]$, quiere decir que $(u, v)$ pertenece a un camino mínmo de $m_1$ a $m_n$ y por ende la agrego al DAG.

Observación: en este caso, como estamos asumiendo que no hay ciclos negativos, en lugar de Bellman-Ford también podríamos usar un algoritmo basado en DAGs (Correr topological sort, y relajar las aristas en ese orden).

¿Cómo hacemos para saber ahora el largo mínimo de un camino máximo? Como ya lo veníamos haciendo: simplemente corremos BFS desde $m_1$ en el DAG, y nos fijamos la altura a la que quedó $m_n$.

### Demostración

Una arista está en el DAG que construimos $\Leftrightarrow$ pertenecía a un camino mínimo de $G$.

$\Rightarrow)$

Si una arista $(u, v)$ está en el DAG es porque $DistanciaA_{m_1} [u] + peso(u,v) + DistanciaA_{m_n} [v] = DistanciaA_{m_1} [m_n]$. Con lo cual existe un camino $R$ de la forma $m_1 \to · · · \to u \to v \to · · · \to m_n$ cuyo peso es $DistanciaA_{m_1} [m_n]$, es decir que $(u, v)$ pertenece a un camino mínimo, siendo $R$ ese camino.

$\Leftarrow$

Si $(u, v)$ pertenece a un camino mínimo, entonces vale $DistanciaA_{m_1} [u] + peso(u,v) + DistanciaA_{m_n} [v] = DistanciaA_{m_1} [m_n]$, y por lo tanto el algoritmo la incluyó en el DAG.

Luego, el DAG efectivamente incluyó todas y solo las aristas que pertenecen a un camino
mínimo de $m_1$ a $m_n$. Y al hacer BFS en el DAG desde $m_1$, por BFS, mn va a tener la mínima distancia posible en el DAG a $m_1$, y por ende esa es la mínima distnacia posible con un camino mínimo.