#include <iostream>
#include <string>
using namespace std;

int main() {
    long long count = 0;
    while (true) {
        string input;
        cin >> input;
        long long best = 0;
        int last_index = 0;
        for (int i = 11; i >= 0; i--) {
            best *= 10;
            int best_index = last_index;
            long long temp = 0;
            for (int j = last_index; j < input.size() - i; j++) {
                if (temp < input[j] - '0') {
                    temp = input[j] - '0';
                    best_index = j;
                }
                last_index = best_index + 1;
            }
            best += temp;
        }
        
        count += best;
        cout << count << endl;
    }
    
}