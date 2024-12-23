#include <bits/stdc++.h>
#define int long long
#define sz(x) ((x).size())
using namespace std;

unordered_map<char, int> idx;

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(NULL); cout.tie(NULL);

   idx['R'] = 0, idx['P'] = 1, idx['S'] = 2;

   int t;
   cin >> t;
   while (t--) {
      string s;
      cin >> s;
      vector<array<int, 3>> cnt(sz(s) + 1);

      int n = s.size();
      for (int i = 1; i <= n; ++i) {
         cnt[i] = cnt[i-1];
         cnt[i][idx[s[i - 1]]]++;
      }

      int final_point = 0, max_k = 0;

      for (int k = 2; k <= n; ++k) {
         int point = 0;
         for (int i = 0; i <= n; i += k) {
            int max_point = 0;
            for (int j = 0; j < 3; ++j) max_point = max(max_point, cnt[min(n, i + k)][j] - cnt[i][j]);
            point += max_point;
         }
         if (point >= final_point) {
            final_point = point;
            max_k = k;
         }
      }
      cout << max_k << "\n";
   }
}
