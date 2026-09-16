class Solution {
public:
    using ll = long long;
    struct Fenwick {
        int n;
        vector<int> bit;
        Fenwick(int n) : n(n), bit(n + 1, 0) {}
        void add(int i, int v) {
            while (i <= n) {
                bit[i] += v;
                i += i & -i;
            }
        }
        int sum(int i) {
            int s = 0;
            while (i > 0) {
                s += bit[i];
                i -= i & -i;
            }
            return s;
        }
    };
    ll solve(vector<int>& nums, int l, int r) {
        if (r - l <= 1) return 0;
        int mid = (l + r) / 2;
        ll ans = solve(nums, l, mid) + solve(nums, mid, r);
        vector<pair<ll, ll>> left, right;
        set<ll> st;
        for (int i = mid - 1; i >= l; i--) {
            auto it = st.upper_bound(nums[i]);
            ll x = (it == st.end() ? 4e18 : *it);
            left.push_back({nums[i], x});
            st.insert(nums[i]);
        }
        st.clear();
        for (int j = mid; j < r; j++) {
            auto it = st.lower_bound(nums[j]);
            ll x = (it == st.begin() ? -4e18 : *prev(it));
            right.push_back({x, nums[j]});
            st.insert(nums[j]);
        }
        sort(left.begin(), left.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });
        sort(right.begin(), right.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });
        vector<ll> vals;
        for (auto& p : left) vals.push_back(p.first);
        sort(vals.begin(), vals.end());
        Fenwick fw(vals.size());
        int p = 0;
        for (auto& [R, b] : right) {
            while (p < (int)left.size() && left[p].second >= b) {
                int idx = lower_bound(vals.begin(), vals.end(), left[p].first) - vals.begin() + 1;
                fw.add(idx, 1);
                p++;
            }
            int hi = lower_bound(vals.begin(), vals.end(), b) - vals.begin();
            int lo = lower_bound(vals.begin(), vals.end(), R) - vals.begin();
            ans += fw.sum(hi) - fw.sum(lo);
        }
        return ans;
    }
    long long shadowPairs(vector<int>& nums) {
        return solve(nums, 0, nums.size());
    }
};