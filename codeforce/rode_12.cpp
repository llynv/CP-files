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

#define MAXLEN 2000010

constexpr uint64_t mod = (1ULL << 61) - 1;

const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

uint64_t base_pow[MAXLEN];

int64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}

void init(){
    base_pow[0] = 1;
    for (int i = 1; i < MAXLEN; i++){
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

struct PolyHash{
    vector<int64_t> pref, suff;

    PolyHash() {}

    template <typename T>
    PolyHash(const vector<T>& ar){
        if (!base_pow[0]) init();

        int n = ar.size();
        assert(n < MAXLEN);
        pref.resize(n + 3, 0), suff.resize(n + 3, 0);

        for (int i = 1; i <= n; i++){
            pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= mod) pref[i] -= mod;
        }

        for (int i = n; i >= 1; i--){
            suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
            if (suff[i] >= mod) suff[i] -= mod;
        }
    }

    PolyHash(const char* str)
        : PolyHash(vector<char> (str, str + strlen(str))) {}

    uint64_t get_hash(int l, int r){
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }

    uint64_t concat(int x, int y){
        return ((modmul(get_hash(0, x - 1), base_pow[x - 1]) + modmul(get_hash(x + 1, y - 1), base_pow[y - x - 1])) % mod + modmul(base_pow[y - 2], get_hash(y + 1, sz(pref) - 1))) % mod;
    }
    

    uint64_t rev_hash(int l, int r){
        int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
        return h < 0 ? h + mod : h;
    }

    bool match(int l1, int r1, int l2, int r2){
        return get_hash(l1, r1) == rev_hash(l2, r2);
    }

    uint64_t concat_back_to_front (int l1, int r1, int l2, int r2){
        return (modmul(get_hash(l1, r1), base_pow[r2 - l2 + 1]) + get_hash(l2, r2)) % mod;
    }
};

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int res = 0;
    unordered_map<string, bool> mp2;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string tt = s;
            tt.erase(tt.begin() + i);
            tt.erase(tt.begin() + j - 1);
            mp2[tt] = 1;

            if (i != 0 && s[i] == s[i-1]) continue;
            if (j == i + 2) {
                res += (s[i] != s[j] && s[j] != s[j-1]);
            } else {
                res += (s[j] != s[j-1]);
            }
        }
    }
    cerr << res << '\n';
    cerr << mp2.size() << '\n';
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