#include<bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin >> n;
   vector<int>a(maxN + 7, 0), cntMul(maxN + 7, 0), ans(maxN + 7, 0);
   for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      a[x]++;
   }
   for (int i = 1; i <= maxN; i++)
   {
      for (int j = i; j <= maxN; j += i)
      {
         cntMul[i] += a[j];
      }
   }
   auto cntDiv = [&](int x) {
      int numDiv = 0;
      for (int i = 1; i * i <= x; i++)
      {
         if (x % i == 0)
         {
            if (i * i != x) numDiv++;
            numDiv++;
         }
      }
      return numDiv;
      };
   for (int i = maxN; i >= 1; i--)
   {
      if (cntMul[i] == 0) continue;
      ans[i] = cntMul[i] * (cntMul[i] - 1) / (int)2;
      for (int j = 2 * i; j <= maxN; j += i)
      {
         ans[i] -= ans[j];
      }
   }
   int kq = 0;
   for (int i = 1; i <= maxN; i++)
   {
      if (ans[i] > 0 && cntDiv(i) == 4) kq += ans[i];
   }
   cout << kq;
}