class Solution {
public:
    int reverseDegree(string s) {
        int deg = 0;
        for (int i = 0; i < s.length(); i++) {
            int rev = 'z' - s[i] + 1;
            deg += rev * (i + 1);
        }
        return deg;
    }
};