<font face="LaTeX">

### ArteConexo
*Un vértice v de un grafo G es un punto de articulación si G − v tiene más componentes conexas que G.\
Por otro lado, un grafo es **biconexo** si es conexo y no tiene puntos de articulación.*

---
*a) Demostrar, usando inducción en la cantidad de vértices, que todo grafo de n vértices que tiene más de $\frac{(n − 1)(n − 2)}{2}$ aristas es conexo.\
Opcionalmente, puede demostrar la misma propiedad usando otras técnicas de demostración.*

---

Queremos demostrar que todo grafo de n vértices que tiene más de $\frac{(n − 1)(n − 2)}{2}$ aristas es conexo.

Consideremos un grafo G con n vértices y m aristas, donde m > $\frac{(n − 1)(n − 2)}{2}$.

<u>**Caso base:**</u>\
Para n = 1, el grafo tiene un solo vértice, por lo que no tiene aristas.\
Para n = 2, el grafo tiene dos vértices y podría tener una arista como mucho por lo que tiene mas de $\frac{(n − 1)(n − 2)}{2} = \frac{(1-1)(2-2)}{2} = 0$ aristas y es conexo.

---

<u>**Hipótesis inductiva:**</u>\
Supongamos que todo grafo de k vértices con más de $\frac{(k − 1)(k − 2)}{2}$ aristas es conexo.

---

<u>**Paso inductivo:**</u>\
Consideremos un grafo G con k+1 vértices y m aristas, donde m > $\frac{((k+1) − 1)((k+1) − 2)}{2}$.

Si eliminamos un vértice v de G, obtenemos un grafo G-v con k vértices y m'=E(G)- todas las aristas del nodo v, por lo que m' = m - d(v) donde d(v) es el grado del vértice v.

Por lo tanto, 
* Si m' $>$ $\frac{(k − 1)(k − 2)}{2}$ por `HI` el grafo G-v es conexo.

---

* Si m' $\leq$ $\frac{(k − 1)(k − 2)}{2}$, entonces las premisas de la proposición no se cumplen, por lo que la proposición es trivialmente verdadera. $False \implies X = True \ \blacksquare$ 

---

</font>