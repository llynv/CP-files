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

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e8;

vector<ii> st, res;
string s;

bool sol(int n, int k, int i) {
    if (i == n) {
        vector<int> pref(n + 2);
        for (auto c : st) {
            if (c.first + c.second > n) {
                pref[c.second]++;
                pref[1]++;
                pref[c.first + c.second - n]--;
            }
            else {
                pref[c.second]++;
                pref[c.first + c.second]--;
            }
        }
        int cnt = 0;
        string tmp = s;
        for (int q = 1; q <= n; ++q) {
            pref[q] += pref[q - 1];
            if (pref[q] & 1) tmp[q - 1] = (tmp[q - 1] ^ '0' ^ '1');
            cnt += (tmp[q - 1] == '1');
        }
        if (cnt == k) {
            res = st;
        }
        return (cnt == k);
    }
    bool isOk = false;
    for (int j = 1; j <= n; ++j) {
        if (isOk) return true;
        st.push_back({ i + 1, j });
        isOk = max(isOk, sol(n, k, i + 1));
        st.pop_back();
    }
    return isOk;
}

void solve()
{
    st.clear();
    res.clear();
    int n, k;
    cin >> n >> k;
    cin >> s;
    int cnt = count_if(all(s), [&](char c) {
        return (c == '1');
        });
    if (n <= 8) {
        bool fn = sol(n, k, 0);
        if (fn) {
            cout << "YES\n";
            for (auto c : res) {
                cout << c.second << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
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