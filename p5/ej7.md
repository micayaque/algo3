Para organizar el tráfico, la ciudad de Ciclos Positivos ha decidido implementar las cabinas de peaje inverso. 

La idea de estas cabinas es incentivar la circulación de vehículos por caminos
alternativos, estableciendo un monto que se le paga a le conductore de un vehículo cuando pasa por la cabina. 

Estas cabinas inversas se suman a las cabinas regulares, donde le conductore paga por pasar por la cabina. 

La ciudad sabe que estas nuevas cabinas pueden dar lugar al negocio del “ciclo puré”, que consiste en transitar eternamente por la ciudad a fin de obtener una ganancia que tienda a infinito. 

Para evitar esta situación, que genera costos y tráfico adicional, lo cual será aprovechado para desgastar a la administración ante la opinion pública, la ciudad quiere evaluar
distintas alternativas antes de llevar las cabinas inversas a la práctica.

$a.$ Modelar el problema de determinar si la ciudad permite el negocio del ciclo puré cuando el costo de transitar por cada cabina $i$ de peaje es $c_i$ ($c_i \lt 0$ si la cabina es inversa) y el costo que cuesta viajar de forma directa de cada cabina $i$ a cada cabina $j$ es $c_{ij} \gt 0$.

El problema de determinar si existe un "ciclo puré" se puede modelar como un grafo dirigido $G = (V, E)$, donde:
- Los nodos representan las cabinas de peaje.
- Las aristas representan los caminos entre cabinas con costos asociados $c_{ij}$, donde un costo negativo indica una ganancia y un costo positivo representa un gasto.

El objetivo es detectar la presencia de ciclos de peso negativo, lo cual indicaría que es posible transitar indefinidamente para obtener una ganancia.

$b.$ Dar un algoritmo para resolver el problema del inciso anterior, indicando su complejidad temporal.

El algoritmo de **Bellman-Ford** se utiliza para encontrar el camino mínimo desde un nodo fuente y, crucialmente, detectar ciclos de peso negativo en un grafo.

1. Inicializar la distancia a la fuente como 0 y las distancias a otros nodos como infinito.
2. Relajar todas las aristas $|V| - 1$ veces.
3. Comprobar si hay ciclos negativos intentando relajar nuevamente las aristas. Si una distancia puede ser disminuida, existe un ciclo negativo.

$O(|V| \cdot |E|)$.


El sistema arrojó que ninguna de las configuraciones deseadas para desincentivar el tráfico evita el negocio de los ciclos puré. 

Desafortunadamente, el plan se filtró a la prensa y comenzaron las peleas mediáticas. A fin de obtener cierto rédito, desde el departamento de marketing sugieren
transformar la idea de cabinas inversas en cabinas mixtas. 

Cuando un vehículo pasa por una cabina mixta, se le paga a le conductore si se le cobró a le conductore en la cabina anterior;
caso contrario, le conductore paga. 

Obviamente, desde marketing sugieren que se le pague a le conductore cuando la cabina mixta sea la primera cabina recorrida para bajar los malos humores.

$c.$ Modelar el problema de determinar si la ciudad permite el negocio de los ciclos puré cuando se aplica la nueva configuración para las cabinas. Además de la información utilizada para el problema original, ahora se conoce cuáles cabinas son mixtas: notar que el monto de cobro es $c_i$ y el monto de pago es $−c_i$ para la cabina mixta $i$ (con $c_i \gt 0$).

Las cabinas mixtas cambian las condiciones del problema:
- Si en la cabina anterior se pagó, se recibe un pago al pasar por la cabina mixta.
- Si en la cabina anterior se recibió un pago, se paga al pasar por la mixta.

El modelo debe incluir el **estado** del vehículo (si pagó o recibió en la cabina anterior) para evaluar correctamente las transiciones. Cada arista entre cabinas debe representar estos posibles cambios de estado y sus costos asociados.

- Construir un grafo extendido donde los nodos representen no solo la cabina sino también el estado (pagado/recibido).
- Aplicar Bellman-Ford en este grafo extendido para detectar ciclos de ganancia infinita.

Esto implica que se duplican los nodos y se ajustan las aristas según las reglas de las cabinas mixtas.

