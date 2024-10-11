Alfredo se está tomando unos días de descanso, así que va a recorrer diferentes pueblos de la Argentina y ha decidido que cuando regrese les regalará un alfajor a cada uno de los $k$ demás docentes de la materia.

Para esto ha decidido que los comprará en cada uno de los $n$ pueblos que recorrerá. 

Al llegar al $i-ésimo$ pueblo tiene $\color{violet}tres\ opciones$:

* $\color{violet}Comprar$ media docena (6) de alfajores locales por $c_i$ pesos.
* $\color{violet}Comerse$ un alfajor en lugar de ir a la tienda a comprar.
* $\color{violet}No\ hacer\ ninguna$ de las dos anteriores.

Y es que a Alfredo le gustan mucho los alfajores, y siente que si pasa $g$ ciudades sin comerse al menos uno, se estresará mucho, lo cual repercutirá en sus clases.

Además, sabemos que $g \leq n$.

Sea $c$ la lista de precios de los alfajores, $c_1, c_2, ..., c_n$ definir de forma recursiva $f_{c, n, k, g} : \N^3 \rightarrow \N$ donde
```math
f_{c, n, k, g}(i, a, h)
```
calcula la cantidad mínima de pesos que Alfredo gastará al partir de la ciudad $i$ con $a$ alfajores y $h$ ciudades que le quedan por recorrer sin comer alfajores antes que le agarre mal humor.

¿Qué llamado(s) se necesitan para resolver el problema?

Importante: acompañen la definición recursiva con una explicación en castellano.

```math
f_{c, n, k, g}(i, a, h)
```

* $c$ lista de precios de los alfajores $c_1, c_2, ..., c_n$
* $n$ cantidad de pueblos a recorrer
* $k$ cantidad de docentes de la materia
* $g$ cantidad de ciudades que puede pasar sin comerse un alfajor
* $i$ ciudad actual
* $a$ cantidad de alfajores actuales
* $h$ cantidad de ciudades que le quedan por recorrer sin comer alfajores antes que le agarre mal humor (al principio es igual a $g$)

```math
f_{c, n, k, g}(i, a, h) = 
\begin{cases} 

\infty  & \hspace{1cm} a \lt 0 \\
\infty  & \hspace{1cm} h==0 \land i < n \land a == 0 \\ 
0       & \hspace{1cm} i==n+1 \land k \leq a \\
\infty  & \hspace{1cm} i == n+1 \land a < k \\

min \begin{cases}
    f_{c, n, k, g}(i+1, a+6, h-1) + c_i \\
    f_{c, n, k, g}(i+1, a-1, g) \\
    f_{c, n, k, g}(i+1, a, h-1)
    \end{cases} & \hspace{1cm} \text{en otro caso}

\end{cases}
```
Casos base:
* Si no le quedan ciudades por recorrer sin comerse un alfajor pero le quedan ciudades para recorrer, y no tiene alfajores, entonces no puede seguir.
* Si ya recorrió todas las ciudades y tiene al menos $k$ alfajores, entonces no necesita comprar.
* Si ya recorrió todas las ciudades y no tiene al menos $k$ alfajores, entonces no puede cumplir con tener k alfajores.

* Sino, nos quedamos con el mínimo de comprar 6 alfajores con costo $c_i$, comerse un alfajor volviendo a tener g ciudades para recorrer sin comer y teniendo un alfajor menos o no hacer nada.
