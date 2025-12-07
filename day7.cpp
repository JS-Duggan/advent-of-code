#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

/** Part 1 - how many times will the beam be split 
 * intuition: using a set of beam indexes, split a beam whenever a 
 * splitter index is in the set
 * 
 * edge cases
 *      - splitting the beam goes out of the bounds of the array, doesn't matter because it won't be split again
 *      - splitters are next to each other, but doesn't seem to be in the input
*/

int part1(vector<string>& input) {
    set<int> beams;
    int times_split = 0;
    for (const auto& s : input) {
        if (beams.empty()) { // skip first loop, just get index of laser
            beams.insert(s.find('S'));
            continue;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '^' && beams.find(i) != beams.end()) { //check if splitter and index inside set
                beams.erase(i);
                beams.insert(i - 1);
                beams.insert(i + 1);
                times_split++;
            }   
        }
    }
    return times_split;
}

/** Part 2 - how many timelines will there be
 * intuition: seems like a graph problem, counting number of possibe paths
 * where the source is the source node, and a splitter is a vertex
 * if a beam doesn't hit another vertex, it is a leaf node
 * 
 * could use some kind of DP/DFS approach, where you recursively go left and right
 * counting the number of possible paths and then saveing the number of timelines
 * from a node so if it is encountered again it can be done
 * 
 * note to self - USE LONG LONG
 */

long long helper(unordered_map<int, long long>& possible_splits, vector<string>& input, int i, int j) {
    int hash_index = i * input[0].size() + j;
    if (possible_splits.count(hash_index)) return possible_splits[hash_index];
    long long paths = 0;
    // cout << "beam starting at: " << i << ", " << j << endl;
    /* iterate through input until splitter is found */
    for (int k = i + 1; k < input.size(); k++) {
        // cout << "checking: " << k << ", " << j << endl;
        if (input[k][j] == '^') {
            /* when splitter is found, recursively find left and right paths */
            paths += helper(possible_splits, input, k, j - 1);
            paths += helper(possible_splits, input, k, j + 1) + 1;
            break;
        }
    }

    return possible_splits[hash_index] = paths;
} 

long long part2(vector<string>& input) {
    /* key will be j x max_height + i - this will give unique hashable key */
    unordered_map<int, long long> possible_splits;
    int source = input[0].find('S');

    return helper(possible_splits, input, 0, source) + 1;
}



int main() {
    vector<string> input;
    string s;
    while (getline(cin, s)) input.push_back(s);
    int p1 = part1(input);
    long p2 = part2(input);
    cout << "Number of times beam is split: " << p1 << "\n";
    cout << "Number of timelines possible: " << p2 << "\n";
}