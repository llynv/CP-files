#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int count_remaining(const vector<string>& members, const vector<bool>& expelled, int k) {
    int agree = 0, disagree = 0;
    for (int j = 0; j < k; j++) {
        agree = disagree = 0;
        for (int i = 0; i < members.size(); i++) {
            if (expelled[i]) continue;
            if (members[i][j] == '+') agree++;
            else disagree++;
        }
        if (agree > disagree) {
            for (int i = 0; i < members.size(); i++) {
                if (expelled[i]) continue;
                if (members[i][j] == '-') expelled[i] = true;
            }
        } else if (disagree > agree) {
            for (int i = 0; i < members.size(); i++) {
                if (expelled[i]) continue;
                if (members[i][j] == '+') expelled[i] = true;
            }
        } else {
            for (int i = 0; i < members.size(); i++) {
                if (expelled[i]) continue;
                expelled[i] = true;
            }
        }
    }
    int remaining = 0;
    for (int i = 0; i < members.size(); i++) {
        if (!expelled[i]) remaining++;
    }
    return remaining;
}

int solve(const vector<string>& members, int k) {
    vector<bool> expelled(members.size());
    expelled[0] = true; // always keep ourselves
    int max_remaining = 1;
    for (int mask = 1; mask < (1 << (members.size() - 1)); mask++) {
        vector<bool> current_expelled(members.size(), false);
        current_expelled[0] = true;
        for (int i = 1; i < members.size(); i++) {
            if ((mask >> (i - 1)) & 1) {
                current_expelled[i] = true;
            }
        }
        int remaining = count_remaining(members, current_expelled, k);
        if (remaining > max_remaining) {
            max_remaining = remaining;
        }
    }
    return max_remaining;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<string> members(n);
        for (int i = 0; i < n; i++) {
            cin >> members[i];
        }
        cout << solve(members, k) << endl;
    }
    return 0;
}
