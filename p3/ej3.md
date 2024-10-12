Unicidad Digrafo
---

Un grafo orientado es un digrafo $D$ tal que al menos uno de $v \rightarrow w$ y $w \rightarrow v$ no es una arista de $D$, para todo $v, w \in V (D)$.

En otras palabras, un grafo orientado se obtiene a partir
de un grafo no orientado dando una dirección a cada arista.

Demostrar en $\color{violet}\text{forma constructiva}$ que **para cada $n$ existe un único grafo orientado cuyos vértices tienen todos grados de salida distintos**.

Ayuda: aprovechar el ejercicio anterior y observar que el absurdo no se produce para un único
grafo orientado.

Ejercicio anterior: $(\forall \ G :  |V_G| >2) \ (\exists \ u,v\in V_G \ \land d(u) = d(v)) $

Por construcción:

Idea: Si la fórmula habla de la existencia de alguna estructura, podemos simplemente explicar cómo se construye.

Un grafo orientado se obtiene a partir de un grafo no orientado dando una dirección a cada arista.

Entonces dado cualquier grafo $G$ no orientado con $n$ vértices, podemos asignarle a cada una de sus aristas $<u,v>$ una dirección, de manera que $u$ tenga una arista saliente y $v$ tenga una arista entrante o al revés.

Por el ejercicio anterior sabemos que $(\forall \ G :  |V_G| >2) \ (\exists \ u,v\in V_G \ \land d(u) = d(v)) $

Cuando el grafo es orientado cada vértice puede tener grado de salida (n-1) - su grado de entrada.

Para que todos los grados de salida de cada vértice sean distintos, podemos asignar un grado de salida único a cada vértice si:

* el primer vértice puede tener 0 aristas de salida (todas las aristas que lo involucran son entrantes),
* el segundo vértice puede tener 1 arista de salida (y (n-2) entrantes),
* y así sucesivamente hasta el último vértice, que tendría (n-1) aristas de salida y 0 entrantes.

Es así como construimos un grafo orientado asegurando que cada vértice tenga un grado de salida distinto.

Absurdo: Si hubieran dos grafos orientados distintos $o$ y $o'$ con todos sus vértices con grados de salida distintos, eso implica que podemos cambiar una de las asignaciones en nuestro grafo orientado que construimos y formar el grafo $o'$.

Podemos ver que si cambiaramos alguna de las asignaciones de los grados de salida de los vértices, tendríamos un vértice con grado de salida repetido.

Esto implicaría por cómo es que se construye este grafo orientado que hay una cantidad de aristas de salida que "no está dirigida", lo que contradice por como construimos al grafo orientado con todos los grados de salida distintos.

Por lo tanto el grafo orientado que tiene a todos sus vértices con grado de salida distintos, es único.

$\square$