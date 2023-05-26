#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

struct Store
{
    int t;
    int c;
};


void solve()
{
    int n, k, c;
    cin >> n >> k >> c;
    map<int, int> mp, ct;
    vector<int> a(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> st;
    st.emplace_back(0, 0);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        st.emplace_back(a[i], w[i]);
    }
    sort(st.begin(), st.end());
    // for (auto c : st) cout << c.first << " " << c.second << "\n";
    int cnt = 0;
    int ck[n+1];
    memset(ck, 1, sizeof(ck));
    for (int i = 1; i <= n; ++i) {
        if (st[i].first != st[i-1].first) {
            c -= st[i].second;
            cnt++;
            ck[i] = 0;
            if (cnt == k) {
                break;
            }
        }
    }
    if (cnt < k || c < 0) {
        cout << "FRIENDSHIP\n";
        return;
    }
    int fd = LONG_LONG_MAX;
    for (int i = 1; i <= n; ++i) {
        if (ck[i]) {
            fd = min(fd, st[i].second);
        }
    }
    if (c - fd >= 0) {
        cout << "LOVE\n";
    } else {
        cout << "NOT FRIENDSHIP BUT NOT LOVE\n";
    }
}