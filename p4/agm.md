### Definición (Camino MaxiMin)

Sea $G$ un grafo, $c : E (G ) \to R$ su función de costos y $v , w \in V (G )$. 

Decimos que $P$ es un camino `MaxiMin` de $v$ a $w$ si se cumple que $P$ maximiza $c_{min} :$

$$c_{min} (P) = min \{ c(vw )| vw \in E (P) \}$$

También se lo conoce cómo el problema del camino más ancho.

> Si nos imaginamos los costos como capacidades, entonces queremos **maximizar** la capacidad que nuestro camino puede trasladar. Y la **capacidad de un camino** está dada por la capacidad de su arista más pequeña.

### Definición (Camino MiniMax)

Sea $G$ un grafo, $c : E (G ) \to R$ su función de costos y $v , w \in V (G )$.

Decimos que $P$ es un camino `MiniMax` de $v$ a $w$ si se cumple que $P$ minimiza $c_{max} :$

$$c_{max} (P) = max\{c(vw )| vw \in E (P)\}$$

### camino AGM ⇔ camino Minimax

Vamos a utilizar el `absurdo`.

Supongamos que **existe un camino minimax $P$ entre los vértices $a$ y $z$ que no está completamente en el $AGM\ T$** , siendo las aristas de $T$ las azules.

Esto significa que hay una arista $N(nueva) = (s, t)$ en $P$ que no está en $T$. 

Sea $Q$ el camino en $T$ desde $s$ hasta $t$. 

Sea $M(mayor)$ la arista de mayor peso en $Q$.

![image](/img/image%20copy.png)

Ahora hay 2 condiciones a considerar:
1. $\color{purple}peso(N) \lt peso(M)$: En ese caso, $T$ no es un $AGM$. Pues
existe $T' = T − M + N$ tal que $peso(T') < peso(T)$. Absurdo!
2. $\color{purple}peso(M) \geq peso(N)$: En este caso podrías eliminar $N$ de $P$ y
agregar las aristas de $Q$ en su lugar, y seguiría siendo un camino minimax, ya que no incluimos una arista con un peso mayor que el que ya estaba en ese camino antes.

Por cada arista $N$ en un camino minimax que no está en $T$, se puede realizar una sustitución de arista como se describe en el punto $2$, creando así un camino minimax que estará completamente en $T$.


## Ejercicio 1

Viaje en peligro

Cifu vive en Kruskal, Rusia, y quiere visitar las ciudades locales, pero su localidad no tiene rutas que lo conecten con el resto. 

En total hay $n$ ciudades, pero el presidente sólo le ofrece **construir $k << n$ rutas**, poniéndole 2 condiciones:

1. Que queden conectadas $k + 1$ localidades.
2. Que la red resultante sea una **subred** de la red que conecta a todas las localidades con costo mínimo.

Sabemos las **ubicaciones** de las localidades y que el **costo** de construir una ruta entre la localidad $x$ y la $y$ se calcula como $\color{purple}r * distEnKm(x, y) + c_{x,y}$ , donde $c_{x,y}$ depende de las localidades. 

Además sabemos en qué localidad se encuentra Cifu.

Queremos una red que cumpla lo pedido. 

¿Es única?

El formato del input es una línea que contiene dos enteros $n$ (cantidad de ciudades) y $k$ (cantidad de rutas). 

Luego tenemos $n$ lineas que tienen el formato $x_i$, $y_i$, las cuales representan la posición de la $i-ésima$ ciudad.

Tenemos que devolver la red de rutas que cumpla lo pedido.

El problema nos pide que queden $k + 1$ localidades conectadas a partir de $k$ rutas, por lo que podemos inferir que nos está
pidiendo generar un árbol.

Luego sabemos que k << n, por lo que el árbol que vamos a generar va a ser un subgrafo del grafo completo.

También nuestro algoritmo va a tener que comenzar desde la localidad de Cifu, puesto que queremos que la misma quede conectada.

Por último como queremos que el presupuesto utilizado sea el menor posible vamos a modelar este problema utilizando $AGM$.

Creamos un grafo con un vértice para cada localidad.

Calculamos las distancias en kilómetros entre las distintas localidades.

A partir de las distancias y los costos $c_{x,y}$ entre las localidades creamos las aristas con sus pesos asociados.

$$costo(x, y ) = distEnKm(x, y ) + c_{x,y}$$

Corremos Prim sobre nuestro grafo para obtener el $AGM$ parcial de tamaño $k$. 

¿Cuál es la complejidad?

Construir el grafo nos va a costar $O(n^2)$ (pues es el grafo completo). 

Luego si usamos la implementación $O(n^2)$ de Prim la complejidad nos va a quedar $O(nk)$.

