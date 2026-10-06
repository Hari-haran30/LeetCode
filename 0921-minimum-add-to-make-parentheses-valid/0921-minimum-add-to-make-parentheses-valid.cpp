class Solution {
public:
    int minAddToMakeValid(string s) {
        int o = 0;
        int v = 0;
        for (char c : s) {
            if (c == '(') {
                o++;
            } else {
                if (o > 0) {
                    o--;
                } else {
                    v++;
                }
            }
        }
        return v + o;
    }
};