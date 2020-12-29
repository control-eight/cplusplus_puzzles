#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

bool CheckState(vector<bool>& diagonals_state) {
    for (bool state : diagonals_state) {
        if (!state) {
            return false;
        }
    }
    return true;
}

bool CheckDiagonal(const vector<vector<int>>& matrix, vector<bool>& diagonals_state, int i, int j) {
    int k = i;
    if (i == 0 && j > 0) {
        k = matrix.size() - 1;
    }
    int l = j;
    int prev = matrix[i++][j++];
    while (i < matrix.size() && j < matrix[0].size()) {
        if (matrix[i][j] != prev) {
            //cout << prev << " " << i << " " << j << " " << matrix[i][j] << endl;
            diagonals_state[k + l] = false;
            return false;
        }
        prev = matrix[i][j];
        i++;
        j++;
    }
    //cout << "Result " << k + l << ", size = " << diagonals_state.size() << endl;
    diagonals_state[k + l] = true;
    return true;
}

bool CheckMatrix(const vector<vector<int>>& matrix, vector<bool>& diagonals_state) {
    for (int i = 0; i < matrix.size(); i++) {
        CheckDiagonal(matrix, diagonals_state, i, 0);
    }
    for (int j = 1; j < matrix[0].size(); j++) {
        CheckDiagonal(matrix, diagonals_state, 0, j);
    }
    return true;
}

void Print(const vector<bool>& diagonals_state) {
    for (int i = 0; i < diagonals_state.size(); i++) {
        cout << i << " = " << diagonals_state[i] << ", ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        int M = Read<int>();
        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = Read<int>();
            }
        }
        vector<bool> diagonals_state(N + M - 1);
        CheckMatrix(matrix, diagonals_state);
        //Print(diagonals_state);
        int Q = Read<int>();
        while (Q--) {
            int X = Read<int>() - 1;
            int Y = Read<int>() - 1;
            int V = Read<int>();
            matrix[X][Y] = V;
            if (X >= Y) {
                CheckDiagonal(matrix, diagonals_state, X - Y, 0);
            } else {
                CheckDiagonal(matrix, diagonals_state, 0, Y - X);
            }
            if (CheckState(diagonals_state)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}