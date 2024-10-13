Intersección Máxima
---

Sea $\text{G}$ un grafo conexo. 

Demostrar por el $\color{violet}\text{contrarrecíproco}$ que todo par de caminos simples de longitud máxima de $\text{G}$ tienen al menos un vértice en común. 

Ayuda: suponer que hay dos caminos disjuntos en vértices de igual longitud y definir explícitamente un camino que sea más largo que
ellos.

Contrarrecíproco: Decir que $\alpha \rightarrow \beta$ es lo mismo que decir $\neg \beta \rightarrow \neg \alpha$.

Queremos demostrar que $\forall \text{ P, Q: caminos simples de longitud máxima de G, tienen al menos un vértice en común}$

Usando el contrarrecíproco, queremos demostrar que:

$\forall \text{P, Q: caminos simples que no tienen vértices en común, P, Q no son de longitud máxima}$

Como $\text{P}$ y $\text{Q}$ son de longitud máxima entonces tienen la misma longitud.

$\text{P}$ y $\text{Q}$ tienen la pinta:

$\text{P} = \{v_1, v_2, \ldots, v_n\}$

$\text{Q} = \{w_1, w_2, \ldots, w_n\}$

con $v_i \ne w_i$ para todo $i$.

entonces como el grafo es conexo, existe un camino $\text{R}$ que conecta a $\text{P}$ con $\text{Q}$.

Este camino $\text{R}$ tiene que tener al menos una arista que conecta a $\text{P}$ con $\text{Q}$, por lo que este camino tendría una arista más que $\text{P}$ y $\text{Q}$, por lo cual P y Q no serían de longitud máxima que es lo que quería probar.

Por lo tanto probamos por contrarrecíproco que todo par de caminos simples de longitud máxima de $\text{G}$ tienen al menos un vértice en común.