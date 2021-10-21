#include <iostream>
#include <vector>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

int ReadOrTerminate() {
    int res = Read<int>();
    if (res == -1) {
        std::exit(-1);
    }
    return res;
}

vector<vector<int>> CC2 = {
        {1, 1},
        {1, 1},
};

/*

\ \ \
\ \ \
\ / \

 */

vector<vector<int>> CC3 = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 0, 0}
};

vector<vector<int>> CC4 = {
        {1, 0, 0, 1},
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 1, 0}
};

vector<vector<int>> CC = CC3;

bool DEBUG = false;6
bool RUN_TESTS = false;
bool TESTS = false;

int Moves = 0;
vector<pair<int, int>> MOVES;

int CalcK(const vector<vector<int>> &m) {
    int ans = 0;
    for (int i = 0; i < m.size() - 1; i++) {
        for (int j = 0; j < m.size() - 1; j++) {
            if (m[i][j] == 1 && m[i + 1][j + 1] == 1 && m[i][j + 1] == 0 && m[i + 1][j] == 0) {
                ans++;
            }
        }
    }
    return ans;
}

void InternalPrint(const vector<vector<int>> &m) {
    for (auto v : m) {
        for (auto el : v) {
            if (el == 1) {
                cout << "/ ";
            } else if (el == 0) {
                cout << "\\ ";
            } else {
                cout << "? ";
            }
        }
        cout << endl;
    }
}

void Print(const vector<vector<int>> &m, bool printK) {
    if (DEBUG) {
        InternalPrint(m);
        if (printK) {
            int trueK = CalcK(m);
            cout << "[DEBUG] KKK = " << trueK << endl;
        }
    }
}

void PrintCC() {
    if (DEBUG) {
        cout << "[DEBUG] Game: " << endl;
        Print(CC, true);
    }
}

void PrintDebug(int i, int j, int K, const vector<vector<int>> &M) {
    if (DEBUG) {
        cout << "[DEBUG] K = " << K << endl;
    }
}

void PrintM(const vector<vector<int>> &M) {
    if (DEBUG) {
        cout << "[DEBUG] Known: " << endl;
        Print(M, false);
    }
}

int Ask(int i, int j, const vector<vector<int>> &M) {
    if (DEBUG) {
        PrintCC();
        CC[i][j] = !CC[i][j];
        PrintCC();
    }
    int newK;
    if (TESTS) {
        MOVES.push_back({i, j});
        CC[i][j] = !CC[i][j];
        newK = CalcK(CC);
    } else {
        cout << "1 " << i + 1 << " " << j + 1 << endl << flush;
        newK = ReadOrTerminate();
    }
    Moves++;
    PrintDebug(i, j, newK, M);
    return newK;
}

void FillSquare(vector<vector<int>> &M, int i, int j) {
    M[i][j] = 1;
    if (j >= 0 && j < M.size() - 1) {
        M[i][j + 1] = 0;
    }
    if (i >= 0 && i < M.size() - 1 && j >= 0 && j < M.size() - 1) {
        M[i + 1][j + 1] = 1;
    }
    if (i >= 0 && i < M.size() - 1) {
        M[i + 1][j] = 0;
    }
}

bool CheckSquareDefined(vector<vector<int>> &M, int i, int j) {
    bool res = true;
    res &= M[i][j] != -1;
    if (j >= 0 && j < M.size() - 1) {
        res &= M[i][j + 1] != -1;
    }
    if (i >= 0 && i < M.size() - 1 && j >= 0 && j < M.size() - 1) {
        res &= M[i + 1][j + 1] != -1;
    }
    if (i >= 0 && i < M.size() - 1) {
        res &= M[i + 1][j] != -1;
    }
    return res;
}

void Revert(const vector<vector<int>> &M, int &K, int i, int j) {
    K = Ask(i, j, M);
}

bool CheckTopLeftCorner(vector<vector<int>> &M, int &K, int i, int j) {
    if (i < 0 || j < 0 || i >= M.size() || j >= M.size()) {
        return true;
    }
    int newK = Ask(i, j, M);
    bool ans = newK != K;
    if (!ans) {
        Revert(M, K, i, j);
    }
    if (newK < K) {
        M[i][j] = 0;
    }
    K = newK;
    return ans;
}

bool CheckTopLeftCornerOpt(vector<vector<int>> &M, int &K, int i, int j) {
    if (i < 0 || j < 0 || i >= M.size() || j >= M.size()) {
        return true;
    }
    int newK = Ask(i, j, M);
    M[i][j] = !M[i][j];
    bool ans = newK != K;
    if (newK < K) {
        M[i][j] = 0;
    }
    K = newK;
    return ans;
}

