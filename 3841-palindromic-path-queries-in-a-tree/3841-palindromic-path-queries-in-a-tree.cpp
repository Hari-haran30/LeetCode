class Solution {
    int timer, LOG;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, base, bit;
    string s;
    int n;
    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[0][u] = p;
        for (int j = 1; j < LOG; j++) {
            up[j][u] = up[j - 1][up[j - 1][u]];
        }
        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
        tout[u] = timer;
    }
    void add(int i, int val) {
        for (; i <= n; i += i & -i) {
            bit[i] ^= val;
        }
    }
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i) {
            res ^= bit[i];
        }
        return res;
    }
    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; j++)
            if (diff & (1 << j)) u = up[j][u];

        if (u == v) return u;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }
        return up[0][u];
    }
    int prefixMask(int u) {
        return base[u] ^ sum(tin[u]);
    }
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        this->s = s;
        timer = 0;
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        up.assign(LOG, vector<int>(n, 0));
        base.assign(n, 0);
        bit.assign(n + 1, 0);
        dfs(0, 0);
        for (int u = 0; u < n; u++) {
            int p = up[0][u];
            base[u] = (u == 0 ? 0 : base[p]) ^ (1 << (s[u] - 'a'));
        }
        vector<bool> ans;
        for (string &q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;
            if (type == "update") {
                char c;
                ss >> c;
                int delta = (1 << (this->s[u] - 'a')) ^ (1 << (c - 'a'));

                add(tin[u], delta);
                add(tout[u] + 1, delta);
                this->s[u] = c;
            } else {
                ss >> v;
                int w = lca(u, v);
                int mask = prefixMask(u) ^ prefixMask(v) ^ (1 << (this->s[w] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};