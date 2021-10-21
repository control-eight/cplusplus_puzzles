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
        string S = Read<string>();
        int count = 0;
        char c = '0';
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == c) {
                while(S[i] == c) {
                    i++;
                }
                i--;
                count++;
                c = (c == '0'? '1': '0');
            }
        }
        cout << count << endl;
    }
    return 0;
}