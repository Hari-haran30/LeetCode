class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1'000'000'007;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        vector<int> last(26, 0);
        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';
            dp[i] = (2 * dp[i - 1]) % MOD;
            dp[i] = (dp[i] - last[c] + MOD) % MOD;
            last[c] = dp[i - 1];
        }
        return (dp[n] - 1 + MOD) % MOD;
    }
};