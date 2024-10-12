Representación de Grafos
---

### Definiciones

### Grafo

Un **grafo** es un par $(V, E)$ con $V$ un conjunto de nodos (o vértices) y $E$ conjunto de aristas (o ejes) de la forma $(u, v)$ con $u, v \in V$.

Si no se aclara, se asume que los ejes no son dirigidos, es decir que $(u, v)=(v, u)$.

En general vamos a notar $n$ la cantidad de nodos y $m$ a la cantidad de aristas.

### Digrafo

Es un grafo, es decir, un par $(V, E)$ como antes, pero cuyas aristas están orientadas. Es decir que en este caso $(u, v) \ne (v, u)$

Puedo tener dos ejes entre dos nodos, uno en cada sentido.

#### Otros:

**Multigrafo**: grafo que permite tener múltiples aristas entre dos nodos.

**Pseudografo**: grafo que permiten tener loops.

**Grafo pesado**: grafo $G=(V, E, w)$ con $w(e)$ una ”función de pesos” que asigna a cada arista $e=(u,v)$ un peso. (Observacion: se puede usar para simplificar multigrafos).

Por el momento nos vamos a concentrar en grafos y digrafos.

**Recorrido**: una sucesión de vértices y aristas del grafo.

**Camino**: un recorrido que no pasa dos veces por el mismo vértice.

**Circuito**: un recorrido que empieza y termina en el mismo nodo.

**Ciclo o circuito simple**: un circuito que no repite vértices. (Nota: para grafos, no consideramos como válido al ciclo de longitud 2)

**Longitud**: la longitud de un recorrido se nota $l(P)$ y es la cantidad de aristas del mismo.

**Distancia entre dos vértices**: longitud del camino más corto entre los vértices (si no existe se dice $\infty$).

Un nodo es **adyacente** a otro si están conectados.

Una arista es **incidente** a un nodo si conecta dicho nodo con algún otro.

### Representando grafos

Por conveniencia, vamos a suponer que todos los nodos del grafo son números de $[1, n]$.

Principalmente vamos a utilizar las siguientes estructuras de representación:

* Lista de aristas
* Lista de adyacencia
* Matriz de adyacencia

Veamos cada una de estas representaciones y sus diferencias.

### Ejemplo: lista de aristas

El conjunto de aristas como una secuencia (lista).

Tomemos el siguiente grafo como ejemplo:

![alt text](/img/image2.png)

Lista de aristas:
$\{(6, 5), (5, 2), (2, 4), (5, 4), (4, 1)\}$

Nota 1: normalmente esta va a ser la única representación con la que se van a expresar los inputs de grafos.

Nota 2: si junto con la lista se pasa el tamaño del grafo, como por convención las etiquetas de los vértices están numeradas $1...n$ podemos deducir qué vértices no
tienen vecinos.

### Ejemplo: lista de adyacencia

El diccionario es un vector y los vecindarios son listas de tamaño $d(v)$ conteniendo a los nodos vecinos.

Lista de adyacencia:

Nodo : lista de vecinos

```math
\begin{cases}
1:4 \\
2 : 4 \rightarrow 5 \\
3: \\
4 : 5 \rightarrow 1 \rightarrow 2 \\
5 : 2 \rightarrow 6 \rightarrow 4\\
6:5
\end{cases}
```

Nota: Se pueden hacer cosas como ordenar los vecindarios, pero es caro mantenerlo si el grafo cambia.

#### Ejemplo: matriz de adyacencia

El diccionario y los vecindarios son vectores de tamaño $n$. Resultando ası́ en una matriz de $nxn$ donde $M_{ij} = 1$ si los vértices $i$ y $j$ son adyacentes y
$M_{ij} = 0$ si no.

![alt text](/img/image3.png)

### Operaciones

¿Qué operaciones podrı́amos llegar a querer hacer sobre un grafo?

