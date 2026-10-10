class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        const int MAX = 100000;
        vector<long long> cnt(MAX + 1, 0);
        for (int i = 0; i < n; i++) {
            cnt[abs(nums1[i] - nums2[i])]++;
        }
        for (int i = MAX; i > 0 && k > 0; i--) {
            if (cnt[i] == 0) continue;
            if (cnt[i] <= k) {
                k -= cnt[i];
                cnt[i - 1] +=  cnt[i];
                cnt[i] = 0;
            } else {
                cnt[i] -= k;
                cnt[i - 1] += k;
                k = 0;
            }
        }
        long long ans = 0;
        for (int i = 1; i <= MAX; i++) {
            ans += cnt[i] * i * i;
        }
        return ans;
    }
};