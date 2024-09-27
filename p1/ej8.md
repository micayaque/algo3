CortesEconómicos
---

Debemos cortar una vara de madera en varios lugares predeterminados. 

Sabemos que el $costo$ de realizar un corte en una madera de longitud $ℓ$ es $ℓ$ (y luego de realizar ese corte quedarán $2$ $varas$ de longitudes que sumarán $ℓ$ ). 

Por ejemplo, si tenemos una vara de longitud $10$ metros que debe ser cortada a los $2, 4$ y $7$ metros desde un extremo, entonces los cortes se pueden realizar, entre otras maneras, de las siguientes formas:

* Primero cortar en la posición $2$, después en la $4$ y después en la $7$. Esta resulta en un $costo$ de $10 + 8 + 6 = 24$ porque el primer corte se hizo en una vara de longitud $10$ metros, el segundo en una de $8$ metros y el último en una de $6$ metros.

* Cortar primero donde dice $4$, después donde dice $2$, y finalmente donde dice $7$, con un costo de $10 + 4 + 6 = 20$, que es menor.

Queremos encontrar el $\textcolor{purple}{mínimo\ costo\ posible\ de\ cortar\ una\ vara\ de\ longitud\ ℓ} $.

#### a) Convencerse de que el mínimo costo de cortar una vara que abarca desde $i$ hasta $j$ con el conjunto $C$ de lugares de corte es $j − i$ más el mínimo, para todo lugar de corte $c$ entre $i$ y $j$, de la suma entre el mínimo costo desde $i$ hasta $c$ y el mínimo costo desde $c$ hasta $j$.

```math
\textcolor{pink}{j-i\ es\ la\ longitud\ de\ la\ vara\ que\ se\ corta\ entre\ i\ y\ j\ entonces\ sumamos\ el costo\ de\ ese\ corte\ con\ el\ costo\ de\ cortar\ las\ dos\ varas\ restantes\ que\ se\ obtienen\ al\ hacer\ ese\ corte.}
```

#### b) Escribir matemáticamente una formulación recursiva basada en a). Explicar su semántica e indicar cuáles serían los parámetros para resolver el problema.

```math
minCosto(i, j, C) = \begin{cases} 0 & \text{si j=i} \\ j - i + \min \{ minCosto_{\forall c \in C:c \gt i}(i, c, C) + minCosto_{\forall c \in C:c \lt j}(c, j, C) & \text{sino} \end{cases}
```
La función devuelve el mínimo costo de cortar una vara que abarca desde $i$ hasta $j$ con el conjunto $C$ de lugares de corte. Los parámetros para resolver el problema son $i \textcolor{purple}{(desde\ donde\ comienza\ la\ vara)} $, $j \textcolor{purple}{(donde\ termina\ la\ vara)}$ y $C \textcolor{purple}{(el\ conjunto\ de\ puntos\ donde\ puede\ cortarse\ la\ vara)} $.

#### c) Diseñar un algoritmo de PD y dar su complejidad temporal y espacial auxiliar. Comparar cómo resultaría un enfoque top-down con uno bottom-up.

```C++
const int INF = 1e9;
int minCosto(int i, int j, vector<int>& C, vector<vector<int>>& memo) {
    if (memo[i][j] != INF) return memo[i][j];
    int min_costo = INF;
    for (int c : C) {
        if (c > i && c < j) {
            int costo = (j - i) + minCosto(i, c, C, memo) + minCosto(c, j, C, memo);
            min_costo = min(min_costo, costo);
        }
    }
    memo[i][j] = min_costo;
    return memo[i][j];
}
```

La complejidad temporal del algoritmo es $O(n* l^2)$ con $n$ la longitud de $C$ y la complejidad espacial auxiliar es $O(l^2) $.

#### d) Supongamos que se ordenan los elementos de $C$ en un vector cortes y se agrega un $0$ al principio y un $ℓ$ al final. Luego, se considera que el mínimo costo para cortar desde el $i-ésimo$ punto de corte en cortes hasta el $j-ésimo$ punto de corte será el resultado buscado si $i = 1$ y $j = |C| + 2$.

#### I) Escribir una formulación recursiva con dos parámetros que esté basada en d) y explicar su semántica.

```math
minCosto(i, j) = cortes[j] - cortes[i] + \min_{c \in [i+1, j-1]} \{ minCosto(i, c) + minCosto(c, j) \}
```


#### II) Diseñar un algoritmo de PD, dar su complejidad temporal y espacial auxiliar y compararlas con aquellas de c). Comparar cómo resultaría un enfoque top-down con uno bottom-up.

```C++
const int INF = 1e9;
int minCosto(int i, int j, vector<int>& cortes, vector<vector<int>>& memo) {
    if (memo[i][j] != INF) return memo[i][j];
    int min_costo = INF;
    for (int c = i + 1; c < j; c++) {
        int costo = (cortes[j] - cortes[i]) + minCosto(i, c, cortes, memo) + minCosto(c, j, cortes, memo);
        min_costo = min(min_costo, costo);
    }
    memo[i][j] = 
    return memo[i][j] = min_costo;
} 
```
