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
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)

string to_upper(string a)
{
   for (int i = 0; i < (int)a.size(); ++i)
      if (a[i] >= 'a' && a[i] <= 'z')
         a[i] -= 'a' - 'A';
   return a;
}
string to_lower(string a)
{
   for (int i = 0; i < (int)a.size(); ++i)
      if (a[i] >= 'A' && a[i] <= 'Z')
         a[i] += 'a' - 'A';
   return a;
}

template <class T>
T gcd(T a, T b)
{
   T r;
   while (b != 0)
   {
      r = a % b;
      a = b;
      b = r;
   }
   return a;
}
template <class T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <class T>
T sqr(T x) { return x * x; }
template <class T>
T cube(T x) { return x * x * x; }

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n, k;
   cin >> n >> k;
   
   int query = 0;
   auto ask = [&](int l, int x) -> int
   {
      query++;
      if (query > 2 * n) {
         return n + 1;
      }
      cout << "? " << l << " " << x << "\n";
      cout.flush();
      int res;
      cin >> res;
      return res;
   };

   int mx = 1;
   for (int i = 1; i <= n; ++i)
   {
      int r = ask(1, mx * i);
      while (r == n + 1 && mx <= n)
      {
         ++mx;
         r = ask(1, mx * i);
      }

      if (mx > n)
         break;
      int start = i + 1, cnt = 1;
      while (start <= n)
      {
         start = ask(start, mx * i) + 1;
         ++cnt;
      }
      if (start > n + 1)  {
         // ++mx;
         continue;
      }
      if (cnt == k)
      {
         cout << "! " << mx * i << "\n";
         cout.flush();
         int res;
         cin >> res;
         if (res == -1)
            exit(0);
         return;
      }
   }

   int r = ask(1, n);
   if (r != n + 1 && n % k == 0)
   {
      cout << "! " << k << "\n";
      cout.flush();
      int res;
      cin >> res;
      if (res == -1)
         exit(0);
      return;
   }

   cout << "! -1\n";
   cout.flush();
   int res;
   cin >> res;
   if (res == -1)
      exit(0);
}

int32_t main()
{

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}