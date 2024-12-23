#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "template";
// Số test kiểm tra
const int NTEST = 1000;
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

      int n = 500000;
      inp << n << '\n';
      for (int i = 0; i < n; i++)
      {
         inp << rand() % 2;
      }
      // Code phần sinh test ở đây
      inp.close();

      auto start = chrono::steady_clock::now();
      // Nếu dùng Linux thì "./" + Tên chương trình
      system((NAME + ".exe").c_str());
      auto end = chrono::steady_clock::now();
      auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();

      if (elapsed > TIME_LIMIT) {
         cout << "Test " << iTest << ": TIME LIMIT EXCEEDED!\n";
         return 0;
      }

      // system((NAME + "_trau.exe").c_str());
      // Nếu dùng linux thì thay fc bằng diff
      if (system(("fc " + NAME + ".out " + NAME + ".out").c_str()) != 0)
      {
         cout << "Test " << iTest << ": WRONG!\n";
         return 0;
      }
      cout << "Test " << iTest << ": CORRECT! (" << elapsed << " ms)\n";
   }
   return 0;
}