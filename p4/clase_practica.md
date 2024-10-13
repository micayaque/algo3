Clase Recorridos en Grafos
---

### Definición DFS

$\text{DFS}$ es un algoritmo recursivo que sigue la idea de backtracking para poder recorrer todos los nodos. 

Lo podemos usar tanto para grafos dirigidos como para no dirigidos.

Vamos a recorrer en profundidad (Depth): siempre vamos hasta el final de la rama y de ahı́ subimos.

La complejidad de $\text{DFS}$ es $\text{O(m+n)}$ ya que recorro todos los nodos una sola vez y reviso las aristas también una sola vez (aunque puede que no
recorra todas).

Sin agregarle complejidad al algoritmo de DFS podemos pedirle que nos devuelva el árbol o bosque (como un $\color{violet}\text{vector de padres}$) y la lista de $\color{violet}\text{backedges}$, que son las aristas que generan ciclos.

Definicion BFS
---

Con $\text{BFS}$ también vamos a recorrer todos los nodos pero en lugar de recorrer en profundidad va recorriendo a lo ancho. 

Se suele implementar iterativo. 

La idea del algoritmo es arrancar en algún nodo y recorrer todos sus vecinos, luego los vecinos de sus vecinos...

La complejidad de $\text{BFS}$ también es $\text{O(m+n)}$, al igual que $\text{DFS}$.

Nos devuelve un árbol $\text{v-geodésico}$, siendo $\text{v}$ el nodo desde el cual corremos el algoritmo. 

Puede devolver también las distancias de $\text{v}$ a todos en el grafo (que son iguales que en el árbol ya que es $\text{v-geodésico}$!!)

Ejercicio 1
---

Vamos a arrancar con uno tranqui: chequeo de $\color{violet}\text{conectividad}$

¿Cómo podemos ver que un grafo es conexo? 

Es decir, dado $\text{G = (V, E)}$, queremos chequear si $\forall \text{ u, w} \in \text{V, } \exists \text{ camino entre u y w, o que d(u, w) = k finito}$.

Podrı́amos correr alguno de los algoritmos de recorrido y ver si todos los nodos fueron visitados (usando el vector visitados). 

Para esto usamos un código aún más simple que el visto en la teórica ya que si no puedo llegar a un nodo $\text{w}$ corriendo $\text{DFS}$ (o $\text{BFS}$) desde otro nodo $\text{v}$ no me interesa correr de vuelta el algoritmo desde $\text{w}$ , sino que ya sé que no es conexo. 

Si lo queremos resolver con $\text{DFS}$, podrı́amos usar esta implementación:

```C++
vector<vector<int>> aristas;
vector<bool> visitado;

void dfs(int v) {
    visitado[v] = true;
    for (int u : aristas[v]) {
        if (!visitado[u]) {
            dfs(u);
        }
    }
}
```

Ahora... 

¿Cómo podemos ver si es conexo o no, luego del recorrido?

Podemos recorrer el vector de `visitados` y analizar si están todos los valores en `true`. 

Significa que desde nuestro nodo inicial, pudimos encontrar un camino para todos los nodos del grafo, con lo cual lo hace conexo. 

Por el contrario, si encontramos alguna posición $\text{i}$ en `false`, significa que desde el nodo que arrancamos no pudimos llegar al vértice $\text{i}$, con lo cual el grafo no es conexo.

Veamos el código...

```C++
dfs(FIRST_NODE);

for(int i = 0; i < visitado.size(); i++) {
    if(!visitado[i]) return false;
}
// si estan todos visitados el grafo es conexo
return true;
```

Ejercicio 2: componentes conexas
---

Dar un algoritmo que dado un grafo devuelva la cantidad de componentes conexas que tiene.

Definition: Dos vértices $\text{u, v}$ pertenecen a la misma componente conexa si existe un camino entre ellos.

Podrı́amos resolverlo con la implementación usual de $\text{DFS}$ o $\text{BFS}$
agregando un **contador de componentes** conexas o bien usar la implementación del ejercicio anterior y agregarle algo asi:


```C++
int componentes = 0;
for (int i = 0; i < n; i++) {
    if (!visitado[i]) {
        componentes++;
        recorroAPartirDelVertice(i);
    }
}
```

Donde `recorroAPartirDelVertice` es la implementación del ejercicio anterior de $\text{DFS}$ (o una similar de $\text{BFS}$).

