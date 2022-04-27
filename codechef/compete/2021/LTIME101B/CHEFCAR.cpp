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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        lli moves = Read<lli>() - 1;
        lli V = Read<lli>();

        lli min = 0;
        if (moves > V) {
            min = (moves - V) * (2 + (1 + (moves - V))) / 2;
        }
        min += std::min(moves, V);

        lli max = moves * (1 + moves) / 2;
        cout << max  << " ";
        cout << min << endl;
    }
    return 0;
}