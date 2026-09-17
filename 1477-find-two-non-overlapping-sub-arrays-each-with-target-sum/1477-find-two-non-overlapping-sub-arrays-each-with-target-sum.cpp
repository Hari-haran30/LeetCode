class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;
        int csum = 0;
        vector<int> bestMin(n, INT_MAX);
        int bestlen = INT_MAX;
        int result = INT_MAX;
        while (j < n) {
            csum += arr[j];
            while (i < j && csum > target) {
                csum -= arr[i++];
            }
            if (csum == target) {
                int len = j - i + 1;
                if (i > 0 && bestMin[i - 1] != INT_MAX) {
                    result = min(result, len + bestMin[i - 1]);
                }
                bestlen = min(bestlen, len);
            }
            bestMin[j] = bestlen;
            j++;
        }
        return result == INT_MAX ? -1 : result;
    }
};