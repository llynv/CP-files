#include <bits/stdc++.h>
using namespace std;

#define LINVG
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)
#define endl "\n"
#define fill(x, y) memset(x, y, sizeof(x))
#define heapMax priority_queue<int>
#define heapMin priority_queue<int, vector<int>, greater<int>>

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LINVG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


void solve();

int32_t main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 1e18;
const int N = 111;
const int M = 7e3 + 5;
 
int dp[N][M], fpos[M], pref[M];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ans;

	for (int i = 0; i < N; ++i) {
		if (i <= 1) {
            dp[i][0] = i;
            continue;
        }
		int nxt = (i * (i - 1))/2 + 2;
 
		for (int j = 0; j < nxt; j++) {
            int sum = 0;
			for (int k = 0; k < i; k++) {
				if(sum > INF){
					sum = -1;
					break;
				}
				if(dp[i-1][j-k] == -1){
					sum = -1;
					break;
				}
				sum += dp[i-1][j-k];
			}
			sum = (sum > INF ? -1 : sum);
			dp[i][j] = sum;
		}
		pref[0] = dp[i][0] == -1;
		for (int j = 1; j < M; ++j) pref[j] = pref[j-1] + (dp[i][j] == -1);
	}

    if(dp[n][m] > -1 && k > dp[n][m]) return void (cout << -1);
        
    for(int i = n; i >= 1; --i){
        if(i == 1){
            ans.push_back(m);
            break;
        }
        for (int j = 0; j < i; ++j) {
            if(dp[i-1][m] == -1 || dp[i-1][m] >= k){
                ans.pb(j);
                break;
            }else{
                k -= dp[i-1][m];
                m--;
            }
        }
    }
        
    if(sz(ans) < n) return void (cout << -1 << endl);
    bool usd[n] = {false};
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            cnt += (!usd[j]);
            if(cnt > ans[i]){
                usd[j] = 1;
                cout << j+1 << " ";
                break;
            }
        }
    }
    cout << "\n";
}
