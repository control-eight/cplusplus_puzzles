#include <iostream>
#include <vector>
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

pair<int, lli> FindLessOrEqual(const vector<lli>& v, lli el) {
    auto iter = lower_bound(v.begin(), v.end(), el);
    if (iter == v.end()) {
        iter--;
    }
    if (*iter <= el) {
        return {iter - v.begin(), *iter};
    }
    if (iter != v.begin()) {
        iter--;
        return {iter - v.begin(), *iter};
    }
    return {-1, *iter};
}

pair<int, lli> FindLessOrEqual2(const vector<lli>& v, lli el) {
    auto iter = lower_bound(v.begin(), v.end(), el);
    // exact match.
    if (iter != v.end() && *iter == el) {
        return {iter - v.begin(), *iter};
    }
    // not found.
    if (iter == v.begin()) {
        return {-1, *iter};
    }
    // return smaller.
    iter--;
    return {iter - v.begin(), *iter};
}

void Print(pair<int, lli> p) {
    cout << "index = " << p.first << " value = " << p.second << endl;
}

void Test1() {
    vector<lli> v = {-10, -5, 0, 1, 3, 5, 10};
    Print(FindLessOrEqual(v, -11));
    Print(FindLessOrEqual(v, -10));
    Print(FindLessOrEqual(v, -7));
    Print(FindLessOrEqual(v, -5));
    Print(FindLessOrEqual(v, -3));
    Print(FindLessOrEqual(v, 0));
    Print(FindLessOrEqual(v, 1));
    Print(FindLessOrEqual(v, 2));
    Print(FindLessOrEqual(v, 3));
    Print(FindLessOrEqual(v, 4));
    Print(FindLessOrEqual(v, 5));
    Print(FindLessOrEqual(v, 7));
    Print(FindLessOrEqual(v, 10));
    Print(FindLessOrEqual(v, 11));
}

void Test2() {
    vector<lli> v = {-10, -5, 0, 1, 3, 5, 10};
    Print(FindLessOrEqual2(v, -11));
    Print(FindLessOrEqual2(v, -10));
    Print(FindLessOrEqual2(v, -7));
    Print(FindLessOrEqual2(v, -5));
    Print(FindLessOrEqual2(v, -3));
    Print(FindLessOrEqual2(v, 0));
    Print(FindLessOrEqual2(v, 1));
    Print(FindLessOrEqual2(v, 2));
    Print(FindLessOrEqual2(v, 3));
    Print(FindLessOrEqual2(v, 4));
    Print(FindLessOrEqual2(v, 5));
    Print(FindLessOrEqual2(v, 7));
    Print(FindLessOrEqual2(v, 10));
    Print(FindLessOrEqual2(v, 11));
}

void CheckEquals(pair<int, lli> left, pair<int, lli> right) {
    if (left.first != right.first && left.second != right.second) {
        cout << "Error!" << endl;
    } else {
        Print(left);
    }
}

void Test3() {
    vector<lli> v = {-10, -5, 0, 1, 3, 5, 10};
    CheckEquals(FindLessOrEqual(v, -11), FindLessOrEqual2(v, -11));
    CheckEquals(FindLessOrEqual(v, -10), FindLessOrEqual2(v, -10));
    CheckEquals(FindLessOrEqual(v, -7), FindLessOrEqual2(v, -7));
    CheckEquals(FindLessOrEqual(v, -5), FindLessOrEqual2(v, -5));
    CheckEquals(FindLessOrEqual(v, -3), FindLessOrEqual2(v, -3));
    CheckEquals(FindLessOrEqual(v, 0), FindLessOrEqual2(v, 0));
    CheckEquals(FindLessOrEqual(v, 1), FindLessOrEqual2(v, 1));
    CheckEquals(FindLessOrEqual(v, 2), FindLessOrEqual2(v, 2));
    CheckEquals(FindLessOrEqual(v, 3), FindLessOrEqual2(v, 3));
    CheckEquals(FindLessOrEqual(v, 4), FindLessOrEqual2(v, 4));
    CheckEquals(FindLessOrEqual(v, 5), FindLessOrEqual2(v, 5));
    CheckEquals(FindLessOrEqual(v, 7), FindLessOrEqual2(v, 7));
    CheckEquals(FindLessOrEqual(v, 10), FindLessOrEqual2(v, 10));
    CheckEquals(FindLessOrEqual(v, 11), FindLessOrEqual2(v, 11));
}

int main() {
    Test3();
    return 0;
}