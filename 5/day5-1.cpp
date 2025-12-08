#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<long long,long long>> intervals;
    string s;
    while (getline(cin, s) && !s.empty()) {
        int i = s.find('-');
        long long a = stoll(s.substr(0,i));
        long long b = stoll(s.substr(i+1));
        intervals.push_back({a, b});
    }

    sort(intervals.begin(), intervals.end());

    long long total = 0;
    long long curL = intervals[0].first;
    long long curR = intervals[0].second;

    for (int i = 1; i < intervals.size(); i++) {
        auto [L, R] = intervals[i];
        if (L > curR + 1) {
            total += curR - curL + 1;
            curL = L;
            curR = R;
        } else {
            curR = max(curR, R);
        }
    }

    total += curR - curL + 1;
    cout << total << endl;
}