class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int start = 0;
        int count = 0;
        for (int r = k - 1; r < n; r++) {
            for (int len = k; len <= r - start + 1; len++) {
                int l = r - len + 1;
                if (check(s, l, r)) {
                    count++;
                    start = r + 1;
                    break;
                }
            }
        }
        return count;
    }
private:
    bool check(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};