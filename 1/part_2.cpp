#include <string>
#include <iostream>
#include <vector>

using namespace std;

int part_2 () {

    /* get input */
    string in;
    vector<string> input;
    while (getline(cin, in)) input.push_back(in);

    /* set initial values */
    int count = 0;
    int pos = 50;
    for (string& s : input) {
        /* get magnitude  */
        int rotation = stoi(s.substr(1));
        
        /* check if pos starts at 0 */
        bool at_zero = pos == 0;

        /* add number of complete rotations to count */
        count += rotation / 100;
        rotation %= 100;
        
        /* apply directon */
        if (s[0] == 'L') rotation = -rotation;

        /* determine new position */
        pos += rotation;
        if ((pos <= 0 || pos >= 100) && !at_zero) count++;
        pos = (pos + 100) % 100;
        cout << s << ": " << pos << endl;
    }  
    return  count;
}

int main() { cout << part_2() << endl; }