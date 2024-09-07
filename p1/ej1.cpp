#include <iostream>
#include <vector>

using namespace std;

// 1) subset_sum(C, i, j, partial_solution): // implementa ss({c_1,...,c_i }, j)
// 2)  if j < 0
//         return false // regla de factibilidad
// 3)  if i = 0 and (j=0)
//         print solucion_parcial
//         return true
// 4)  else 
//         return subset_sum(C, i−1, j, solucion_parcial) 
//         ∨  subset_sum(C, i−1, j−C[i], partial_solution ++ [C[i]])

bool subset_sum(vector<int>& C, int i, int j, vector<int>& partial_solution) {
    if (j < 0) return false;
    if (i == 0 && j != 0) return false;
    if (i == 0 && j == 0) {
        for (int e : partial_solution) cout << e << " ";
        cout << endl;
        return true;
    } else {
        vector<int> new_partial_solution = partial_solution;
        new_partial_solution.push_back(C[i]);
        return subset_sum(C, i-1, j, partial_solution) || subset_sum(C, i-1, j-C[i], new_partial_solution);
        partial_solution.pop_back(); // backtracking: eliminar el ultimo elemento añadido en partial_solution para volver a probar otros candidatos.
    }
}

int main() {
    vector<int> C = {6, 12, 6};
    vector<int> partial_solution;
    subset_sum(C, C.size() - 1, 12, partial_solution);
    return 0;
}