## APSP (All-Pairs Shortest Paths)
Objetivo

En esta clase veremos algoritmos cuyo objetivo es encontrar la
longitud de todos los caminos mínimos.

¿Cuál es la complejidad mínima que deberíamos esperar? $O(n^2)$, ya que es el tamaño del output.

## Floyd-Warshall (APSP)
Intuición

Sea $G$ un grafo con vértices numerados $\{1, . . . , n\}$.
Sea $C_{i,j}^k$ el conjunto de todos los caminos entre $i$ y $j$ que solo usan nodos en el conjunto $\{1, . . . , k \}$, y sea $p$ el camino mínimo de $C_{i,j}^k$.

¿Qué relación hay entre $C_{i,j}^{k-1}$ y $p$? ¿Puede $p$ también ser el camino mínimo de $C_{i,j}^{k −1}$?

Hay dos opciones: $k \notin p$ o $k \in p$

Si $k \notin p$ entonces $p$ también es un camino mínimo en $C_{i,j}^{k-1}$.

Caso contrario, podemos descomponer a $p$

![image](/img/image%20copy%203.png)

La primer porción es un camino mínimo de $i$ a $k$ que usa nodos en el conjunto $\{1, . . . , k − 1\}$, mientras que la segunda es un camino mínimo entre $k$ y $j$ con nodos en el conjunto $\{1, . . . , k − 1\}$.

Formulación:

Sea $d_{ij}^{(k)}$ el peso del camino mínimo de $i$ a $j$ usando como vertices intermedios $\{1, 2, . . . , k \}$

![image](/img/image%20copy%204.png)

Invariante: Típicamente Floyd-Warshall se implementa bottom-up, manteniendo
en cada iteración $k$ la matriz $d^k$. Es decir, en cada paso $k$ se tiene acceso a los caminos mínimos que solo usan nodos dentro del conjunto $\{1, . . . , k \}$.


![image](/img/image%20copy%205.png)

Análisis

¿Complejidad temporal? $O(n^3 )$.

¿Complejidad espacial? $O(n^3 )$ 

¿Se puede mejorar? Si, a $O(n^2 )$.

¿Qué pasa si el grafo tiene aristas de peso negativo? Nada, en
ningún momento del razonamiento nos importó.

¿Sirve para detectar ciclos negativos? Si, ver la diagonal.

>Lema

>Si $G$ tiene un ciclo de longitud negativa entonces $d_{i,i}^n \lt 0$ para algún $i$.

## Dantzig
Estrategia

Llamemos $G_k$ al subgrafo de $G$ inducido por los nodos $\{1, . . . , k \}$, y sea $D^k$ la matriz de distancias de $G_k$ ¿Cómo se relacionan $D^k$ y $D^{k +1}$?

Distancia de $i \in \{1, . . . , k\}$ a $k+1$: hay que ir hasta un $j$ y luego tomar el eje $j \to k+1$. Es decir, $D_{i, k+1}^{k+1} = mín_{1 \leq j \leq k} (D_{i,j}^k + w_{j, k+1})$.

Distancia de $k+1$ a $i \in \{1, . . . , k\}$: análogo.

Distancia de $i$ a $j$, ambos menores a $k+1$: uso el camino viejo que no pasaba por $k+1$, o bien paso por $k+1$ combinando dos caminos óptimos. Es decir, $D_{i,j}^{k+1} = mín (D_{i,j}^k, D_{i, k+1}^{k+1} + D_{k+1, j}^{k+1})$.

![](/img/image%20copy%207.png)

¿Invariante? Al finalizar la iteración $k$ tenemos las distancias del grafo inducido por los primeros $k$ nodos.

¿Complejidad temporal? $O(n^3 )$.

¿Complejidad espacial? $O(n^3 )$ a lo bestia, se puede hacer en
$O(n^2 )$.

¿Detecta ciclos de longitud negativa? Sip.

Ambos algoritmos que vimos tienen complejidad $O(n^3 )$ y devuelven
los caminos todos a todos ¿No podríamos haber usado algún
algoritmo uno a todos $n$ veces?

Usando Dijkstra: $O(n × m log n) = O(nm log n)$.

Usando Bellman-Ford: $O(n × nm) = O(n^2 m)$.

El segundo siempre es malo, pero el primero le gana a $O(n^3 )$ en
grafos ralos. Sin embargo, no siempre se puede usar...

### Algoritmo de Johnson
Intuición

Si tenemos un grafo con pesos negativos podemos modificar el costo en los nodos de tal forma que los pesos ahora sean positivos, pero los caminos mínimos sigan siendo los mismos.

