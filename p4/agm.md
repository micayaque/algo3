

Vínculo entre MiniMax y AGM
---

camino AGM $\rightarrow$ camino MiniMax

---
Vamos a demostrarlo por absurdo.\
<u>Demo:</u>\
Supongamos que existe un camino minimax **P** entre los vértices **a** y **z** que no está completamente en el AGM T.\
![árbol generador mínimo T](./img/agm_clase.png)

Esto significa que hay una arista N (nueva) = (s,t) en **P** que no está en T.\
Sea Q el camino en T desde **a** hasta **z**.
Sea M (mayor) la arista de mayor peso en Q.

Hay dos condiciones a considerar:
1. **La arista M es más pesada que N.**\
    En este caso T no es un AGM, ya que si reemplazamos M por N, el peso total de T disminuirá.\
    Esto contradice la suposición de que T es un AGM.
2. **La arista M es menor o igual que N.**\
    En este caso, si reemplazamos N por M en **P**, el peso total de **P** disminuirá.\
    Esto contradice la suposición de que **P** es un camino minimax.

Por lo tanto, no puede haber un camino minimax entre dos vértices que no esté completamente en el AGM.


---

