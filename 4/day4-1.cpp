#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> grid;
    string input;

    while (true) {
        if (!getline(cin, input)) break;
        if (input.empty()) break;
        grid.push_back(input);
    }
    vector<vector<int>> dirs{
        {1,1},
        {1,0},
        {0,1},
        {0,-1},
        {-1,0},
        {1,-1},
        {-1,1},
        {-1,-1}
    };

    vector<string> copy = grid;
    int ans = 0;
    int rolls = 0;
    do {
        rolls = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '.') continue;
                int count = 0;
                for (const auto& dir : dirs) {
                    if (i + dir[0] >= 0 && i + dir[0] < grid.size() && j + dir[1] >= 0 && j + dir[1] < grid[i].size()) {
                        if (grid[i + dir[0]][j + dir[1]] == '@') count++;
                    }
                }
                if (count < 4) {
                    rolls++;
                    grid[i][j] = '.';
                }
            }
        }
        ans += rolls;
    } while (rolls > 0);
    cout << ans << endl;
    // for (const string& s : copy) {
    //     for (char c : s) {
    //         cout << c;
    //     }
    //     cout << endl;
    // }
}