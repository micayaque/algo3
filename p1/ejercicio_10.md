<font face="LaTeX">

### PilaCauta

*Tenemos cajas numeradas de 1 a N , todas de iguales dimensiones. Queremos encontrar la máxima
cantidad de cajas que pueden apilarse en una única pila cumpliendo que:*
* *sólo puede haber una caja apoyada directamente sobre otra;*
* las cajas de la pila deben estar ordenadas crecientemente por número, de abajo para arriba;*
* *cada caja i tiene un peso wi y un soporte si , y el peso total de las cajas que están arriba de otra no debe exceder el soporte de esa otra.*

*Si tenemos los pesos w = [19, 7, 5, 6, 1] y los soportes s = [15, 13, 7, 8, 2] (la caja 1 tiene peso 19
y soporte 15, la caja 2 tiene peso 7 y soporte 13, etc.), entonces la respuesta es 4. Por ejemplo,
pueden apilarse de la forma 1-2-3-5 o 1-2-4-5 (donde la izquierda es más abajo), entre otras
opciones.*

*a) Pensar la idea de un algoritmo de backtracking (no hace falta escribirlo).*

La idea de un algoritmo de backtracking sería ir probando todas las posibles combinaciones de cajas que se pueden apilar, y quedarse con la que tenga mayor cantidad de cajas. Para esto, se debería tener en cuenta que la caja que se va a apilar debe cumplir con las condiciones de peso y soporte de la caja que está debajo de ella.

---

*b) Escribir una formulación recursiva que sea la base de un algoritmo de PD. Explicar su
semántica e indicar cuáles serían los parámetros para resolver el problema.*

```python
def pila_cauta(i, s, w):
    if i==n-1:      #arriba de la última caja no se puede apilar ninguna
        return 0
    else:
        #si se puede apilar la caja i+1
        puedo_apilar = True
        for j in range(0,i):
                tmp = s[j]-w[i+1]
                if tmp < 0: puedo_apilar = False

        if puedo_apilar:
            for j in range(0,i):
                s[j]-=w[i+1]
            agrego = 1 + pila_cauta(i+1, s, w)
            no_agrego = pila_cauta(i+1, s, w)
            return max(agrego, no_agrego)

        no_agrego = pila_cauta(i+1, s, w)
        return max(0, no_agrego)
```

La función `pila_cauta` recibe como parámetros el índice de la caja que se está considerando, el vector de soportes y el vector de pesos. La semántica de la función es la siguiente: si la caja que se está considerando se puede apilar, se apila y se llama recursivamente a la función con la siguiente caja. Si no se puede apilar, se llama recursivamente a la función con la siguiente caja sin apilar la caja actual. La función devuelve la cantidad máxima de cajas que se pueden apilar.

---

*c) Diseñar un algoritmo de PD y dar su complejidad temporal y espacial auxiliar. Comparar cómo resultaría un enfoque top-down con uno bottom-up.*

```python
def pila(s,w):
    def pila_cauta(i, s, w, memo):
        if i==n-1:      #arriba de la última caja no se puede apilar ninguna
            memo[i] = 1
            return memo[i]
        else:
            #si se puede apilar la caja i+1
            puedo_apilar = True
            for j in range(0,i):
                    tmp = s[j]-w[i+1]
                    if tmp < 0: puedo_apilar = False

            if puedo_apilar:
                for j in range(0,i):
                    s[j]-=w[i+1]
                agrego = 1 + pila_cauta(i+1, s, w)
                for j in range(0,i):
                    s[j]-=w[i+1]
                no_agrego = pila_cauta(i+1, s, w)
                memo[i][j] = max(agrego, no_agrego)
                return m[i][j]

            memo[i][j] = pila_cauta(i+1, s, w)
            return max(0,memo[i][j])
    n=len(s)
    memo = [0]*n
    pila_cauta(0, s, w, memo)
```
La complejidad temporal del algoritmo es $ O(n*n) $ con n la cantidad de cajas.
La complejidad espacial es $ O(n) $ 

---

![llamados_top_down](./img/llamados_top_down.png)

Si lo resolvieramos con un enfoque bottom-up deberíamos ir resolviendo los casos "desde las hojas". En la imagen se muestra cómo se irían resolviendo los llamados a la función `pila_cauta` con un enfoque top-down. En cada llamado se resuelven los llamados a la derecha antes de resolver los llamados a la izquierda. En un enfoque bottom-up se resolverían primero los llamados a la izquierda antes de resolver los llamados a la derecha. En este caso, se resolverían primero los llamados a la caja 5, luego los llamados a la caja 4, luego los llamados a la caja 3, etc.



</font>