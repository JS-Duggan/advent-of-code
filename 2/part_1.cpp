#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

long part_1() {

    /* get input */
    string input;
    cin >> input;
    stringstream ss(input);
    string s;
    long ans = 0;

    while (getline(ss, s, ',')) {
        /* find upper and lower bound */
        int mid = s.find('-');
        string s_lower = s.substr(0, mid);
        string s_upper = s.substr(mid + 1);
        long lower = stol(s_lower);
        long upper = stol(s_upper);

        /* select lower and upper bounds for number generation */
        long start = stol(s_lower.substr(0, s_lower.size() / 2)); 
        long end = stol(s_upper.substr(0, s_upper.size() / 2 + 1));


        /* generate doouble numbers - start at bottom of size range */
        for (long i = start; i <= end; i++) {
            int size = floor(log10(i)) + 1;
            long candidate = i * pow(10, size) + i;
            if (candidate > upper) break;
            if (candidate >= lower) ans += candidate;
        }
    }
    return ans;
}

int main() { cout << "Part 1: " << part_1() << endl; }