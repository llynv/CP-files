#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

   auto start = clock();

   unordered_map<string, double> mp;
   map<string, double> prod;
   int i = 0;
   string str;
   string v[3] = {"", "", ""};

   auto mini = [&](double &a, double b) {
      if (a > b) a = b;
   };

   while (getline(cin, str)) {
      i = 0;   
      for (auto &x : str) {
         if (x == ',') {
            i++;
            continue;
         }
         v[i] += x;
      }

      double amt = stod(v[2]);

      mp[v[0]] += amt;
      if (prod[v[1]] == 0.0) {
         prod[v[1]] = amt;
      } else {
         mini(prod[v[1]], amt);
      }

      v[0] = v[1] = v[2] = "";
   }
   pair<string, double> res = {mp.begin()->first, mp.begin()->second};
   for (auto &x : mp) {
      if (x.second < res.second) {
         res = x;
      }
   }

   cout << fixed << setprecision(2);

   cout << res.first << " " << res.second << "\n";

   vector<pair<double, string>> v1;
   for (auto &x : prod) {
      cout << x.first << " " << x.second << "\n";
   }
   // sort(v1.begin(), v1.end());
   // for (int i = 0; i < 5; ++i) {
   //    cout << v1[i].second << " " << v1[i].first << "\n";
   // }

   cerr << "Time: " << (clock() - start) / (double)CLOCKS_PER_SEC << '\n';
}