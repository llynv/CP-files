#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "template";
// Số test kiểm tra
const int NTEST = 10000;
// Thời gian giới hạn (milliseconds)
const int TIME_LIMIT = 1000;

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

      long long n = 2000;
      inp << n << '\n';
      for (long long i = 0; i < n; ++i) inp << rd() % (long long) (1e18) + 1 << ' ';
      long long q = rd() % 200000 + 1;
      inp << '\n' << q << '\n';
      for (long long i = 0; i < q; ++i) {
         long long l = rd() % n + 1, r = rd() % n + 1, k = rd() % (long long) (1e18) + 1;
         if (l > r) swap(l, r);
         inp << l << ' ' << r << ' ' << k << '\n';
      }

      auto start = chrono::steady_clock::now();
      // Nếu dùng Linux thì "./" + Tên chương trình
      system((NAME + ".exe").c_str());
      system((NAME + "_trau.exe").c_str());

      // system((NAME + "_trau.exe").c_str());
      // Nếu dùng linux thì thay fc bằng diff
      cout << "Test " << iTest << '\n';
      if (system(("fc " + NAME + ".ans " + NAME + ".out").c_str()) != 0)
      {
         cout << "Test " << iTest << ": WRONG!\n";
         return 0;
      }
   }
   return 0;
}