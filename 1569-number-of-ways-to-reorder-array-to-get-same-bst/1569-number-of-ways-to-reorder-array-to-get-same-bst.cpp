class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<long long>> c;
    long long count(vector<int>& arr) {
        if (arr.size() <= 2) return 1;
        vector<int> left, right;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[0]) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }
        long long ways = c[left.size() + right.size()][left.size()];
        ways = ways * count(left) % mod;
        ways = ways * count(right) % mod;
        return ways;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        c.assign(n+1, vector<long long>(n+1, 0));
        for (int i = 0; i <= n; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
            }
        }
        return (count(nums) - 1 + mod) % mod;
    }
};