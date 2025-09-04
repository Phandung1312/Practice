
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long, long long> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

typedef vector<long long> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

typedef set<long long> si;
typedef set<ll> sll;
typedef set<string> ss;
typedef multiset<long long> msi;
typedef multiset<ll> msll;

typedef map<long long, long long> mii;
typedef map<ll, ll> mll;
typedef map<string, long long> msi_str;
typedef unordered_map<long long, long long> umii;
typedef unordered_map<ll, ll> umll;

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORN(i, n) for(int i = 0; i < (n); i++)
#define FORE(i, n) for(int i = 1; i <= (n); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define FORRN(i, n) for(int i = (n-1); i >= 0; i--)
#define FORRE(i, n) for(int i = (n); i >= 1; i--)
#define FOREACH(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define FOREACHR(it, v) for(auto it = v.rbegin(); it != v.rend(); it++)

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())
#define len(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define era erase
#define clr clear

#define gcd __gcd
#define lcm(a, b) ((a) * (b) / gcd(a, b))
#define sqr(x) ((x) * (x))
#define cube(x) ((x) * (x) * (x))

#define maxi(a, b) a = max(a, b)
#define mini(a, b) a = min(a, b)

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define sp ' '

#define int long long
const long long MAXX = 2e18;
const long long MINX = -2e18;


#define DEBUG 1
 
#if DEBUG
#define del cout << '\n'
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    int i = 0, n = (int)distance(x.begin(), x.end());
    os << "{ ";
    for (const auto& y : x) os << y << (++i < n ? ", " : "");
    return os << " }";
}
template <typename... Args>
void _debug(const char* names, Args&&... args) {
    string_view s(names);
    cout << "{ ";
    size_t i = 0, cnt = 0, n = sizeof...(args);
    auto next = [&]() {
        while (i < s.size() && (s[i] == ' ' || s[i] == ',')) ++i;
        size_t st = i;
        while (i < s.size() && s[i] != ',') ++i;
        return s.substr(st, i - st);
    };
    ((cout << next() << ": " << args << (++cnt < n ? ", " : "")), ...);
    cout << " }" << '\n';
}
#else
#define del
#define debug(...)
#endif


int n;
int m;
vi x;

int point(int a, int b){
    if(a * b < 0) return 1;
    if(a*b && abs(a) > abs(b)) return 1;
    return 0;
}
void process(){
    vi b;
    unordered_set<int> S;
    FORN(i, n){
        S.insert(x[i]);
    }
    FORE(i, n){
        if(!S.count(i)) b.pb(i);
        if(!S.count(-i)) b.pb(-i);
    }

    vector<vector<int>> dp(1 << n, vector<int>(n + 1 , 0));
    dp[0][0] = 1;
    // debug(S, b);
    FORN(mask, 1 << n){
        int i = __builtin_popcount((unsigned) mask);    
        FORN(s, i + 1){
            if(dp[mask][s]){
                FORN(j, n) if( !((mask >> j) & 1) ){
                    int next = mask | ( 1 << j);
                    int p = point(x[i], b[j]);
                    dp[next][s + p] += dp[mask][s];
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][m] << endl;
}
int32_t main() {
    fast_io;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        x.resize(n);
        FORN(i, n){
            cin >> x[i];
        }
        process();
    }
    return 0;
}
