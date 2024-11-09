### Definición (Camino MaxiMin)

Sea $G$ un grafo, $c : E (G ) \to R$ su función de costos y $v , w \in V (G )$. 

Decimos que $P$ es un camino `MaxiMin` de $v$ a $w$ si se cumple que $P$ maximiza $c_{min} :$

$$c_{min} (P) = min \{ c(vw )| vw \in E (P) \}$$

También se lo conoce cómo el problema del camino más ancho.

> Si nos imaginamos los costos como capacidades, entonces queremos **maximizar** la capacidad que nuestro camino puede trasladar. Y la **capacidad de un camino** está dada por la capacidad de su arista más pequeña.

### Definición (Camino MiniMax)

Sea $G$ un grafo, $c : E (G ) \to R$ su función de costos y $v , w \in V (G )$.

Decimos que $P$ es un camino `MiniMax` de $v$ a $w$ si se cumple que $P$ minimiza $c_{max} :$

$$c_{max} (P) = max\{c(vw )| vw \in E (P)\}$$

### camino AGM ⇔ camino Minimax

Vamos a utilizar el `absurdo`.

Supongamos que **existe un camino minimax $P$ entre los vértices $a$ y $z$ que no está completamente en el $AGM\ T$** , siendo las aristas de $T$ las azules.

Esto significa que hay una arista $N(nueva) = (s, t)$ en $P$ que no está en $T$. 

Sea $Q$ el camino en $T$ desde $s$ hasta $t$. 

Sea $M(mayor)$ la arista de mayor peso en $Q$.

![image](/img/image%20copy.png)

Ahora hay 2 condiciones a considerar:
1. $\color{purple}peso(N) \lt peso(M)$: En ese caso, $T$ no es un $AGM$. Pues
existe $T' = T − M + N$ tal que $peso(T') < peso(T)$. Absurdo!
2. $\color{purple}peso(M) \geq peso(N)$: En este caso podrías eliminar $N$ de $P$ y
agregar las aristas de $Q$ en su lugar, y seguiría siendo un camino minimax, ya que no incluimos una arista con un peso mayor que el que ya estaba en ese camino antes.

Por cada arista $N$ en un camino minimax que no está en $T$, se puede realizar una sustitución de arista como se describe en el punto $2$, creando así un camino minimax que estará completamente en $T$.

## Ejercicio 1

Viaje en peligro

Cifu vive en Kruskal, Rusia, y quiere visitar las ciudades locales, pero su localidad no tiene rutas que lo conecten con el resto. 

En total hay $n$ ciudades, pero el presidente sólo le ofrece **construir $k << n$ rutas**, poniéndole 2 condiciones:

1. Que queden conectadas $k + 1$ localidades.
2. Que la red resultante sea una **subred** de la red que conecta a todas las localidades con costo mínimo.

Sabemos las **ubicaciones** de las localidades y que el **costo** de construir una ruta entre la localidad $x$ y la $y$ se calcula como $\color{purple}r * distEnKm(x, y) + c_{x,y}$ , donde $c_{x,y}$ depende de las localidades. 

Además sabemos en qué localidad se encuentra Cifu.

Queremos una red que cumpla lo pedido. 

¿Es única?

