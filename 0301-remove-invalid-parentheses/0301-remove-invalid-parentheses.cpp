class Solution {
public:
    set<string> ans;
    void solve(string& s, int idx, string cur, int o, int ro, int rc) {
        if (idx == s.length()) {
            if  (o == 0 && ro == 0 && rc == 0) {
                ans.insert(cur);
            }
            return;
        }
        char ch = s[idx];
        if (ch != '(' && ch != ')') {
            solve(s, idx + 1, cur + ch, o, ro, rc);
            return;
        }
        if (ch == '(' && ro > 0) {
            solve(s, idx + 1, cur, o, ro - 1, rc);
        }
        if (ch == ')' && rc > 0) {
            solve(s, idx + 1, cur, o, ro, rc - 1);
        }
        if (ch == '(') {
            solve(s, idx + 1, cur + ch, o + 1, ro, rc);
        } else {
            if (o > 0) {
                solve(s, idx + 1, cur + ch, o - 1, ro, rc);
            }
        }
    } 
    vector<string> removeInvalidParentheses(string s) {
        int ro = 0;
        int rc = 0;
        for (char ch : s) {
            if (ch == '(') {
                ro++;
            } else if (ch == ')') {
                if (ro > 0) {
                    ro--;
                } else {
                    rc++;
                }
            }
        }
        solve (s, 0, "", 0, ro, rc);
        return vector<string>(ans.begin(), ans.end());
    }
};