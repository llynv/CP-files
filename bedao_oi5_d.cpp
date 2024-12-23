
/*
  Code by: linvg
  Created: 31.10.2024 20:05:24
*/

#include <bits/stdc++.h>

#define MAXLEN 1000010

using namespace std;

constexpr uint64_t mod = (1ULL << 61) - 1;

const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

uint64_t base_pow[MAXLEN];

int64_t modmul(uint64_t a, uint64_t b) {
  uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
  uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
  uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
  ret = (ret & mod) + (ret >> 61);
  ret = (ret & mod) + (ret >> 61);
  return ret - 1;
}

void init() {
  base_pow[0] = 1;
  for (int i = 1; i < MAXLEN; i++) {
    base_pow[i] = modmul(base_pow[i - 1], base);
  }
}

struct PolyHash {
  /// Remove suff vector and usage if reverse hash is not required for more speed
  vector<int64_t> pref, suff;

  PolyHash() {}

  template <typename T>
  PolyHash(const vector<T>& ar) {
    if (!base_pow[0]) init();

    int n = ar.size();
    assert(n < MAXLEN);
    pref.resize(n + 3, 0), suff.resize(n + 3, 0);

    for (int i = 1; i <= n; i++) {
      pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
      if (pref[i] >= mod) pref[i] -= mod;
    }

    for (int i = n; i >= 1; i--) {
      suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
      if (suff[i] >= mod) suff[i] -= mod;
    }
  }

  PolyHash(const char* str)
    : PolyHash(vector<char>(str, str + strlen(str))) {
  }

  uint64_t get_hash(int l, int r) {
    int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
    return h < 0 ? h + mod : h;
  }

  uint64_t rev_hash(int l, int r) {
    int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
    return h < 0 ? h + mod : h;
  }
  bool isPalindrome(int l1, int r1, int l2, int r2) {
    return (modmul(get_hash(l1, r1), base_pow[r2 - l2 + 1]) + get_hash(l2, r2)) % mod == (modmul(rev_hash(l2, r2), base_pow[r1 - l1 + 1]) + rev_hash(l1, r1)) % mod;
  }
};

void solve()
{
  int n;
  cin >> n;
  char s[n];
  cin >> s;

  PolyHash hash(s);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int u = i; u < j; ++u) {
        for (int v = u + 1; v <= j; ++v) {
          ans += hash.isPalindrome(i, u, v, j);
        }
      }
    }   
  }
  cout << ans << '\n';
}


int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
  freopen("vastr.inp", "r", stdin);
  freopen("vastr.out", "w", stdout);
  // int t;
  // cin >> t;
  // while (t--)
  solve();
  return 0;
}