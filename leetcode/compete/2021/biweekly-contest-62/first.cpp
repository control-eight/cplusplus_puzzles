#include <iostream>
#include <iostream>
#include <vector>
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

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() / static_cast<double>(m) != n) {
            return {};
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            result.push_back(vector<int>());
            for (int j = 0; j < n; j++) {
                result.back().push_back(original[n * i + j]);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> original = {1,2,3,4,5,6};
    vector<vector<int>> v = s.construct2DArray(original,2,3);
    cout << "res" << endl;
    return 0;
}