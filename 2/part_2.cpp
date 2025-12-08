#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <set>

using namespace std;

long long part_2() {

    /* get input */
    string input;
    cin >> input;
    stringstream ss(input);
    string s;
    long long ans = 0;
    set<long long> seen = {};

    while (getline(ss, s, ',')) {
        /* find upper and lower bound */
        int mid = s.find('-');
        string s_lower = s.substr(0, mid);
        string s_upper = s.substr(mid + 1);
        long long upper = stoll(s_upper);
        long long lower = stoll(s_lower);

        /* select upper bounds for pattern size */
        long long end = stoll(s_upper.substr(0, s_upper.size() / 2 + 1));

        
        /* generate repeated pattern numbers */
        for (long long i = 1; i <= end; i++) {
            long long candidate = i;
            int length = floor(log10(candidate)) + 1;
            while (true) {
                candidate = candidate * pow(10, length) + i;
                if (candidate > upper) break;
                if (candidate >= lower && seen.count(candidate) == 0) {
                    ans += candidate;
                    seen.insert(candidate);
                }
            }
        }
    }
    return ans;
}

int main() { cout << "Part 2: " << part_2() << endl; }