Luego, podemos usar Dijkstra.

¿Cuánto cuesta encontrar el valor por el cual modificar los nodos?

$O(nm)$ (es literalmente usar Bellman-Ford). La complejidad final es $O(nm + nm log n) = O(nm log n)$

### Optimizando Canciones
Enunciado

Rasta, que venció el bajón luego de comer tantos alfajores, está
aprendiendo a tocar la guitarra. 

Como le gusta irse de campamento
con amigos mochileros, se está esforzando en mejorar su velocidad
para tocar acordes para los fogones.

Existen $k$ acordes en total, y la canción con la que está practicando tiene una sucesión de $n$ acordes. 

A Rasta le toman $S_{ij}$ segundos pasar del acorde $i$ al acorde $j$, pero a veces le es más rápido pasar por acordes intermedios.

Se asume que Rasta empieza con la mano acomodada en el primer
acorde. ¿Cuál es el mínimo tiempo que le toma tocar la canción?

Por ejemplo, si la canción va del acorde $6$ al $7$, capaz Rasta hace más rápido yendo del $6$ al $3$, y luego del $3$ al $7$.

Definamos la canción $C = c_1 , c_2 , ..., c_n$

Dado que Rasta puede hacer más rápido pasando por acordes
intermedios, es posible que pueda tocar la canción $C$ en menos de $\sum_{i=1}^{n-1} S_{C_i C_{i+1}}$ tiempo.

Podemos imaginar un grafo $G = (V, E)$ de $k$ vértices, con una
arista $i \to j$ de peso $S_{ij}$.

Buscamos saber, para todo par de acordes $i, j$, el mínimo tiempo
que necesita Rasta para pasar de $i$ a $j$.

Esto es nada menos que la matriz de distancias de $G$.

Ahora tenemos que usar algún algoritmo para computar
distancias todos con todos.

¿Floyd-Warshall o Johnson?

Para decidir cuál, ¿Nuestro grafo es denso o ralo? como hay un
$S_{ij} \forall i \neq j$, es completo, así que $E \in \theta (V^2)$.

Usando `FW`, el valor buscado es $t = \sum_{i=1}^{n−1} δ\delta (C_i , C_{i+1})$.

Complejidad: $O(k^3 + n)$, donde $k^3$ cuesta calcular la matriz con DP y $n$ para recorrer la canción y sumar.

### Modificado
Enunciado

Después de un rato de practicar, Rasta se dio cuenta que la canción
todavía no estaba muy fluída y decidió pedir ayuda a sus amigos.

Tuki y Sasha, que también iban al campamento, le sugirieron que
podría cambiar un acorde para disminuir el tiempo que le toma tocar la canción. ¿Qué cambio podría minimizar el tiempo total?

Una manera de responder esta pregunta es yendo acorde por
acorde y probando cambiarlo por cada uno de los otros $k-1$.

En particular, si cambio el i-ésimo acorde por $e$, tengo que
$$t_{e\to i} = t − d(C_{i−1} , C_i ) − d(C_i , C_{i+1} ) + d(C_{i−1} , e) + d(e, C_{i + 1})$$

Salvedad: hay que definir que $d = 0$ si $C_{i−1} = 0$ o $C_{i+1} = n + 1$

Podemos aprovechar una propiedad de la matriz de distancias: La
desigualdad triangular. Dada una métrica (la que utilizamos para
medir las distancias en el grafo):
$$\forall i, j, q \ d(i, j) \leq d(i, q) + d(q, j)$$

Luego, no probamos todos los acordes, sino que vemos cuál nos
conviene repetir.

Notar que cambiar un acorde por una repetición no necesariamente da un total menor, puede ser igual.

Tomemos como ejemplo el enunciado. Sean
$S_{6,7} = 3, S_{6,3} = 1, S_{3,7} = 1$, y supongamos que la canción es:

$$c_1 , ..., 6, 3, 7, ...C_n$$

Si repetimos el $6$ (o el $7$) tenemos:
$$C_1 , ..., 6, 6, 7, ..., C_n$$ 

donde el costo $6 \to 7 = 2$ porque Rasta sigue pasado por el acorde $3$ pero no lo toca.

Algoritmo

Calculamos la matriz de  distancias y el valor $t$ original. $O(k^3 + n)$.

Para cada posición $i \gt 1$, calculamos el $t_{C_{i−1} \to C_i}$ (el total de cambiar $C_i$ por repetir $C_{i−1}$, y nos quedamos con el mínimo). $O(n)$

Costo total: $O(k^3 + n)$.