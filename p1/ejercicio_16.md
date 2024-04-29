<font face="LaTeX">


## RutaEficiente

Tomás quiere viajar de Buenos Aires a Mar del Plata en su flamante Renault 12. Como está
preocupado por la autonomía de su vehículo, se tomó el tiempo de anotar las distintas estaciones de servicio que se encuentran en el camino. Modeló el mismo como un **segmento de 0 a M**, donde Buenos aires está en el kilómetro 0, Mar del Plata en el M, y las distintas estaciones de servicio están ubicadas en los kilómetros 0 = x1 ≤ x2 ≤ . . . xn ≤ M .
Razonablemente, Tomás quiere minimizar la cantidad de paradas para cargar nafta. Él sabe que su auto es capaz de hacer hasta C kilómetros con el tanque lleno, y que al comenzar el viaje este está vacío.

---

*a) Proponer un algoritmo greedy que indique cuál es la cantidad mínima de paradas para cargar nafta que debe hacer Tomás, y que aparte devuelva el conjunto de estaciones en las que hay que detenerse. Probar su correctitud.*

Queremos probar que:

---
Sea 
* $ o_i  ∈ O $ una solución óptima con $ |O| = m $, 
* $ g_i ∈ G $ nuestra solución
golosa con $ |G| = n $ y además $ n > m 
$, 

entonces para $ i ∈ (1, . . . , m) $
$ g_i ≥ o_i $

Vamos a demostrar esto usando inducción.

---
<u>Caso base:</u> `i=1`. 

Tenemos $ g_1 $ y $ o_1 $, como ambas parten del mismo lugar y nuestra estrategia golosa se movió lo máximo que se podía tenemos que:
`o1 ≤ g1 `

---
<u>Caso inductivo:</u> 

Nuestra **<u>hipótesis inductiva</u>** es la siguiente, 
dado $ 1 ≤ i ≤ k $ tenemos que $ o_i ≤ g_i $ , observemos que pasa con $ i = k + 1 $.
* Por un lado tenemos
$ o_{k+1} = o_k + D $ con $ 0 < D < C $

Queremos ver que $ g_{k+1} ≥ o_{k+1} $ 

como $ o_{k+1} − g_k ≤_{HI} o_{k+1} − o_k $

---
$ o_k ≤ g_k $\
$ -g_k \geq -o_k$\
$ o_{k+1} − g_k ≤ o_{k+1} − o_k ≤ C $

---



Si unimos las dos cosas anteriores conseguimos $ o_{k+1} − g_k ≤ C $
Por lo cual $ g_{k+1} $ se puede mover al menos hasta $ o_{k+1} $ que es lo que queríamos probar.


</font>