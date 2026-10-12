class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long mod = 1e9 + 7;
        vector<int> cnt(30, 0);
        for (int i : nums) {
            for (int j = 0; j < 30; j++) {
                if ((i >> j) & 1) cnt[j]++;
            }
        }
        long long res = 0;
        for (int i = 0; i < k; i++) {
            long long cur = 0;
            for (int j = 0; j < 30; j++) {
                if (cnt[j] > 0) {
                    cur |= (1LL << j);
                    cnt[j]--;
                }
            }
            res = (res + (cur % mod) * (cur % mod)) % mod;
        }
        return (int)res;
    }
};