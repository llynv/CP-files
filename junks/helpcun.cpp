#include <iostream>
#include <vector>

using namespace std;

pair<int, vector<int>> longestCommonSubsequence(const string &a, const string &b) {
    int m = a.length();
    int n = b.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Populate the DP array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int lcsLength = dp[m][n];
    vector<int> lcsIndices;
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcsIndices.insert(lcsIndices.begin(), i - 1);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return {lcsLength, lcsIndices};
}

int check[277] = {0};

int main() {
    string a, b;
    cin >> b >> a;
    
    pair<int, vector<int>> result = longestCommonSubsequence(a, b);
    string str = "";
    for (int index : result.second) {
        check[b[index]] = 1;
        // cout << index << " ";
    }

    int mn = a.size(), mx = -1;
    for (int i = result.second.front(); i <= result.second.back(); ++i) {
        if (!check[a[i]]) {
            mn = min(mn, i);
            mx = max(mx, i);
            // cout << mx << " " << mn << endl;
        }
    }
    cout << (mx == -1 ? 0 : mx - mn + 1);
}   
