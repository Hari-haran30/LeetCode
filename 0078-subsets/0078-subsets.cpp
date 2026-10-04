class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int st, vector<int>& cur) {
        ans.push_back(cur);
        for (int i = st; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            solve(nums, i + 1, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        solve(nums, 0, cur);
        return ans;
    }
};