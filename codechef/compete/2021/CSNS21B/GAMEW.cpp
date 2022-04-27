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
        int blocks_count = 0;
        char last = 'a';
        for (int i = 0; i < N; i++) {
            char c = Read<char>();
            if (last == 'a' || last != c) {
                last = c;
                blocks_count++;
            }
        }
        if (blocks_count == 1 || blocks_count == 3 || blocks_count == 4) {
            cout << "SAHID" << endl;
            continue;
        }
        if (blocks_count == 2) {
            cout << "RAMADHIR" << endl;
            continue;
        }
        if ((blocks_count - 5) % 3 == 0) {
            cout << "RAMADHIR" << endl;
        } else {
            cout << "SAHID" << endl;
        }
    }
    return 0;
}

// 3 4 .. 6 7 .. 9 10

// 0011

// 001100

// 00110011 -> 001111

// 0011001100 -> 00110011 -> 001111

// 001100110011 -> 1100110011 -> 11000011

// 001100
// 0011001100

// кто первый придет к 3 или 4 группам