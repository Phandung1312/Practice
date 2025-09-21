
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

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORN(i, n) for (int i = 0; i < (n); i++)
#define FORE(i, n) for (int i = 1; i <= (n); i++)
#define FORR(i, a, b) for (int i = (a); i >= (b); i--)
#define FORRN(i, n) for (int i = (n - 1); i >= 0; i--)
#define FORRE(i, n) for (int i = (n); i >= 1; i--)
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
const long long MAXX = 2e18;
const long long MINX = -2e18;

#define DEBUG 0

#if DEBUG
#define del cout << '\n'
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
template <class X, class Y>
ostream &operator<<(ostream &os, pair<X, Y> const &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, Container const &x)
{
    int i = 0, n = (int)distance(x.begin(), x.end());
    os << "{ ";
    for (const auto &y : x)
        os << y << (++i < n ? ", " : "");
    return os << " }";
}
template <typename... Args>
void _debug(const char *names, Args &&...args)
{
    string_view s(names);
    cout << "{ ";
    size_t i = 0, cnt = 0, n = sizeof...(args);
    auto next = [&]()
    {
        while (i < s.size() && (s[i] == ' ' || s[i] == ','))
            ++i;
        size_t st = i;
        while (i < s.size() && s[i] != ',')
            ++i;
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
vi h;
vi w;
void caculSum(vi &a, int start, int end, int trans)
{
    vector<pair<int, int>> seq;
    vi indexs;
    vector<vector<pii>> maxIndexs;
    for (int i = start; i * trans <= end * trans; i += trans)
    {
        auto firstIt = lower_bound(seq.begin(), seq.end(), h[i], [](const pii &p, const int &val)
                                   { return p.first < val; });
        int k = (firstIt - seq.begin());
        a[i] = k > 0 ? w[i] + a[indexs[k - 1]] : w[i];
        auto secondIt = lower_bound(firstIt, seq.end(), a[i], [](const pii &p, const int &val)
                                    { return p.second < val; });
        int r = secondIt - seq.begin();
        if (r - k > 1)
        {
            seq.erase(seq.begin() + k + 1, seq.begin() + r);
            indexs.erase(indexs.begin() + k + 1, indexs.begin() + r);
        }
        if (firstIt == seq.end())
        {
            seq.push_back({h[i], a[i]});
            indexs.push_back(i);
        }
        else
        {
            if (firstIt == secondIt)
            {
                seq.insert(firstIt, {h[i], a[i]});
                indexs.insert(indexs.begin() + k, i);
            }
            else
            {
                *firstIt = {h[i], a[i]};
                indexs[k] = i;
            }
        }
    }
}
void process(int Case)
{
    vi inc(n, 0);
    vi dec(n, 0);
    caculSum(inc, 0, n - 1, 1);
    caculSum(dec, n - 1, 0, -1);
    debug(inc);
    debug(dec);
    int result = 0;
    int maxV = 0;
    int minV = 0;
    FORN(i, n)
    {
        maxi(maxV, inc[i]);
        maxi(minV, dec[i]);
    }
    cout << "Case " << Case << ". ";
    if (maxV >= minV)
    {
        cout << "Increasing (" << maxV << "). ";
        cout << "Decreasing (" << minV << ").";
    }
    else
    {
        cout << "Decreasing (" << minV << "). ";
        cout << "Increasing (" << maxV << ").";
    }
    cout << endl;
}
int32_t main()
{
    fast_io;
    int t;
    cin >> t;
    int Case = 0;
    while (t--)
    {
        cin >> n;
        Case++;
        h.resize(n);
        w.resize(n);
        FORN(i, n)
        {
            cin >> h[i];
        }
        FORN(i, n)
        {
            cin >> w[i];
        }
        process(Case);
    }
    return 0;
}
