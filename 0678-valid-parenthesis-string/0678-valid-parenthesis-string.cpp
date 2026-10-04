class Solution {
public:
    bool checkValidString(string s) {
        int minO = 0;
        int maxO = 0;
        for (char c : s) {
            if (c == '(') {
                minO++;
                maxO++;
            } else if (c == ')') {
                minO--;
                maxO--;
            } else {
                minO--;
                maxO++;
            }
            if (maxO < 0) {
                return false;
            } 
            if (minO < 0) {
                minO = 0;
            } 
        }
        return minO == 0;
    }
};