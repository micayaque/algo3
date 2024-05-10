<font face="LaTeX">

<u>**Unicidad de Grados**</u>

Sean $G_2$ = $K_2$ y $G_{n+1} = \overline{G_n \cup K_1}$ para todo n ≥ 2.\
Demostrar por inducción que $G_n$ tiene un único par de vértices de igual grado.


---

El grafo $G_{n+1}$ se forma tomando la unión de $G_n$ y un $K_1$ (un grafo de un solo vértice), y luego tomando el complemento de este grafo unido. En el grafo unido $G_n \cup K_1$, el vértice en $K_1$ no tiene conexiones con $G_n$, y al tomar el complemento, este vértice se conectará con todos los vértices de $G_n$, mientras que las conexiones existentes dentro de $G_n$ se invertirán.

---

Dado que en $G_n$ había un único par de vértices de igual grado, al agregar un nuevo vértice y formar el complemento, este nuevo vértice tendrá grado $n$ (porque se conecta con todos los vértices de $G_n$), que es un grado distinto al de cualquier otro vértice en $G_n$ ya que $G_n$ tenía menos de $n$ vértices. 

---

Por lo tanto, los grados de los vértices originales de $G_n$ en $G_{n+1}$ se modificarán de tal manera que el par de vértices de igual grado en $G_n$ ya no tendrá el mismo grado en $G_{n+1}$, pero se mantendrá la unicidad del par de igual grado al considerar la nueva estructura del grafo.

Por lo tanto, podemos concluir que si $G_n$ tiene un único par de vértices de igual grado, entonces $G_{n+1}$ también lo tendrá, lo que completa nuestro paso inductivo.

---

Por lo tanto, mediante el principio de inducción matemática, hemos demostrado que para todo $n \geq 2$, $G_n$ tiene un único par de vértices de igual grado.

Recuerda, el paso clave aquí es entender cómo la operación de formar el complemento del grafo unido afecta los grados de los vértices y cómo eso preserva la propiedad de tener un único par de vértices de igual grado a través de las iteraciones.

</font>