#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "template";
// Số test kiểm tra
const int NTEST = 1000;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
   assert(l <= h);
   return l + rd() * 1LL * rd() % (h - l + 1);
}

int main()
{
   srand(time(NULL));
   for (int iTest = 0; iTest < NTEST; iTest++)
   {
      // string fileName = NAME + "(" + to_string(iTest) + ").inp";
      // ofstream inp((fileName).c_str());
      ofstream inp((NAME + ".inp").c_str());

      int t = rand() % 100 + 1;

      inp << t << '\n';

      for (int k = 0; k < t; ++k) {
         // Code phần sinh test ở đây
         int n = rand() % 1000 + 5;
         inp << n << '\n';
         
         int a = rand() % (n - 3) + 1;
         a = n - a;
         int pre = 100000;
         for (int i = 0; i < a; ++i) {
            int x = pre - (rand() % 100 + 1);
            inp << x << ' ';
            pre = x;
         }
         for (int i = a; i < n; ++i) {
            int x = pre + (rand() % 100 + 1);
            inp << x << ' ';
            pre = x;
         }
      }

      // Code phần sinh test ở đây
      inp.close();
      // Nếu dùng Linux thì "./" + Tên chương trình
      system((NAME + ".exe").c_str());
      system((NAME + "_trau.exe").c_str());
      // Nếu dùng linux thì thay fc bằng diff
      if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
      {
         cout << "Test " << iTest << ": WRONG!\n";
         return 0;
      }
      cout << "Test " << iTest << ": CORRECT!\n";
   }
   return 0;
}