CazadorDeFalsos
---

Se tiene una matriz booleana $A$ de $n × n$ y una operación $\text{conjunciónSubmatriz}$ que toma $O(1)$ tiempo y que dados $4$ enteros $i_0 , i_1 , j_0 , j_1$ devuelve la conjunción de todos los elementos en la submatriz que toma las filas $i_0$ hasta $i_1$ y las columnas $j_0$ hasta $j_1$ . 

Formalmente:

$1)$ Dar un algoritmo de complejidad temporal estrictamente menor que $O(n^2)$ que calcule la posición de algún `false`, asumiendo que hay al menos uno. 

Calcular y justificar la complejidad del algoritmo.

$\text{conjunciónSubmatriz}(i_0 , i_1 , j_0 , j_1 ) = \bigwedge_{i_0 \leq i\leq i_1 ,j_0 \leq j\leq j_1}^{} A[i,j]$

```C++
int posicion_false(vector<vector<int>> A, int i_0, int j_0, int i_1, int j_1){
    
    if(i_0 == i_1) {
        //buscar false
        int pos = 0;
        for(int j = 0; j < A[0].size(); j++){ // O(n)
            if(A[i_0][j] == false) return j;
        }
    }
    
    bool arriba = conjunciónSubmatriz(i_0, (i_0+i_1)/2, j_0, j_1);  // O(1)
    bool abajo = conjunciónSubmatriz((i_0+i_1)/2+1, i_1, j_0, j_1);     // O(1)
    
    if(!arriba) return posicion_false(A, i_0, j_0, (i_0+i_1)/2, j_1);    
    if(!abajo) return posicion_false(A, (i_0+i_1)/2+1, j_0, i_1, j_1);

}
```

La complejidad del algoritmo es $O(\log n)$, ya que en cada iteración se divide la matriz en $2$ submatrices de tamaño $\frac{n}{2}$ filas. Y `sólo en el caso base` se recorre una fila de la matriz, lo que tiene complejidad $O(n)$.

$2)$ Modificar el algoritmo anterior para que cuente cuántos `false` hay en la matriz. 

Asumiendo que hay a lo sumo $5$ elementos false en toda la matriz, calcular y justificar la complejidad del algoritmo. 

Esto se puede lograr con complejidad menor a $O(n^2)$.

```C++
int posicion_false(vector<vector<int>> A, int i_0, int j_0, int i_1, int j_1){
    
    if(i_0 == i_1) {
        //contar los false
        int count = 0;
        for(int j = 0; j < A[0].size(); j++){ // O(n)
            if(A[i_0][j] == false) count++;
        }
        return count;
    }
    
    bool arriba = conjunciónSubmatriz(i_0, (i_0+i_1)/2, j_0, j_1);  // O(1)
    bool abajo = conjunciónSubmatriz((i_0+i_1)/2+1, i_1, j_0, j_1);     // O(1)
    
    int falsos = 0;
    if(!arriba and !abajo){
        falsos+= posicion_false(A, i_0, j_0, (i_0+i_1)/2, j_1) + posicion_false(A, (i_0+i_1)/2+1, j_0, i_1, j_1);
    } else if(!arriba){
        falsos+= posicion_false(A, i_0, j_0, (i_0+i_1)/2, j_1);
    } else {
        falsos += posicion_false(A, (i_0+i_1)/2+1, j_0, i_1, j_1);
    }
    return falsos;
}
```