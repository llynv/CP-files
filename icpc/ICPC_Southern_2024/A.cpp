#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

// Fenwick Tree 3D implementation
class FenwickTree3D
{
public:
   int n;
   vector<vector<vector<int>>> bit;

   FenwickTree3D(int size) : n(size), bit(size + 1, vector<vector<int>>(size + 1, vector<int>(size + 1, 0))) {}

   // update the value of the element at (x, y, z) by assign it to val
   void update(int x, int y, int z, int val)
   {
      int current_val = query(x, y, z) - query(x - 1, y, z) - query(x, y - 1, z) - query(x, y, z - 1) + query(x - 1, y - 1, z) + query(x - 1, y, z - 1) + query(x, y - 1, z - 1) - query(x - 1, y - 1, z - 1);
      int delta = val - current_val;
      for (int i = x; i <= n; i += i & -i)
      {
         for (int j = y; j <= n; j += j & -j)
         {
            for (int k = z; k <= n; k += k & -k)
            {
               bit[i][j][k] += delta;
            }
         }
      }
   }

   int query(int x, int y, int z)
   {
      int sum = 0;
      for (int i = x; i > 0; i -= i & -i)
      {
         for (int j = y; j > 0; j -= j & -j)
         {
            for (int k = z; k > 0; k -= k & -k)
            {
               sum += bit[i][j][k];
            }
         }
      }
      return sum;
   }

   int range_query(int x1, int y1, int z1, int x2, int y2, int z2)
   {
      return query(x2, y2, z2) - query(x1 - 1, y2, z2) - query(x2, y1 - 1, z2) - query(x2, y2, z1 - 1) + query(x1 - 1, y1 - 1, z2) + query(x1 - 1, y2, z1 - 1) + query(x2, y1 - 1, z1 - 1) - query(x1 - 1, y1 - 1, z1 - 1);
   }
};

void solve()
{
   int n, q;
   cin >> n >> q;

   map<array<int, 3>, int> mp;
   FenwickTree3D fenwickTree(n);

   while (q-- > 0)
   {
      string s;
      cin >> s;
      if (s == "UPDATE")
      {
         int x, y, z, val;
         cin >> x >> y >> z >> val;
         fenwickTree.update(x, y, z, val);
      }
      else
      {
         int x1, y1, z1, x2, y2, z2;
         cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
         int ans = fenwickTree.range_query(x1, y1, z1, x2, y2, z2);

         cout << ans << "\n";
      }
   }
}
int32_t main()
{
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t;
   cin >> t;
   while (t-- > 0)
   {
      solve();
   }
}