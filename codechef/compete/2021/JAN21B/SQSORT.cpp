#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

struct Op {
    int from;
    int to;
    int weight;
};

vector<int> ReadVector(int N) {
    vector<int> res;
    while (N--) {
        res.push_back(Read<int>());
    }
    return res;
}

int PickTarget(const vector<vector<int>> &data, const vector<int> &d_cost) {
    int min = 1e9;
    int min_index = -1;

    for (int i = 0; i < d_cost.size(); i++) {
        if (data[i].size() == 1024) {
            continue;
        }
        int cost = d_cost[i];
        if (cost < min) {
            min = cost;
            min_index = i;
        }
    }
    return min_index;
}


int Score(double load_factor, int cost, bool partial_order, int containers_count) {
    if (partial_order) {
        return load_factor;
    } else {
        if (containers_count < 64) {
            return load_factor * cost * 0.4;
        } else {
            return load_factor * cost * 30;
        }
    }
}

/*int Score(double load_factor, int cost, bool partial_order, int containers_count) {
    double partial_order_coeff = 1.0;
    if (partial_order) {
        partial_order_coeff = 0;
    }
    load_factor = load_factor * 5;
    return load_factor * cost * partial_order_coeff;
}*/

int PickDistributeTo(const vector<vector<int>> &data, int n, int size,
                     const vector<int> &w_cost, const vector<int> &d_cost,
                     int filter_out1, int filter_out2) {
    int min = 1e9;
    int min_index = -1;
    for (int i = 0; i < data.size(); i++) {
        if (i != filter_out1 && i != filter_out2) {
            double load_factor = (data[i].size() * 1.0) / size;
            int cost = d_cost[i] * w_cost[n - 1];
            bool partial_order = data[i].empty() || data[i].back() < n;
            int score = Score(load_factor, cost, partial_order, d_cost.size());
            if (score < min) {
                min = score;
                min_index = i;
            }
        }
    }
    return min_index;
}

void
DistributeTo(int target, vector<vector<int>> &data, vector<Op> &ops, int size, const vector<int> &w_cost,
             const vector<int> &d_cost) {
    vector<int> &target_container = data[target];
    while (!target_container.empty()) {
        int x = *target_container.begin();
        int to = PickDistributeTo(data, x, size, w_cost, d_cost, target, -1);
        data[to].push_back(x);
        target_container.erase(target_container.begin());
        ops.push_back({target, to, w_cost[x - 1]});
    }
}

vector<int> DefineOrder(const vector<vector<int>> &data, int B) {
    vector<int> res(B + 1);
    for (int i = 0; i < data.size(); i++) {
        auto v = data[i];
        for (int c : v) {
            res[c] = i;
        }
    }
    return res;
}

void PopAndMove(vector<vector<int>> &data, const vector<int> &w_cost, const vector<int> &d_cost, int size,
                int n, int container, int target, vector<int> &order, vector<Op> &ops) {
    vector<int> &c = data[container];
    while (c.front() != n) {
        int x = *c.begin();
        int distribute_to = PickDistributeTo(data, x, size, w_cost, d_cost, target, container);
        data[distribute_to].push_back(x);
        c.erase(c.begin());
        ops.push_back({container, distribute_to, w_cost[x - 1]});
        order[x] = distribute_to;
    }
    c.erase(c.begin());
}


void FindAndPutTo(vector<vector<int>> &data, const vector<int> &w_cost, const vector<int> &d_cost, int size,
                  int n, int container, int target, vector<int> &order, vector<Op> &ops) {
    PopAndMove(data, w_cost, d_cost, size, n, container, target, order, ops);
    data[target].push_back(n);
    ops.push_back({container, target, w_cost[n - 1]});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N = Read<int>();
    int B = Read<int>();
    vector<int> c_cost = ReadVector(N);
    vector<int> d_cost = ReadVector(N);
    vector<int> w_cost = ReadVector(B);
    vector<vector<int>> data(N);
    for (int i = 0; i < N; i++) {
        int M = Read<int>();
        while (M--) {
            data[i].push_back(Read<int>());
        }
    }
    // Solve
    vector<Op> ops;
    int target = PickTarget(data, d_cost);
    int size = B;
    DistributeTo(target, data, ops, size, w_cost, d_cost);
    vector<int> order = DefineOrder(data, B);
    for (int i = 1; i < order.size(); i++) {
        FindAndPutTo(data, w_cost, d_cost, size, i, order[i], target, order, ops);
        size--;
    }
    // Print Answer
    for (int i = 0; i < N; i++) {
        cout << "Q";
    }
    cout << endl;
    cout << ops.size() << endl;
    lli total_cost = 0;
    for (auto op : ops) {
        cout << op.from + 1 << " " << op.to + 1 << endl;
        total_cost += c_cost[op.from] * op.weight + c_cost[op.to] * op.weight;
    }
    //cout << "__TOTAL = " << total_cost << endl;
    //cout << total_cost << endl;
    return 0;
}