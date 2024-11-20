### La gira de Pablo
> 1.1

> La banda de “rock ” de Pablo y Ramón ya está planeando sus años de éxito con múltiples giras nacionales. 

> Su objetivo es planear muchas giras que terminen todas en Ushuaia, tocando en el medio por bares en todas las ciudades que les queden de camino. 

> Tienen un mapa de los lugares donde podrı́an tocar, unidos por rutas unidireccionales. 

> Pero Pablo tiene miedo de que después de viajar por una ruta, los paparazzis se enteren de que pasan por ahı́ y los molesten la próxima vez que viajen, ası́ que le interesa planear sus giras de forma de no usar nunca una ruta dos veces. 

> ¿Cuántas giras distintas puede planear?

Ejercicio $5$ de la guía.

> 1.2

> Ramón se queja de que la restricción de terminar en Ushuaia no tiene sentido y que solo lo estaban haciendo porque a Pablo le gusta la que manejaba el bar.

> Propone una nueva restricción: Pueden terminar en cualquier capital provincial, ası́ se pueden tomar un avión de vuelta más fácil. ¿Cuántas giras distintas pueden hacer ahora?

Ahora las giras pueden terminar en **cualquier capital provincial**:

- Los nodos representan las ciudades.
- Las aristas representan las rutas unidireccionales entre las ciudades.
- Ahora, los posibles nodos destino son todas las capitales provinciales.

- Cada ruta (arista) solo puede usarse una vez en todas las giras.
- Las giras pueden terminar en cualquier nodo correspondiente a una capital provincial.

- Determinar la cantidad máxima de giras disjuntas en aristas que parten de $s$ (el nodo inicial) y terminan en cualquiera de los nodos correspondientes a capitales provinciales.

El problema sigue siendo un problema de **caminos disjuntos en aristas**, pero ahora debemos manejar múltiples posibles nodos sumideros $t$.

- Usamos el grafo original con los mismos nodos y aristas.
- Asignamos capacidad unitaria $c(u, v) = 1$ a cada arista.
- Agregamos un **super-sumidero** $t'$ al grafo.
- Conectar cada capital provincial $t_i$ con una arista dirigida $t_i \to t'$, con capacidad infinita o suficientemente alta para no limitar el flujo.

- Encontrar el flujo máximo desde la fuente $s$ al super-sumidero $t'$.
- El valor del flujo máximo será el número máximo de caminos disjuntos en aristas que terminan en alguna capital provincial.

La **restricción de capacidad $0 \leq f(u, v) \leq 1$** asegura que cada arista se utilice como máximo una vez en todos los caminos.

> 1.3

Ceci, la manager de la banda, les informa que algunas de las ciudades intermedias donde piensan pasar son lugares de buen gusto, y, por la calidad de su música, una vez que tocan ahı́ no van volver a ser bienvenidos. 

Ahora la banda puede pasar a lo sumo una vez por cada ciudad de buen gusto.

- Nodos: Las ciudades del mapa.
- Aristas: Las rutas unidireccionales entre las ciudades.
- Algunas ciudades (nodos) son marcadas como **ciudades de buen gusto**.

- Cada arista solo puede usarse una vez (como en los casos anteriores).
- Cada ciudad de buen gusto puede usarse como máximo una vez en todas las giras.

- Queremos determinar el número máximo de giras disjuntas en aristas que parten de $s$ (el nodo inicial) y terminan en los nodos correspondientes a las capitales provinciales, respetando las nuevas restricciones.

Para modelar correctamente la restricción de **ciudades de buen gusto**, utilizaremos la técnica de **división de nodos**:

**División de nodos de buen gusto**:
- Cada nodo de buen gusto $u$ se divide en dos subnodos:
    - $u_\text{in}$: Nodo de entrada.
    - $u_\text{out}$: Nodo de salida.
- Conecta $u_\text{in} \to u_\text{out}$ con una arista de capacidad $1$.
- Las aristas entrantes a $u$ en el grafo original ahora van hacia $u_\text{in}$, y las aristas salientes de $u$ salen de $u_\text{out}$.

**Resto de los nodos**:
- Para nodos que no son de buen gusto, mantenemos la estructura original del grafo.

**Fuente y super-sumidero**:
- Agrega un nodo fuente $s$.
- Agrega un super-sumidero $t'$, conectando todas las capitales provinciales $t_i \to t'$ con capacidad infinita o suficientemente alta.

**Capacidades de las aristas**:
- Todas las aristas tienen capacidad $1$.

La división de nodos asegura que:
* Cada ciudad de buen gusto puede ser utilizada como máximo una vez, ya que el flujo está limitado por la capacidad de $u_\text{in} \to u_\text{out}$, que es $1$.
* Los caminos que pasan por otras ciudades no tienen restricciones adicionales, ya que esas ciudades no se dividen.