void Set(vector<vector<int>> &M, int &K, int i, int j, int value) {
    if (M[i][j] != value) {
        K = Ask(i, j, M);
        M[i][j] = value;
    }
}

bool PreCheck(vector<vector<int>> &M, int &K, int corner_i, int corner_j, int i, int j, int value) {
    if (CheckSquareDefined(M, corner_i, corner_j)) {
        return true;
    }
    if (M[i][j] != value) {
        Set(M, K, i, j, value);
        if (CheckSquareDefined(M, corner_i, corner_j)) {
            return true;
        }
    }
    return false;
}

bool ChangeTopLeft(vector<vector<int>> &M, int &K, int i, int j) {
    if (M[i][j] != -1) {
        return PreCheck(M, K, i, j, i, j, 1);
    }
    int newK = Ask(i, j, M);
    if (newK > K) {
        K = newK;
        FillSquare(M, i, j);
        PrintM(M);
        return true;
    } else if (newK < K) {
        K = newK;
        FillSquare(M, i, j);
        M[i][j] = !M[i][j];
        PrintM(M);
        return true;
    }
    return false;
}

bool ChangeTopRight(vector<vector<int>> &M, int &K, int i, int j) {
    int top_left_i = i;
    int top_left_j = j - 1;
    if (M[i][j] != -1) {
        return PreCheck(M, K, top_left_i, top_left_j, i, j, 0);
    }
    int newK = Ask(i, j, M);
    if (newK > K) {
        K = newK;
        if (CheckTopLeftCorner(M, K, top_left_i, top_left_j)) {
            if (M[top_left_i][top_left_j] == 0) {
                FillSquare(M, top_left_i, top_left_j);
                M[top_left_i][top_left_j] = 0;
            } else {
                FillSquare(M, top_left_i, top_left_j);
            }
            PrintM(M);
            return true;
        } else {
            FillSquare(M, i, j);
            PrintM(M);
            return PreCheck(M, K, top_left_i, top_left_j, i, j, 0);
        }
    } else if (newK < K) {
        K = newK;
        Revert(M, K, i, j);
        if (CheckTopLeftCorner(M, K, top_left_i, top_left_j)) {
            if (M[top_left_i][top_left_j] == 0) {
                FillSquare(M, top_left_i, top_left_j);
                M[top_left_i][top_left_j] = 0;
            } else {
                FillSquare(M, top_left_i, top_left_j);
            }
            PrintM(M);
            return true;
        } else {
            FillSquare(M, i, j);
            PrintM(M);
            return PreCheck(M, K, top_left_i, top_left_j, i, j, 0);
        }
    }
    return false;
}

bool ChangeBottomLeft(vector<vector<int>> &M, int &K, int i, int j) {
    int top_left_i = i - 1;
    int top_left_j = j;
    if (M[i][j] != -1) {
        return PreCheck(M, K, top_left_i, top_left_j, i, j, 0);
    }
    int newK = Ask(i, j, M);
    if (newK > K) {
        K = newK;
        if (CheckTopLeftCorner(M, K, top_left_i, top_left_j)) {
            if (M[top_left_i][top_left_j] == 0) {
                FillSquare(M, top_left_i, top_left_j);
                M[top_left_i][top_left_j] = 0;
            } else {
                FillSquare(M, top_left_i, top_left_j);
            }
            PrintM(M);
            return true;
        } else {
            FillSquare(M, i, j);
            PrintM(M);
            return PreCheck(M, K, top_left_i, top_left_j, i, j, 0);
        }
    } else if (newK < K) {
        K = newK;
        Revert(M, K, i, j);
        if (CheckTopLeftCorner(M, K, top_left_i, top_left_j)) {
            if (M[top_left_i][top_left_j] == 0) {
                FillSquare(M, top_left_i, top_left_j);
                M[top_left_i][top_left_j] = 0;
            } else {
                FillSquare(M, top_left_i, top_left_j);
            }
            PrintM(M);
            return true;
        } else {
            FillSquare(M, i, j);
            PrintM(M);
            return PreCheck(M, K, top_left_i, top_left_j, i, j, 0);
        }
    }
    return false;
}

