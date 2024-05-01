### Equilibrio Digrafo
Demostrar, usando inducción en la cantidad de aristas, que todo digrafo D satisface
$\sum_{v\in V(D)}^{} d_{in}(v) = \sum_{v\in V(D)}^{} d_{out}(v) = |E(D)|$

<u>Caso base: </u>
\
$\sum_{v\in V(D)}^{} d_{in}(v) = \sum_{v\in V(D)}^{} d_{out}(v) = 0$
\
$\sum_{v\in V(D)}^{} 0 = \sum_{v\in V(D)}^{} 0 = 0$
\
$\therefore$ el caso base se cumple trivialmente

---
<u>Hipótesis inductiva:</u>
\
$\sum_{v\in V(D)}^{} d_{in}(v) = \sum_{v\in V(D)}^{} d_{out}(v) = k$

<u>Caso inductivo:</u>
\
$\sum_{v\in V(D)}^{} d_{in}(v) = \sum_{v\in V(D)}^{} d_{out}(v) = k+1$


Si agregamos una arista al digrafo con k aristas vamos a tener otro digrafo $ D^* $ en donde haya dos vértces unidos por esa arista nueva, entonces 

$\sum_{v\in V(D^{*})}^{} d_{in}(v) = \sum_{v\in V(D^{*})}^{} d_{out}(v) = |E(D^{*})| $ 
\
Una arista está formada por un nodo s y un nodo t y de esta forma d(u) y d(v) van a incrementarse en 1 por lo que también.
$\sum_{v\in V(D^{*})}^{} d_{in}(v) + d(<s,t>) = \sum_{v\in V(D^{*})}^{} d_{out}(v) + d(<s,t>)= k+1 $ 
\
$\sum_{v\in V(D)}^{} d_{in}(v) + 1 = \sum_{v\in V(D)}^{} d_{out}(v) + 1 = k+1$
\
Se cumple por HI.$ \blacksquare $