Como $k << n$ la complejidad total es $O(n^2)$.

Con $n$ = cantidad de ciudades.

## Invariante de Prim

La consigna pide que la red resultante sea una subred de la red que conecta a todas las localidades con costo mínimo. 

¿Por qué pide eso y no que sea directamente la red que contenga a Kruskal que conecta a k localidades con costo mínimo? 

Esto se debe a que el invariante de Prim cumple que, en su $i-ésimo$ paso, va a tener un subgrafo de tamaño $i$ del $AGM$, no el
árbol de $i$ aristas mínimo entre los que contengan a la raíz.

En este grafo, por ejemplo, si arrancamos del nodo $K$ el árbol de i aristas que nos va a generar $Prim$ (el azul) no va a ser el
mínimo (el rojo).

![alt text](/img/image20.png)

## Ejercicio 2

Audífonos Defectuosos

Sasha vino de intercambio a Exactas y quiere ver cómo llegar desde su hogar hasta Ciudad Universitaria. 

Sus auriculares marca $AGM$ (auriculares generalmente malos) están rotos, por lo que no tiene forma de cancelar el sonido.

Conocemos todas las calles que conectan una esquina con otra en el mapa y tenemos una función $d$ la cual nos dice el volumen de cada calle. 

Sasha sufre mucho los sonidos fuertes, por lo que quiere encontrar una ruta que minimice el ruido máximo.

Queremos determinar cuál es el máximo nivel de ruido que tiene que soportar para llegar a Ciudad Universitaria desde su casa.

El formato del input es una línea que contiene dos enteros $C$ (cantidad de calles) y $E$ (cantidad de esquinas). 

Luego tenemos $C$ lineas que tienen el formato $e_i$, $e_j$, $d_{ij}$, las cuales
representan el nivel del ruido de la calle que conecta la esquina $i$ con la $j$.

Tenemos que devolver el umbral mínimo de tolerancia para Sasha.

¿Que propiedad tiene que tener el camino que Sasha quiere encontrar?

¿Cómo se llama este tipo de camino?

¿Qué herramienta tenemos para conocer este tipo de camino?

### Lema

> Sea $T$ un árbol generador de un grafo $G$ y $c : E (G ) \to R$ su función de costo. 

> Entonces, $T$ es un $AGM$ de $(G , c)$ si y sólo si todo camino de $T$ es `MiniMax` de $(G , c)$.

Creamos un grafo con un vértice correspondiente a cada esquina.

Agregamos una arista entre las esquinas que tengan una calle que las conecta y le colocamos un costo igual a su nivel de
ruido.

Buscamos el $AGM$ del grafo con $Prim$ o $Kruskal$. 

¿Cuál es la complejidad? 

$O(m + n log n)$, con $n = E$ y $m = C$.

Nos fijamos la arista de máximo costo del camino `MiniMax` entre la esquina de Sasha y Ciudad Universitaria. 

Esa es nuestra respuesta.

Variaciones Ejercicio 2

Posibles variaciones del ejercicio

¿Cómo cambiaría nuestra solución si ahora nos dicen que queremos encontrar los umbrales de tolerancia para todos los lugares (esquinas) a las que puede ir Sasha?

A partir del $AGM$ generado encontramos el camino `MiniMax` entre todos los nodos. 

Pues todo camino del $AGM$ es `MiniMax`.

Luego nos fijamos para cada nodo cuál es su umbral de tolerancia.

¿Qué ocurre si ahora Tasha (hermana de Sasha) se duerme si pasa por lugares con ruido menor a cierto umbral y el umbral es un dato? 

¿Cómo conseguimos el camino?

Hacemos lo mismo, solo que ahora conseguimos el Árbol Generador Máximo, es análogo.

¿Cómo cambiaría nuestra solución si el grafo resultante es ralo o denso?

$\color{purple}\text{Si es ralo, entonces nos conviene usar Kruskal; si es denso, nos conviene usar Prim.}$

## Ejercicio 3

Martin fue a la $NDJ$ (noche de juegos) y se cruzó con unos estudiantes de Biología. 

Ahí le contaron el problema que tenían con
un hormiguero que estaban intentando mantener.

Alimentando hormigas

En el hormiguero hay $n$ cuevas. 

La $i-ésima$ cueva tiene coordenadas $(x_i , y_i )$, ninguna tiene comida.

Hay dos formas de proveer comida a una cueva:

1. Colocarle un tubo de comida.
2. Construir un túnel entre una cueva $i$ sin comida a otra cueva $j$ que tenga comida. 

Para unir dos cuevas $i,j$ necesitamos $|x_i − x_j | + |y_i − y_j |$ centímetros de madera.