bool ChangeCorner(vector<vector<int>> &M, int &K, int i, int j) {
    int top_left_i = i - 1;
    int top_left_j = j - 1;
    if (M[i][j] != -1) {
        return PreCheck(M, K, top_left_i, top_left_j, i, j, 1);
    }
    int newK = Ask(i, j, M);
    int prev_diff = newK - K;
    if (newK > K) {
        K = newK;
        if (CheckTopLeftCorner(M, K, top_left_i, top_left_j)) {
            if (M[top_left_i][top_left_j] == 0) {
                FillSquare(M, top_left_i, top_left_j);
                M[top_left_i][top_left_j] = 0;
            } else {
                FillSquare(M, top_left_i, top_left_j);
            }
            PrintM(M);
            return true;
        }
    } else if (newK < K) {
        K = newK;
        Revert(M, K, i, j);
        if (CheckTopLeftCorner(M, K, top_left_i, top_left_j)) {
            if (M[top_left_i][top_left_j] == 0) {
                FillSquare(M, top_left_i, top_left_j);
                M[top_left_i][top_left_j] = 0;
            } else {
                FillSquare(M, top_left_i, top_left_j);
            }
            PrintM(M);
            return true;
        }
    }
    return false;
}

bool ChangeCornerOpt1(vector<vector<int>> &M, int &K, int i, int j) {
    int top_left_i = i - 1;
    int top_left_j = j - 1;
    if (M[i][j] != -1) {
        return true;
    }
    int newK = Ask(i, j, M);
    int prev_diff = newK - K;
    if (newK > K) {
        K = newK;
        if (CheckTopLeftCornerOpt(M, K, top_left_i, top_left_j)) {
            if (M[top_left_i][top_left_j] == 0) {
                FillSquare(M, top_left_i, top_left_j);
                M[top_left_i][top_left_j] = 0;
            } else {
                FillSquare(M, top_left_i, top_left_j);
            }
            PrintM(M);
            return true;
        }
    } else if (newK < K) {
        K = newK;
        Revert(M, K, i, j);
        if (CheckTopLeftCornerOpt(M, K, top_left_i, top_left_j)) {
            if (M[top_left_i][top_left_j] == 0) {
                FillSquare(M, top_left_i, top_left_j);
                M[top_left_i][top_left_j] = 0;
            } else {
                FillSquare(M, top_left_i, top_left_j);
            }
            PrintM(M);
            return true;
        }
    }
    return false;
}

bool ChangeCornerOpt2(vector<vector<int>> &M, int &K, int i, int j) {
    if (M[i][j] != -1) {
        return true;
    }
    int newK = Ask(i, j, M);
    int prev_diff = newK - K;
    if (newK > K) {
        if (prev_diff > 1) {
            //FillSquare(M, i, j);
        }
        M[i][j] = 1;
        return true;
    } else {
        if (prev_diff > 1) {
            //FillSquare(M, i, j);
        }
    }
    return false;
}

bool SolveStart(vector<vector<int>> &M, int &K, int i, int j) {
    if (CheckSquareDefined(M, 0, 0)) {
        return true;
    }
    if (i == 0 && j == 0) {
        if (SolveStart(M, K, i, j + 1)) {
            return true;
        }
        if (ChangeTopLeft(M, K, i, j)) {
            return true;
        }
        return SolveStart(M, K, i, j + 1);
    } else if (i == 0 && j == 1) {
        if (SolveStart(M, K, i + 1, j)) {
            return true;
        }
        if (ChangeTopRight(M, K, i, j)) {
            return true;
        }
        return SolveStart(M, K, i + 1, j);
    } else if (i == 1 && j == 0) {
        return ChangeBottomLeft(M, K, i, j);
    } else if (i == 1 && j == 1) {
        if (SolveStart(M, K, i, j - 1)) {
            return true;
        }
        if (ChangeCorner(M, K, i, j)) {
            return true;
        }
        return SolveStart(M, K, i, j - 1);
    }
    return false;
}

void SolveFirstVBlock(vector<vector<int>> &M, int &K, int i, int j) {
    if (ChangeCornerOpt1(M, K, i + 1, j)) {
        return;
    }
    if (ChangeTopRight(M, K, i, j)) {
        return;
    }
    ChangeCornerOpt1(M, K, i + 1, j);
}

void SolveFirstRow(vector<vector<int>> &M, int &K, int j_start) {
    int i = 0;
    for (int j = j_start; j < M.size(); j++) {
        if (!CheckSquareDefined(M, i, j - 1)) {
            Set(M, K, i, j - 1, 1);
            Set(M, K, i + 1, j - 1, 0);
            SolveFirstVBlock(M, K, i, j);
        }
    }
}

void SolveFirstHBlock(vector<vector<int>> &M, int &K, int i_start) {
    int j = 0;
    if (ChangeCornerOpt1(M, K, i_start, j + 1)) {
        return;
    }
    if (ChangeBottomLeft(M, K, i_start, j)) {
        return;
    }
    ChangeCornerOpt1(M, K, i_start, j + 1);
}

