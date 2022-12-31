#include <iostream>
#include <set>
#define TAM 9

using namespace std;

int sudoku[TAM][TAM];

bool checkLine(int x){
    set<int> numbers;

    for(int i = 0; i < TAM; ++i){
        numbers.insert(sudoku[x][i]);
    }

    return numbers.size() == TAM;
}

bool checkColun(int x){
    set<int> numbers;

    for(int i = 0; i < TAM; ++i){
        numbers.insert(sudoku[i][x]);
    }

    return numbers.size() == TAM;
}

bool checkSquare(int x){
    set<int> numbers;
    int line = 3*(x/3), colun = 3*(x%3);

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            numbers.insert(sudoku[line + i][colun + j]);
        }
    }

    return numbers.size() == TAM;
}

int main(){
    int n;
    string result;

    cin >> n;
    for(int k = 1; k <= n; ++k){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                cin >> sudoku[i][j];
            }
        }

        cout << "Instancia " << k << endl;

        result = "YES";
        for(int i = 0; i < 9; ++i){
            if(!checkLine(i) || !checkLine(i) || !checkSquare(i)){
                result = "No";
                break;
            }
        }

        cout << result << endl << endl;
    }

    return 0;
}
