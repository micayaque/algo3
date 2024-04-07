#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Player {
public:
    string name;
    int offense;
    int defense;

    Player(string n, int o, int d) : name(n), offense(o), defense(d) {}
};

int max_defense;
int max_sum;
vector<string> max_team;
vector<string> max_defenders;

void generateTeam(vector<Player>& players, int start, int length, vector<string>& current_team, int current_sum, vector<string>& max_team, 
    vector<string>& max_defenders, vector<bool>& usados) {
    // si el contador length es 0 entonces ya formamos una subsecuencia de delanteros de tamaño 5 (cb)
    if (length == 0) {
        int defense=0;
        vector<string> defenders;
        for(int k=0; k<10; k++){
            if(!usados[k]){
                defenders.push_back(players[k].name);
                defense += players[k].defense;
            }
        }
        sort(max_team.begin(), max_team.end());
        bool lexi;
        // elijo el de mayor ataque, si empatan el de mayor defensa y si empatan de nuevo el menor lexicograficamente
        if(max_sum < current_sum){
            max_sum = current_sum;
            max_defense = defense;
            max_team = current_team;
            max_defenders = defenders;
        } else if((max_sum == current_sum and max_defense < defense)){
            max_defense = defense;
            max_team = current_team;
            max_defenders = defenders;
        } else {
            vector<string> temp = current_team;
            sort(temp.begin(), temp.end());
            lexi = lexicographical_compare(temp.begin(), temp.end(), max_team.begin(), max_team.end());
            if((max_sum == current_sum and max_defense == defense and lexi)){
                max_team = current_team;
                max_defenders = defenders;
            }
        }
        // los ordeno antes de retornarlos porque en el output tienen que estar ordenados
        sort(max_defenders.begin(), max_defenders.end());
        return;
    }



    // si length != 0 entonces mi subsecuencia actual tiene menos de 5 elementos
    // hago recursion agregandole todos los posibles jugadores
    for (int i = start; i <= 10 - length; ++i) {
        current_team.push_back(players[i].name);
        current_sum += players[i].offense;
        usados[i]=true;
        generateTeam(players, i + 1, length - 1, current_team, current_sum, max_team, max_defenders, usados);
        current_team.pop_back();
        current_sum -= players[i].offense;
        usados[i]=false;
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        vector<Player> players;
        for (int j = 0; j < 10; ++j) {
            string name;
            int offense, defense;
            cin >> name >> offense >> defense;
            players.push_back(Player(name, offense, defense));
        }


        vector<string> current;
        int attackersLength = 5;
        int start = 0;
        int current_sum = 0;
        vector<bool> usados(10, false);

        max_sum = 0;
        max_defense = 0;

        generateTeam(players, start, attackersLength, current, current_sum, max_team, max_defenders, usados);
        
        cout << "Case " << i << ":" <<endl;
        cout << "(";
        for(int i=0; i<4; i++){
            cout << max_team[i] << ", ";
        }
        cout << max_team[4] << ")" << endl;
        
        cout << "(";
        for(int i=0; i<4; i++){
            cout << max_defenders[i] << ", ";
        }
        cout << max_defenders[4] << ")" << endl;
        
    }

    return 0;
}
