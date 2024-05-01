<font face="LaTeX">

### Doble Grado

---

Demostrar, usando la técnica de reducción al absurdo, que todo grafo no trivial tiene al menos dos vértices del mismo grado. \
Ayuda: prestar atención a la secuencia ordenada de los grados de los vértices.

$(\forall \ G :  |V_G| >2) \ (\exists \ u,v\in V_G \ \land d(u) = d(v)) $ 

---

Queremos ver que existe un grafo no trivial que no tiene dos vértices del mismo grado.

$(\exists \ G \ : |V_G| >2) (\forall \ u,v \ \in V_G \ d(u) \neq \ d(v)) $



Los grados posibles de los vértices en un grafo de (n) vértices varían desde 0 (un vértice no conectado a ningún otro) hasta (n-1) (un vértice conectado a todos los demás).\
En un grafo **no trivial**, no es posible tener al mismo tiempo un vértice de grado 0 y otro de grado (n-1), porque si un vértice está conectado a todos los demás (n-1), entonces no puede haber un vértice sin conexiones (grado 0).

Dado que no podemos tener vértices de grado 0 y (n-1) al mismo tiempo, los grados posibles en realidad son desde 0 hasta (n-2) o desde 1 hasta (n-1). Esto nos deja con (n-1) posibles grados para (n) vértices.

La secuencia ordenada de los grados de los vértices sería: $[0,1,2,3,...,n-2]$ o $[1,2,3,...,n-1]$.

Si intentamos asignar un grado único a cada uno de los (n) vértices usando solo (n-1) opciones, inevitablemente tendremos que repetir al menos uno de los grados, lo que contradice nuestra suposición inicial de que todos los vértices tienen grados diferentes. 

Por lo tanto, nuestra suposición inicial debe ser falsa, y debe existir al menos un par de vértices con el mismo grado en todo grafo no trivial. $\blacksquare$
</font>