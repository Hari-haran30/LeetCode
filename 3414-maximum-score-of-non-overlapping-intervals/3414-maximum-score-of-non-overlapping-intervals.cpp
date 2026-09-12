class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long, 3>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2]};
        }
        sort(a.begin(), a.end());
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> ans(n + 1, vector<vector<int>>(5));
        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (a[m][0] > a[i][1]) r = m;
                else l = m + 1;
            }
            nxt[i] = l;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i + 1][k];
                ans[i][k] = ans[i + 1][k];
                int j = nxt[i];
                long long takeScore = a[i][2] + dp[j][k - 1];
                vector<int> takeAns = ans[j][k - 1];
                takeAns.push_back((int)a[i][2]);
                takeAns.pop_back();
            }
        }
        vector<vector<long long>> best(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> res(n + 1, vector<vector<int>>(5));
        vector<array<long long, 4>> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (b[m][0] > b[i][1]) r = m;
                else l = m + 1;
            }
            nxt[i] = l;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                best[i][k] = best[i + 1][k];
                res[i][k] = res[i + 1][k];
                int j = nxt[i];
                long long score = b[i][2] + best[j][k - 1];
                vector<int> cur = res[j][k - 1];
                cur.push_back((int)b[i][3]);
                sort(cur.begin(), cur.end());
                if (score > best[i][k] ||
                    (score == best[i][k] && cur < res[i][k])) {
                    best[i][k] = score;
                    res[i][k] = cur;
                }
            }
        }
        return res[0][4];
    }
};