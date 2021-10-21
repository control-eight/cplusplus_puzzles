#include <iostream>
#include <iostream>
#include <vector>
#include <set>
#include <span>
#include <unordered_set>
#include <unordered_map>
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

void Print(vector<int> v) {
    for (int el : v) {
        cout << el << ", ";
    }
    cout << "\n";
}

class Solution {
public:

    int CalcRhombus(const int size, const int k, const int l, const vector<vector<int>>& grid) {
        int sum = 0;
        int i = k;
        int j = l;
        int grow_left = -1;
        int grow_down = -1;
        do {
            sum += grid[i][j];
            i += grow_down;
            j += grow_left;
            if (abs(i - k) >= size) {
                grow_down = -grow_down;
            }
            if (abs(j - l) >= 2 * size) {
                grow_left = -grow_left;
            }
            if (i >= grid.size() || i < 0 || j < 0 || j >= grid[0].size()) {
                return -1;
            }
        } while (i != k || j != l);
        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();

        set<int> res;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                res.insert(grid[i][j]);
                for (int l = j + 1; l < w; l++) {
                    int s = CalcRhombus(l - j, i, l, grid);
                    if (s != -1) {
                        res.insert(s);
                    }
                }
            }
        }
        vector<int> ss(res.rend(), res.rend() + 3);
        return ss;
    }
};

int main() {
    vector<vector<int>> vv1 = {{7,7,7}};
    vector<vector<int>> vv2 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> vv3 = {{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
    Solution s;
    Print(s.getBiggestThree(vv1));
    //Print(s.getBiggestThree(vv2));
    //Print(s.getBiggestThree(vv3));
    return 0;
}