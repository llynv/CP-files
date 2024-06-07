#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define LINVG
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)
#define endl "\n"
#define fill(x, y) memset(x, y, sizeof(x))
#define heapMax priority_queue<int>
#define heapMin priority_queue<int, vector<int>, greater<int>>

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator>>(ostream& is, const T_container& v) { for (auto& c : v) is >> c; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LINVG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


void solve();

int32_t main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (auto& c : a) {
        cin >> c;
        cnt += (c != 0);
    }
    if (cnt & 1) return void(cout << "-1\n");
    if (cnt == 0) {
        cout << n << "\n";
        rep(i, 1, n + 1) cout << i << " " << i << "\n";
        return;
    }
    vector<ii> ans;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0 && a[i + 1] != 0) {
            if (a[i] == a[i + 1]) {
                ans.pb({ i + 1, i + 2 });
                res++;
            }
            else {
                ans.pb({ i + 1, i + 1 });
                ans.pb({ i + 2, i + 2 });
                res += 2;
            }
            ++i;
            continue;
        }

        if (a[i] != 0) {
            int j = i + 1;
            for (; j < n and a[j] == 0; ++j) {}
            int step = j - i - 1;
            if (a[i] == a[j]) {
                if (step > 1) {
                    ans.push_back({ i + 1, i + 1 });
                    ans.push_back({ i + 2, j - 1 });
                    ans.push_back({ j, j + 1 });
                }
                else {
                    ans.push_back({ i + 1, i + 1 });
                    ans.push_back({ j, j + 1 });
                }
            }
            else {
                ans.push_back({ i + 1, i + 1 });
                ans.push_back({ i + 2, j });
                ans.push_back({ j + 1, j + 1 });
            }
            i = j;
        }
    }
    vector<ii> tmp;
    sort(all(ans));
    if (ans[0].fi > 1) tmp.push_back({ 1, ans[0].fi - 1 });
    tmp.push_back(ans[0]);
    for (int i = 1; i < sz(ans); ++i) {
        if (ans[i].fi > ans[i - 1].se + 1) {
            tmp.push_back({ ans[i - 1].se + 1, ans[i].fi - 1 });
        }
        tmp.push_back(ans[i]);
    }
    sort(all(tmp));
    if (tmp.back().se < n) tmp.push_back({ tmp.back().se + 1, n });
    cout << sz(tmp) << "\n";
    for (auto& c : tmp) cout << c.fi << " " << c.se << "\n";
}