void SolveByBlocks(vector<vector<int>> &M, int &K, int i_start) {
    for (int i = i_start; i < M.size(); i++) {
        if (!CheckSquareDefined(M, i - 1, 0)) {
            Set(M, K, i - 1, 0, 1);
            Set(M, K, i - 1, 1, 0);
            SolveFirstHBlock(M, K, i);
        }
        for (int j = 2; j < M.size(); j++) {
            if (!CheckSquareDefined(M, i - 1, j - 1)) {
                Set(M, K, i, j - 1, 0);
                Set(M, K, i - 1, j - 1, 1);
                Set(M, K, i - 1, j, 0);
                if (!ChangeCornerOpt2(M, K, i, j)) {
                    M[i][j] = 0;
                }
            }
        }
    }
}

void GenerateTests(int N, vector<vector<vector<int>>>& cases, vector<vector<int>> test) {
    if (test.size() == N && test[test.size() - 1].size() == N) {
        cases.push_back(test);
        return;
    }
    if (test.empty() || test[test.size() - 1].size() == N) {
        test.push_back({});
    }
    vector<vector<int>> test1 = test;
    test1[test1.size() - 1].push_back(0);
    GenerateTests(N, cases, test1);
    vector<vector<int>> test2 = test;
    test2[test2.size() - 1].push_back(1);
    GenerateTests(N, cases, test2);
}

void GenerateRandomTests(int N, vector<vector<vector<int>>>& cases, int count) {
    while(count--) {
        vector<vector<int>> M(N, vector<int>(N, -1));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                M[i][j] = rand() % 2;
            }
        }
        cases.push_back(M);
    }
}

bool IsEqual(const vector<vector<int>>& c, const vector<vector<int>>& M) {
    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j < c.size(); j++) {
            if (c[i][j] != M[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Validate(vector<vector<int>> c, const vector<vector<int>>& M, const vector<pair<int, int>> moves) {
    vector<vector<int>> original = c;
    for (auto move : moves) {
        c[move.first][move.second] = !c[move.first][move.second];
    }
    if (!IsEqual(c, M)) {
        cout << "Cant convert from " << endl;
        InternalPrint(original);
        cout << " to " << endl;
        InternalPrint(M);
        cout << " got " << endl;
        InternalPrint(c);
        return false;
    }
    //cout << "Moves count = " << moves.size() << endl;
    return true;
}

void RunTest() {
    DEBUG = false;
    TESTS = true;
    int N = 100;
    vector<vector<vector<int>>> cases;
    //GenerateTests(N, cases, {});
    GenerateRandomTests(N, cases, 1);
    cout << "For N = " << N << endl;
    int max_moves = 0;
    int errors = 0;
    for (auto c : cases) {
        //cout << "Run " << endl;
        //InternalPrint(c);
        int K = CalcK(c);
        CC = c;
        vector<vector<int>> M(N, vector<int>(N, -1));
        SolveStart(M, K, 0, 0);
        SolveFirstRow(M, K, 2);
        SolveByBlocks(M, K, 2);
        if (!Validate(c, M, MOVES)) {
            errors++;
            //if (errors == 10) {
            //    break;
            //}
        }
        max_moves = std::max<int>(max_moves, MOVES.size());
        MOVES = {};
    }
    cout << "Errors = " << errors << " out of " << cases.size() << endl;
    cout << "Max moves = " << max_moves << endl;
    std::exit(-1);
}

int main() {
    if (RUN_TESTS) {
        RunTest();
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        Moves = 0;
        int N = Read<int>();
        int Q = Read<int>();
        int K = Read<int>();

        vector<vector<int>> M(N, vector<int>(N, -1));
        //PrintCC();
        if (DEBUG) {
            cout << "[DEBUG] SolveStart: " << endl;
        }
        SolveStart(M, K, 0, 0);
        if (DEBUG) {
            cout << "[DEBUG] SolveFirstRow: " << endl;
        }
        SolveFirstRow(M, K, 2);
        if (DEBUG) {
            cout << "[DEBUG] SolveByBlocks: " << endl;
        }
        SolveByBlocks(M, K, 2);
        if (DEBUG) {
            cout << "[DEBUG] Moves = " << Moves << endl;
        }

        cout << "2" << endl << flush;
        for (auto is : M) {
            for (int iii = 0; iii < is.size(); iii++) {
                if (DEBUG) {
                    cout << is[iii];
                } else {
                    cout << !is[iii];
                }
                if (iii != is.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl << flush;
        }
        if (Read<int>() != 1) {
            std::exit(-1);
        }
    }
    return 0;
}