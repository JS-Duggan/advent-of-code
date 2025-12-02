#include <string>
#include <iostream>

using namespace std;

int main() {
    int count = 0;
    int pos = 50;
    string input;
    for (int i = 0; i < 4531; i++) {
        cin >> input;
        int rotation = stoi(input.substr(1));
        bool dir = input[0] == 'L';

        if (dir) pos = (pos - rotation + 100) % 100;
        else pos = (pos + rotation) % 100;

        if (pos == 0) count++;
    }  
    cout << count << endl;
}