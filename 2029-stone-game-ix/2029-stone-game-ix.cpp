class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int z = 0, o = 0, t = 0;
        for (int x : stones) {
            if (x % 3 == 0) {
                z++;
            }
            else if (x % 3 == 1) {
                o++;
            }
            else {
                t++;
            }
        }
        if (z % 2 == 0) {
            return o > 0 && t > 0;
        }
        return abs(o - t) > 2;
    }
};