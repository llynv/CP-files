#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

unsigned char a[N];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie();
   cout.tie();
   int n;
   scanf("%d", &n);
   for (int i = 0; i <= n - 1; ++i)
   {
      scanf("%hhu", a + i);
   }
   int q, l, r;
   unsigned char x, y;
   scanf("%d", &q);
   for (int i = 0; i < q; ++i) {
      scanf("%d %d %hhu %hhu", &l, &r, &x, &y);
      for (int j = l - 1; j <= r - 1; ++j) {
         if (a[j] == x) {
            a[j] = y;
         }
      }
   }
   for (int i = 0; i <= n - 1; ++i) {
      printf("%hhu ", a[i]);
   }
}
