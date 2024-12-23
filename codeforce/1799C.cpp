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
#define vector2d(var, y, z, type, x) vector<vector<type>> var(y, vector<type>(z, x))
#define vector3d(var, y, z, w, type, x) vector<vector<vector<type>>> var(y, vector<vector<type>>(z, vector<type>(w, x)))
#define vector4d(var, y, z, w, u, type, x) vector<vector<vector<vector<type>>>> var(y, vector<vector<vector<type>>>(z, vector<vector<type>>(w, vector<type>(u, x)))

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
    string s;
    cin >> s;
    unordered_map<char, int> cnt;
    for (auto &c : s) cnt[c]++;
    string ev, od;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (!cnt[c]) continue;
        if (cnt[c] % 2 == 0) {
            ev += c;
        } else {
            od += c;
            cnt[c]--;
            if (cnt[c]) ev += c;
        }
    }
    string a1, a2, ans;
    ans = s;
    reverse(all(s));
    ans = max(ans, s);

    for (int i = 0; i < ev.size(); ++i) {
        a1 += ev[i];
        a1 += ev[i];
        a2.insert(a2.size() / 2, 1, ev[i]);
        a2.insert(a2.size() / 2 + 1, 1, ev[i]);
    }

    string tmp1 = a1, tmp2 = a2;

    for (int i = 0; i <= od.size(); ++i) {
        string o1 = od.substr(0, i);
        string o2 = od.substr(i, od.size() - i);
        
        for (int k = 0; k < o2.size() / 2; k++) {
            string tmp;
            for (int j = 0; j < ans.size(); ++j) tmp += 'z';
            int pos = 0;
            for (int j = 0; j < a1.size(); ++j) {
                string t1 = a1, t2 = a1;
                t1.insert(t1.begin() + j, o2[k]);
                t1.insert(t1.begin() + t1.size() - j - 1, o2[o2.size() - 1 - k]);
                t2.insert(t2.begin() + j, o2[k]);
                t2.insert(t2.begin() + t2.size() - j - 1, o2[o2.size() - 1 - k]);
                reverse(all(t2));
                if (max(t1, t2) < tmp) {
                    tmp = max(t1, t2);
                    pos = j;
                }
            }
            a1.insert(a1.begin() + pos, o2[k]);
            a1.insert(a1.begin() + a1.size() - pos, o2[o2.size() - 1 - k]);

            for (int j = 0; j < s.size(); ++j) tmp += 'z';
            pos = 0;
            for (int j = 0; j < a2.size(); ++j) {
                string t1 = a2, t2 = a2;
                t1.insert(t1.begin() + j, o2[k]);
                t1.insert(t1.begin() + t1.size() - j - 1, o2[o2.size() - 1 - k]);
                t2.insert(t2.begin() + j, o2[k]);
                t2.insert(t2.begin() + t1.size() - j - 1, o2[o2.size() - 1 - k]);
                reverse(all(t2));
                if (max(t1, t2) < tmp) {
                    tmp = max(t1, t2);
                    pos = j;
                }
            }
            a2.insert(a2.begin() + pos, o2[k]);
            a2.insert(a2.begin() + a2.size() - pos, o2[o2.size() - 1 - k]);
        }

        if (o2.size() % 2 == 1) {
            a1.insert(a1.size() / 2, 1, o2[o2.size() / 2]);
            a2.insert(a2.size() / 2, 1, o2[o2.size() / 2]);
        }
        
        a1 += o1;
        a2 += o1;
        string r1 = a1, r2 = a2;
        reverse(all(r1));
        reverse(all(r2));

        ans = min(ans, max(a1, r1));
        ans = min(ans, max(a2, r2));
        
        a1 = tmp1;
        a2 = tmp2;
    }


    string res;
    unordered_map<char, int> cnt2;
    dbg(ans);
    for (auto &c : ans) cnt2[c]++;
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < cnt[ans[i]] / 2; ++j) res += ans[i];
        if (cnt2[ans[i]] % 2 != 0) {
            res += ans[i];
        }
    }
    cout << res << '\n';
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