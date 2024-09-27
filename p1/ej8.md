CortesEconómicos
---

Debemos cortar una vara de madera en varios lugares predeterminados. 

Sabemos que el $costo$ de realizar un corte en una madera de longitud $ℓ$ es $ℓ$ (y luego de realizar ese corte quedarán $2$ $varas$ de longitudes que sumarán $ℓ$ ). 

Por ejemplo, si tenemos una vara de longitud $10$ metros que debe ser cortada a los $2, 4$ y $7$ metros desde un extremo, entonces los cortes se pueden realizar, entre otras maneras, de las siguientes formas:

* Primero cortar en la posición $2$, después en la $4$ y después en la $7$. Esta resulta en un $costo$ de $10 + 8 + 6 = 24$ porque el primer corte se hizo en una vara de longitud $10$ metros, el segundo en una de $8$ metros y el último en una de $6$ metros.

* Cortar primero donde dice $4$, después donde dice $2$, y finalmente donde dice $7$, con un costo de $10 + 4 + 6 = 20$, que es menor.

Queremos encontrar el $\textcolor{purple}{mínimo\ costo\ posible\ de\ cortar\ una\ vara\ de\ longitud\ ℓ} $.

a) Convencerse de que el mínimo costo de cortar una vara que abarca desde $i$ hasta $j$ con el conjunto $C$ de lugares de corte es $j − i$ más el mínimo, para todo lugar de corte $C$ entre $i$ y $j$, de la suma entre el mínimo costo desde $i$ hasta $C$ y el mínimo costo desde $C$ hasta $j$.

