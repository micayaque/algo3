AstroTrade
---

Astro Void se dedica a la compra de asteroides. Sea $p ∈ N^n $ tal que $ p_i $ es el precio de un asteroide
el i-ésimo día en una secuencia de $n$ días. Astro Void quiere comprar y vender asteroides durante esos $n$ días de manera tal de obtener la mayor ganancia neta posible. 

#### Debido a las dificultades que existen en el transporte y almacenamiento de asteroides, Astro Void puede comprar a lo sumo un asteroide cada día, puede vender a lo sumo un asteroide cada día y comienza sin asteroides. Además, el Ente Regulador Asteroidal impide que Astro Void venda un asteroide que no haya comprado. 

#### Queremos encontrar la máxima ganancia neta que puede obtener Astro Void respetando las restricciones indicadas. Por ejemplo, si $p = (3, 2, 5, 6)$ el resultado es $6$ y si $p = (3, 6, 10)$ el resultado es $7$. Notar que en una solución óptima, Astro Void debe terminar sin asteroides.

#### a) Convencerse de que la máxima ganancia neta (m.g.n.), si Astro Void tiene c asteroides al fin del día j, es:

$indefinido$ (i.e., $-\infty$) si $c < 0$ o $c > j$,$\textcolor{purple}{si\ c\ (cantidad\ de\ asteroides\ <0\ \rightarrow vendí\ más\ que\ un\ asteroide\ por\ día,\ lo\ cual\ no\ está\ permitido \\ análogamente\ si\ c>j (cantidad\ de\ días\ que\ pasaron)\ \rightarrow compré\ más\ de\ un\ asteroide\ por\ día )}$ 

o el $máximo$ entre:
* la $m.g.n.$ de finalizar el día $j − 1$ con $c − 1$ asteroides y comprar uno en el día $j$, $\textcolor{purple}{si\ el\ día\ j-1\ tengo\ c-1\ asteroides\ \rightarrow el\ día\ j\ tengo\ c\ asteroides\ por\ lo\ que\ compré}$
* la $m.g.n.$ de finalizar el día $j − 1$ con $c + 1$ asteroides y vender uno en el día $j$, $\textcolor{purple}{si\ el\ día\ j-1\ tengo\ c+1\ asteroides\ \rightarrow el\ día\ j\ tengo\ c\ asteroides\ por\ lo\ cual\ vendí}$
* la $m.g.n.$ de finalizar el día $j − 1$ con $c$ asteroides y no operar el día $j$ $\textcolor{purple}{si\ el\ día\ j-1\ tengo\ c\ asteroides\ \rightarrow el\ día\ j\ tengo\ c\ por\ lo\ cual\ no\ operé\ ese\ día}$.

#### b) Escribir matemáticamente la formulación recursiva enunciada en a). Dar los valores de los casos base en función de la restricción de que comienza sin asteroides.

$$mgn(i, c) = \begin{cases} 0 & \text{si } i=n \ \land \ c = 0\\ -\infty & \text{si } i=n \ \land \ c \gt 0\\ 
      -\infty & \text{si } c < 0 \lor c > i \\ 
      \max \{ mgn(i+1, c-1) + p_i, mgn(i+1, c+1) - p_i, mgn(i+1, c) \} & \text{sino}
   \end{cases}$$

#### c) Indicar qué dato es la respuesta al problema con esa formulación recursiva.

La respuesta al problema es $mgn(0, 0) $

#### d) Diseñar un algoritmo de PD top-down que resuelva el problema y explicar su complejidad temporal y espacial auxiliar.

```C++
const int INF_NEG = -1e9;
int mgn(int i, int c, const vector<int>& p, vector<vector<int>>& memo){
    if(memo[i][c] != INF_NEG) return memo[i][c];
    if(i == p.size() && c == 0) return memo[i][c] = 0;
    if(i == p.size() && c > 0) return memo[i][c] = INF_NEG;
    if(c < 0 || c > i) return memo[i][c] = INF_NEG;
    return memo[i][c] = max(mgn(i+1, c-1, p, memo) + p[i], mgn(i+1, c+1, p, memo) - p[i], mgn(i+1, c, p, memo));
}
```
La complejidad temporal del algoritmo es $O(n*c)\ \textcolor{purple}{con\ n\ la\ cantidad\ de\ días\ y\ c\ la\ cantidad\ de\ asteroides\ que\ podemos\ comprar/vender,\ osea\ n\ también) } $  y la complejidad espacial auxiliar es también $O(n*c) $.
