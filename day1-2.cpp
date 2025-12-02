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
        count += rotation / 100;
        rotation %= 100;
        if (dir) {
            if (pos == 0)  pos += 100;
            pos -= rotation;
        } else {
            pos += rotation;
        }
        if (pos <= 0 || pos >= 100) count++;
        pos %= 100;
    }  
    cout << count << endl;
}