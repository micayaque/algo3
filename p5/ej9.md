Sea $S$ una cadena con $n$ paréntesis que abren y $n$ paréntesis que cierran. 

Dada una longitud $ℓ$ impar, decimos que $s : \{1, . . . , n\} \to N$ es un $ℓ$-posicionamiento uniforme de $S$ si $s(i)$ es par y al escribir el i-ésimo paréntesis que abre en $s(i)$ y el i-ésimo paréntesis que cierra en $s(i) + ℓ$, $1 \leq i \leq n$, se obtiene una escritura válida de $S$. 

Por ejemplo, si $S = ( ( ( ) ( ( ) ( ) ) ) ( ) )$ y $ℓ = 15$, entonces $s(1) = 0, s(2) = 6, s(3) = 10, s(4) = 16, s(5) = 20, s(6) = 22$ y $s(7) = 36$ es un $15$-posicionamiento uniforme de $S$. 

Definir un SRD que permita resolver el problema de determinar si una cadena dada $S$ tiene un $ℓ$-posicionamiento uniforme cuando $ℓ \gt 0$ impar también es dado. 

El mejor SRD que conocemos tiene $O(n)$ inecuaciones y, por lo tanto, permite resolver el problema en $O(n^2)$ de aplicando el algoritmo del ejercicio anterior.

La clave está en modelar las posiciones de los paréntesis como un problema de restricciones lineales que se puede resolver aplicando el algoritmo de Bellman-Ford.

Para resolver el problema, representaremos las posiciones de los paréntesis como incógnitas en un sistema de restricciones de diferencias. 

- Definimos una variable $x_i$ para representar la posición del i-ésimo paréntesis que abre en la cadena $S$.
- La posición del i-ésimo paréntesis que cierra será $x_i + \ell$.

La **posición** del paréntesis que cierra debe ser mayor que la posición de cualquier paréntesis que abre antes de él:
$$x_{i+1} \geq x_i + \ell \quad \text{para } 1 \leq i < n$$

Esto se traduce a la inecuación:
$$x_{i+1} - x_i \geq \ell \quad \Rightarrow \quad x_i - x_{i+1} \leq -\ell$$

Los paréntesis que abren deben ser colocados en posiciones **pares**:
$$x_i \text{ es par para todo } i$$

Las posiciones deben estar dentro del intervalo permitido de la cadena:
$$0 \leq x_i \leq \text{longitud total de la cadena } S$$

Podemos fijar $x_1 = 0$ para iniciar la colocación desde la posición inicial.

Modelado:
- Cada variable $x_i$ se representa como un nodo $v_i$ en el grafo.
- Las inecuaciones $x_i - x_{i+1} \leq -\ell$ se representan como aristas dirigidas $v_{i+1} \to v_i$ con peso $-\ell$.
- Un vértice adicional $v_0$ representa el inicio con una arista $v_0 \to v_1$ de peso 0.

Aplicamos el algoritmo de Bellman-Ford en el grafo $D(S)$ para encontrar las distancias mínimas desde $v_0$. Si el algoritmo detecta un ciclo de peso negativo, entonces no hay solución. Si no hay ciclos de peso negativo, las distancias calculadas proporcionan las posiciones $x_i$ que satisfacen el $\ell$-posicionamiento uniforme.

- El número de inecuaciones es $O(n)$.
- La ejecución del algoritmo de Bellman-Ford tiene una complejidad de $O(n^2)$, dado que $m = O(n)$.

```cpp
//definimos las restricciones de diferencias basadas en las condiciones del problema
for (int i = 1; i < n; ++i) {
    agregar_arista(i + 1, i, -ℓ); //representa la restricción x_i - x_(i+1) ≤ -ℓ
}

//ejecutar Bellman-Ford desde el nodo v_0
if (bellmanFord(n, 0, edges, distances)) {
    cout << "No hay solución" << endl;
} else {
    for (int i = 1; i <= n; ++i) {
        cout << "Posición x" << i << " = " << distances[i] << endl;
    }
}
```