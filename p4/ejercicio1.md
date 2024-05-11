<font face="LaTeX">

<u>Recorridos en profundidad</u>

*Sea T un árbol generador de un grafo (conexo) G con raíz r, y sean V y W los vértices que están a distancia par e impar de r, respectivamente.*

---
*a) Observar que si existe una arista **vw ∈ E(G) \ E(T)** tal que v, w ∈ V o v, w ∈ W , entonces el único ciclo de T ∪ {vw} tiene longitud impar.*

V $\rightarrow$ Todos los vértices del grafo G que están a distancia par de la raíz r.

W $\rightarrow$ Todos los vértices del grafo G que están a distancia impar de la raíz r.

Si $\exists$ vw $\in$ E(G)\E(T) $\land$ v,w $\in$ V o v,w $\in$ W $\Rightarrow$ el único ciclo de T $\cup$ {vw} tiene longitud impar.
---

Tenemos que probar dos cosas:
Una es que el ciclo es único y la otra es que la longitud del ciclo es impar.

Para probar que el ciclo es único, sabemos que T es un árbol generador de un grafo G. Por lo tanto, las aristas que no están en T son las que forman ciclos. Si tomamos una arista vw que no está en T vamos a formar un ciclo en T $\cup$ {vw}. Y este ciclo es único porque si hubiera otro ciclo, entonces T no sería un árbol generador.

Para probar que el ciclo tiene longitud impar vamos a hacer un análisis por casos.

1. Si v, w $\in$ V $\Rightarrow$ la distancia entre r y v es par y la distancia entre r y w es par. Sabemos que v tiene un camino a r por lo que r forma parte del ciclo. Lo mismo pasa con w. Por lo tanto, el ciclo tiene longitud distancia(v, r) + distancia(r, w) + 1 = par + par + 1 = impar.

    Se suma 1 porque nos falta unir a la arista vw.

2. Si v, w $\in$ W $\Rightarrow$ la distancia entre r y v es impar y la distancia entre r y w es impar. Sabemos que v tiene un camino a r por lo que r forma parte del ciclo. Lo mismo pasa con w. Por lo tanto, el ciclo tiene longitud distancia(v, r) + distancia(r, w) + 1 = impar + impar + 1 = impar.

---

*b) Observar también que si toda arista de E(G)\E(T) une un vértice de V con otro de W, entonces (V, W) es una bipartición de G y, por lo tanto, G es bipartito.*

**Un grafo es bipartito si y solo si sus vértices se pueden dividir en dos conjuntos disjuntos tales que no hay aristas que unan dos vértices del mismo conjunto.**

En este contexto, los conjuntos $V$ y $W$ representan precisamente estos dos conjuntos disjuntos, dado que uno contiene vértices a distancia par de la raíz $r$ y el otro a distancia impar.

Propiedad del grafo bipartito: Dada la estructura de $V$ y $W$, cualquier ciclo en el grafo debe alternar entre vértices de estos conjuntos, lo cual es posible únicamente si el ciclo tiene longitud par. La existencia de una arista que conecte vértices dentro del mismo conjunto ($V$ o $W$) introduciría un ciclo impar, contradiciendo la premisa de que todas las aristas fuera del árbol generador conectan $V$ con $W$.

---

*c) A partir de las observaciones anteriores, diseñar un algoritmo lineal para determinar si un
grafo conexo G **es bipartito**.\
En caso afirmativo, el algoritmo debe retornar una **bipartición de G**.\
En caso negativo, el algoritmo debe retornar un **ciclo impar de G**.\
Explicitar cómo
es la implementación del algoritmo; no es necesario incluir el código.*

Para determinar si un grafo conexo G es bipartito, se puede utilizar el siguiente algoritmo:

1. Seleccionar un vértice arbitrario $r$ como raíz del árbol generador $T$.
2. Realizar un recorrido en profundidad desde $r$ para determinar los conjuntos $V$ y $W$.
3. Verificar si existe una arista que conecte dos vértices de $V$ o dos vértices de $W$. En caso afirmativo, retornar el ciclo impar formado por esta arista.
4. En caso contrario, retornar la bipartición $(V, W)$.

El algoritmo es lineal porque el recorrido en profundidad tiene complejidad $O(n + m)$, donde $n$ es la cantidad de vértices y $m$ es la cantidad de aristas del grafo. La verificación de la existencia de aristas que conecten dos vértices del mismo conjunto también tiene complejidad $O(n + m)$.

---

*d) Generalizar el algoritmo del inciso anterior a grafos no necesariamente conexos observando que un grafo G es bipartito si y solo si sus componentes conexas son bipartitas.*

Para generalizar el algoritmo a grafos no necesariamente conexos, se puede realizar un recorrido en profundidad desde cada vértice no visitado. En cada componente conexa, se aplicaría el algoritmo del inciso anterior para determinar si es bipartita. Si alguna componente conexa no es bipartita, el grafo completo tampoco lo será.



</font>