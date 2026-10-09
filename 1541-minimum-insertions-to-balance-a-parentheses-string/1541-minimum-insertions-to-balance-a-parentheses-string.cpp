class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int o = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                o++;
            } else {
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }
                if (o > 0) {
                    o--;
                } else {
                    ans++;
                }
            }
        }
        return ans + 2 * o;
    }
};