#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    sort(a.begin(), a.end());
    int i = 0, j = a.size() - 1, cnt = 0;
    while (i < j) {
        if (a[j] + a[i] > x) {
            --j;
        } else {
            --j;
            ++i;
        }
        cnt++;
    }
    cnt += (i == j);
    cout << cnt;
}