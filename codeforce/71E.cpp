/*
  Code by: linvg
  Created: 23.09.2024 13:05:59
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

unordered_map<string, int> periodic_table_of_the_chemical_elements;

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<string> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   vector<string> b(k);
   for (int i = 0; i < k; ++i) {
      cin >> b[i];
   }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   periodic_table_of_the_chemical_elements = {
      {"H", 1},
      {"He", 2},
      {"Li", 3},
      {"Be", 4},
      {"B", 5},
      {"C", 6},
      {"N", 7},
      {"O", 8},
      {"F", 9},
      {"Ne", 10},
      {"Na", 11},
      {"Mg", 12},
      {"Al", 13},
      {"Si", 14},
      {"P", 15},
      {"S", 16},
      {"Cl", 17},
      {"Ar", 18},
      {"K", 19},
      {"Ca", 20},
      {"Sc", 21},
      {"Ti", 22},
      {"V", 23},
      {"Cr", 24},
      {"Mn", 25},
      {"Fe", 26},
      {"Co", 27},
      {"Ni", 28},
      {"Cu", 29},
      {"Zn", 30},
      {"Ga", 31},
      {"Ge", 32},
      {"As", 33},
      {"Se", 34},
      {"Br", 35},
      {"Kr", 36},
      {"Rb", 37},
      {"Sr", 38},
      {"Y", 39},
      {"Zr", 40},
      {"Nb", 41},
      {"Mo", 42},
      {"Tc", 43},
      {"Ru", 44},
      {"Rh", 45},
      {"Pd", 46},
      {"Ag", 47},
      {"Cd", 48},
      {"In", 49},
      {"Sn", 50},
      {"Sb", 51},
      {"Te", 52},
      {"I", 53},
      {"Xe", 54},
      {"Cs", 55},
      {"Ba", 56},
      {"La", 57},
      {"Ce", 58},
      {"Pr", 59},
      {"Nd", 60},
      {"Pm", 61},
      {"Sm", 62},
      {"Eu", 63},
      {"Gd", 64},
      {"Tb", 65},
      {"Dy", 66},
      {"Ho", 67},
      {"Er", 68},
      {"Tm", 69},
      {"Yb", 70},
      {"Lu", 71},
      {"Hf", 72},
      {"Ta", 73},
      {"W", 74},
      {"Re", 75},
      {"Os", 76},
      {"Ir", 77},
      {"Pt", 78},
      {"Au", 79},
      {"Hg", 80},
      {"Tl", 81},
      {"Pb", 82},
      {"Bi", 83},
      {"Po", 84},
      {"At", 85},
      {"Rn", 86},
      {"Fr", 87},
      {"Ra", 88},
      {"Ac", 89},
      {"Th", 90},
      {"Pa", 91},
      {"U", 92},
      {"Np", 93},
      {"Pu", 94},
      {"Am", 95},
      {"Cm", 96},
      {"Bk", 97},
      {"Cf", 98},
      {"Es", 99},
   };
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}