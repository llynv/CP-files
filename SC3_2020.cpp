#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int N = 1e6+7;

int cnt[N];
vector<ii> a;



void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        // memset(it, 0, sizeof(it));
        solve();
    }
    return 0;
}

const int INF = 0x3f3f3f3f;

void solve()
{
    int n, m;
    cin >> n >> m;
    set<int> pos;
    vector<int> res(m);
    // dbg(res);
    memset(cnt, 0, n * 8 + 8);
    a.clear();
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a.emplace_back(make_pair(l, r));
        // pos.insert(i);
        // build(1, 1, m, l, r);
    }
    for (int i = 0; i < m; ++i) pos.insert(i);
    for (int i = n - 1; i >= 0; --i) {
        // build(1, 1, n, a[i].first, a[i].second);

        int start = a[i].first - 1;
        int end = a[i].second - 1;
        auto spos = pos.lower_bound(start);
        if (*spos > end) continue;
        auto epos = pos.upper_bound(end);
        if (epos == pos.begin()) {
            continue;
        }
        // --epos;
        // if (*spos > *epos) continue;

        // cout << start << " " << end << "\n";

        vector<int> v;
        for (auto it = spos; *it <= end, it != pos.end(); it = pos.lower_bound(start)) {
            if (*it > end || it == pos.end()) {
                break;
            }
            
            res[*it] = i + 1;
            v.emplace_back(*it);
            // cout << *it << " ";
            pos.erase(it);
        }
        // cout << "\n";
        // for (auto c : v) pos.erase(c);
        // dbg(spos);
    }
    int ans = 0;
    for (auto c : res) {
        if (c != 0) ans += (cnt[c]++ == 0);
    }
    // dbg(res);
    cout << ans << "\n";
}
