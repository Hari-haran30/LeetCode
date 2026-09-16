class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long mod = 1000000007LL;
        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        for (int i = 0; i< n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= k; i++) {
            long long sum = 0;
            for (int j = 1; j < n; j++) {
                sum = (sum + dp[j - 1][i - 1])  % mod;
                dp[j][i] = (dp[j - 1][i] + sum) % mod;
            }
        }
        return (int)dp[n - 1][k];
    }
};