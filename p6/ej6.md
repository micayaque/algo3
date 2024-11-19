### Problemas de modelado II: asignación

En el pueblo de Asignasonia las fiestas de casamiento son muy peculiares y extrañamente frecuentes. 

Las invitaciones a la fiesta nunca son personales sino familiares: cada persona invitada asiste siempre con todes sus familiares solteres, a quienes se les reservan mesas especiales de solteres.

Además, hay una regla no escrita que establece un límite $c_{ij}$ a la cantidad de solteres de la familia $i$ que pueden sentarse en la mesa $j$. 

Esta forma de festejar es la que, aparentemente, aumenta la cantidad de casamientos futuros. 

Desafortunadamente, el esfuerzo que implica mantener viva esta tradición está llevando a que varias parejas eviten el compromiso marital. 

Es por esto que la intendencia de Asignasonia requiere un algoritmo que resuelva el problema de asignación de les solteres a sus mesas.

> $a)$ Proponer un modelo de flujo que dados los conjuntos $F = \{f_1 , . . . , f_{|F |} \}, M = \{m_1 , . . . , m_{|M |} \}$ y $C = \{c_{ij} | 1 \leq i \leq |F |, 1 \leq j \leq |M |\}$ determine una asignación que respete las tradiciones sabiendo que:

* > la familia $i$ esta formada por $f_i$ personas solteres, la mesa $j$ tiene $m_j$ lugares disponibles para solteres, y en la mesa $j$ solo pueden sentarse $c_{ij}$ solteres de la familia $i$.

Queremos diseñar un modelo de flujo que permita asignar a los solteros de las familias $F$ a las mesas $M$ cumpliendo con las restricciones dadas.

Creamos una red dirigida $G = (V, E)$:

* **Nodos**:
   - Un nodo fuente $s$.
   - Un nodo por cada familia $f_i \in F$.
   - Un nodo por cada mesa $m_j \in M$.
   - Un nodo sumidero $t$.

* **Aristas**:
   - De $s$ a cada familia $f_i$, con capacidad igual al número de solteros en esa familia: $f_i$.
   - De cada familia $f_i$ a cada mesa $m_j$, con capacidad $c_{ij}$ (máximo número de solteros de $f_i$ que pueden sentarse en $m_j$).
   - De cada mesa $m_j$ a $t$, con capacidad igual al número de lugares disponibles en la mesa: $m_j$.

Queremos maximizar el flujo desde $s$ a $t$, que corresponde al número máximo de solteros asignados a las mesas mientras se respetan las restricciones.

- Cada familia puede enviar como máximo $f_i$ solteros en total.
- Cada mesa puede recibir como máximo $m_j$ solteros en total.
- Para cada combinación $(f_i, m_j)$, como máximo $c_{ij}$ solteros de $f_i$ pueden sentarse en $m_j$.

> $b)$ Dar una interpretación a cada unidad de flujo y cada restricción de capacidad.

Cada unidad de flujo representa a un soltero que es asignado de una familia $f_i$ a una mesa $m_j$.

$c_{ij}$ asegura que no se sienten más de $c_{ij}$ solteros de la familia $f_i$ en la mesa $m_j$.

$s \to f_i$ garantiza que una familia no envíe más solteros de los que tiene disponibles.

$m_j \to t$ garantiza que no se asignen más solteros a una mesa de los lugares disponibles.

> $c)$ Determinar la complejidad de resolver el modelo resultante con el algoritmo de Edmonds y Karp.

El algoritmo de Edmonds-Karp tiene una complejidad de $O(nm^2)$, donde:
- $n$: Número de nodos.
- $m$: Número de aristas.

- 1 nodo fuente $s$.
- $|F|$ nodos para las familias.
- $|M|$ nodos para las mesas.
- 1 nodo sumidero $t$.
$$n = 2 + |F| + |M|$$

- $|F|$ aristas de $s$ a cada familia $f_i$.
- $|F| \cdot |M|$ aristas de las familias $f_i$ a las mesas $m_j$.
- $|M|$ aristas de las mesas $m_j$ a $t$.
$$m = |F| + |F| \cdot |M| + |M|$$

#### **Complejidad total**:
$$O(nm^2) = O\left((2 + |F| + |M|) \cdot (|F| + |F| \cdot |M| + |M|)^2\right)$$