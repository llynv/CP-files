#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> cache;
    vector<string> str;
    while (n--) {
        string s;
        cin >> s;
        if (s[1] == '1') {
            string d1, ip2;
            cin >> d1 >> ip2;
            cache[d1] = ip2;
        } else {
            string d3;
            cin >> d3;
            if (cache[d3] != "") {
                warning = true;
            } else {
            }
            if ()
            str.emplace_back(cache);
        }
    }
    return 0;
}