* Inicializar un grafo.
* Agregar o sacar un nodo del grafo.
* Agregar o sacar una arista del grafo
* Obtener el vecindario de un nodo $v$.
* Evaluar si dos aristas $u$ y $v$ son adyacentes.

### Complejidades

Las complejidades para las representaciones vistas quedarı́an:

![alt text](/img/image4.png)

Nota: como el tamaño del grafo está dado por su cantidad de nodos y aristas, una complejidad $O(n+m)$ es lineal respecto al tamaño del grafo.

### Eligiendo una representación

Qué representación conviene usar va a depender de:
* Las caracterı́sticas del grafo (por ejemplo si es ralo o denso).
* Para qué lo vamos a querer usar y qué complejidades queremos para sus operaciones.

La fiesta de Santi
---
Enunciado:

Santi quiere festejar su cumpleaños con otros $k-1$ amigos en su monoambiente. 

Para estar cómodos preferirı́an que no haya demasiada
gente en la fiesta, entonces se pusieron de acuerdo en invitar solamente a los amigos que tienen en común.

Como Santi está muy cansado con tantos trabajos, nos pidió que, dada la lista de todos los amigos que tiene cada uno de los $k$ cumpleañeros, le armemos la lista de invitados.

Sea $G = (V , E )$ y $S = \{s_1 , . . . , s_k \}$ donde $s_i \in V$

![alt text](image-2.png)

Complejidad matriz de adyacencia: $O(nk)$

Complejidad lista de adyacencia: $O(nd_m k)$

![alt text](image-3.png)

Complejidad lista de adyacencia: $O(n + m)$

Complejidad lista de aristas: $O(n + m)$

La CABArrera
---
Enunciado:

Dadas las hazañas de Franco Colapinto en F1, la Ciudad de Buenos Aires quiere hacer un circuito para que el corredor pueda hacer una carrera por la ciudad. 

Por las altas velocidades que se manejan en estas carreras, la ciudad quiere que desde todo punto del circuito se tenga acceso a un punto seguro en caso de una falla inesperada. 

Una vez en este punto ya no se podrán reincorporar a la carrera. 

Como la ciudad está muy ocupada por la organización nos pidieron que verifiquemos que el circuito propuesto
$\color{violet}\text{tenga un punto seguro}$.

¿Cuál es la solución más directa? ¿Qué complejidad tiene?

Buscar la fila en la matriz que tenga todos 0

Complejidad: O(n^2)

¿Nos podemos aprovechar de la matriz?

¿Que pasa si $M_{ij} = 1$? ¿Y si $M_{ij} = 0$?

Nos aprovechamos de que todos los nodos deben ser incidentes con lo cual, podemos ir descartando de a filas y columnas.

Si $M_{ij} = 1$ entonces sabemos que existe el arco $ij$ con lo cual podemos descartar el nodo $i$.

Si $M_{ij} = 0$ entonces sabemos que no existe el arco $ij$ con lo cual podemos descartar el nodo $j$.

La siguiente coordenada que visitaremos será el $max(i, j) + 1$ para asegurarnos que en toda iteración $i \ne j$ ya que $M_{ii} = 0$ para todos los nodos.

Veamos algunas iteraciones, donde $(i, j)$ es la coordenada y $\{v_1 , . . . , v_n \}$ los posibles candidatos.

![alt text](/img/image-6.png)

Sea $M$ la matriz de adyacencia de $G$

![alt text](/img/image7.png)


¿Con una lista de adyacencia será mejor?

Buscar el nodo con lista vacı́a en $O(n)$

Verificar que no sea un nodo aislado $(d_{in} (v ) > 0)$ en $O(n + m)$

¿Con lo cuál nos conviene?

Con matriz de adyacencia: $O(n)$

Con lista de adyacencia: $O(n + n + m)$

¿Que pasa si el grafo es denso?

Ejercicios Demostraciones sobre grafos
---

Buscaminas
---

Enunciado:

Vicky se aburrı́a ası́ que se puso a jugar al buscaminas. 

