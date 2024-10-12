Doble Grado
---

Demostrar, usando la técnica de $\color{violet}\text{reducción al absurdo}$, que todo grafo no trivial tiene al menos dos vértices del mismo grado.

Ayuda: prestar atención a la secuencia ordenada de los grados de los vértices.

`Reducción al absurdo:`

Idea: Para probar que $\alpha \rightarrow \beta$ vamos a asumir que valen $\alpha$ y $\neg \beta$, para ver luego que esto contradice algún resultado previo.

Queremos ver que todo grafo no trivial tiene al menos dos vértices del mismo grado:

$(\forall \ G :  |V_G| >2) \ (\exists \ u,v\in V_G \ \land d(u) = d(v)) $

Usamos reducción al absurdo:

Supongamos que existe un grafo no trivial que no tiene dos vértices del mismo grado:

$(\exists \ G \ : |V_G| >2) (\forall \ u,v \ \in V_G \ d(u) \neq \ d(v)) $

Los grados posibles de los vértices en un grafo de $n$ vértices varían desde 0 (un vértice no conectado a ningún otro) hasta $n-1$ (un vértice conectado a todos los demás).

La secuencia ordenada de los grados de los vértices sería: $[0,1,2,3,...,n-2]$ o $[1,2,3,...,n-1]$.

En ambos casos tenemos $n-1$ posibles grados para $n$ vértices.

Si intentamos asignar un grado único a cada uno de los $n$ vértices usando solo $n-1$ opciones, inevitablemente tendremos que repetir al menos uno de los grados, lo que contradice nuestra suposición inicial de que todos los vértices tienen grados diferentes.

Por lo tanto, nuestra suposición inicial debe ser falsa, y debe existir al menos un par de vértices con el mismo grado en todo grafo no trivial. $\blacksquare$

