#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    long count = 0;
    while (true) {
        string input;
        cin >> input;
        long best = 0;
        for (int i = 0; i < input.size() - 11; i++) {
            best = max(best, helper(input.substr(i), 12));
        }
        count += best;
        cout << count << endl;
    }
    
}

long helper(string s, int size) {
    
}