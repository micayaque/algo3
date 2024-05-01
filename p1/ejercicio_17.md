<font face="LaTeX">

### <u>División Pandémica</u>

*En medio de una pandemia, la Escuela de Aulas Grandes y Ventiladas quiere implementar un protocolo especial de distanciamiento social que tenga en cuenta que la escuela no tienen restricciones de espacio. El objetivo es **separar a cada curso en dos subcursos** a fin de **reducir la cantidad de pares de estudiantes que sean muy cercanos**, dado que se estima que estos estudiantes tienen dificultades para respetar tan buscado distanciamiento.\
Para este fin, en el protocolo se estableció que cada curso que tenga `c parejas` de estudiantes cercanos tiene que dividirse en dos subcursos, cada uno de los cuales puede tener a lo sumo `c/2 parejas` de estudiantes cercanos.\
Notar que no importa si un subcurso queda con más estudiantes que otro.*\
*Formalmente, para cada curso contamos con un conjunto de estudiantes `E` y su conjunto `C` de pares de estudiantes cercanos.\
Luego, una partición `(A, B)` de `E` es una solución factible para `(E, C)` cuando:\
`|(A × A) ∩ C| ≤ |C|/2`  y \
`|(B × B) ∩ C| ≤ |C|/2`. \
Por ejemplo, si E = {1, 2, 3, 4} y C = {1-2, 2-3, 3-4}, entonces ({1, 3, 4}, {2}) y ({2, 4}, {1, 3}) son soluciones factibles.*

---

*a) Especificar el problema descrito definiendo cuál es la instancia (i.e. cuáles son los datos de entrada y qué condiciones satisfacen) y cuál es el resultado esperado (i.e., cuáles son los datos de salida y qué condiciones satisfacen).*

La instancia o datos de entrada es un par de conjuntos `(E, C)`, donde `E` es un conjunto de estudiantes y `C` es un conjunto de pares de estudiantes cercanos.\
Las condiciones que satisfacen son:
1. `C` es un conjunto de pares de elementos de `E`.
2. Para todo par `(a, b)` en `C`, `a` y `b` son elementos de `E`.
3. Para todo par `(a, b)` en `C`, `a` y `b` son distintos.
4. Para todo par `(a, b)` en `C`, `a` y `b` son cercanos.

El resultado esperado o datos de salida es un par de conjuntos `(A, B)`, donde `A` y `B` son subconjuntos de `E`.\
Las condiciones que satisfacen son:
1. `A` y `B` son disjuntos.
2. `A` y `B` son subconjuntos de `E`.
3. `|(A × A) ∩ C| ≤ |C|/2`.
4. `|(B × B) ∩ C| ≤ |C|/2`.

---

*b) Demostrar que para toda instancia existe un resultado esperado que satisface las condiciones definidas por el protocolo.\
<u>Ayuda: hacer inducción en la cantidad de estudiantes.</u>\
Para el paso inductivo, considerar que si les estudiantes se asignan iterativamente a los subcursos,
entonces conviene **enviar a cada estudiante al subcurso que tenga la menor cantidad de estudiantes cercanos a elle**.*

---

**Demostración:**\
Sea `n` la cantidad de estudiantes en `E`.\

---

<u>Caso base:</u> `n=2`\
En este caso es trivial ver que podemos hacer 2 particiones en la que separemos al único par de estudiantes cercanos que tenemos y cumplir las condiciones definidas por el protocolo, el resultado esperado es `(A={e1}, B={e2})`\
$\therefore$ vale el caso base.\

---

<u>Hipótesis inductiva:</u>
Supongamos que para `n=k` la afirmación es verdadera, es decir, existe un resultado esperado que satisface las condiciones definidas por el protocolo.

---

<u>Caso inductivo:</u> `n=k+1`\
Consideremos una instancia `(E, C)` con `k+1` estudiantes.\
Sea `e` un estudiante cualquiera `| e ∈ E`.\
Definimos `E' = E - {e}` y `C' = C - {(e, e') | e' ∈ E}`, el conjunto de estudiantes sacando a un estudiante cualquiera de los dos conjuntos de la solución.\
Si tenemos `k` estudiantes, entonces tenemos dos subconjuntos `A'` y `B'` que cumplen con las condiciones del protocolo.

---

Si tenemos `k+1` estudiantes, entonces queremos ver que dos subconjuntos `A' U {e}` y `B'` o, `A'` y `B' U {e}` que cumplen con las condiciones del protocolo.\
Al agregar un estudiante adicional, examinamos su relación con los estudiantes existentes.

Por **hipótesis inductiva**, existe un resultado esperado `(A', B')` que satisface las condiciones definidas por el protocolo para `(E', C')`. Entonces, consideramos que ya tenemos dos subcursos que cumplen con las condiciones del protocolo para $k$ estudiantes.\
Ahora, debemos considerar al estudiante `e` y asignarlo a uno de los dos subcursos:
1. Si `e` se asigna a `A'`, entonces `A = A' U {e}` y `B = B'`.
2. Si `e` se asigna a `B'`, entonces `A = A'` y `B = B' U {e}`.

Usando la <u>Ayuda</u> para minimizar el incremento de pares cercanos en cualquiera de los subcursos, asignamos a {e} al subcurso que tenga menos pares de estudiantes cercanos con {e}.

Para asignar a `e` a uno de los dos subcursos, debemos considerar la cantidad de pares de estudiantes cercanos que se forman con `e` en cada uno de los subcursos.\
Definimos:\
`a = |C ∩ {(e, e') | e' ∈ A}|` y \
`b = |C ∩ {(e, e') | e' ∈ B}|`.\
Si `a ≤ |C|/2` y `b ≤ |C|/2`, entonces podemos asignar a `e` a uno de los dos subcursos y cumplir con las condiciones del protocolo.\
Si `a > |C|/2`, entonces asignamos a `e` a `B'` y `b ≤ |C|/2`.\
Si `b > |C|/2`, entonces asignamos a `e` a `A'` y `a ≤ |C|/2`.

Por lo tanto, si podemos dividir un curso de `k` estudiantes de esta manera, entonces, siguiendo el mismo razonamiento y método de asignación, podemos hacerlo para un curso de `k+1` estudiantes.

$\therefore$ para cualquier número de estudiantes, podemos encontrar una división que satisfaga las condiciones del protocolo. $\blacksquare$

---

*c) A partir de la demostración del inciso anterior, diseñar un algoritmo que encuentre una solución factible en tiempo lineal en función del tamaño de la entrada definido en el inciso a).*

```python
def division_pandemica(E, C):
    A, B = set(), set()
    for e in E:
        A_pares = sum([1 for a in A if (a, e) in C])
        B_pares = sum([1 for b in B if (b, e) in C])
        if A_pares <= B_pares:
            A.add(e)
        else:
            B.add(e)
    return A, B
```

</font>