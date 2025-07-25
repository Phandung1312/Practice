#include <bits/stdc++.h>
// #include "../../debug.h"

using namespace std;
#define int long long

void process(vector<vector<int>> &casisnos, int n, int k)
{
    sort(casisnos.begin(), casisnos.end(), [](const vector<int> &a, const vector<int> &b)
         {
        if(a[2] != b[2] ){
            return a[2] > b[2];
        }
        return a[0] > b[0]; });

    vector<pair<int, int>> a;
    a.push_back({casisnos[0][2], casisnos[0][0]});
    // DBG(a.back().first);
    // DBG(a.back().second);
    for (int i = 1; i < n; i++)
    {
        if (casisnos[i][2] == a.back().first)
        {
            if (casisnos[i][0] < a.back().second)
            {
                a.back().second = casisnos[i][0];
            }
        }
        else
        {
            a.push_back({casisnos[i][2], casisnos[i][0]});
        }
    }

    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << "[" << a[i].first << "," << a[i].second << "]";
    // }
    // cout << endl;
    int result = k;
    // DBG(result);
    int r = a.size() - 1;
    while(r >= 0) {
    // Tìm index đầu tiên thỏa mãn result >= a[i].first
    auto it1 = lower_bound(a.begin(), a.begin() + r + 1, result, 
        [](const pair<int, int>& p, int val) { return p.first > val; });
    
    if (it1 != a.begin() + r + 1) {
        // Nếu tìm thấy, kết thúc
        cout << result << endl;
        return;
    }
    
    // Tìm index đầu tiên thỏa mãn result >= a[i].second
    int bestIdx = -1;
    for (int i = 0; i <= r; i++) {
        if (result >= a[i].second) {
            bestIdx = i;
            break;
        }
    }
    
    if (bestIdx == -1) {
        // Không tìm thấy phần tử nào thỏa mãn
        cout << result << endl;
        return;
    }
    
    // Cập nhật giá trị và tiếp tục
    result = a[bestIdx].first;
    r = bestIdx - 1;
}

    cout << result << endl;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> casinos(n, vector<int>(3));
        for (int i = 0; i < n; i++)
        {
            cin >> casinos[i][0] >> casinos[i][1] >> casinos[i][2];
        }
        process(casinos, n, k);
    }
    return 0;
}