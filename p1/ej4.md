RutaMinima
---

Dada una matriz D de $n × n$ números naturales, queremos encontrar una permutación $π^1$ de $\{1,...,n\}$ que minimice $D_{π(n)π(1)}$ + $\sum_{i=1}^{n-1} D_{π(i)π(i+1)}$

### **a)** Diseñar un algoritmo de backtracking para resolver el problema, indicando claramente cómo se codifica una solución candidata, cuáles soluciones son válidas y qué valor tienen, qué es una solución parcial y cómo se extiende cada solución parcial.

Una solución candidata es una permutación del vector $\{1,...n\}$. La forma de codificarla es ubicando todos los posibles valores en cada posición del vector.

Las soluciones válidas van a ser las que minimizen la suma.

Una solución parcial al problema es una codificación parcial del vector que queremos permutar, la extendemos encontrando un nuevo valor para el lugar del vector en el cual nos encontremos.

El valor de una solución se calcula sumando $D_{\pi(n)\pi(1)}$ + $\sum_{i=1}^{n-1} D_{\pi(i)\pi(i+1)}$, es decir, el costo de recorrer la matriz según el orden definido por $\pi$, más el costo de volver del último elemento al primero.

```C++
int valor_permutacion(vector<int> &perm, vector<vector<int>> &matriz) {
    int n = perm.size();
    int valor = matriz[perm[n - 1]][perm[0]];  //costo de ir del último al primer elemento
    for (int i = 0; i < n - 1; i++) {
        valor += matriz[perm[i]][perm[i + 1]];  /costo de ir de un elemento al siguiente
    }
    return valor;
}

int backtrack_permutaciones(vector<vector<int>>& matriz, vector<int>& permutacion_actual, int mejor_valor, vector<int>& mejor_permutacion) {
    int n = matriz.size();
    if (permutacion_actual.size() == n) {
        int valor_actual = valor_permutacion(permutacion_actual, matriz);
        if (valor_actual < mejor_valor) {
            mejor_valor = valor_actual;
            mejor_permutacion = permutacion_actual;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (find(permutacion_actual.begin(), permutacion_actual.end(), i) == permutacion_actual.end()) {
                permutacion_actual.push_back(i);
                mejor_valor = backtrack_permutaciones(matriz, permutacion_actual, mejor_valor, mejor_permutacion);
                permutacion_actual.pop_back();
            }
        }
    }
    return mejor_valor;
}

int main(){
    int n;
    cin >> n;
    int mejor_valor = float('inf')
    vector<int> mejor_permutacion = []
    vector<vector<int>> matriz(n, vector<int>(n));
    int mejor_valor = backtrack_permutaciones(matriz, [], mejor_valor, mejor_permutacion)
    return 0;
}
```


---

### *b) Calcular la complejidad temporal y espacial del mismo.*

- La complejidad temporal del algoritmo propuesto es $O(n!)$, ya que se generan todas las permutaciones posibles de los números del $1$ al $n$.

---

### *c) Proponer una poda por optimalidad y mostrar que es correcta.*

Si el valor de la solución parcial actual es mayor o igual al valor de la mejor solución encontrada hasta el momento, no tiene sentido seguir explorando esa rama, ya que no se encontrará una solución óptima.

Esta poda es correcta porque si el costo parcial ya es mayor que el de una solución completa previamente encontrada, continuar explorando esa rama solo incrementará el costo.