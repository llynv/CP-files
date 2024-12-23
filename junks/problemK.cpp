#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 4e6 + 7;
int choose[N], team[N];

int fw[N];

void add(int i, int v) {
   for (; i < N; i += i & -i) fw[i] += v;
}

int sum(int i) {
   int res = 0;
   for (; i > 0; i -= i & -i) res += fw[i];
   return res;
}

int select[N];

void solve() {
   int n;
   scanf("%d", &n);

   for (int i = 1; i <= n; i += 2) {
      scanf("%d", &choose[i]);
   }
   for (int i = 2; i <= n; i += 2) {
      scanf("%d", &choose[i]);
   }

   for (int i = 1; i <= n; i++) {
      add(i, 1);
   }

   for (int i = 1; i <= n; i++) {
      int l = 1, r = n;
      while (l < r) {
         int m = (l + r) / 2;
         if (sum(m) >= choose[i]) {
            r = m;
         } else {
            l = m + 1;
         }
      }
      team[i] = l;
      add(l, -1);
   }
   
   for (int i = 1; i <= n; i += 2) printf("%d ", team[i]);
   printf("\n");
   for (int i = 2; i <= n; i += 2) printf("%d ", team[i]);
}
int32_t main() {
   clock_t start = clock();
   solve();
   fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}