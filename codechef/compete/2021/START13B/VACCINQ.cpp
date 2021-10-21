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
        int P = Read<int>();
        int X = Read<int>();
        int Y = Read<int>();

        int count = 0;
        int time = 0;
        for (int i = 0; i < N; i++) {
            int c = Read<int>();
            if (count < P) {
                if (c == 0) {
                    time += X;
                } else {
                    time += Y;
                }
            }
            count++;
        }
        cout << time << endl;
    }
    return 0;
}