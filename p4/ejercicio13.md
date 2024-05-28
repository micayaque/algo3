El algoritmo de Kruskal (resp. Prim) $\textcolor{salmon}{con\ orden\ de\ selección}$ es una variante del algoritmo de Kruskal (resp. Prim) donde a cada $\textcolor{pink}{arista\ e}$ se le asigna una prioridad $\textcolor{pink}{q(e)}$ además de su peso $\textcolor{salmon}{p(e)}$.
---

Luego, si en alguna iteración del algoritmo de Kruskal (resp. Prim) hay $\textcolor{pink}{más\ de\ una\ arista\
posible\ para\ ser\ agregada}$, entre esas opciones se elige alguna de mínima $\textcolor{pink}{prioridad}$.
---

*Esto nos dice que cuando ejecutamos Kruskal en la versión con orden de selección cada arista además de tener un peso asignado también tiene asignada una prioridad por lo cual al momento de elegir una arista como "menor" para las aristas que tengan igual peso se tendrá en cuenta cuál es la prioridad de cada arista para ser elegida y será elegida la que tenga mínima(0) prioridad.*

a) Demostrar que para todo árbol generador mínimo T de G, si las $\textcolor{pink}{prioridades\ de\ asignación}$ están definidas por la función
---

$$q(e) = \begin{cases} 
    0 & \text{si } e \in T \\
    1 & \text{si } e \notin T
   \end{cases}$$
---

entonces se obtiene T como resultado del algoritmo de Kruskal (resp. Prim) con $\textcolor{salmon}{orden\ de\ selección}$ ejecutado sobre G (resp. cualquiera sea el vértice inicial en el caso de Prim).
---

*La prioridad de asignación es 0 si la arista pertenece al árbol, es decir, si es que el algoritmo de Kruskal eligió a esa arista que tiene prioridad mínima(0) ya que en el otro caso tiene prioridad 1.*

---

$\forall\ \mathcal{T}\ AGM_G\ si\ se\ definen\ las\ prioridades\ de\ las\ aristas\ con\ q(e)\ \Rightarrow\ se\ obtiene\ \mathcal T\ como\ resultado\ de\ Kruskal\ /\ Prim\ con\ orden\ de\ selección\ $
---

Supongamos que no se obtiene $\mathcal T$ como resultado de Kruskal/Prim con $\textcolor{salmon}{orden\ de\ selección}$.

---

Definición de $\textcolor{salmon}{orden\ de\ selección}$: a cada $\textcolor{pink}{arista\ e}$ se le asigna una prioridad $\textcolor{pink}{q(e)}$ además de su peso $\textcolor{salmon}{p(e)}$.\
Luego, si en alguna iteración del algoritmo de Kruskal/Prim hay $\textcolor{pink}{más\ de\ una\ arista\ posible\ para\ ser\ agregada}$, entre esas opciones se elige alguna de mínima $\textcolor{pink}{prioridad}$.

---

Entonces al momento de generar el $AGM_G\ \mathcal T$ si nos encontramos con aristas que tengan el mismo peso ninguna arista debería tener prioridad sobre la otra y deberíamos elegir a cualquiera $\textcolor{pink}{\ arbitrariamente\ }$ para agregar al árbol/bosque.\
Por consiguiente, $\mathcal T$ no cumple con la función q(e) de prioridades.\
Lo que nos lleva a un $\textcolor{orange}{absurdo}$ porque estabamos suponiendo por hipótesis que $\mathcal T$ tiene prioridades definidas en sus aristas con $q(e)$. Que lo que nos dice es que si la prioridad es menor(0) entonces la arista pertenece al árbol y si la prioridad es mayor(1) entonces la arista no pertenece al árbol.\
Por lo tanto $\mathcal T$ se obtiene con orden de selección.

---

b) Usando el inciso anterior, demostrar que si los pesos de G son todos distintos, entonces G tiene un único árbol generador mínimo.
---

Todos los pesos de G son distintos $\Rightarrow$ G tiene un único árbol generador mínimo
---

Supongamos que G tiene $\textcolor{pink}{más\ de\ un\ árbol\ generador\ mínimo}$.\
Sean $\mathcal{\textcolor{green}{T_1}}$ y $\mathcal{\textcolor{green}{T_2}}$ dos $AGM_G$.
Existe una arista $\textcolor{orange}{e}$ que pertenece a $\mathcal{\textcolor{green}{T_1}}$ pero no a $\mathcal{\textcolor{green}{T_2}}$ o viceversa.\
Sea $\textcolor{orange}{e}$ la arista que pertenece a $\mathcal{\textcolor{green}{T_1}}$ pero no a $\mathcal{\textcolor{green}{T_2}}$.\
Y sea $\textcolor{orange}{e'}$ la arista que pertenece a $\mathcal{\textcolor{green}{T_2}}$ pero no a $\mathcal{\textcolor{green}{T_1}}$.\
Si asignamos $\mathcal{\textcolor{salmon}{prioridades}}$ a las aristas de G con la función $\mathcal{\textcolor{salmon}{q(e)}}$ que se definió en el inciso anterior, entonces $\mathcal{\textcolor{green}{T_1}}$ y $\mathcal{\textcolor{green}{T_2}}$ se obtienen como resultado del algoritmo de Kruskal/Prim con orden de selección.\
Por lo tanto, en alguna iteración de Prim o Kruskal, como $\textcolor{orange}{e}$ y $\textcolor{orange}{e'}$ son aristas distintas de $\mathcal{\textcolor{green}{T_1}}$ y $\mathcal{\textcolor{green}{T_2}}$ respectivamente, significa que una de las dos aristas tiene prioridad 0 y la otra prioridad 1.\
Eso significa que en alguna iteración el algoritmo tuvo que elegir entre agregar $\textcolor{orange}{e}$ o $\textcolor{orange}{e'}$ al AGM.\
Lo que nos dice que $\textcolor{orange}{e}$ y $\textcolor{orange}{e'}$ tienen pesos iguales, lo cual es absurdo porque todos los pesos de G son distintos.\
Por lo tanto, si G tiene todos los pesos de sus aristas distintos, G tiene un único árbol generador mínimo.