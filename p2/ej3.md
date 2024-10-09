PotenciaLogarítmica
---
Encuentre un algoritmo para calcular $\color{violet}a^b$ en tiempo logarı́tmico en $b$.

Piense cómo reutilizar los resultados ya calculados.

Justifique la complejidad del algoritmo dado.

```math
a^b = a^{\frac{b}{2}} * a^{\frac{b}{2}} \\
a^{\frac{b}{2}} = a^{\frac{b}{4}} * a^{\frac{b}{4}} \\
a^{\frac{b}{4}} = a^{\frac{b}{8}} * a^{\frac{b}{8}} \\
... \\
a^{\frac{b}{b}} = a
```
Podemos dividir $b$ por 2 en cada llamada recursiva para lograr el tiempo logarítmico.

```C++
int potencia_logaritmica(int a, int b){
    if (b == 0) return 1;   //O(1)
    if (b == 1) return a;   //O(1)
    if (b % 2 == 0) return  potencia_logaritmica(a, b / 2) * potencia_logaritmica(a, b / 2);
    return a * potencia_logaritmica(a, b - 1);
}
```

En cada paso del algoritmo se divide $b$ por 2 y el resto de las operaciones es O(1) por lo que la complejidad es $O(\log b)$.

