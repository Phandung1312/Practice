
#include <bits/stdc++.h>
using namespace std;

// ==================== TYPE DEFINITIONS ====================
// Basic types
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

// Vector shortcuts
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// Set shortcuts
typedef set<int> si;
typedef set<ll> sll;
typedef set<string> ss;
typedef multiset<int> msi;
typedef multiset<ll> msll;

// Map shortcuts
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<string, int> msi_str;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;

// ==================== CONSTANTS ====================
const int INF = 1e9 + 7;
const ll LINF = 1e18;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

// Directions for grid problems
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// ==================== MACROS ====================
// Loop shortcuts
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORN(i, n) for(int i = 0; i < (n); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define FORRN(i, n) for(int i = (n-1); i >= 0; i--)
#define FOREACH(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define FOREACHR(it, v) for(auto it = v.rbegin(); it != v.rend(); it++)

// Range-based for loop shortcuts
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())
#define len(v) ((int)v.size())

// Container operations
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define era erase
#define clr clear

// Math shortcuts
#define gcd __gcd
#define lcm(a, b) ((a) * (b) / gcd(a, b))
#define sqr(x) ((x) * (x))
#define cube(x) ((x) * (x) * (x))

// Bit operations
#define bit(x, i) (((x) >> (i)) & 1)
#define setbit(x, i) ((x) | (1LL << (i)))
#define clearbit(x, i) ((x) & (~(1LL << (i))))
#define flipbit(x, i) ((x) ^ (1LL << (i)))
#define popcount __builtin_popcountll

// Min/Max shortcuts
#define maxi(a, b) a = max(a, b)
#define mini(a, b) a = min(a, b)

// Input/Output shortcuts
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define sp ' '

void process(vll& b, int n){
    ll min = b[0];
    FOR(i, 1, n){
        ll a = b[i];
        if(a <= min) {
            min = a;
            continue;
        };
        if(min == 1 || (a / (min)) > 1){
            cout << "NO" << endl;
            return;
        } 
    }
    cout << "YES" << endl;
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vll b(n);
        FORN(i, n){
            cin >> b[i];
        }
        process(b, n);
    }
    return 0;
}


