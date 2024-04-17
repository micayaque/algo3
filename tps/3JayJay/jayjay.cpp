#include <iostream>
#include <vector>

using namespace std;

int max_acorns(int t, int h, int f, vector<vector<int>> forest, vector<vector<int>> memo){
    //Lleno los niveles primeros f niveles de la tabla bottom-up desde donde arranco 
    //(casos en los que anteriormente sólo pude haber ido para abajo en los mismos árboles)
    for(int j=0; j<t; ++j){
        memo[h-1][j] = forest[h-1][j];
    }
    for(int i=(h-2); i>= max(0,h-f); --i){
        for(int j=0; j<t; ++j){
            memo[i][j] = memo[i+1][j] + forest[i][j];
        }
    }
    //Lleno la tabla bottom-up a partir del nivel (h-f-1)
    //La posición memo[i][j] guarda cuánto es el máximo de nueces que puedo tener si me moví al nivel i, árbol j
    for(int i=(h-f-1); i>=0; --i){
        for(int j=0; j<t; ++j){
            memo[i][j] = memo[i+1][j] + forest[i][j]; //Inicializo memo[i][j] con la posibilidad de "irte para abajo en el mismo árbol"
            for(int k=0; k<t; ++k){                   //Busco si considerando la posibilidad en la que llegue a memo[i][j] saltando me da más nueces,
                if (k!= j and memo[i+f][k] + forest[i][j] > memo[i][j]) memo[i][j] = memo[i+f][k] + forest[i][j]; //si es así, reemplazo m[i][j] (irme para abajo) por la nueva cantidad de nueces xq es mayor
            }            
        }
    }
    //Cuando llego al nivel final (abajo de todo) nivel == 0 la máxima cantidad de nueces que puedo haber juntado
    //va a ser la que temina en alguno de los árboles j, por eso es el máximo de la última fila a la que llegue osea la del nivel 0 (i==0)
    int res = 0;
    for(int i=0; i<t; ++i){
        if(memo[0][i] > res) res = memo[0][i];
    }
    return res;
}

int main() {
    int c; // Número de datasets
    cin >> c; // Leer el número de datasets
    while (c != 0) {
        for (int i = 0; i < c; ++i) {
            int t, h, f; // Número de árboles, altura de los árboles, altura que Jayjay pierde al volar
            cin >> t >> h >> f;

            vector<vector<int>> memo(h, vector<int>(t));   // Crear la matriz de memoización para el algoritmo bottom-up
            vector<vector<int>> forest(h, vector<int>(t)); // Crear una matriz de acorns del bosque y la inicializa con ceros
            for(int i=0; i<h; ++i){
                for(int j=0; j<t; ++j){
                    forest[i][j] = 0;
                    memo[i][j]=0;
                }
            }

            // Lee la ubicación de cada acorn en el bosque
            for (int j = 0; j < t; ++j) {
                int acorns;
                cin >> acorns; // Leer el número de bellotas en el árbol j
                for(int i=0; i<acorns; ++i){
                    int a;
                    cin >> a;
                    forest[a-1][j] += 1;
                }
            }
            int out = max_acorns(t, h, f, forest, memo);
            cout << out <<endl;
        }
        // Leer el siguiente valor de c
        cin >> c;
    }
    return 0;
}