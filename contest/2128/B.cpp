#include <bits/stdc++.h>
using namespace std;

bool is_good(const vector<int>& v) {
    int n = v.size();
    for (int i = 0; i + 4 < n; ++i) {
        if ((v[i] < v[i + 1] && v[i + 1] < v[i + 2] && v[i + 2] < v[i + 3] && v[i + 3] < v[i + 4]) ||
            (v[i] > v[i + 1] && v[i + 1] > v[i + 2] && v[i + 2] > v[i + 3]) && v[i + 3] > v[i + 4])
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<int> dq(n);
        for (int i = 0; i < n; ++i)
            cin >> dq[i];
        
        vector<int> q;
        string answer;

        // Strategy: build increasing or decreasing sequence while keeping it "good"
        int last = -1; // q is empty

        while (!dq.empty()) {
            int left = dq.front();
            int right = dq.back();

            // Try both choices and pick the one that keeps q "good"
            bool pick_left = false;

            if (q.empty()) {
                pick_left = (left < right);
            } else {
                // Try adding left
                q.push_back(left);
                if (is_good(q)) {
                    pick_left = true;
                    q.pop_back();
                } else {
                    q.pop_back();
                }
            }

            if (pick_left) {
                answer += 'L';
                q.push_back(dq.front());
                dq.pop_front();
            } else {
                answer += 'R';
                q.push_back(dq.back());
                dq.pop_back();
            }
        }

        cout << answer << '\n';
    }

    return 0;
}