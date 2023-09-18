#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename T>
void DBVT (T (&arr)) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << "Vector[" << i+1 << "] = " << arr[i] << "\n";
    }
}

template<typename T, int N>
void DBARR (T (&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cout << "Array[" << i+1 << "] = " << arr[i] << "\n";
    }
}

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve()
{
    string s;
    cin >> s;
    int cnt['z'+1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i]]++;
    }
    vector<char> vt;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (cnt[i] % 2 != 0) {
            vt.emplace_back(char(i));
        }
    }
    // DBVT(vt);
    if (vt.size() <= 1) {
        cout << 0 << "\n";
        return;
    }
    int res = 0;
    int i = 0;
    sort(vt.begin(), vt.end());
    if (vt.size() % 2 == 0) {
        
    }
    cout << res << "\n";
}

