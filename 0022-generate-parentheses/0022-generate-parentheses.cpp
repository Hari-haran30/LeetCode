class Solution {
public:
    vector<string> par;
    void generate(string s, int o, int c, int n) {
        if (s.length() == 2 * n) {
            par.push_back(s);
            return;
        }
        if (o < n) {
            generate(s + "(", o + 1, c, n);
        }
        if (c < o) {
            generate(s + ")", o, c + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        generate("", 0, 0, n);
        return par;
    }
};