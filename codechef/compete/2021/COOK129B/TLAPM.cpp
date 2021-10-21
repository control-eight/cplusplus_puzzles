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

int CalcValue(int x1, int y1, int x2, int y2) {
    if (x2 < 0 || y2 < 0) return 0;

    int start = x1 + 1;
    int value = start;
    while (x1 <= x2) {
        start++;
        value += start;
        x1++;
    }
    value-=start;
    start--;
    value+=start;

    y1++;
    while (y1 <= y2) {
        start++;
        value += start;
        y1++;
    }
    value-=start;
    return value;
}

int Calc(int x1, int y1, int x2, int y2) {
    if (x2 < 0 || y2 < 0) return 0;

    int ans = 0;
    int start = x1 + 1 + y1;
    int value = CalcValue(0, 0, x1, y1);
    while (x1 <= x2) {
        //cout << value << endl;
        ans += value;
        start++;
        value += start;
        x1++;
    }
    value-=start;
    start--;
    value+=start;

    y1++;
    while (y1 <= y2) {
        //cout << value << endl;
        ans += value;
        start++;
        value += start;
        y1++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int x1 = Read<int>() - 1;
        int y1 = Read<int>() - 1;
        int x2 = Read<int>() - 1;
        int y2 = Read<int>() - 1;
        cout << Calc(x1, y1, x2, y2) << endl;
    }
    return 0;
}