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
    char suit;
    cin >> suit;
    vector<string> a(2 * n);
    rep (i, 0, 2 * n) {
        cin >> a[i];
    }
    map<char, int> mp;
    vector<vector<int>> card(26);
    for (auto &c : a) {
        mp[c[1]]++;
        card[c[1]-'A'].push_back(c[0]-'0');
    }
    bool isOk = true;
    int suitCount = (mp.find(suit) != mp.end()) ? mp[suit] : 0;
    for (auto &c : mp) {
        if (c.fi != suit && c.se % 2 != 0) {
            suitCount--;
        }
    }
    if (suitCount % 2 != 0 || suitCount < 0) return void (cout << "IMPOSSIBLE\n");
    for (auto &c : card) {
        sort(all(c));
    }
    vector<string> nonSuit;
    for (auto &c : mp) {
        if (c.fi != suit && c.se % 2 != 0) {
            for (int i = 0; i+1 < c.se; i += 2) {
                cout << card[c.fi - 'A'][i] << c.first << ' ';
                cout << card[c.fi - 'A'][i+1] << c.first << '\n';
            }
            string str = "";
            str += (card[c.fi - 'A'].back() + '0');
            str += c.fi;
            nonSuit.push_back(str);
        } else if (c.fi != suit) {
            for (int i = 0; i < c.se; i += 2) {
                cout << card[c.fi - 'A'][i] << c.first << ' ';
                cout << card[c.fi - 'A'][i+1] << c.first << '\n';
            }
        }
    }
    int fn = 0;
    for (int i = 0; i < nonSuit.size(); i++) {
        cout << nonSuit[i] << ' ';
        cout << card[suit - 'A'][fn] << suit << '\n';
        ++fn;
    }
    for (int i = fn; i < card[suit - 'A'].size(); i += 2) {
        cout << card[suit - 'A'][i] << suit << ' ';
        cout << card[suit - 'A'][i+1] << suit << '\n';
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