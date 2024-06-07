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
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char, int> cnt;   
    unordered_map<char, vector<int>> pos;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cnt[s[i]]++;
        pos[s[i]].pb(i);
    }
    int hoz = min(cnt['E'], cnt['W']), mhoz = max(cnt['E'], cnt['W']);
    int ver = min(cnt['N'], cnt['S']), mver = max(cnt['N'], cnt['S']);
    if ((mhoz - hoz) % 2 || (mver - ver) % 2) {
        cout << "NO\n";
        return;
    }
    vector<char> ans(n, ' ');
    int ch = 0, cv = 0;
    unordered_map<char, int> step;
    for (int i = 0; i < n; ++i) {
        if (cnt['E'] > cnt['W'] && ch < mhoz - hoz) {
            if (s[i] == 'E') {
                ans[i] = (ch % 2) ? 'R' : 'H';
                (ch % 2) ? step['R']++ : step['H']++;
                ch++;
            }
        } else if (cnt['W'] > cnt['E'] && ch < mhoz - hoz) {
            if (s[i] == 'W') {
                ans[i] = (ch % 2) ? 'R' : 'H';
                (ch % 2) ? step['R']++ : step['H']++;
                ch++;
            }
        }

        if (cnt['N'] > cnt['S'] && cv < mver - ver) {
            if (s[i] == 'N') {
                ans[i] = (cv % 2) ? 'R' : 'H';
                (cv % 2) ? step['R']++ : step['H']++;
                cv++;
            }
        } else if (cnt['S'] > cnt['N'] && cv < mver - ver) {
            if (s[i] == 'S') {
                ans[i] = (cv % 2) ? 'R' : 'H';
                (cv % 2) ? step['R']++ : step['H']++;
                cv++;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (ans[i] != ' ') continue;
        ++count;
    }

    dbg(ans, count, step['R'], step['H']);

    if (step['R'] == 0 && step['H'] == 0 && count < 4) return void (cout << "NO\n");
    if ((step['R'] == 0 || step['H'] == 0) && count < 2) return void (cout << "NO\n");

    if (cnt['E'] >= cnt['W']) {
        int h = 0;
        for (int i = pos['E'].size() - hoz; i < pos['E'].size(); ++i) {
            ans[pos['E'][i]] = (h % 2) ? 'R' : 'H';
            ++h;
        }
        h = 0;
        for (int i = pos['W'].size() - hoz; i < pos['W'].size(); ++i) {
            ans[pos['W'][i]] = (h % 2) ? 'R' : 'H';
            ++h;
        }
    } else if (cnt['W'] > cnt['E']) {
        int h = 0;
        for (int i = pos['W'].size() - hoz; i < pos['W'].size(); ++i) {
            ans[pos['W'][i]] = (h % 2) ? 'R' : 'H';
            ++h;
        }   
        h = 0;
        for (int i = pos['E'].size() - hoz; i < pos['E'].size(); ++i) {
            ans[pos['E'][i]] = (h % 2) ? 'R' : 'H';
            ++h;
        }
    }

    if (cnt['N'] >= cnt['S']) {
        int h = 0;
        for (int i = pos['N'].size() - ver; i < pos['N'].size(); ++i) {
            ans[pos['N'][i]] = (h % 2) ? 'H' : 'R';
            ++h;
        }
        h = 0;
        for (int i = pos['S'].size() - ver; i < pos['S'].size(); ++i) {
            ans[pos['S'][i]] = (h % 2) ? 'H' : 'R';
            ++h;
        }
    } else if (cnt['S'] > cnt['N']) {
        int h = 0;
        for (int i = pos['S'].size() - ver; i < pos['S'].size(); ++i) {
            ans[pos['S'][i]] = (h % 2) ? 'H' : 'R';
            ++h;
        }
        h = 0;
        for (int i = pos['N'].size() - ver; i < pos['N'].size(); ++i) {
            ans[pos['N'][i]] = (h % 2) ? 'H' : 'R';
            ++h;
        }
    }

    for (auto c : ans) {
        cout << c;
    }
    cout << "\n";
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