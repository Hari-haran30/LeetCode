class Solution {
public:
    bool check(vector<int>& a, int k) {
        int n = a.size();
        int prevMax = 0;
        for (int i = 0; i < n; i += k) {
            int d = 0;
            int mn = INT_MAX;
            int mx = INT_MIN;
            for (int j = i; j < i + k; j++) {
                mn = min(mn, a[j]);
                mx = max(mx, a[j]);
                int nxt = (j+1 < i+k) ? a[j+1] : a[i];
                if (a[j] > nxt) d++;
            }
            if (d > 1 || prevMax > mn) return false;
            prevMax = mx;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k == 0 && check(nums,k)) {
                sum += k;
            }
        }
        return sum;
    }
};