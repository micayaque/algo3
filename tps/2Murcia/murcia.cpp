#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int max_d = 0;
int max_c = 0;

using namespace std;

int inc(vector<int>& memo, int end, vector<int>& h, vector<int>& w){ 
    // si estamos en el primer edificio no hay nada que comparar porque
    // la subsecuencia creciente más larga hasta el primer edificio es el mismo edificio
    if (end == 0){
        if(max_c < w[0]) max_c = w[0];
        return w[0];
    }
    // si ya tenemos memoizado el resultado de la subsecuencia más larga hasta el edificio end
    // no hace falta volver a calcularlo
    if(memo[end] != 0) return memo[end];
    // si no tenemos aún memoizado el resultado de la subsecuencia más larga hasta el edificio end
    // lo calculamos recursivamente y lo memoizamos
    // de todos los edificios que estan a la izquierda del edificio actual (end) 
    for(int start=end-1; start>=0; start--){
        // necesitamos calcular la subsecuencia creciente más larga hasta cada uno de ellos
        if(memo[start] == 0) memo[start] = max(memo[start], inc(memo, start, h, w));
        bool flag = false;
        // si el edificio actual es más alto que el edificio start
        // entonces podemos añadir el edificio actual a la subsecuencia creciente
        // evaluamos si conviene o no (siempre nos quedamos con la máxima subsecuencia)
        if(h[start] < h[end]){ 
            memo[end] = max(memo[end], memo[start] + w[end]);
            flag = true;
        }
        // si no conviene añadir el edificio actual a la subsecuencia creciente
        // entonces nos quedamos con el edificio actual (cada edificio es una posible subsecuencia)
        if(!flag) memo[end] = max(memo[end], w[end]);
    }
    // actualizamos la longitud de la subsecuencia creciente más larga
    if(max_c < memo[end]) max_c = memo[end];
    // retornamos la longitud de la subsecuencia creciente más larga hasta el edificio end
    return memo[end];
}

// buscar la subsecuencia decreciente más larga es completamente análogo a buscar la subsecuencia creciente más larga
int dec(vector<int>& memo, int end, vector<int>& h, vector<int>& w){ 
    if (end == 0){
        if(max_d < w[0]) max_d = w[0];
        return w[0];
    }
    if(memo[end] != 0) return memo[end];

    for(int start=end-1; start>=0; start--){
        if(memo[start] == 0) memo[start] = max(memo[start], dec(memo, start, h, w));
        bool flag = false;
        if(h[start] > h[end]){ 
            memo[end] = max(memo[end], memo[start] + w[end]);
            flag = true;
        }
        if(!flag) memo[end] = max(memo[end], w[end]);
    }
    if(max_d < memo[end]) max_d = memo[end];
    return memo[end];
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int n;
        cin >> n;
        vector<int> h;
        vector<int> w;
        for (int j = 0; j < n; ++j) {
            int height;
            cin >>height;
            h.push_back(height);
        }
        for (int j = 0; j < n; ++j) {
            int width;
            cin >>width;
            w.push_back(width);
        }   

        vector<int> memo (n,0);
        int end = n-1;
        max_c = 0;
        inc(memo, end, h, w);

        vector<int> tmp (n,0);
        memo = tmp;
        end = n-1;
        max_d = 0;
        dec(memo, end, h, w);

        if(max_c >= max_d){
            cout << "Case " << i <<". " << "Increasing (" << max_c << "). Decreasing (" << max_d << ")" <<"." << endl;
        }else{
            cout << "Case " << i <<". " << "Decreasing (" << max_d << "). Increasing (" << max_c << ")" <<"." << endl;
        }
        
    }

    return 0;
}