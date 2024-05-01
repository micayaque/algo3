<font face="LaTeX">

### ParejasdeBaile
*Tenemos dos conjuntos de personas y para cada persona sabemos su habilidad de baile. Queremos armar la máxima cantidad de parejas de baile, sabiendo que para cada pareja debemos elegir exactamente una persona de cada conjunto de modo que la diferencia de habilidad sea menor o igual a 1 (en módulo). Además, cada persona puede pertenecer a lo sumo a una pareja de baile. Por ejemplo, si tenemos un multiconjunto con habilidades {1, 2, 4, 6} y otro con {1, 5, 5, 7, 9}, la máxima cantidad de parejas es 3. Si los multiconjuntos de habilidades son {1, 1, 1, 1, 1} y {1, 2, 3}, la máxima cantidad es 2.*

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

<u>**Hipótesis inductiva:** </u>

Supongamos que el algoritmo encuentra la cantidad máxima de parejas de baile óptima para los primeros $𝑘 $ elementos de las listas *habilidades1* y *habilidades2*. $𝑃(𝑘) $

<u>**Caso base:** </u>

Para el caso base, consideremos cuando una de las listas *habilidades1* o *habilidades2* es **vacía**. En este caso, no se pueden formar parejas de baile, por lo que la cantidad máxima de parejas es 0. El algoritmo devuelve correctamente 0 en este caso, ya que no hay elementos para comparar.

Por lo tanto, el algoritmo satisface el caso base. 

<u>**Paso inductivo:** </u>

Queremos probar que también encuentra la cantidad de parejas de baile óptima para los primeros $𝑘+1 $ elementos de las listas *habilidades1* y *habilidades2*. $P(𝑘+1) $


* Si el 𝑘+1-ésimo elemento de *habilidades1* es emparejado con el 𝑘+1-ésimo elemento de *habilidades2*, entonces la cantidad total de parejas será  $𝑃(𝑘)+1 $. Por **HI** suponemos que la cantidad óptima de parejas para los primeros 𝑘 elementos es $P(𝑘) $, y agregamos una pareja más al emparejar estos dos elementos. Esto nos da $𝑃(𝑘)+1 $ parejas en total, que es la cantidad óptima de parejas para los primeros $𝑘+1 $ elementos.
* Si el 𝑘+1-ésimo elemento de *habilidades1* no puede ser emparejado con el 𝑘+1-ésimo elemento de *habilidades2*, entonces el algoritmo avanzará en una de las listas y no se contará una pareja adicional porque al estar las habilidades ordenadas ascendentemente no tenemos forma de crear una nueva pareja con el elemento que estamos mirando ya que a la derecha de elemento mayor solo van a haber elementos de habilidad mayor lo que solo aumentaría más aún el módulo de la diferencia de habilidades. 

    Esto significa que la cantidad óptima de parejas para los primeros 𝑘+1 elementos sigue siendo 𝑃(𝑘), ya que no se agregó ninguna pareja adicional. Como suponemos que el algoritmo encuentra la cantidad máxima de parejas para los primeros 𝑘 elementos, no se contará ninguna pareja más en este caso.

Por lo tanto, en ambos casos, el algoritmo encontrará la cantidad máxima de parejas de baile óptima para los primeros $𝑘+1 $ elementos de las listas *habilidades1* y *habilidades2*.
Dado que el algoritmo comienza con la cantidad máxima de parejas de baile para los primeros elementos y avanza de manera golosa, siempre seleccionando la pareja más compatible en ese momento, el algoritmo encuentra la solución óptima.
$\blacksquare $

</font>