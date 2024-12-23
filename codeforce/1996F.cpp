/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<ii> b(n);
    for (auto &c : a) cin >> c;
    for (int i = 0; i < n; ++i) {
        cin >> b[i].second;
        b[i].first = a[i];
    }
    sort(all(b), greater<ii>());

    auto f = [&](int m) -> ii {
        int res = 0, cnt = 0;
        vector<ii> c = b;
        for (int i = 0; i < n; ++i) {
            if (c[i].first >= m) {
                int pos = (c[i].first - m + 1) / c[i].second;
                res += pos * c[i].first - c[i].second * (pos - 1) * pos / 2;
                cnt += pos;
                c[i].first -= pos * c[i].second;
            }
        }
        return {res, cnt};
    };

    dbg(b);
    int ans = 0;
    int l = 1, r = *max_element(all(a));
    while (l < r) {
        int m = (l + r) / 2;
        ii t = f(m);
        if (t.second > k) {
            l = m + 1;
            continue;
        }
        auto t1 = f(m+1);
        dbg(m, t, t1);
        if (t.first <= t1.first ) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    dbg(l);
    for (int i = 0; i < n; ++i) {
        if (b[i].first >= l) {
            int pos = (b[i].first - l + 1) / b[i].second;
            ans += pos * b[i].first - b[i].second * (pos - 1) * pos / 2;
            k -= pos;
            b[i].first -= pos * b[i].second;
        }
    }

    dbg(b);
    dbg(ans, k);

    priority_queue<ii> pq;
    for (int i = 0; i < n; ++i) {
        pq.push(b[i]);
    }
    while (k --> 0)
    {
        ii t = pq.top();
        if (t.first <= 0) break;
        pq.pop();
        ans += t.first;
        t.first -= t.second;
        pq.push(t);
    }
    

    cout << ans << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}