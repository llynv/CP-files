#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;
const int MAX = 1e6 + 7;

const string li[] = {"Welcome", "Hue", "University", "of", "Sciences"};

map<string, bool> mp;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string x;
    while(cin >> x) {
        mp[x] = 1;
    }

    fu(i, 0, 4)
    {
        if(mp[li[i]] == false)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}