Ejercicio 3
---

¡Para combatir el bajón!

A Rasta le gusta mucho comer alfajores. 

Es por eso que quiere ir todas las mañanas a la fábrica de alfajores que está en una esquina cerca de su casa para comprárselos. 

Pero sucede que Rasta detesta enormemente repetir caminos, ¡y ni hablemos de caminar de
más! 

Rasta anhela saber de cuántas maneras distintas puede ir de la esquina donde queda su casa a la fábrica de alfajores caminando siempre lo menor posible.

Idea: O sea, en resumidas cuentas, queremos calcular el número de caminos con mı́nima cantidad de cuadras entre la casa de Rasta ($\text{R}$) y la fábrica ($\text{F}$). 

¿Cómo podemos hacer?

Primero modelemos el problema como un grafo. 

Sea $\text{G = (V, E)}$.

¿Quienes van a ser los vértices de $\text{V}$?

Las esquinas por las que puede pasar Rasta.

¿Quienes van a ser las aristas de E? 

Las cuadras del barrio.

![alt text](/img/image-16.png)

Vamos a resolverlo usando programación dinámica.

Sabemos que $\text{BFS}$ nos da un vector con las distancias de $\text{v}$ a todos, ası́ que comenzamos corriendo un $\text{BFS}$.

Luego usando el vector de distancias hacemos un algoritmo que de abajo hacia arriba en el árbol chequee si para algún otro vecino de $\text{v, distancia[w] = distancia[adyacente a w] + 1}$.

Si pasa eso debo volver a correr el algoritmo desde el $\text{adyacente de w}$, ya que podrı́a haber más de una manera de llegar a ese con distancia mı́nima también.

Lo hacemos con programación dinámica ya que tenemos
superposición de problemas.

