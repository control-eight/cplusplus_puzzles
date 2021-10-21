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

        lli sum = (1+N)/2 * N;
        if (N % 2 == 1 || N == 2 || sum % 2 != 0 || (N / 2) % 2 == 1) {
            cout << "NO" << endl;
            continue;
        }

        std::vector<int> v1;
        std::vector<int> v2;
        int s1 = 0;
        int s2 = 0;
        for (int i = N, j = N-1; i > N/2; i-=2, j-=2) {
            s1 += i;
            v1.push_back(i);
            v2.push_back(j);
            s2 += j;
        }
        for (int i = N/2, j = N/2 - 1; i > 0; i-=2, j-=2) {
            s2 += i;
            v2.push_back(i);
            v1.push_back(j);
            s1 += j;
        }

        if (s1 == 0 || s2 == 0 || s1 != s2) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;

        for (int v : v1) {
            cout << v << " ";
        }
        cout << endl;

        for (int v : v2) {
            cout << v << " ";
        }
        cout << endl;

    }
    return 0;
}