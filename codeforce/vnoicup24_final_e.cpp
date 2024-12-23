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

const int MOD = 1e9 + 7;

struct Point {
    int64_t x, y; /// x*x or y*y should not overflow
    int id;
    Point(){}
    Point(int64_t x, int64_t y) : x(x), y(y) {}

    inline bool operator < (const Point &p) const {
        return ((x < p.x) || (x == p.x && y < p.y));
    }
};

int64_t cross(const Point &O, const Point &A, const Point &B){
    return ((A.x - O.x) * (B.y - O.y)) - ((A.y - O.y) * (B.x - O.x));
}

vector<Point> get_convex_hull(vector<Point> P){
    int i, t, k = 0, n = P.size();
    vector<Point> H(n << 1);
    sort(P.begin(), P.end());

    for (i = 0; i < n; i++) {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
        H[k++] = P[i];
    }
    for (i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
        H[k++] = P[i];
    }

    H.resize(k - 1);
    return H;
}

/***
 *
 * Returns whether the polygon is convex or not
 * Points in P is given in clock-wise of anti-clockwise order
 *
***/

bool is_convex(vector <Point> P){
    int n = P.size();
    if (n <= 2) return false; /// Line or point is not convex

    n++, P.push_back(P[0]);  /// Last point = first point
    bool flag1 = (cross(P[0], P[1], P[2]) > 0);
    for (int i = 1; (i + 1) < n; i++){
        bool flag2 = (cross(P[i], P[i + 1], (i + 2) == n ? P[1] : P[i + 2]) > 0);
        if (flag1 ^ flag2) return false;
    }

    return true;
}

int calc_area(vector<Point> P) {
    int n = P.size();
    int64_t area = 0;
    for (int i = 0; i < n; i++) {
        area += P[i].x * P[(i + 1) % n].y - P[i].y * P[(i + 1) % n].x;
    }
    return abs(area);
}

void solve()
{
    int n;
    cin >> n;
    vector<Point> P(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
        P[i].id = i + 1;
    }
    int res = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        vector<Point> cur;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                cur.push_back(P[i]);
            }
        }
        vector<Point> hull = get_convex_hull(cur);
        if (is_convex(hull)) {
            res += calc_area(hull);
            // cerr << calc_area(hull) << '\n';
            res %= MOD;
        }
    }
    cout << res % MOD << '\n';
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