
/*
  Code by: linvg
  Created: 14.09.2024 01:41:19
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
const int N = 1e6 + 7;

int it[4 * N + 5], lz[4 * N + 5], pref[N + 1], a[N];
int n;

void build (int index, int l, int r) {
    if (l == r) {
        it[index] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(index << 1, l, mid);
    build(index << 1 | 1, mid + 1, r);
    it[index] = 0; 
}

void update (int index, int l, int r, int u, int val) {
    if (r < u || l > u) return;
    if (l == r) {
        it[index] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(index << 1, l, mid, u,  val);
    update(index << 1 | 1, mid + 1, r, u, val);
    it[index] = max(it[index << 1], it[index << 1 | 1]);
}

int get_val (int index, int l, int r, int u, int v) {
    if (l > v || r < u) return 1ll;
    if (u <= l && r <= v) {
        return it[index];
    }
    int mid = (l + r) >> 1;
    return max(get_val(index << 1 | 1, mid + 1, r, u, v), get_val(index << 1, l, mid, u, v));
}


void solve()
{
    cin >> n;
    int id = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) id = i;
    }
    build(1, 1, n);
    vector<int> store;
    int res = 0;
    for (int i = 0; i < n; ++i, id = (id + 1) % n) {
        store.push_back(a[id]);
        update(1, 1, n, store[i], i + 1);
        if (i == 0) {
            res = max(res, n);
            continue;
        }
        if (store[i] > store[i-1]) {
            pref[i + 1] = pref[i] + store[i];
            res = max(res, pref[i + 1] + n);
        } else {
            int p = get_val(1, 1, n, 1, store[i] - 1);
            pref[i + 1] = pref[p] + (i - p + 1) * store[i];
            res = max(res, pref[i + 1] + n);
        }
    }
    cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}