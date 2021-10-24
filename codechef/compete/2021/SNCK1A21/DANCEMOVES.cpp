#include <iostream>

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
        int X = Read<int>();
        int Y = Read<int>();
        if (Y <= X) {
            cout << X - Y << endl;
        } else {
            int diff = Y - X;
            if (diff % 2 == 0) {
                cout << diff / 2 << endl;
            } else {
                cout << diff / 2 + 2 << endl;
            }
        }
    }
    return 0;
}