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
        int count_india = 0;
        for (int i = 0; i < 5; i++) {
            int a = Read<int>();
            if (a == 1) {
                count_india++;
            } else if (a == 2) {
                count_india--;
            }
        }
        if (count_india == 0) {
            cout << "DRAW" << endl;
        } else if (count_india > 0) {
            cout << "INDIA" << endl;
        } else {
            cout << "ENGLAND" << endl;
        }
    }
    return 0;
}