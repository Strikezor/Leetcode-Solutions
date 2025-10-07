class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, 1);
        unordered_map<int, int> mp;  
        set<int> dryDays;

        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                int lake = rains[i];
                res[i] = -1;
                if (mp.count(lake)) {
                    auto it = dryDays.upper_bound(mp[lake]);
                    if (it == dryDays.end()) return {};
                    res[*it] = lake;
                    dryDays.erase(it);
                }
                mp[lake] = i;
            } else {
                dryDays.insert(i);
            }
        }
        return res;
    }
};