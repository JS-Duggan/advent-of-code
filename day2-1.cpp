#include <string>
#include <sstream>
#include <iostream>

using namespace std;

bool repeating(string s) {
    int n = s.size();
    for (int i = 1; i <= n / 2; i++) {
        if (n % i != 0) continue;
        long long check = stoll(s.substr(0, i));
        bool repeated = true;
        for (int j = i; j <= n - i; j += i) {
            long long curr = stoll(s.substr(j, i));
            if (check != curr) {
                repeated = false;
                break;
            }
        }
        if (repeated) return true;
    }
    return false;
}

int main() {
    string input;
    cin >> input;
    stringstream ss(input);
    string token;
    long long ans = 0;
    while (getline(ss, token, ',')) {
        int mid = token.find('-');
        long long lower = stoll(token.substr(0, mid));
        long long upper = stoll(token.substr(mid + 1));
        for (long long i = lower; i <= upper; i++) {
            string check = to_string(i);
            if (repeating(check)) ans += i;
        }
    }

    cout << ans << endl;
}
