#include <climits>
#include <iostream>
#include <random>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fir first
#define sec second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a) ((int)a.size())
#define all(a) a.begin(), a.end()

constexpr int N = 1e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;

constexpr int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

// Pollard's rho algorithm
ull gcd(ull a, ull b) {
   return b ? gcd(b, a % b) : a;
}

ull pollard_rho(ull n) {
   if (n % 2 == 0) return 2;
   ull x = dist(rnd) % n, y = x, c = dist(rnd) % n, d = 1;
   while (d == 1) {
      x = (x * x + c) % n;
      y = (y * y + c) % n;
      y = (y * y + c) % n;
      d = gcd(x > y ? x - y : y - x, n);
   }
   return d == n ? pollard_rho(n) : d;
}

#define int long long
struct SAIS {
   // 后缀类型
#define L_TYPE 0
#define S_TYPE 1

   int ss[N];
   int rl[N], rk[N], lcp[N];
   // ss是字符串,rk是每一个后缀在排序之后的排名,rl[i]表示第i个排名的数是第几个,lcp[i]也就是height,是排名
   // 第1的后缀和第1-1的后缀的lcp
   int n;
   void init(const vector<int>& s) {
      n = s.size();
      for (int i = 1; i <= n; ++i)
         ss[i] = s[i - 1];
      // st中的字符必须调成正数!!!!!!!!!!!!!!
   }

   // 判断一个字符是否为LMS字符
   inline bool is_lms_char(int* type, int x) {
      return x > 1 && type[x] == S_TYPE && type[x - 1] == L_TYPE;
   }

   // 判断两个LMS子串是否相同
   inline bool equal_substring(int* S, int x, int y, int* type) {
      do {
         if (S[x] != S[y]) return false;
         x++, y++;
      } while (!is_lms_char(type, x) && !is_lms_char(type, y));
      return S[x] == S[y] && type[x] == type[y];
   }

   // 诱导排序(从*型诱导到L型、从L型诱导到S型)
   // 调用之前应将*型按要求放入SA中
   inline void induced_sort(int* S, int* SA, int* type, int* bucket, int* lbucket, int* sbucket, int n, int SIGMA) {
      // 诱导L型
      for (int i = 1; i <= n; i++)
         if (SA[i] > 1 && type[SA[i] - 1] == L_TYPE)
            SA[lbucket[S[SA[i] - 1]]++] = SA[i] - 1;
      // 诱导S型
      for (int i = n; i >= 1; i--)
         if (SA[i] > 1 && type[SA[i] - 1] == S_TYPE)
            SA[sbucket[S[SA[i] - 1]]--] = SA[i] - 1;
   }

