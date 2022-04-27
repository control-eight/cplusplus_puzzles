#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

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
        int A = Read<int>();

        if (A % 2 == 1) {
            if (N % 2 == 0) {
                cout << "Even" << endl;
            } else {
                cout << "Odd" << endl;
            }
        } else {
            if (N == 1) {
                cout << "Even" << endl;
            } else {
                cout << "Impossible" << endl;
            }
        }
    }
    return 0;
}