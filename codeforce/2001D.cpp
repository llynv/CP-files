
/*
  Code by: linvg
  Created: 27.08.2024 16:13:03
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

struct segment_tree {
    // get min and max leftmost index in a range
    // update all elements in a range
    int n;
    vector<int> minv, maxv, lazy, a;
    segment_tree(int _n) : n(_n), minv(4 * n), maxv(4 * n), lazy(4 * n), a(_n) {}
    segment_tree(vector<int> _a) : segment_tree(_a.size()) {
        a = _a;
        build(1, 0, n - 1);
    }
    void build(int id, int l, int r) {
        if (l == r) {
            minv[id] = maxv[id] = l;
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        if (a[minv[id * 2]] <= a[minv[id * 2 + 1]]) minv[id] = minv[id * 2];
        else minv[id] = minv[id * 2 + 1];
        if (a[maxv[id * 2]] >= a[maxv[id * 2 + 1]]) maxv[id] = maxv[id * 2];
        else maxv[id] = maxv[id * 2 + 1];
    }
    void push(int id, int l, int r) {
        if (lazy[id] == 0) return;
        minv[id] += lazy[id];
        maxv[id] += lazy[id];
        if (l != r) {
            lazy[id * 2] += lazy[id];
            lazy[id * 2 + 1] += lazy[id];
        }
        lazy[id] = 0;
    }
    pair<int, int> get(int x, int y) {
        return get(1, 0, n - 1, x, y);
    }
    pair<int, int> get(int id, int l, int r, int x, int y) {
        push(id, l, r);
        if (l > y || r < x) return {INF, -INF};
        if (l >= x && r <= y) return {minv[id], maxv[id]};
        int mid = (l + r) / 2;
        auto p1 = get(id * 2, l, mid, x, y);
        auto p2 = get(id * 2 + 1, mid + 1, r, x, y);
        int mnv, mxv;
        dbg(p1, p2);
        if (p1.first == INF && p2.first == INF) return p1;
        if (p1.first == INF) return p2;
        if (p2.first == INF) return p1;
        if (a[p1.first] <= a[p2.first]) mnv = p1.first;
        else mnv = p2.first;
        if (a[p1.second] >= a[p2.second]) mxv = p1.second;
        else mxv = p2.second;
        return {mnv, mxv};
    }

};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> cnt;
    for (auto &c : a) cin >> c, cnt[c]++;
    int k = cnt.size();
    vector<int> pos;
    vector<int> diff(n);
    for (int i = 0; i < n; ++i) {
        cnt[a[i]]--;
        if (cnt[a[i]] == 0) {
            pos.push_back(i);
            cnt.erase(a[i]);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        cnt[a[i]]++;
        diff[i] = cnt.size();    
    }
    dbg(diff);
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}