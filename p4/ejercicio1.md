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

b) Observar también que si toda arista de E(G)\E(T) une un vértice de V con otro de W, entonces (V, W) es una bipartición de G y, por lo tanto, G es bipartito.



</font>