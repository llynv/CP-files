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

    vector<int> nums(n+1);
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == '>') nums[i] = nums[i-1]+1;
        else nums[i] = nums[i-1];
    }

    int bleft = 0, bright = 0;

    vector<int> sumLeft(n+1), sumRight(n+1);

    for (int i = 0; i < n; ++i) {
        bleft += (s[i] == '>');
        sumLeft[i+1] = sumLeft[i] + bleft;
    }

    for (int i = n-1; i > 0; --i) {
        bright += (s[i] == '<');
        sumRight[i] = sumRight[i+1] + bright;
    }

    bleft = 0;

    dbg(sumLeft);   
    dbg(sumRight);

    for (int i = 1; i <= n; ++i) {

        if (bleft < bright) {
            int l = i, r = n;
            while (l <= r) {
                int mid = (l+r) >> 1;
                if (n - nums[mid] + nums[i-1] > bleft) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }

            int totalRight = sumRight[i] - sumRight[l] - (l-i)*(bright-bleft);
            int totalLeft = sumLeft[i];

            dbg(totalLeft, totalRight, l, i, bleft, bright);

            cout << totalLeft + totalRight << ' ';
        } else if (bleft > bright) {
            int l = 1, r = i;
            while (l <= r) {
                int mid = (l+r) >> 1;
                if (nums[i] - nums[mid-1] > bright) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }

            int totalLeft = sumLeft[i] - sumLeft[l] - (i-l)*(bleft-bright);
            int totalRight = sumRight[i];

            dbg(totalLeft, totalRight, l, i, bleft, bright);

            cout << totalLeft + totalRight << ' ';
        } else {
            cout << sumLeft[i] + sumRight[i] << ' ';
        }

        bright -= (s[i-1] == '<');
        bleft += (s[i-1] == '>');
    }
    cout << '\n';
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