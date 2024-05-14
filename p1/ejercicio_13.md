### ParejasdeBaile
*Tenemos dos conjuntos de personas y para cada persona sabemos su habilidad de baile. Queremos armar la máxima cantidad de parejas de baile, sabiendo que para cada pareja debemos elegir exactamente una persona de cada conjunto de modo que la diferencia de habilidad sea menor o igual a 1 (en módulo). Además, cada persona puede pertenecer a lo sumo a una pareja de baile. Por ejemplo, si tenemos un multiconjunto con habilidades {1, 2, 4, 6} y otro con {1, 5, 5, 7, 9}, la máxima cantidad de parejas es 3. Si los multiconjuntos de habilidades son {1, 1, 1, 1, 1} y {1, 2, 3}, la máxima cantidad es 2.*

---

*a) Considerando que ambos multiconjuntos de habilidades estan ordenados en forma creciente,
observar que la solución se puede obtener recorriendo los multiconjuntos en orden para realizar los emparejamientos.*

---

*b) Diseñar un algoritmo goloso basado en a) que recorra una única vez cada multiconjunto. Explicitar la complejidad temporal y espacial auxiliar.*


```python
def parejas_de_baile(habilidades1, habilidades2):
    i = 0
    j = 0
    parejas = 0
    while i < len(habilidades1) and j < len(habilidades2):
        if abs(habilidades1[i] - habilidades2[j]) <= 1:
            parejas += 1
            i += 1
            j += 1
        elif habilidades1[i] < habilidades2[j]:
            i += 1
        else:
            j += 1
    return parejas
```

La complejidad temporal del algoritmo es O(n + m) donde n y m son la cantidad de elementos de los multiconjuntos de habilidades. La complejidad espacial auxiliar es O(1).

*c) Demostrar por inducción que el algoritmo dado en b) es correcto.*

Sea $G_k$ una solución parcial construida mediante nuestra estrategia golosa luego de k iteraciones del algoritmo y $O_k$ una solución parcial óptima.

Sea n = $|S_k|$ queremos demostrar por inducción que $|G_k|$ $\geq$ $|O_k|$ para todo k = 1, 2, ..., n.

Al comienzo de la k-ésima iteración del algoritmo tiene en consideración los primeros i elementos de habilidades1 y los primeros j elementos de habilidades2. 

<u> Caso base: </u> k = 0

Como todavía no comenzamos a elegir parejas, i = 0 y j = 0. Por lo tanto, $|G_0|$ = 0 y cualquier solución óptima $|O_0|$ = 0 porque no tenian nada para elegir aún.

<u> Paso inductivo: </u> k $\geq$ 0

Supongamos que $|G_k|$ $\geq$ $|O_k|$ para algún k $\geq$ 0. Queremos demostrar que $|G_{k+1}|$ $\geq$ $|O_{k+1}|$.

Por definición de nuestra estrategia golosa para la k+1-ésima iteración, si la diferencia de habilidad entre habilidades1[i] y habilidades2[j] es menor o igual a 1, entonces se elige esa pareja. En caso contrario, se avanza en el multiconjunto que tenga la habilidad menor.

Si la pareja es elegida, entonces $|G_{k+1}|$ = $|G_k|$ + 1 (por definición del algoritmo) y $|O_{k+1}|$ $\leq$ $|O_k|$ + 1 (porque la solución óptima no puede ser peor que la solución parcial óptima anterior). 

Como $|G_k|$ $\geq$ $|O_k|$ por hipótesis y $|G_{k+1}|$ = $|G_k|$ + 1 y $|O_{k+1}|$ $\leq$ $|O_k|$ + 1, entonces $|G_{k}|$ + 1 $\geq$ $|O_{k}| + 1$.\
(Restamos 1 de cada lado y nos queda la HI).

Por lo tanto, $|G_{k+1}|$ $\geq$ $|O_{k+1}|$ para todo k $\geq$ 0.

Si la pareja no es elegida, entonces $|G_{k+1}|$ = $|G_k|$.\
Como los conjuntos de habilidades están ordenados en forma creciente, entonces la diferencia de habilidad entre el de menor habilidad y los de habilidades restantes del otro conjunto va a ser aún mayor. Por lo tanto, no se va a poder elegir ninguna pareja más adelante.\
Por lo tanto, la solución óptima tampoco va a poder elegir pareja en ese caso.\
Por lo tanto, $|O_{k+1}|$ = $|O_k|$.

Y por HI $|G_{k+1}|$ = $|G_k|$ $\geq$ $|O_k|$ = $|O_{k+1}|$.

$\blacksquare$