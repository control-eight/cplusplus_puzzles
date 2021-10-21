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

bool compare(const std::tuple<double, int, int>& l, const std::tuple<double, int, int>& r) {
    return std::get<0>(l) > std::get<0>(r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int A = Read<int>();
        int B = Read<int>();
        int C = Read<int>();
        int X = Read<int>();
        int Y = Read<int>();
        int Z = Read<int>();
        int res = 0;
        for (int i = 0; i <= 20; i++) {
            for (int j = 0; j <= 20; j++) {
                for (int z = 0; z <= 20; z++) {
                    if (i * A + j * B + z * C <= 240) {
                        res = std::max(res, i * X + j * Y + z * Z);
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}