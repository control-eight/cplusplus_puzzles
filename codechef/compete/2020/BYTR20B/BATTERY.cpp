#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

typedef std::tuple<int, int> key_tuple;

struct key_hash : public std::unary_function<key_tuple, std::size_t> {
    std::size_t operator()(const key_tuple &k) const {
        return std::get<0>(k) ^ std::get<1>(k);
    }
};

struct key_equal : public std::binary_function<key_tuple, key_tuple, bool> {
    bool operator()(const key_tuple &l, const key_tuple &r) const {
        return l == r;
    }
};

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

iterator Test() {

}

int FindMax(const vector<int>& energy, int t, int limit, lli current,
            unordered_map<const key_tuple, int, key_hash, std::equal_to<>> &cache, int actions) {
    if (t > limit) {
        return current;
    }
    auto key = make_tuple(t, actions);
    if (cache.find(key) != cache.end()) {
        return cache[key];
    }
    int res = 0;
    if (energy[t-1] > energy[energy.size() - t]) {
        res = std::max(res, FindMax(energy, t + 1, limit, current + energy[t-1], cache, actions));
    } else  {
        res = std::max(res, FindMax(energy, t + 1, limit, current + energy[energy.size() - t], cache, actions));
    }
    res = std::max(res, FindMax(energy, t + 1, limit, current, cache, actions + 1));
    if (actions >= 2) {
        res = std::max(res, FindMax(energy, t + 1, limit, current + energy[t-1] + energy[energy.size() - t], cache, actions - 1));
    }
    cache[key] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        int X = Read<int>();
        vector<int> energy;
        while (N--) {
            energy.push_back(Read<int>());
        }
        int limit = (energy.size() + 1) / 2;
        unordered_map<const key_tuple, int, key_hash, std::equal_to<>> cache;
        int max = FindMax(energy, 1, limit, 0, cache, 1);
        if (max >= X) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}