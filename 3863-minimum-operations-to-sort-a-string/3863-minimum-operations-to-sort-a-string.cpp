class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool sorted = true;
        for (int i = 1; i < n; i++) {
            if (s[i] < s[i-1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) return 0;
        if (n == 2) return -1;
        char mn = 'z', mx = 'a';
        for (char ch : s) {
            if (ch < mn) mn = ch;
            if (ch > mx) mx = ch;
        }
        if (s[0] == mn || s[n-1] == mx) return 1;
        int mxcnt = 0, mncnt = 0;
        for (char ch : s) {
            if (ch == mx) mxcnt++;
            if (ch == mn) mncnt++;
        }
        if (s[0] == mx && mxcnt == 1 && s[n-1] == mn && mncnt == 1) return 3;
        return 2;
    }
};