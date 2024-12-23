#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long

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

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> a(n); 
    set<int> s;
    for (auto &c : a) {
        cin >> c;
        s.insert(c);
    }       
    int cnt = 0;
    int res = (a.size() - s.size()) * c;

    set<int>::iterator it = s.end();
    --it;

    cnt = (cnt == 0 ? 1 : cnt);
    int tt = LONG_LONG_MAX, sl = 0;
    for (auto ii = s.begin(); ii != s.end(); ++ii) {
        // tt = max(tt, (int)(i - s.size()) * d + (tmax - i) * c);
        tt = min(tt, (*(ii) - 1 - sl) * d + (s.size() - sl - 1) * c);
        sl++;
    }
    cout << min(tt + res, a.size() * c + d) << "\n";
}

// void solve()
// {
//     int n;
//     cin >> n;
//     set<int> day;
//     while (n--) {
//         int type;
//         cin >> type;
//         if (type == 1) {
//             int a, b, d;
//             cin >> a >> b >> d;
//             int tt = (a - b) * (d - 1);
//             if (day.empty()) {
//                 for (int i = tt + 1; i <= tt + a; ++i) {
//                     day.insert(day.end(), i);
//                 }
//                 cout << "1 ";
//             } else {
//                 set<int> tmp;
//                 for (int i = tt + 1; i <= tt + a; ++i) {
//                     if (day.find(i) != day.end()) {
//                         tmp.insert(tmp.end(), i);
//                     } else {
//                         break;
//                     }
//                 }

//                 if (tmp.empty()) {
//                     cout << "0 ";
//                 } else {
//                     cout << "1 ";
//                     for (auto c : day) {
//                         if (tmp.find(c) == tmp.end()) {
//                             day.erase(c);
//                         }
//                     }
//                 }
//             }
//         } else {
//             int a, b;
//             cin >> a >> b;
//             if (day.empty()) {
//                 cout << "-1 ";
//             } else {
//                 set<int>::iterator it = day.end();
//                 --it;
//                 if (day.size() == 1) {
//                     cout << ceil((double)(*(it) - a) / (a - b)) + 1 << "\n";
//                 } else {
//                     cout << "-1 ";
//                 }
//             }
//         }
//     }
//     cout << "\n";
// }
