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
        int N = Read<int>();
        string S = Read<string>();
        string P = Read<string>();
        if (S == P) {
            cout << "YES" << endl;
        } else {
            int count1 = 0;
            int count0 = 0;
            for (char c : P) {
                if (c == '1') {
                    count1++;
                } else {
                    count0++;
                }
            }
            if (count1 == 0 || count0 == 0) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}