   // SA-IS主体
   // S是输入字符串,length是字符串的长度,SIGMA是字符集的大小
   int* sais(int* S, int length, int SIGMA) {
      int n = length;
      int* type = new int[n + 5];
      int* name = new int[n + 5];
      int* SA = new int[n + 5];
      int* bucket = new int[SIGMA + 5]; //每个字符的桶
      int* lbucket = new int[SIGMA + 5]; //每个字符的L型桶的起始位置
      int* sbucket = new int[SIGMA + 5]; // 每个字符的S型桶的起始位置
      // 初始化每个桶
      memset(bucket, 0, sizeof(int) * (SIGMA + 5));
      for (int i = 1; i <= n; i++)
         bucket[S[i]]++;
      for (int i = 0; i <= SIGMA; i++) {
         // 后缀类型
         if (i == 0) {
            bucket[i] = bucket[i];
            lbucket[i] = 1;
         }
         else {
            bucket[i] += bucket[i - 1];
            lbucket[i] = bucket[i - 1] + 1;
         }
         sbucket[i] = bucket[i];
      }

      // 确定后缀类型(利用引理2.1)
      type[n] = S_TYPE;
      for (int i = n - 1; i >= 1; i--) {
         if (S[i] < S[i + 1])
            type[i] = S_TYPE;
         else if (S[i] > S[i + 1])
            type[i] = L_TYPE;
         else
            type[i] = type[i + 1];
      }

      // 寻找每个LMS子串
      int cnt = 0;
      int* position = new int[n + 5];
      for (int i = 1; i <= n; i++)
         if (is_lms_char(type, i)) position[++cnt] = i;
      // 对LMS子串进行排序
      for (int i = 1; i <= cnt; i++)
         SA[sbucket[S[position[i]]]--] = position[i];
      induced_sort(S, SA, type, bucket, lbucket, sbucket, n, SIGMA);

      // 为每个LMS子串命名
      fill(name, name + n + 3, -1);
      int lastx = 1, namecnt = 1; //上一次处理的LMS子串与名称的计数
      bool flag = false; //这里顺便记录是否有重复的字符
      for (int i = 2; i <= n; i++) {
         int x = SA[i];
         if (is_lms_char(type, x)) {
            if (lastx >= 0 && !equal_substring(S, x, lastx, type))
               namecnt++;
            // 因为只有相同的LMS子串才会有同样的名称
            if (lastx >= 0 && namecnt == name[lastx]) flag = true;
            name[x] = namecnt;
            lastx = x;
         }
      } // for
      name[n] = 0;

      // 生成S1
      int* S1 = new int[cnt + 5];
      int pos = 0;
      for (int i = 1; i <= n; i++)
         if (name[i] >= 0) S1[++pos] = name[i];
      int* SA1;
      if (!flag) {
         // 直接计算SA1
         SA1 = new int[cnt + 5];
         for (int i = 1; i <= cnt; i++)
            SA1[S1[i] + 1] = i;
         SA1 = sais(S1, cnt, namecnt); // 递归计算SA1
      }
      else
         SA1 = sais(S1, cnt, namecnt); // 递归计算SA1

      // 从SA1诱导到SA
      for (int i = 0; i <= SIGMA; i++) {
         if (i == 0)
            lbucket[i] = 1;
         else
            lbucket[i] = bucket[i - 1] + 1;
         sbucket[i] = bucket[i];
      }
      fill(SA, SA + n + 3, 1);
      for (int i = cnt; i >= 1; i--) // 这里是逆序扫描SA1,因为SA中S型桶是倒序的
         SA[sbucket[S[position[SA1[i]]]]] = position[SA1[i]];
      induced_sort(S, SA, type, bucket, lbucket, sbucket, n, SIGMA);
      delete[] S1;
      delete[] SA1;
      delete[] bucket;
      delete[] lbucket;
      delete[] sbucket;
      delete[] position;
      delete[] type;
      delete[] name;
      return SA;
   }

   void build() {
      ss[0] = ss[n + 2] = -1;
      ss[n + 1] = 0;
      int SIGMA = 0;
      for (int i = 1; i <= n; ++i)
         SIGMA = max(SIGMA, ss[i]);
      int* sa = sais(ss, n + 1, SIGMA);
      for (int i = 2; i <= n + 1; ++i)
         rk[sa[i]] = i;
      delete[] sa;
      for (int i = 1; i <= n; ++i)
         rl[rk[i]] = i;
      for (int i = 1, len = 0; i <= n; ++i) {
         if (len)--len;
         while (i + len <= n && rl[rk[i] - 1] + len <= n
            && ss[i + len] == ss[rl[rk[i] - 1] + len])
            ++len;
         lcp[rk[i]] = len;
      }
   }

   ll calc() {
      ll Ans = 0, now = 0;
      vector<pair<ll, ll>> stk;
      for (int i = 1; i <= n; ++i) {
         // cout lcp[i] << '\n';
         ll len = 1;
         while (!stk.empty() && stk.back().first >= lcp[i]) {
            len += stk.back().second;
            now = stk.back().first * stk.back().second;
            stk.pop_back();
         }
         stk.push_back({ lcp[i], len });
         now = lcp[i] * len;
         Ans += now;
      }
      return Ans + 2 * (long long)(n + 1) * n / 2;
   }
} sa;

#undef L_TYPE
#undef R_TYPE

void solve() {
   int n;
   cin >> n;
   vector<int> v(n);
   for (int i = 0; i < n; ++i)
      cin >> v[i];
   sa.init(v);
   sa.build();
   ll x = sa.calc();
   ll y = n;
   ll g = gcd(x, y);
   cerr << x << ' ' << y << '\n';
   cout << x / g << " " << y / g << '\n';
}

signed main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   solve();
   return 0;
}