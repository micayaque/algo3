<font face = "LaTeX">

### PotenciaLogarítmica
*Encuentre un algoritmo para calcular $a^b$ en tiempo logarı́tmico en b.\
Piense cómo reutilizar los resultados ya calculados.\
Justifique la complejidad del algoritmo dado.*

---

Para calcular $a^b$ en tiempo logarítmico en $b$ se puede utilizar la siguiente función recursiva:

```python
def potencia_logaritmica(a, b):
    if b == 0:
        return 1
    if b % 2 == 0:
        return potencia_logaritmica(a, b // 2) * potencia_logaritmica(a, b // 2)
    return a * potencia_logaritmica(a, b - 1)
```

La función `potencia_logaritmica` recibe dos parámetros, $a$ y $b$, y retorna $a^b$.\
Si $b$ es igual a 0, la función retorna 1.\
Si $b$ es par, la función retorna $a^{b/2} \cdot a^{b/2}$.\
Si $b$ es impar, la función retorna $a \cdot a^{b-1}$.

La complejidad de la función `potencia_logaritmica` es $O(\log b)$, ya que en cada llamada recursiva se divide $b$ por 2.


</font>