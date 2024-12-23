
/*
  Code by: linvg
  Created: 16.09.2024 10:39:08
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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

    uint64_t rev_hash(int l, int r){
        int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
        return h < 0 ? h + mod : h;
    }

    bool match(int l1, int r1, int l2, int r2){
        return get_hash(l1, r1) == rev_hash(l2, r2);
    }

    bool is_palindrome(int l, int r){
        return get_hash(l, r) == rev_hash(l, r);
    }
};

// segment tree with lazy propagation for hash
struct HashSegmentTree{
    struct Node{
        int l, r;
        uint64_t hash;
        Node *left, *right;

        Node(int l, int r, uint64_t hash)
            : l(l), r(r), hash(hash), left(nullptr), right(nullptr) {}
    };

    Node* root;

    HashSegmentTree(const vector<int>& ar){
        root = build(0, ar.size() - 1, ar);
    }

    Node* build(int l, int r, const vector<int>& ar){
        if (l == r) return new Node(l, r, ar[l]);

        Node* cur = new Node(l, r, 0);
        int mid = (l + r) >> 1;
        cur->left = build(l, mid, ar);
        cur->right = build(mid + 1, r, ar);

        cur->hash = modmul(cur->left->hash, base_pow[cur->right->r - cur->right->l + 1]) + cur->right->hash;
        if (cur->hash >= mod) cur->hash -= mod;

        return cur;
    }

    uint64_t query(int l, int r){
        return query(root, l, r);
    }

    uint64_t query(Node* cur, int l, int r){
        if (cur->l > r || cur->r < l) return 0;
        if (l <= cur->l && cur->r <= r) return cur->hash;

        uint64_t left = query(cur->left, l, r);
        uint64_t right = query(cur->right, l, r);

        return modmul(left, base_pow[cur->right->r - r]) + right;
    }

    // bool update(int pos, int val){
    //     return update(root, pos, val);
    // }

};

void solve()
{   
    int n, q;
    cin >> n >> q;
    char s[n];
    cin >> s;
    vector<vector<int>> pref(26, vector<int>(n + 1, 0));
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = pref[i][j - 1] + (s[j - 1] == 'a' + i);
        }
    }
    PolyHash hash(s);

    HashSegmentTree tree(vector<int>(s, s + n));

    while (q--) {
        int t;
        cin >> t;
        if (t == 2) {
            int l, r;
            cin >> l >> r;
            // bool is_palindrome = hash.is_palindrome(l - 1, r - 1);
            bool is_palindrome = 
            int cnt = 0;
            for (int i = 0; i < 26; i++) {
                cnt += (pref[i][r] - pref[i][l - 1]) > 0;
            }
            if (!is_palindrome) {
                cout << (r - l + 1) << '\n';
                continue;
            }
            if (cnt == 1 && is_palindrome) {
                cout << 0 << '\n';
            } else {
                cout << r - l << '\n';
            }
        } else {
            int l, r, k;
            cin >> l >> r >> k;
        }
    }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
//    int t;
//    cin >> t;
//    while (t--)
   solve();
   return 0;
}