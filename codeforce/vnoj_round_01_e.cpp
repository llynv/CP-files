#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define loop_up(i,a,b) for( ll i = a ; i <= b ; i ++ )
#define loop_down(i,a,b) for( ll i = b ; i >= a ; i -- )
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int MOD = 1e9 + 7;
int n;
struct matrix
{
   int val[2][2];

} a, c;
matrix operator*(matrix a, matrix b)
{
   matrix tmp;
   loop_up(i, 0, 1)
   {
      loop_up(j, 0, 1)
      {
         tmp.val[i][j] = 0;
         loop_up(k, 0, 1)
         {
            tmp.val[i][j] += a.val[i][k] * b.val[k][j];
            tmp.val[i][j] %= MOD;
         }
      }
   }
   return tmp;
}
matrix lt(matrix x, int n)
{
   if (n == 1) return x;
   matrix tmp = lt(x, n / 2);
   tmp = tmp * tmp;
   if (n % 2 == 1) tmp = tmp * x;
   return tmp;
}
int main()
{
   int t;
   cin >> t;
   while (t--) {
      cin >> n;

      if (n == 0)
      {
         cout << 0;
         return 0;
      }
      a.val[0][0] = 1;
      a.val[0][1] = 1;
      a.val[1][0] = 1;
      a.val[1][1] = 0;
      c = lt(a, n);
      cout << (c.val[0][0] + c.val[0][1]) % MOD << "\n";
   }
}