Planteamos la función $\text{\#caminosHasta}$

```math
\text{\#caminosHasta} = 
\begin{cases}
1 & \text{R=V}\\
\sum_{w* \in N_v} \#caminosHasta(w)
\end{cases}
```

donde $\text{w* = \{w } \in N_v : \delta(w) + 1 = \delta(v) \}$

Y lo inicializamos con $\text{\#caminosHasta(F)}$

```C++
int cantidadDeCaminosHasta(v){
    if(distancia[v] == 0) return 1;
    if(memo[v] != -1) return memo[v];
    int res = 0;
    for(int vecino : aristas[v]){
        if(distancia[vecino] + 1 == distancia[v]){
            res += cantidadDeCaminosHasta(vecino);
        }
    }
}
```

¿Qué complejidad tiene este algoritmo?

Corrimos $\text{BFS}$ una vez:

Programación dinámica: como la función y la memoización recibe los vértices, pero a cada uno accedo $\text{|E|}$ veces, entonces la complejidad de este paso es $\text{O(|V| + |E|)}$.

Ejercicio 4
---

Nadie acepta nada: chequeo de bipartito

Actualmente, nos encontramos viviendo el ocaso de la televisión tradicional, donde cambiamos actores de años de trayectoria por nuevos personajes denominados “Streamers”, que sin maquillaje ni escrúpulos hablan sobre tópicos variados de la vida. 

La plataforma $\text{MyTube}$ genera un ambiente amigable para la transmisión en vivo, y además teniendo en cuenta que para el usuario promedio $\text{(Gen Z/Millenial)}$ es una red social recurrente, Micky Granadina y Mico Bonniato quieren llamar a varios de estos Streamers para crear dos canales de Streaming.

Estos van a ser Aglo y Zulu-Tv. Ambos estaban muy entusiasmados pero empezaron a encontrar problemas.

La gran exposición de los Streamers generó algunos conflictos entre ellos, por lo que Micky y Mico quieren ver si pueden armar ambos canales sin conflictos internos.

Se cuenta con $\text{N}$ Streamers en total, y con $\text{c}$ pares de conflictos $\text{(A, B)}$, que significa que $\text{A}$ está peleado con $\text{B}$. 

Se quiere modelar el problema como un problema de grafos, en el que respondamos si es posible armar dos canales sin conflictos.

Primero modelemos el problema como un grafo. 

Sea $\text{G = (V, E)}$.

¿Quiénes van a ser los vértices de $\text{V}$ ? Los Streamers

¿Quiénes van a ser las aristas de $\text{E}$? Los conflictos

Idea: Puede haber streamers sin conflictos, entonces la solución tiene que preservarse para cada componente conexa.

Recordemos que dos vértices $\text{u, v}$ pertenecen a la misma componente conexa si existe un camino entre ellos.

A fin de cuentas queremos que cada componente conexa sea un grafo bipartito.

Definition: Un grafo es bipartito si existen dos conjuntos $V_1$ y $V_2$ tales que $V_1 \cup V_2 = V, V_1 \cap V_2 = \empty$ y $\forall v \in V_1, (u, v) \in E \Rightarrow u \in V_2$ , y análogamente para $V_2$.

Es decir que los vértices en $V_1$ sólo son adyacentes a los de $V_2$ y los de $V_2$ sólo son adyacentes a los de $V_1$.

En resumen, quiero verificar si todas las componentes conexas de $\text{G}$ son bipartitas.

Puedo usar $\text{BFS}$, ya que al armar el árbol de $\text{BFS}$, lo que tengo que chequear es que los nodos que tengan nivel con la misma paridad no tengan aristas en común. 

Recordemos que por invariante de $\text{BFS}$, sabemos que el nivel es la distancia a la raı́z, que puede ser cualquier nodo de la componente en principio.

Definition (Lema): Sean $\text{u, v} \in \text{V : (u, v) } \in E$.

G es bipartito $\Leftrightarrow$ no hay ningún ciclo impar.

```C++
bool isBipartiteComponent(int& graph[MAX_NODES][MAX_NODES], int n, int start, int& distance[]){
    queue<int> q;
    distance[start] = 0;
    q.push(start);
    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        for(int possible_neighbour in range(n)){
            //si no visite el nodo lo visito y pongo su distancia
            if(graph[vertex][possible_neighbour]){
                if(distance[possible_neighbour] == -1){
                    distance[possible_neighbour] = distance[vertex] + 1;
                    q.push(possible_neighbour);
                }
                else if((distance[possible_neighbour] - distance[vertex]) % 2 == 0){
                    return false;
                }
            }
        }
    }
    return true;
}
```

Ejercicio 5: detectar aristas puente
---

Dar un algoritmo lineal basado en DFS para encontrar todas las aristas puente de $\text{G}$ (2d de la guia).

A tener en cuenta:

Una arista es puente si al sacarla aumenta la cantidad de
componentes conexas

Una back-edge nunca puede ser puente

Las aristas que son puentes son aquellas tree-edges que no tienen una back-edge que las “cubra”

![alt text](/img/image17.png)

Primero debemos convencernos de que la cantidad de backedges que cubren la arista entre $\text{v}$ y su padre se puede calcular de la siguiente manera:

```math
\text{cubren(v) = backEdgesConExtremoInferiorEn(v)
− backEdgesConExtremoSuperiorEn(v) +}
\sum_{w \in hijos(v)} \text{cubren(w)}
```
Veamos un ejemplo.

Los números al lado de los nodos indican el valor de cubren en dicho nodo.

Si cubren de un nodo $\text{v}$ es $\text{0}$ significa que la arista de $\text{v}$ al padre es puente.

Ahora si corremos un $\text{DFS}$ que de alguna manera calcule para cada nodo `backConExtremoInferiorEn` y `backConExtremoSuperiorEn`. 

Puede ser algo asi:

```C++
vector<vector<int>> treEdges;   //init en []
...
void dfs(int v, int p=-1){
    estado[v] = 1 = EMPECE_A_VER;
    for(int u : aristas[v]){
        if(estado[u] == NO_LO_VI){
            treEdges[v].push_back(u);
            dfs(u, v);
        } else if(u != p){
            backConExtremoInferiorEn[v]++;
            backConExtremoSuperiorEn[u]++;
        }
    }
    estado[v] = TERMINE_DE_VER;
}
```

En este $\text{DFS}$ si ya pasé por un nodo y no es el padre entonces sumo una backedge.

Notar que en esta implementación de $\text{DFS}$ se asume que los nodos tienen tres estados: no lo vi, empecé a ver y terminé de ver

Hacemos un algoritmo que calcule cubren con programación dinámica ya que tenemos superposición de subproblemas (siempre para cubren de $\text{v}$ necesito cubren de los hijos).

```C++
vector<int> memo;   //init en -1
int cubren(int v, int p=-1){
    if(memo[v] != -1) return memo[v];
    int res = 0;
    res += backConExtremoInferiorEn[v];
    res -= backConExtremoSuperiorEn[v];
    for(int hijo : treEdges[v]){
        if(hijo != p){
            res += cubren(hijo, v);
        }
    }
    memo[v] = res;
    return res;
}
```

Y ahora finalmente solo necesito calcular cuántos puentes nos quedan, que es la cantidad de nodos $\text{v}$ tal que $\text{cubren(v) = 0}$.

```C++
int puentes = 0;
for(int i = 0; i < n; i++){
    if(cubren(i) == 0){
        puentes++;
    }
}
```

OJO nos falta restar la cantidad de componentes ya que como vimos en los ejemplos la raı́z de los árboles también tiene $\text{cubren = 0}$.

`puentes -= componentesConexas`

Complejidad?

DFS: $\text{O(n+m)}$

cubren: $\text{O(n)}$ ya que como máximo llenamos el vector de
memoización

puentes: $\text{O(n)}$ porque recorro el vector cubren que tiene longitud `cant nodos`

Ejercicio luces
---

Igna compró una casa en el campo y las luces vinieron falladas: si bien hay luces en todas las habitaciones, los interruptores que las controlan están en otras habitaciones respectivamente. 

A Igna le da miedo la oscuridad, ası́ que nos pidió que le busquemos la manera más corta de llegar hasta su habitación (sin que queden otras luces prendidas en la casa) desde el primer cuarto arrancando con las luces
de los otros cuartos apagadas y nunca puede estar en una habitación a oscuras. 

Si bien no nos dio muchos detalles nos dijo que como
máximo su casa tiene $\text{10}$ habitaciones

¿Cómo podrı́amos modelar el grafo en este problema?

En principio pensemos cada habitación como un nodo y que los nodos están conectados entre sı́ si las habitaciones son adyacentes. 

¿Cómo vemos el tema de las luces?

Con el grafo modelado de esa manera no tenemos en cuenta a las luces. 

Vamos a tener que modificar el modelo... Alguna idea?

Vamos a incluir ahora las luces al modelo. 

Necesitamos un grafo donde cada nodo nos dé información sobre la posición de Igna y de las luces de toda la casa y cada arista represente una acción válida.

Entonces en este nuevo modelo vamos a tener un nodo para cada estado. 

Un estado es una habitación con cierta configuración de luces particular. 

¿Cuántos nodos son?

Serı́an $\text{h} \cdot 2^h$ , siendo $\text{h}$ la cantidad de habitaciones. 

Parece muchı́simo peeeeeero como máximo puede haber 10 habitaciones.

¿Y ahora como ponemos las aristas?

Va a haber una arista de $\text{A}$ a $\text{B}$ si las habitaciones son adyacentes y con los interruptores de $\text{A}$ Igna puede poner la configuración de luces
que tiene $\text{B}$.

Ya tenemos el modelado. ¿Ahora qué podemos hacer?

Queremos minimizar las distancias entonces con correr $\text{BFS}$ desde el estado inicial (primera habitación y luces apagadas) y luego chequear la distancia hasta el estado final (ultima habitación y luces apagadas)
alcanza.

Orden topológico
---

Dado un digrafo $\text{D}$, un orden topológico de $\text{D}$ es un ordenamiento $v_1 . . . v_n$ de sus nodos que cumple que toda arista queda de la forma $v_i, v_j$ con $i \lt j$ (en el ordenamiento). 

Es decir, damos un orden a los nodos de tal forma que las aristas apuntan de izquierda a derecha (“no hay aristas para atrás”).

Veamos un ejemplo...

![alt text](/img/image18.png)

Idea para el algoritmo que nos da un orden topológico:

Primero tenemos que verificar si el digrafo tiene ciclos (Ejercicio, sale con DFS). 

Si tiene ciclos no tiene orden topológico.

Usamos la implementación de $\text{DFS}$ de tres estados: no lo vi, empecé a ver y terminé de ver.

Vamos a modificar $\text{DFS}$ para que si terminé de procesar un nodo lo pushee a un stack finish.

El siguiente algoritmo nos da el orden topológico:

```C++
topological_sort(G):
    DFS(G)
    return invertir finish
```