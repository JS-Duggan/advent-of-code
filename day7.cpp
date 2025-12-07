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
 * could use some kind of DP/DFS approach, where you recursively go left and creating
 * one new timeline each time you split. If a beam hits a splitter that has already been
 * calculated we will know how may extra paths are possible
 * 
 * optimisation:
 * by using a bottom up approach we can minimize memory usage by approaching the problem
 * iteratively instead of recursively, while only keeping track of the most recent state
 * instead of all visited states. 
 * 
 * intuition is as follows - when a beam splits, there will be two resultant timelines, 
 * the left path will be assumed to be the current timeline, and the right path a new
 * timeline. This means that when n beams hit a splitter, there will be 2 * n resultant
 * timelines, the n original timelines going left, and the n new timelines going right.
 * Therefore, this approach tracks the number of timelines at each index in the problem. When
 * a splitter is hit, double the number of timelines by placing n timelines at index i - 1 (left)
 * and n timelines at index i + 1 (right). This means that the total number of timelines will
 * be the sum of all timelines after the final iteration.  
 * 
 * note to self - USE LONG LONG
 */
long long part2(vector<string>& input) {
    vector<long long> beams(input[0].size());
    beams[(input[0].find('S'))] = 1;
    for (const auto& s : input) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '^') { //check if splitter and splite beam, timelines can overlap
                if (i > 0) beams[i - 1] += beams[i];
                if (i < s.size() - 1) beams[i + 1] += beams[i];
                beams[i] = 0;
            }   
        }
    }
    long long times_split = 0;
    for (long long timelines : beams) times_split += timelines;
    return times_split;
}

int main() {
    vector<string> input;
    string s;
    while (getline(cin, s)) input.push_back(s);
    int p1 = part1(input);
    long long p2 = part2(input);
    cout << "Number of times beam is split: " << p1 << "\n";
    cout << "Number of timelines possible: " << p2 << "\n";
}