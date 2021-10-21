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

int primes[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        lli N = Read<lli>();
        if (N%2 == 0) {
            cout << 2*N << " " << N << endl;
        }  else {
            for (int prime : primes) {
                if (N%prime != 0) {
                    cout << ((prime/2 + 1) * 2) * N << " " << prime * N << endl;
                    break;
                }
            }
        }
    }
    return 0;
}