Sabemos que construir un tubo de comida cuesta $T$ y un centímetro de madera cuesta $M$.

¿Cuál es la manera más barata de que todas las cuevas tengan acceso a la comida?

Crear un grafo con un vértice correspondiente a cada cueva.

Agregar aristas entre las cuevas con el costo de unir las cuevas con madera.

Un AGM en este grafo representa una solución al problema, puesto que es indistinto donde colocamos cualquiera de los tubos.

Pero hay un problema...

¡Cuidado! ¡Este modelo no funciona!

Siempre está bueno dibujar algunos ejemplos y pensar casos borde para nuestro algoritmo. 

En este caso si tenemos dos posibles
componentes conexas que estén muy lejos, puede ser mejor colocar dos tubos de comida en vez de uno solo.

Entonces puede ser que nos esté faltando agregar información a nuestro grafo. 

¿Cómo la podemos agregar?

Crear un grafo con un vértice correspondiente a cada cueva y crear un **vértice adicional**, llamémoslo Tubo.

Agregar aristas entre las cuevas con el costo de unir las cuevas con madera.

Agregar aristas entre cada cueva y el Tubo con costo equivalente a instalar un tubo de comida en la cueva.

Ahora sí: Un $AGM\ T$ en este grafo sí que representa una solución al problema.

A partir de las aristas de $T$ podemos decirles a nuestros amigos de Biología qué hacer. 

Por cada arista $(c_i , c_j)$ sabemos
que tenemos que colocar un túnel entre la cueva $i$ y la cueva $j$.

Luego por cada arista $(c_i , Tubo)$ sabemos que tenemos que colocar un tubo de comida en la cueva $i$.

Lo que hicimos fue: 

$$\text{Problema} \to \text{Modelado} \to \text{Algoritmo sobre el grafo} \to \text{traducción de la salida del algoritmo a la
solución del problema}.$$

## Ejercicio 4

Cifu volvio de su estancia de investigacion en Emiratos Arabes.

Como había salido tan bien su proyecto el presidente Mohammed bin $Prim$ le pidio ayuda.

Rutas y aeropuertos

Ahora Cifu tiene que conectar todas las ciudades de Emiratos Arabes. 

Puede poner la cantidad de rutas y aeropuertos
que desee. 

Se puede volar desde una ciudad con aeropuerto a cualquier otra que tenga aeropuerto. 

Conocemos los costos de colocar una ruta entre la ciudad $i$ y la $j$ , que es $c_{i,j}$. 

También conocemos el costo de colocar un aeropuerto en la ciudad $i$, $a_i$. 

Con toda esta información queremos lograr conectar todas las ciudades usando el menor presupuesto posible.

Nuestro grafo G seguramente va a tener a las ciudades como vértices y van a estar conectadas con aristas de costo $c_{i,j}$.

Ahora la pregunta que tenemos es: ¿Cómo modelamos los aeropuertos?

Una opción posible es intentar hacer lo mismo que en el ejercicio anterior. 

Pero en este caso la relación es distinta, no nos sirve que haya sólo una ciudad con aeropuerto como podía suceder en el caso anterior.

Separemos entonces las posibles soluciones en 2: las que usan algún aeropuerto y las que no. 

Vamos a encontrar la mejor que no use
ningún aeropuerto, y la mejor que use al menos uno, y compararlas.

Si una solución no usa ningún aeropuerto, necesariamente tiene que conectar todas las ciudades con rutas. 

Por lo tanto, debe ser un subgrafo del grafo que contiene solo las rutas como aristas. 

Como todos los pesos de las rutas son positivos, el $AGM$ va a ser la solución óptima que no use aeropuertos.

Usemos el modelo $G'$ en el que agregamos un nodo que represente a todos los aeropuertos, llamémoslo Aeropuerto. 

¿Qué pasa con el $AGM$ de este grafo?

Supongamos que una solución $S$ sí usa un aeropuerto. 

Por cada calle usada en $S$, seleccionamos la arista correspondiente en $G'$, y por cada aeropuerto agregado a una ciudad, seleccionamos la arista correspondiente que incida en Aeropuerto. 

Al grafo inducido por las aristas que seleccionamos lo llamamos $H$.

Sabemos que $H$ es conexo, porque en $S$ cada ciudad debe estar conectada a alguna ciudad que tenga un aeropuerto, y todas las ciudades que tienen un aeropuerto están conectadas a Aeropuerto.

Además, si tenemos una solución $S$ tal que $H$ no es un árbol, podemos sacar alguna calle o aeropuerto de la solución y obtener
una solución mejor. 

Por último, un árbol generador de $G'$ es una
solución válida.

