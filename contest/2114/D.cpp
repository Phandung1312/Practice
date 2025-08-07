
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

typedef set<int> si;
typedef set<ll> sll;
typedef set<string> ss;
typedef multiset<int> msi;
typedef multiset<ll> msll;

typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<string, int> msi_str;
typedef unordered_map<int, int> umii;
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

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, n) for (int i = 0; i < (n); i++)
#define FORR(i, a, b) for (int i = (a); i >= (b); i--)
#define FORRN(i, n) for (int i = (n - 1); i >= 0; i--)
#define FOREACH(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define FOREACHR(it, v) for (auto it = v.rbegin(); it != v.rend(); it++)

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

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl '\n'
#define sp ' '

#define int long long
#include "../../debug.h"

int process(vector<pair<int, int>> &monsters, int n)
{
    if (n == 1)
        return 1;
    sort(monsters.begin(), monsters.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first < b.first; });
    pair<int, int> leftFirst = {monsters[0].first, monsters[0].second};
    pair<int, int> leftSecond = {monsters[1].first, monsters[1].second};

    pair<int, int> rightFirst = {monsters[n - 1].first, monsters[n - 1].second};
    pair<int, int> rightSecond = {monsters[n - 2].first, monsters[n - 2].second};

    sort(monsters.begin(), monsters.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    pair<int, int> topFirst = {monsters[0].first, monsters[0].second};
    pair<int, int> topSecond = {monsters[1].first, monsters[1].second};

    pair<int, int> downFirst = {monsters[n - 1].first, monsters[n - 1].second};
    pair<int, int> downSecond = {monsters[n - 2].first, monsters[n - 2].second};

    debug(leftFirst, leftSecond, rightFirst, rightSecond, topFirst, topSecond, downFirst, downSecond);

    pair<int, int> topLeftCorF = {leftFirst.first < topFirst.first ? leftFirst.first : topFirst.first,
                                  leftFirst.second < topFirst.second ? leftFirst.second : topFirst.second};
    pair<int, int> topLeftCorS = {leftSecond.first < topSecond.first ? leftSecond.first : topSecond.first,
                                  leftSecond.second < topSecond.second ? leftSecond.second : topSecond.second};

    pair<int, int> downRightCorF = {downFirst.first > rightFirst.first ? downFirst.first : rightFirst.first,
                                    downFirst.second > rightFirst.second ? downFirst.second : rightFirst.second};
    pair<int, int> downRightCorS = {downSecond.first > rightSecond.first ? downSecond.first : rightSecond.first,
                                    downSecond.second > rightSecond.second ? downSecond.second : downFirst.second};
    
                                   
    return 2;
}

int32_t main()
{
    fast_io;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> monsters(n);
        FORN(i, n)
        {
            cin >> monsters[i].first >> monsters[i].second;
        }
        process(monsters, n);
    }
    return 0;
}
