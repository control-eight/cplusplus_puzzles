#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

class SegmentTree {
public:
    SegmentTree(int N, int M, const vector<vector<int>>& r, int s): rect(r), size(s) {
        ini_seg = vector(5 * M, vector<int>(5 * N, 0));
        fin_seg = vector(5 * M, vector<int>(5 * N, 0));
    }

    void segment(int low, int high,
                int pos, int strip) {
        if (high == low) {
            ini_seg[strip][pos] = rect[strip][low];
        } else {
            int mid = (low + high) / 2;
            segment(low, mid, 2 * pos, strip);
            segment(mid + 1, high, 2 * pos + 1, strip);
            ini_seg[strip][pos] = max(ini_seg[strip][2 * pos],
                                  ini_seg[strip][2 * pos + 1]);
        }
    }

    void finalSegment(int low, int high, int pos) {
        if (high == low) {
            for (int i = 1; i < 2 * size; i++)
                fin_seg[pos][i] = ini_seg[low][i];
        } else {
            int mid = (low + high) / 2;
            finalSegment(low, mid, 2 * pos);
            finalSegment(mid + 1, high, 2 * pos + 1);

            for (int i = 1; i < 2 * size; i++)
                fin_seg[pos][i] = max(fin_seg[2 * pos][i],
                                  fin_seg[2 * pos + 1][i]);
        }
    }

    int finalQuery(int pos, int start, int end,
                   int x1, int x2, int node) {
        if (x2 < start || end < x1) {
            return 0;
        }

        if (x1 <= start && end <= x2) {
            return fin_seg[node][pos];
        }

        int mid = (start + end) / 2;
        int p1 = finalQuery(2 * pos, start, mid,
                            x1, x2, node);

        int p2 = finalQuery(2 * pos + 1, mid + 1,
                            end, x1, x2, node);

        return max(p1, p2);
    }

    int query(int pos, int start, int end,
              int y1, int y2, int x1, int x2, int global_pos, int global_start, int global_end) {
        if (y2 < start || end < y1) {
            return 0;
        }

        if (y1 <= start && end <= y2) {
            return (finalQuery(global_pos, global_start, global_end, x1, x2, pos));
        }

        int mid = (start + end) / 2;
        int p1 = query(2 * pos, start,
                       mid, y1, y2, x1, x2, global_pos, global_start, global_end);
        int p2 = query(2 * pos + 1, mid + 1,
                       end, y1, y2, x1, x2, global_pos, global_start, global_end);

        return max(p1, p2);
    }

    vector<vector<int>> ini_seg;
    vector<vector<int>> fin_seg;
    const vector<vector<int>>& rect;
    int size;
};

struct S {
    bool alice;
    int turn;
    int left;
    int up;
};

struct Res {
    bool alice;
    int min;
};

void Print(vector<vector<S>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j].alice << "[" << matrix[i][j].left
                 << ", " << matrix[i][j].up << "] ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        int M = Read<int>();
        int K = Read<int>();
        vector<vector<S>> matrix(N, vector<S>(M, {false, -1, 0, 0}));
        int I = N * M;
        bool alice = true;
        int turn = 1;
        while (I--) {
            int X = Read<int>();
            int Y = Read<int>();
            matrix[X - 1][Y - 1] = {alice, turn, 0, 0};
            alice = !alice;
        }

        for (int i = 0; i < N; i++) {
            bool series = true;
            int count = 0;
            for (int j = 0; j < M; j++) {
                if (matrix[i][j].alice == series) {
                    count++;
                    matrix[i][j].left = count;
                } else {
                    series = !series;
                    count = 1;
                    matrix[i][j].left = 1;
                }
            }
        }
        for (int j = 0; j < M; j++) {
            bool series = true;
            int count = 0;
            for (int i = 0; i < N; i++) {
                if (matrix[i][j].alice == series) {
                    if (i > 0 && matrix[i - 1][j].left >= K && matrix[i][j].left >= K) {
                        count++;
                        matrix[i][j].up = count;
                    } else {
                        count = 1;
                        matrix[i][j].up = 1;
                    }
                } else {
                    series = !series;
                    count = 1;
                    matrix[i][j].up = 1;
                }
            }
        }
        //Print(matrix);
        vector<vector<int>> C(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                C[i][j] = matrix[i][j].turn;
            }
        }

        SegmentTree segment_tree(N, M, C, N);
        for (int row = 0; row < N; row++)
            segment_tree.segment(0, N - 1, 1, row);
        segment_tree.finalSegment(0, N - 1, 1);

        Res res = {false, -1};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j].up == K && i >= K && j >= K) {
                    int ans = segment_tree.query(1, 1, N, i - K, i, j - K, j, 1, 1, N);
                    if (ans > res.min) {
                        res = {.alice = matrix[i][j].alice, .min = ans};
                    }
                }
            }
        }

        if (res.min == -1) {
            cout << "Draw" << endl;
        } else if (res.alice) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
    return 0;
}