El flujo máximo en esta red corresponderá al número máximo de caminos disjuntos en aristas y nodos (en las ciudades de buen gusto).

---

### 2 El simposio de Martı́n

> Martı́n está organizando un simposio sobre teorı́a de grafos y sabe que la gente no viene si no hay buena comida. 

> Tiene un conjunto $P$ de platos que puede cocinar. 

> Hizo una encuesta entre los investigadores y formuló para cada uno una lista $I_i \subseteq P$ de sus platos favoritos. 

> Sabe que para cada plato $p_j \in P$ puede cocinar a lo sumo $q_j$ unidades. 

> Martı́n quiere saber cuál es la máxima cantidad de investigadores a los que le va a poder servir su comida favorita.

### **Modelado como un problema de flujo**

- Un nodo fuente $s$.
- Un nodo por cada investigador $I_i$.
- Un nodo por cada plato $p_j \in P$.
- Un nodo sumidero $t$.

**Aristas**:
- Del nodo fuente $s$ a cada nodo investigador $I_i$, con capacidad $1$ (cada investigador puede ser servido una sola vez).
- De cada nodo investigador $I_i$ a los nodos de sus platos favoritos $p_j \in I_i$, con capacidad $1$ (cada investigador puede elegir como máximo un plato favorito).
- De cada nodo de plato $p_j$ al nodo sumidero $t$, con capacidad $q_j$ (cantidad máxima de unidades que Martín puede cocinar de $p_j$.

El flujo máximo en esta red representa el número máximo de investigadores que pueden ser servidos con su comida favorita.

- **Unidad de flujo**:
  - Una unidad de flujo representa a un investigador que ha sido servido con uno de sus platos favoritos.

- **Restricción de capacidad $s \to I_i$**:
  - Garantiza que cada investigador sea servido como máximo una vez.

- **Restricción de capacidad $I_i \to p_j$**:
  - Garantiza que cada investigador pueda elegir un solo plato favorito.

- **Restricción de capacidad $p_j \to t$**:
  - Asegura que Martín no cocine más unidades de un plato de las que puede $q_j$.

### **Correctitud del modelo**

**Cada investigador recibe su plato favorito**:
- El flujo desde $I_i$ a $p_j$ está limitado a $1$, asegurando que cada investigador pueda elegir como máximo un plato favorito.

**Cada plato respeta su límite de producción**:
- Las capacidades $q_j$ en las aristas $p_j \to t$ garantizan que Martín no exceda su límite de producción.

**Flujo máximo = Máximo número de investigadores servidos**:
- Por el teorema de flujo máximo-corte mínimo, el flujo máximo desde $s$ a $t$ representa el número máximo de investigadores que pueden ser servidos.

### **Complejidad**

La red tiene:
- $n$ nodos para los investigadores.
- $m$ nodos para los platos.
- $2 + n + m$ nodos en total.
- $n + e + m$ aristas, donde $e$ es el número total de preferencias (suma de los tamaños de los conjuntos $I_i$).

**Complejidad usando Edmonds-Karp**:
$$O((n + m) \cdot (n + e)^2)$$

---

### 3 Tuki en GH

Tuki fue uno de los afortunados en entrar a la casa de GH (Grupo Humano). 

En este juego cada semana los jugadores votan por la eliminación de otro jugador.

Cada jugador vota a un único jugador y los jugadores con más votos son enviados a un desafı́o.

Tuki sabe que conviene mantener la votación lo más pareja posible, para evitar problemas en la casa. 

El sabe que:
* Hay $J$ jugadores y $K$ grupos.
* El jugador $i$ pertenece al grupo $g_i$.
* El jugador $i$ está dispuesto a votar al conjunto $N_i$ de jugadores.
* Si algún grupo $G_l$ recibe más votos que el doble de la cantidad de jugadores en el grupo, entonces se va a sentir atacado.
* Si un jugador individual $i$ recibe más de $3$ votos, entonces también se siente atacado.

Quiere decidir, dados los $J$ jugadores junto a sus conjuntos $N_i$ y la descripción de los $K$ grupos, si es posible que la votación logre que ningún grupo
ni jugador se sienta atacado.

---

### 4 Victoria y las charlas

Ya confirmada la lista de asistentes al simposio, a Victoria le tocó la tarea de distribuirlos entre todas las charlas que se van a dar al mismo tiempo. 

Como cada una de las $C$ charlas tiene un cupo máximo de $A_i$ personas, cada asistente le informó su lista $I_j$ de charlas que le interesan. 

Como Victoria conoce mucho el chisme de la comunidad de investigación de teorı́a de grafos, ella sabe que todos los investigadores se pueden dividir en $R$ riñas de por lo menos dos investigadores cada una. 

Sabemos que cada investigador pertenece a exáctamente una riña.

Nos interesa saber si hay alguna  forma de organizar a todos los participantes en las distintas charlas de forma que se respeten sus deseos y nadie se pelee.