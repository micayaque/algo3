<font face="LaTeX">

### CacheOpt

---

*Como los accesos a memoria RAM son lentos en comparación al trabajo propio del CPU, es común que se coloquen memorias intermedias más diminutas y de alta velocidad entre ambas unidades, las cuales llamamos cachés.\
Cuando un programa se ejecuta y hace una consulta a la
memoria por cierta posición $r$ primero se verifica si la posición $r$ está cargada en la caché, en cuyo caso el CPU la puede obtener sin tener que hacer el acceso a la RAM.\
Cuando esto ocurre, decimos que ocurre un **caché hit**. En cambio, si la posición $r$ no está en la caché, esta se busca a memoria, se carga en la caché, y luego se la informa al CPU. A este evento se lo conoce como **caché miss**.\
Como la caché es más chica que la memoria RAM es inevitable que eventualmente ocurra un caché miss y que la caché este llena. En ese caso, la caché debe decidir qué información va a desechar para darle lugar a la nueva entrada. Naturalmente, se busca minimizar la cantidad de
misses de los siguientes accesos.\
El problema de Off-line caching consiste en determinar, dada una caché C de tamaño k y una lista de n requests $R=\{r_1,r_2,...,r_n\}$ a posiciones de memoria, qué decisión debe tomar en cada paso la caché para minimizar la cantidad de misses.\
Por ejemplo, si k = 2 y R = {1, 2, 3, 1} entonces:*
* La primera consulta es un miss, pero como hay lugar en la caché (empieza vacía) se carga la posición 1 a C (C = {1}).
* Con la segunda consulta pasa lo mismo, por lo que la caché queda en el estado C = {1, 2}.
* En la tercera consulta la caché esta llena, por lo que se debe desechar alguna entrada.\
Notemos que si se desecha 1 entonces la cuarta consulta dará otro miss, mientras que si se
desecha 2 entonces habrá un hit.

Una política posible para decidir qué elemento desechar es la furthest-in-future: se desecha aquella
posición $r$ cuyo siguiente acceso es el más lejano (o bien, que no tiene un siguiente acceso).

---

*b) Probar que la política furthest-in-future es óptima (es decir, que minimiza la cantidad de misses).\
Ayuda: Dada una serie de decisiones, probar que si en un paso no se sigue la política furthest entonces podemos alterar ese paso para que sí la siga sin afectar la cantidad de misses.*



---

*c) Dar un algoritmo con complejidad temporal O(n log(k)) que informe qué decisión debe tomar la caché en cada paso para minimizar la cantidad de misses.*



</font>