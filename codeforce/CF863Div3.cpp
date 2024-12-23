#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve();

int32_t main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}

//find kth number that do not contain the eliminated number
void solve()
{
    int n;
    cin >> n;
    string s;
    int x = 4; // the eliminated number;
    while (n > 0) {
        s += to_string(n % 9);
        n /= 9;
    }
    cout << s << " ";
    if (s.empty()) s = "0";
    string res = "";
    for (int i = s.size()-1; i >= 0; i--) {
        int k = s[i] - '0';
        k += (k >= x);
        res += to_string(k);
    }
    cout << res << "\n";
}