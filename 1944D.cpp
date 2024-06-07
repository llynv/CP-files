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

void solve()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<vector<int>> cnt(n+1, vector<int>(26, 0));
    for (int i = 1; i <= n; ++i) {
        cnt[i] = cnt[i-1];
        cnt[i][s[i-1] - 'a']++;
    }

    vector<int> power(sz(s) + 2);
    power[0] = 1LL;
    for (int i = 0; i <= sz(s); ++i) {
        power[i + 1] = power[i] * 29LL;
    }

    vector<int> hash(sz(s) + 2), hash_rev(sz(s) + 2);
    for (int i = 1; i <= sz(s); ++i) {
        hash[i] = hash[i-1] + (s[i-1] - 'a' + 1) * power[i-1];
    }    

    for (int i = sz(s); i >= 1; --i) {
        hash_rev[i] = hash_rev[i+1] + (s[i-1] - 'a' + 1) * power[sz(s) - i];
    }

    auto get_hash = [&](int l, int r) {
        return hash[r] - hash[l-1];
    };

    auto get_hash_rev = [&](int l, int r) {
        return hash_rev[l] - hash_rev[r+1];
    };

    auto is_palindrome = [&](int l, int r) {
        return get_hash(l, r) * power[n-r] == get_hash_rev(l, r) * power[l-1];
    };

    while (q--) {
        int l, r;
        cin >> l >> r;

        dbg(is_palindrome(l, r));
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