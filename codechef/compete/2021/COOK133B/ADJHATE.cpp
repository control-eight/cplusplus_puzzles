#include <iostream>
#include <vector>

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
        vector<int> A;
        for (int i = 0; i < N; i++) {
            A.push_back(Read<int>());
        }

        vector<int> R;
        int uneven_c = 0;
        for (int el : A) {
            if (abs(el) % 2 != 0) {
                R.push_back(el);
                uneven_c++;
            }
        }
        for (int el : A) {
            if (abs(el) % 2 == 0) {
                R.push_back(el);
            }
        }

        if (uneven_c == R.size() || uneven_c == 0) {
            cout << -1 << endl;
        } else {
            for (int el : R) {
                cout << el << " ";
            }
            cout << endl;
        }
    }
    return 0;
}