class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, int st, vector<int>& cur){
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = st; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            cur.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        solve(candidates, target, 0, cur);
        return ans;
    }
};