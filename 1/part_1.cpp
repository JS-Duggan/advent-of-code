#include <string>
#include <iostream>
#include <vector>

using namespace std;

int part_1 () {

    /* get input */
    string in;
    vector<string> input;
    while (getline(cin, in)) input.push_back(in);

    /* set initial values */
    int count = 0;
    int pos = 50;
    for (string& s : input) {
        /* determine rotation direction and magnitude */
        int rotation = stoi(s.substr(1));
        if (s[0] == 'L') rotation = -rotation;

        /* calculate position */
        pos = (pos + rotation + 100) % 100;

        /* if pointing at 0, increment */
        if (pos == 0) count++;
    }  

    return count;
}

int main() { cout << "part 1: " << part_1() << "\n"; }