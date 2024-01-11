#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pll pair<ll, ll>
using namespace std;
const ll MAX = 1e6 + 7;

ll n, k;
ll cnt;

struct Point
{
    ll x, y, z;
    Point(ll _x = 0, ll _y = 0, ll _z = 0)
    {
        x = _x, y = _y, z = _z;
    }

    bool operator < (Point other) const
    {
        if(z == other.z)
        {
            if(y == other.y)
            {
                return x < other.x;
            }
            return y < other.y;
        }
        return z < other.z;
    }

    bool operator == (Point other) const
    {
        return (x == other.x && y == other.y && z == other.z);
    }

    Point intersect(Point other)
    {
        if(x != 0 && x == other.x)
            return Point(x, y ^ other.y, z ^ other.z);
        else if(y != 0 && y == other.y)
            return Point(x ^ other.x, y, z ^ other.z);
        else if(z != 0 && z == other.z)
            return Point(x ^ other.x, y ^ other.y, z);
        else
            return Point(-1, -1, -1);
    }
    void print()
    {
        cout << x << " " << y << " " << z << "\n";
    }
};

vector<Point> one, two, three;

void enter()
{
    cin >> n >> k;
    fu(i, 1, k)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        Point a = Point(x, y, z);
        if(x == 0)
            one.push_back(a);
        else if(y == 0)
            two.push_back(a);
        else
            three.push_back(a);
    }
}
set<Point> s;

void prepare(vector<Point>& a, vector<Point>& b)
{
    for(Point mot : a)
    {
        for(Point hai : b)
        {
            Point inte = mot.intersect(hai);
            if(inte == Point(-1, -1, -1))
                continue;
            cnt++;
//            cout << "1. "; mot.print();
//            cout << "2. "; hai.print();
//            cout << "inte. "; inte.print();
//            cout << "\n";
//            mp[inte]++;
        }
    }
}

bool check(ll x, ll y)
{
    return x == y;
}

void solve()
{
    ll res = 0;
    res += n * k;
    prepare(one, two);
    prepare(two, three);
    prepare(one, three);
    res -= cnt;
//    cout << cnt << "\n";
    for(Point mot: one)
    {
        for(Point hai: two)
        {
            Point inte = mot.intersect(hai);
            if(inte == Point(-1, -1, -1))
                continue;
            s.insert(inte);
        }
    }

    for(Point p : s)
    {
        for(Point ba : three)
        {
//            p.print();
//            ba.print();
//            cout << "\n";
            if((p.x == ba.x && p.y == ba.y) || (p.y == ba.y && p.z == ba.z) || (p.z == ba.z && p.x == ba.x))
                res++;
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    enter();
    solve();
}