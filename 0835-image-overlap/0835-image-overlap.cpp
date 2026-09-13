class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) ones1.push_back({i, j});
                if (img2[i][j]) ones2.push_back({i, j});
            }
        }
        map<pair<int, int>, int> count;
        int ans = 0;
        for (auto i : ones1) {
            for (auto j : ones2) {
                pair<int, int> shift = {j.first - i.first, j.second - i.second};
                count[shift]++;
                ans = max(ans, count[shift]);
            }
        }
        return ans;
    }
};