Empieza con un tablero $T$ formado por $n$ casillas, cada una de las cuales contiene o bien una bomba, o bien un número. 

Luego de resolverlo, como seguı́a aburrida, se puso a armar, otro tablero $T’$ con casillas dispuestas de la misma manera que en $T$. 

La diferencia es que cada casilla de $T’$ contiene un número si la correspondiente casilla de $T$ contiene una bomba, y viceversa. 

Tanto en $T$ como en $T’$, cuando una casilla contiene un número, esa es la cantidad de bombas en las casillas del mismo tablero que son vecinas a la dada.

Como Vicky es muy buena con las matemáticas, cuando terminó de armar el tablero se dio cuenta instantáneamente que la suma de todos los
números de $T$ daba lo mismo que la suma de todos los números de $T’$.

Esto le llamó mucho la atención, y nos pidió que la ayudemos a demostrar, usando grafos, que siembre la suma de los números en un tablero cualquiera $T$ es igual a la suma de los números en un tablero $T’$ armado
como hizo ella.

SUGERENCIA: modelar $T$ con un grafo o digrafo $G$ que tiene un vértice por cada casilla del tablero.

Modelo: $G=(V,E)$ donde $V=\{\text{Casilla del tablero}\}$, $E=\{(u, v ) \in V | u \text{ es un número y } v \text{ una bomba o viceversa}\}$

### Demostración:

Sea $G$ el grafo que modela el tablero $T$. 

Notar que el grafo es bipartito: una parte, llamémosla $V_1$ , representa las casillas con bombas; y otra parte, $V_2$ representa las casillas con números.

La suma de los números en $T$, es igual a la suma de los grados de los vértices en $V_1$, que al ser $G$ bipartito es la cantidad de ejes de $G$.

Sea $G’$ el grafo que modela el tablero $T’$. 

Este grafo es isomorfo a $G$, donde ahora $V_2$ representa las casillas con bombas; y $V_1$ las casillas
que tienen números. 

$G’$ también es bipartito.

Ahora, la suma de los números en $T’$ va a ser igual a la suma de los grados de los vértices en $V_2$, que al ser $G$ bipartito es la cantidad de ejes de $G’$.

Ahora, como dijimos que $G$ y $G’$ son isomorfos, esto quiere decir que tienen la misma cantidad de aristas, y por lo tanto, la suma en $T$ y $T’$ son iguales.

---

Inducción en grafos
---

En grafos muchas veces vamos a tener que hacer inducción en la cantidad de nodos o aristas de un grafo.

Tengan en cuenta que:

**NUNCA**: tomo un grafo $G_k$ de $k$ vértices (o $k$ aristas) y digo que si una propiedad $P$ se prueba para este grafo, agregándole un $v$ vértice (o arista) sigue valiendo $P$ para $G_{k+1}$. (*)

**SIEMPRE**: tomo un grafo $G_{k+1}$ de $k + 1$ vértices (o $k + 1$ aristas) con ciertas caracterı́sticas y le saco un vértice (o arista) con algún tipo de estrategia particular y veo que cumple $P$. 
Luego, agrego el vértice o arista y veo que sigue cumpliendo $P$.

(*) el problema con esto es que estamos queriendo probar la propiedad para todo grafo $G_{k+1}$ de $k+1$ nodos (o aristas). 

Sin embargo al tomar un grafo $G_k$ y agregarle un nodo o
arista estariamos solo considerando los grafos $G_{k+1}$ que tenı́an a $G_k$ como subgrafo, y eso no necesariamente eso abarca a todo $G_{k+1}$ posible.

---

### Demostrando algo falso

Enunciado:

Si todos los vértices de un grafo tienen grado mayor a cero, entonces el grafo es conexo.

Recordemos que un grafo es conexo si existe un camino entre cualquier par de vértices.

Contraejemplos:
![alt text](/img/image8.png)

Demostremos esta propiedad (falsa) por inducción (incorrecta) en el tamaño del grafo.