Por lo tanto, la solución óptima que usa al menos un aeropuerto es el árbol generador mínimo de $G'$.

Algoritmo

1. Crear un grafo $G$ con un vértice correspondiente a cada ciudad.
2. Agregar aristas entre las ciudades con el costo de colocar una ruta entre ellas.
3. Correr $Prim$ o $Kruskal$ sobre $G$ para obtener el $AGM$, y guardar el peso en `pesoSinAeropuertos`.
4. Agregar a $G$ un nodo Aeropuerto y agregar aristas entre Aeropuerto y cada ciudad con el costo de colocar un aeropuerto en la ciudad.
5. Correr $Prim$ o $Kruskal$ sobre $G$ y guardar el peso en `pesoConAeropuertos`.
6. Devolver `mı́n(pesoSinAeropuertos, pesoConAeropuertos)`.

Dada una arista $e = uv$, cómo sabemos si $u$ y $v$ están en componentes conexas diferentes?

## Disjoint Set

Es una estructura de datos que nos provee las siguientes operaciones eficientemente:
* `Find-set(u)`: Dado un vértice nos dice a qué componente conexa pertenece.
* `union(u,v)`: Une las componentes conexas a las que pertenecen $u$ y $v$.

Vamos a representar a las componentes conexas en forma de árboles: 

Cada árbol va a corresponder a una componente conexa.

La raíz del árbol representará al representante de la componente
conexa. 

Al principio empezamos con $n$ nodos donde cada uno es su propia componente conexa, donde el representante es uno mismo.

Luego, cuando hacemos la unión entre dos nodos, ambos nodos van a tener el mismo representante. 

La complejidad del `find()` es $O(n)$
en peor caso, por lo tanto la complejidad total sería $O(m * n)$.

Se suelen implementar dos optimizaciones a esta estructura de datos:
* Union by rank
* Path Compression

### Union by rank
A cada nodo se le asigna un rank, que indica el tamaño de su subarbol mas grande.

Al principio, cada nodo tiene rank 0.

Cuando se hace una union, si el rank de ambos nodos es igual, se incremente el rank del representante en 1.

En caso contrario, el nodo con rank menor apunta hacia el de rank mayor, sin alterar el valor del rank del representante.

La complejidad en el peor caso para:
* `Find` queda $O(log n)$
* `union` queda $O(1)$, ya que solamente hacemos apuntar un representante a otro.

Veamos por qué para Find es esa complejidad. 

La estrategia será ver en que el árbol resultante que nos queda de unir dos
componentes conexas, es un árbol que tiene una altura acotada.

Lema

> Cada nodo raiz de rank $k$ tiene al menos $2^k$ nodos en su arbol.

Demostración.

Hagamos induccion sobre $k$. 

Caso base: $k = 0$, entonces tiene al
menos un nodo en su árbol, que es cierto 

Caso inductivo: Considero $P(n-1)$ verdadero, quiero ver que $P(n)$ es cierto. 

Un nodo de rank $k$ es solo creado mergeando dos nodos raíz de rank $k − 1$. 

Por hipótesis inductiva, cada uno de esos nodos raíz tiene al menos $2^{k−1}$ nodos en sus árboles. 

Si los juntamos nos queda que $2^{k−1} + 2^{k−1} = 2^k$ , que es lo queríamos.

Lema

> El rank mas alto de un nodo es menor o igual a $log_2 (n)$

Demostración.

Por la proposición anterior, un nodo de rank $x$ tiene a lo sumo $2^x$.

Sea $n$ la cantidad de nodos totales dentro del árbol, entonces se cumple que $2^x \leq n$ que es lo mismo que $x \leq log_2 n$.

Esto nos dice que el rank máximo está acotado por el logaritmo de la cantidad de nodos. 

Con lo cual, la altura máxima de nuestro
árbol es a lo sumo logarítmica. 

Entonces si queremos buscar el representante de un elemento, basta que recorra todo el árbol hasta la raíz. 

Por eso nos queda en complejidad $O(logn)$.

### Path Compression

Empezando desde un nodo $x$, ir hasta la raíz para encontrar el representante. 

En el camino, cambiar los punteros de todos los nodos dentro del camino para apuntar directamente al representante.

Sin optimizaciones: la complejidad del `find()` es $O(n)$ en peor caso, por lo tanto la complejidad total sería $O(m * n)$.

Con `union by size/by rank` la complejidad de cada find es $O(log n)$ en peor caso.

Si además se usa Path Compression la complejidad amortizada de cada find() es $O(\alpha(n))$, donde $\alpha$ representa a la función inversa de Ackermann. 

Como esta funcion crece extremadamente lento, entonces en la practica es $O(1)$.