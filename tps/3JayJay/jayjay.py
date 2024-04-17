def max_acorns(t, h, acorns, f):
    #Inicializo la estructura para memoizar resultados
    memo = [[0] * t for _ in range(h)]

    #Lleno los niveles primeros f niveles de la tabla bottom-up desde donde arranco 
    #(casos en los que anteriormente sólo pude haber ido para abajo en los mismos árboles)
    for j in range(0, t):
        memo[h-1][j] = acorns[h-1][j]
        memo[h-2][j] = memo[h-1][j] + acorns[h-2][j]
    # Lleno la tabla bottom-up a partir del nivel (h-f-1)
    # La posición memo[i][j] guarda cuánto es el máximo de nueces que puedo tener si me moví al nivel i, árbol j
    for i in range(h - f - 1, -1, -1): 
        for j in range(0, t):
            memo[i][j] = memo[i+1][j] + acorns[i][j] #Inicializo memo[i][j] con la posibilidad de "irte para abajo en el mismo árbol"
            for k in range(0, t):
                #Busco si considerando la posibilidad en la que llegue a memo[i][j] saltando me da más nueces,
                #si es así, reemplazo m[i][j] (irme para abajo) por la nueva cantidad de nueces xq es mayor
                if k!= j and memo[i+f][k] + acorns[i][j] > memo[i][j] : memo[i][j] = memo[i+f][k] + acorns[i][j] 
    #Cuando llego al nivel final (abajo de todo) nivel == 0 la máxima cantidad de nueces que puedo haber juntado
    #va a ser la que temina en alguno de los árboles j, por eso es el máximo de la última fila a la que llegue osea la del nivel 0 (i==0)
    return max(memo[0])

t = 3
h = 10
acorns =    [
                [1, 0, 0], #primer fila 
                [0, 0, 0], # ...
                [0, 1, 1],
                [1, 0, 1],
                [0, 1, 1],
                [0, 0, 1],
                [0, 1, 0],
                [0, 1, 0],
                [0, 2, 1],
                [1, 0, 0]
            ]
f = 2
print(max_acorns(t, h, acorns, f))