$P(n)$: Si todos los vértices de un grafo con $n$ vértices tiene grado mayor a cero, entonces el grafo es conexo.

`Caso Base (n ≤ 2):`
* P(1) : no puede tener grado positivo. Cumple.
* P(2) : solo hay un grafo que cumple tener grados positivos, $K_2$. Es un grafo conexo. Cumple.

`Paso inductivo: debemos mostrar que P(n) ⇒ P(n + 1) para todo n ≥ 2.`

Considerar $G_n$ tal que $\forall v \in V(G_n), d(v) \gt 0$.

Por $H.I.$ $G_n$ es conexo. 

Agregamos el vértice $x$ para obtener $G_{n+1}$.

Para ver que $G_{n+1}$ es conexo debemos ver que existe camino entre $x$ y cualquier otro vértice $z$.

Como $x$ tiene grado positivo, existe una arista $(x, y)$.

Para llegar de $x$ a $z$ podemos usar la arista $(x, y)$ y el camino $[y, z]$.

Dicho camino existe pues $G_n$ es conexo.

Por lo tanto vale $P(n+1)$.

#### Demostrando algo falso: Errores

Cada paso es correcto, el problema es que esto no prueba $P(n + 1)$.

Necesitamos probar que $\text{TODO}$ grafo de $n + 1$ vértices con grados positivos es conexo.

El error esta en suponer que todos los grafos de $n + 1$ vértices pueden ser construidos usando todos los grafos de $n$ vértices que cumplen la propiedad $P(n)$. (Ver contraejemplos)

Demo correcta por inducción
---

Enunciado:

Probar que si $G$ es un grafo de $n$ nodos y tiene al menos $n$ ejes, entonces tiene un ciclo.

`Hipótesis inductiva:` $P(n)$= para todo grafo de $n$ nodos vale que si tiene al menos $n$ ejes entonces tiene un ciclo.

¿Vale $P(1)$? El primer caso interesante es $P(3)$, que también vale.

Para el caso inductivo, queremos probar que $P(n) \Rightarrow P(n + 1)$. 

Es decir, tenemos que tomar un grafo cualquiera de $n+1$ nodos, y demostrar (aprovechando que vale $P(n)$) que si tiene $n+1$ o más ejes entonces tiene un ciclo.

Sea $G$ un grafo con $n+1$ nodos, y al menos $n+1$ ejes.

Vamos a separar en dos casos:
* Hay un nodo $v$ de grado a lo sumo $1$: entonces $G \backslash \{v\}$ es un grafo de $n$ nodos, con al menos $n$ ejes. Luego, tiene un ciclo (por la hipótesis
inductiva). Ese ciclo también está en G.
A modo de ejemplo:
![alt text](/img/image9.png)

* Caso contrario, todos los nodos tiene al menos grado $2$. Se puede demostrar fácilmente entonces que tiene al menos un ciclo:

La idea es, podemos tomar un vértice $v_1$, movernos a otro vértice $v_2$, y luego siempre vamos a poder movernos a otro vértice $v_i$ por una arista distinta a la que usamos para llegar.

Pero como la cantidad de nodos es finita, si podemos ir de nodo en nodo de manera infinita, eventualmente vamos a tener que repetir un nodo. Por lo tanto existe un ciclo.

Representación de árboles
---

**Árbol**:

Un árbol es un grafo conexo, acı́clico y con $n-1$ aristas.

Nota: alcanza con saber que cumple con dos de dichas propiedades para afirmar que un grafo es un árbol.

![alt text](/img/image10.png)

¿Podemos aprovecharnos de esto para representarlos de una manera más compacta? ¡Sı́!

Podemos tener una función padre tal que `padre[v]` es el (único) padre de $v$ para todo $v$ que no es la raı́z. 

Para la raı́z $r$ podrı́amos poner `padre[r] = r`, por ejemeplo.

Con el ejemplo anterior:

![alt text](/img/image11.png)

