class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mins(n);
        mins[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mins[i] = min(nums[i], mins[i + 1]);
        }
        int m = nums[0];
        for (int i = 0; i < n; i++) {
            m = max(m, nums[i]);
            if (m - mins[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};