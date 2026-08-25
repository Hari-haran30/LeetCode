class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int multiple = k;
        while (true) {
            if (find(nums.begin(), nums.end(), multiple) == nums.end()){
                return multiple;
            }
            multiple += k;
        }
    }
};