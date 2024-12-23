/*
  Code by: linvg
  Created: 13.09.2024 15:41:08
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e8;
const int N = 2e5 + 7;

vector<int> it(4 * N + 5);

void build(vector<int>& a, int index, int l, int r) {
    if (l == r) {
        it[index] = a[l - 1];
        return;
    }
    int mid = (l + r) >> 1;
    build(a, index << 1, l, mid);
    build(a, index << 1 | 1, mid + 1, r);
    it[index] = min(it[index << 1], it[index << 1 | 1]);
}

void update(int index, int l, int r, int u, int v) {
    if (l > u || r < u) return;
    if (l == r) {
        it[index] += v;
        return;
    }
    int mid = (l + r) >> 1;
    update(index << 1, l, mid, u, v);
    update(index << 1 | 1, mid + 1, r, u, v);
    it[index] = min(it[index << 1], it[index << 1 | 1]);
}

int get(int index, int l, int r, int u) {
    if (l > u || r < u) return INF;
    if (l == r) return it[index];
    int mid = (l + r) >> 1;
    return min(get(index << 1, l, mid, u), get(index << 1 | 1, mid + 1, r, u));
}


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), d(n);
    for (auto& c : a) cin >> c;
    for (auto& c : d) cin >> c;
    vector<vector<int>> segments;
    vector<array<int, 2>> limits, idx;
    vector<int> total;
    int cur = 0;
    segments.push_back(vector<int>());

    for (int i = 0; i < n; ++i) {
        cur = d[i];
        if (cur <= 0) {
            cur = d[0];
            if (segments.back().size()) {
                limits.push_back(array<int, 2>({ -INF, -INF }));
                int sum = 0;
                int len = segments.back().size();
                for (int j = 0; j < len; ++j) {
                    sum += segments.back()[j];
                    limits.back()[0] = max(limits.back()[0], d[i - len + j] - j);
                    limits.back()[1] = max(limits.back()[1], d[i - len + j] - len + 1 + j);
                }
                idx.push_back({i - len, i - 1});
                total.push_back(sum);
                segments.push_back(vector<int>());
            }
            segments.back().push_back(a[i]);
            idx.push_back({i, i});
            total.push_back(a[i]);
            limits.push_back({0ll, 0ll});
            segments.push_back(vector<int>());
            continue;
        }
        segments.back().push_back(a[i]);
        cur--;
    }

    if (segments.back().size()) {
        limits.push_back(array<int, 2>({ -INF, -INF }));
        int sum = 0, i = n;
        int len = segments.back().size();
        for (int j = 0; j < len; ++j) {
            sum += segments.back()[j];
            limits.back()[0] = max(limits.back()[0], d[i - len + j] - j);
            limits.back()[1] = max(limits.back()[1], d[i - len + j] - len + 1 + j);
        }
        idx.push_back({i - len, i - 1});
        total.push_back(sum);
        segments.push_back(vector<int>());
    }

    if (segments.back().empty()) segments.pop_back();
    dbg(segments);
    dbg(total);
    dbg(limits);
    dbg(idx);


    int l = 0, r = INF, ans = INF;
    while (l <= r) {
        int mid = (l + r) >> 1;
        vector<int> b = total;
        bool ok = true;
        int remain = 0, cur = 0;

        for (int i = 0; i < segments.size(); ++i) {
            cur = max(cur, limits[i][1]);
            int ss = segments[i].size();
            if (b[i] > mid * ss) {
                if (d[idx[i][1]] == 0) {
                    ok = false;
                    break;
                }
                remain += b[i] - mid * ss;
                b[i] = mid * ss;
            } else {
                if (cur != 0) {
                    for (int j = max(0ll, i - limits[i][0]); j <= min(ss - 1, i + limits[i][1]); ++j) {
                        if (i == j) continue;
                        int ssj = segments[j].size();
                        if (b[j] < mid * ssj) {
                            int x = min(mid * ssj - b[j], remain);
                            b[j] += x;
                            remain -= x;
                            b[i] -= x;
                        }
                    }
                }
            }
            cur--;
        }
        if (remain) {
            b[segments.size() - 1] += remain;
        }

        if ((int) ceil(1.0 * b[segments.size() - 1] / segments.back().size()) > mid) {
            ok = false;
        }

        dbg(mid);
        dbg(l, r);
        dbg(b);
 
        if (ok) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}