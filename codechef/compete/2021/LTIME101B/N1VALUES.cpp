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
        int N = Read<int>();

        for (int i = 0; i < N; i++) {
            if (i == 0) {
                cout << "1 1 ";
            } else {
                cout << static_cast<lli>(std::pow(2, i)) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}