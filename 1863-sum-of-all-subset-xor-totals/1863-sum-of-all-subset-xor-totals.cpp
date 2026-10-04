class Solution {
public:
    int ans = 0;
    void solve(vector<int>& nums, int idx, int xr) {
        if (idx == nums.size()) {
            ans += xr;
            return;
        }
        solve(nums, idx + 1, xr);
        solve(nums, idx + 1, xr ^ nums[idx]);
    }
    int subsetXORSum(vector<int>& nums) {
        solve(nums, 0, 0);
        return ans;
    }
};