#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

void print(const vector<int> v) {
    cout << "[";
    for (int i : v) {
        cout << i << ", ";
    }
    cout << "]" << endl;
}

class SeatManager {
public:
    SeatManager(int n) {
        unreserved.reserve(n);
        for (int i = 1; i <= n; i++) {
            unreserved.push_back(i);
        }
        std::make_heap(unreserved.begin(),unreserved.end(), [](int left, int right) {return right < left;});
    }

    int reserve() {
        int result = unreserved.front();
        std::pop_heap(unreserved.begin(),unreserved.end(), [](int left, int right) {return right < left;}); unreserved.pop_back();
        //print(unreserved);
        //cout << "Result: " << result << endl;
        return result;
    }

    void unreserve(int seatNumber) {
        unreserved.push_back(seatNumber); std::push_heap(unreserved.begin(),unreserved.end(), [](int left, int right) {return right < left;});
        //print(unreserved);
    }

    std::vector<int> unreserved;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

int main() {
    SeatManager seatManager(5); // Initializes a SeatManager with 5 seats.
    seatManager.reserve();    // All seats are available, so return the lowest numbered seat, which is 1.
    seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
    seatManager.unreserve(2); // Unreserve seat 2, so now the available seats are [2,3,4,5].
    seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
    seatManager.reserve();    // The available seats are [3,4,5], so return the lowest of them, which is 3.
    seatManager.reserve();    // The available seats are [4,5], so return the lowest of them, which is 4.
    seatManager.reserve();    // The only available seat is seat 5, so return 5.
    seatManager.unreserve(5); // Unreserve seat 5, so now the available seats are [5].
    return 0;
}