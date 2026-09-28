class Solution {
public:
    int maxDepth(string s) {
        int d = 0;
        int md = 0;
        for (char c : s) {
            if(c == '(') {
                d++;
                md = max(md, d);
            }
            else if (c == ')') d--;
        }
        return md;
    }
};