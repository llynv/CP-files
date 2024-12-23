/*
  Code by: linvg
  Created: 09.12.2024 14:29:09
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T gcd(initializer_list<T> __l) { int a = 0; for (auto x : __l) { a = gcd(a, x); } return a; }
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
const int MOD = 1e9 + 7;





constexpr int SIZE = 100;
constexpr int BASE_PW = 9;

constexpr long long BASE = pow(10, BASE_PW) + 0.25;

char tmpbuf[SIZE * BASE_PW + 10];

struct UnsignedBignum {
   int len;
   long long data[SIZE];

   long long& operator [](int x) {
      return(data[x]);
   }
   const long long& operator [](int x) const {
      return(data[x]);
   }

   UnsignedBignum(long long x = 0) {
      len = 0;
      memset(data, 0, sizeof(data));
      (*this) = x;
   }

   UnsignedBignum(const char* str) {
      int l = strlen(str + 1);
      long long val = 0;
      (*this).clear();

      for (int i = 1; i <= (l - 1) / BASE_PW + 1; i++) {
         val = 0;
         for (int j = l - BASE_PW * i + 1; j <= l - BASE_PW * i + BASE_PW; j++) {
            if (j >= 1) val = val * 10 + str[j] - 48;
         }
         data[++len] = val;
      }
   }

   void clear() {
      for (int i = 1; i <= len; i++) data[i] = 0;
      len = 0;
   }

   inline int compare(const UnsignedBignum& a, const UnsignedBignum& b) {
      if (a.len > b.len) return 0;
      if (a.len < b.len) return 1;

      for (int i = a.len; i >= 1; i--) {
         if (a.data[i] > b.data[i]) return 0;
         if (a.data[i] < b.data[i]) return 1;
      }
      return 2;
   }

   inline bool operator < (const UnsignedBignum& x) {
      return (compare(*this, x) == 1);
   }

   inline bool operator > (const UnsignedBignum& x) {
      return (compare(*this, x) == 0);
   }

   inline bool operator <= (const UnsignedBignum& x) {
      return (compare(*this, x) >= 1);
   }

   inline bool operator >= (const UnsignedBignum& x) {
      return ((compare(*this, x) & 1) == 0);
   }

   inline bool operator != (const UnsignedBignum& x) {
      return (compare(*this, x) != 2);
   }

   inline bool operator == (const UnsignedBignum& x) {
      return (compare(*this, x) == 2);
   }

   inline UnsignedBignum operator = (const UnsignedBignum& x) {
      for (int i = x.len + 1; i <= len; i++) data[i] = 0;
      for (int i = 1; i <= x.len; i++) data[i] = x.data[i];
      len = x.len;
      return *this;
   }

   inline UnsignedBignum operator = (long long x) {
      for (int i = 0; i <= len; i++) data[i] = 0;
      len = 0;

      do {
         data[++len] = x % BASE;
         x /= BASE;
      } while (x);
      return *this;
   }

   inline UnsignedBignum operator += (const UnsignedBignum& b) {
      return *this = (*this + b);
   }

   inline UnsignedBignum operator *= (const UnsignedBignum& b) {
      return *this = (*this * b);
   }

   inline UnsignedBignum operator -= (const UnsignedBignum& b) {
      return *this = (*this - b);
   }

   inline UnsignedBignum operator /= (const UnsignedBignum& b) {
      return *this = (*this / b);
   }

   inline UnsignedBignum operator %= (const UnsignedBignum& b) {
      return *this = (*this % b);
   }

   inline UnsignedBignum operator *= (long long x) {
      return (*this = (*this * x));
   }

   inline UnsignedBignum operator += (long long x) {
      return (*this = (*this + x));
   }

   inline UnsignedBignum operator -= (long long x) {
      return (*this = (*this - x));
   }

   inline UnsignedBignum operator /= (long long x) {
      return (*this = (*this / x));
   }

   UnsignedBignum operator * (const UnsignedBignum& x) {
      UnsignedBignum res = UnsignedBignum(0LL);

      for (int i = 1; i <= len; i++) {
         for (int j = 1; data[i] && j <= x.len; j++) {
            if (x.data[j]) {
               res.data[i + j - 1] += data[i] * x.data[j];
               res.data[i + j] += res.data[i + j - 1] / BASE;
               res.data[i + j - 1] %= BASE;
            }
         }
      }

      res.len = len + x.len - 1;
      while (res.data[res.len + 1]) res.len++;
      while (res[res.len] == 0 && res.len > 1) res.len--;
      return res;
   }

   UnsignedBignum operator / (long long x) {
      assert(x);

      long long y = 0;
      UnsignedBignum res;
      for (int i = len; i >= 1; i--) {
         y = y * BASE + data[i];
         res[i] = y / x;
         y %= x;
      }

      res.len = len;
      while (res[res.len] == 0 && res.len > 1) res.len--;
      return res;
   }

   void divide(const UnsignedBignum& b, UnsignedBignum& rem, UnsignedBignum& quot) {
      assert(!(b.len == 1 && b[1] == 0));

      long long x = data[len], y = b[b.len];
      int i, l1 = BASE_PW * (len - 1), l2 = BASE_PW * (b.len - 1);

      while (x) x /= 10, l1++;
      while (y) y /= 10, l2++;

      UnsignedBignum temp = b;
      rem = *this;

      for (i = 1; i * BASE_PW <= (l1 - l2); i++) temp *= BASE;
      for (i = 1; i <= (l1 - l2) % BASE_PW; i++) temp *= 10;
      for (i = l1 - l2; i >= 0; i--) {
         x = 0;
         while (rem >= temp) rem -= temp, x++;
         quot[i / BASE_PW + 1] = quot[i / BASE_PW + 1] * 10 + x;
         temp /= 10;
      }

      quot.len = (l1 - l2) / BASE_PW + 1;
      while (rem.len > 1 && !rem[rem.len]) rem.len--;
      while (quot.len > 1 && !quot[quot.len]) quot.len--;
   }

   UnsignedBignum operator / (const UnsignedBignum& x) {
      UnsignedBignum rem, quot;
      divide(x, rem, quot);
      assert(quot.len > 0);
      return quot;
   }

   UnsignedBignum operator % (const UnsignedBignum& x) {
      UnsignedBignum rem, quot;
      divide(x, rem, quot);
      assert(rem.len > 0);
      return rem;
   }

   long long operator % (long long x) {
      long long res = 0;
      for (int i = len; i >= 1; i--) res = (res * BASE + data[i]) % x;
      return res;
   }

   UnsignedBignum operator + (const UnsignedBignum& x) {
      UnsignedBignum res;
      int i, l = max(len, x.len);
      for (i = 1; i <= l; i++) res[i] = data[i] + x[i];
      for (i = 1; i <= l; i++) res[i + 1] += res[i] / BASE, res[i] %= BASE;

      res.len = l;
      if (res[res.len + 1]) res.len++;
      while (res[res.len] == 0 && res.len > 1) res.len--;
      return res;
   }

   UnsignedBignum operator - (const UnsignedBignum& x) {
      UnsignedBignum res;
      for (int i = 1; i <= len; i++) res.data[i] = data[i] - x.data[i];
      for (int i = 1; i <= len; i++) {
         if (res[i] < 0) res.data[i] += BASE, res.data[i + 1]--;
      }

      res.len = len;
      while (res[res.len] == 0 && res.len > 1) res.len--;
      return res;
   }

   void read_bignum() {
      assert(scanf("%s", tmpbuf + 1));
      *this = UnsignedBignum(tmpbuf);
   }

   string to_str() {
      sprintf(tmpbuf, "%lld", data[len]);
      string s = string(tmpbuf);

      for (int i = len - 1; i >= 1; i--) {
         sprintf(tmpbuf, "%0*lld", BASE_PW, data[i]);
         s += string(tmpbuf);
      }
      return s;
   }
};

struct Bignum {
   int sign;
   UnsignedBignum val;

   Bignum(long long x = 0) {
      sign = 0;
      val = llabs(x);
      if (x < 0) sign = 1;
   }

   Bignum(UnsignedBignum x) {
      val = x;
      sign = 0;
   }

   inline Bignum operator = (long long x) {
      sign = 0;
      val = llabs(x);
      if (x < 0) sign = 1;
      return *this;
   }

   Bignum operator * (const Bignum& x) {
      UnsignedBignum y = x.val;
      Bignum res;
      res.val = y * this->val;
      res.sign = this->sign ^ x.sign;
      if (res.val == UnsignedBignum(0LL)) res.sign = 0;
      return res;
   }

   Bignum operator / (const Bignum& x) {
      UnsignedBignum y = this->val;
      Bignum res;
      res.val = y / x.val;
      res.sign = this->sign ^ x.sign;
      if (res.val == UnsignedBignum(0LL)) res.sign = 0;
      return res;
   }

   Bignum operator % (const Bignum& x) {
      UnsignedBignum y = this->val;
      Bignum res;
      res.val = y % x.val;
      res.sign = this->sign;
      if (res.val == UnsignedBignum(0LL)) res.sign = 0;
      return res;
   }

   Bignum operator + (const Bignum& x) {
      Bignum res;

      if (this->sign == x.sign) {
         res.sign = this->sign;
         res.val = this->val + x.val;
      }
      else {
         UnsignedBignum v = this->val, w = x.val;

         int cmp = v.compare(v, w);
         if (cmp != 1) {
            res.sign = this->sign;
            res.val = v - w;
         }
         else {
            res.sign = x.sign;
            res.val = w - v;
         }
      }

      if (res.val == UnsignedBignum(0LL)) res.sign = 0;
      return res;
   }

   Bignum operator - (const Bignum& x) {
      Bignum res = x;
      res.sign ^= 1;
      return *this + res;
   }

   inline int compare(const Bignum& a, const Bignum& b) {
      if (a.sign != b.sign) {
         if (a.sign == 0) return 0;
         if (b.sign == 0) return 1;
      }

      UnsignedBignum x = a.val, y = b.val;
      if (a.sign == 0) return x.compare(x, y);
      return x.compare(y, x);
   }

   inline bool operator < (const Bignum& x) {
      return (compare(*this, x) == 1);
   }

   inline bool operator > (const Bignum& x) {
      return (compare(*this, x) == 0);
   }

   inline bool operator <= (const Bignum& x) {
      return (compare(*this, x) >= 1);
   }

   inline bool operator >= (const Bignum& x) {
      return ((compare(*this, x) & 1) == 0);
   }

   inline bool operator != (const Bignum& x) {
      return (compare(*this, x) != 2);
   }

   inline bool operator == (const Bignum& x) {
      return (compare(*this, x) == 2);
   }

   inline Bignum operator += (const Bignum& b) {
      return *this = (*this + b);
   }

   inline Bignum operator *= (const Bignum& b) {
      return *this = (*this * b);
   }

   inline Bignum operator -= (const Bignum& b) {
      return *this = (*this - b);
   }

   inline Bignum operator /= (const Bignum& b) {
      return *this = (*this / b);
   }

   inline Bignum operator %= (const Bignum& b) {
      return *this = (*this % b);
   }

   inline Bignum operator *= (long long x) {
      return (*this = (*this * x));
   }

   inline Bignum operator += (long long x) {
      return (*this = (*this + x));
   }

   inline Bignum operator -= (long long x) {
      return (*this = (*this - x));
   }

   inline Bignum operator /= (long long x) {
      return (*this = (*this / x));
   }

   inline void read_bignum() {
      assert(scanf("%s", tmpbuf));
      sign = (tmpbuf[0] == '-');

      if (!sign) {
         int i, l = strlen(tmpbuf);
         for (i = l; i >= 1; i--) tmpbuf[i] = tmpbuf[i - 1];
         tmpbuf[l + 1] = 0;
      }

      val = UnsignedBignum(tmpbuf);
   }

   string to_str() {
      string s = "";
      if (sign) s = s + '-';
      return s + val.to_str();
   }
};

int converted(string s)
{
   __int128_t x = 0;
   for (int i = 0; i < sz(s); ++i) {
      x = x * 10 + (s[i] - '0');
   }
   dbg(s, (int) x);
   int cnt = 0;
   while (x > 1) {
      cnt++;
      x /= 2;
   }
   return cnt;
}

void solve()
{
   int n;
   cin >> n;
   vector<int> exp;
   for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      exp.push_back(converted(s));
   }
   dbg(exp);
   map<int, multiset<int>> pos;
   vector<int> prev(n);
   iota(all(prev), -1ll);

   vector<bool> rm(n, false);

   while (true) {
      bool flag = false;
      int id_mi = -1;
      for (int i = 1; i < n; i++) {
         int cur = i - 1;
         while (cur > 0 && rm[cur]) --cur;
         if (exp[i] == exp[cur]) {
            rm[cur] = true;
            exp[i]++;
            flag = true;
         }
      }
      if (!flag) {
         for (int i = 0; i < n; ++i) {
            if (!rm[i]) {
               if (id_mi == -1) id_mi = i;
               if (exp[id_mi] > exp[i]) id_mi = i;
            }
         }
         if (id_mi == -1) {
            break;
         }
         rm[id_mi] = true;
         for (int i = 0; i < n; ++i) {
            if (prev[i] == id_mi) {
               prev[i] = prev[id_mi];
            }
         }
      }
   }

   int res = *max_element(all(exp));

   dbg(res);
   dbg(exp);

   Bignum x(1);
   for (int i = 1; i <= res; ++i) x *= Bignum(2);
   cout << x.to_str() << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}