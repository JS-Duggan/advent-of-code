#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

void part1() {
    string input, token;
    vector<vector<string>> nums;
    while (getline(cin, input)) {
        nums.push_back({});
        stringstream ss(input);
        while (ss >> token) nums.back().push_back(token);
    }
    
    vector<string> ops = nums.back();
    nums.pop_back();
    long long ans = 0;
    for (int i = 0; i < nums[0].size(); i++) {
        string op = ops[i];
        long long running = stoll(nums[0][i]);
        for (int j = 1; j < nums.size(); j++) {
            if (op == "*") running *= stoll(nums[j][i]);
            else running += stoll(nums[j][i]);
        }
        ans += running;
    }

    cout << "solution: " << ans << "\n";
}

void part2() {
    string input;
    vector<string> lines;
    while (getline(cin, input)) lines.push_back(input);
    string ops = lines.back();
    lines.pop_back();

    vector<vector<char>> chars(lines.size());

    for (int i = 0; i < lines.size(); i++) {
        for (char c : lines[i]) {
            chars[i].push_back(c);
        }
    }
    int height = chars.size();
    int length = chars[0].size();

    /* iterate through top to bottom, left to right */
    long ans = 0;
    int op_idx = 0;
    vector<long> nums;
    for (int l = 0; l < length; l++) {
        long tracker = 0;
        for (int h = 0; h < height; h++) {
            if (chars[h][l] != ' ') {
                tracker = tracker * 10 + (chars[h][l] - '0');
            }
        }
        /* append to nums or blank space so perform operation */
        if (tracker) nums.push_back(tracker);
        else {
            /* multiply */
            if (ops[op_idx] == '*') {
                long total = 1;
                for (long num : nums) {
                    total *= num;
                }
                ans += total;
            } 
            /* add */
            else {
                long total = 0;
                for (long num : nums) {
                    total += num;
                }
                ans += total;
            }
            op_idx = l + 1;
            nums.clear();
        }
    }
    /* last iteration to catch the last set of operations */
    if (ops[op_idx] == '*') {
        long total = 1;
        for (long num : nums) {
            total *= num;
        }
        ans += total;
    } 
    /* add */
    else {
        long total = 0;
        for (long num : nums) {
            total += num;
        }
        ans += total;
    }
    nums.clear();
            
    cout << "solution: " << ans << "\n";
}

int main() { part2(); }