Sean $P$ y $Q$ dos caminos distintos de un grafo $G$ que unen un vértice $v$ con otro $w$. 

Demostrar en forma $\color{violet}\text{directa}$ que $G$ tiene un ciclo cuyas aristas pertenecen a $P$ o $Q$. 

Ayuda: denotar $P = v_0,...,v_p$ y $Q = w_0,...,w_q$ con $v_0 = w_0 = v$ y $v_p = w_q = w$. 

Definir explícitamente cuáles son los subcaminos de $P$ y $Q$ cuya unión forman un ciclo.


Demostración directa: Para probar que $x$ satisface una propiedad $P(x)$ simplemente tomamos la deﬁnición de $P$
y mostramos que $x$ la cumple.

Queremos demostrar que si $P$ y $Q$ son dos caminos distintos que unen un vértice $v$ con otro $w$ en un grafo $G$, entonces $G$ tiene un ciclo cuyas aristas pertenecen a $P$ o $Q$.

Sean $P = v_0,...,v_p$ y $Q = w_0,...,w_q$ con $v_0 = w_0 = v$ y $v_p = w_q = w$.

Si $P$ y $Q$ no comparten aristas, entonces $P \cup Q$ es un ciclo.

Porque podemos ir de $v$ a $w$ por $P$ y luego volver de $w$ a $v$ por $Q$.

![alt text](/img/image15.png)

Si $P$ y $Q$ comparten aristas, entonces hay un vértice $v_i$ que es el primero en el que se separan.

![alt text](/img/image14.png)

Sabemos que tanto $P$ como $Q$ llegan al vértice $w$, pueden llegar:

* volviendo a juntarse en el mismo camino por lo cual en aljún momento volverían a compartir algún vértice $v_j$ con lo cual forman un ciclo porque se puede ir de $v_i$ a $v_j$ por $P$ y de $v_j$ a $v_i$ por $Q$.

* o bien no volviendo a juntarse en el mismo camino, en cuyo caso $P$ y $Q$ forman un ciclo porque se puede ir de $v_i$ a $w$ por $P$ y de $w$ a $v_i$ por $Q$.

