class Solution {
public:
    int sumD(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (sumD(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }
};