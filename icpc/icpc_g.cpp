
/*
  Code by: linvg
  Created: 28.10.2024 15:46:09
*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e5 + 7;

int mp[N], oneAfterPos[N], pref[N];
char a[N];

void solve()
{
   int n;
   scanf("%lld", &n);
   scanf("%s", a);
   vector<int> zero;
   for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i];
      if (a[i] != '1') {
         zero.push_back(i);
         pref[i + 1]++;
      }
      mp[sz(zero)] = i;
   }
   oneAfterPos[n] = n;
   int ans = n - sz(zero);
   for (int i = n - 1; i >= 0; --i) {
      if (a[i] == '1') {
         oneAfterPos[i] = i;
      } else {
         oneAfterPos[i] = oneAfterPos[i + 1];
      }
   }
   if (zero.empty()) {
      printf("%lld\n", ans);
      return;
   }
   for (int i = 0; i <= sz(zero) / 2; ++i) {
      int one = 0;
      int cur = oneAfterPos[zero[i]];
      while (true) {
         if (pref[cur] + pref[zero[i] + 1] > pref[n]) break;
         one += 1;
         cur = oneAfterPos[mp[pref[cur] + pref[zero[i] + 1]]];
      }
      if (one > 0) {
         ans = max(ans, pref[zero[i] + 1] * (one + 1) + one);
      }
   }
   printf("%lld\n", ans);
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // freopen("template.inp", "r", stdin);
   // freopen("template.out", "w", stdout);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   // clock_t time = clock();
   // fill(mp, mp + N, -1);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   // cerr << "Run Time : " << (double)(clock() - time) / CLOCKS_PER_SEC << '\n';
   return 0;
}