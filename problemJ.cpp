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
    vector<string> cards;
    for (int i = 0; i < 52; ++i) {
        string card;
        cin >> card;
        cards.push_back(card);
        if (cards.size() <= 3) continue;
        bool ok = true;
        while (ok && cards.size() > 3) {
            ok = false;
            int j = cards.size() - 1;
            while (cards.size() > 3 && j >= 3) {
                if (cards[j][0] == cards[j - 3][0]) {
                    dbg(cards);
                    cards.erase(cards.begin() + j - 3, cards.begin() + j + 1);
                    dbg(cards, "erase");
                    j = cards.size() - 1;
                    ok = true;
                    continue;
                }
                --j;
            }
            j = cards.size() - 1;
            while (cards.size() > 3 && j >= 3) {
                if (cards[j][1] == cards[j - 3][1]) {
                    dbg(cards, "2");
                    dbg(cards[j], cards[j - 3]);
                    cards.erase(cards.begin() + j);
                    cards.erase(cards.begin() + j - 3);
                    dbg(cards, "erase 2");
                    ok = true;
                    break;
                }
                --j;
            }
        }
    }
    dbg(cards);
    cout << sz(cards) << ' ';
    for (auto c : cards) cout << c << ' ';
}


int32_t main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}