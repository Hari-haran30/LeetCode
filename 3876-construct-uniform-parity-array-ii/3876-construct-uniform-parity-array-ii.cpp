class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min = *min_element(nums1.begin(), nums1.end());
        if (min % 2 != 0) {
            return true;
        }
        for (int i : nums1) {
            if (i % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};