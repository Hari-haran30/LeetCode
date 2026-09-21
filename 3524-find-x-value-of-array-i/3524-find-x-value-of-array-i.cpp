class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k);
        vector<long long> dp(k);
        for (int i : nums) {
            int rem = i % k;
            vector<long long> next(k);
            next[rem]++;
            for (int j = 0; j < k; j++) {
                next[(j * rem) % k] += dp[j];
            }
            dp = next;
            for (int j = 0; j < k; j++) {
                result[j] += dp[j];
            }
        }
        return result;
    }
};