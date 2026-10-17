class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end(), [&](auto a, auto b) {
            int s1 = digitSum(a.first);
            int s2 = digitSum(b.first);
            if (s1 != s2) return s1 < s2;
            return a.first < b.first;
        });
        vector<bool> visited(n, false);
        int swap = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i) continue;
            int j = i;
            int cycle = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle++;
            }
            swap += cycle - 1;
        }
        return swap;
    }
};