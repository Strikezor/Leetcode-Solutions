class Solution {
public:
    long long dp[100001];
    int n;
    long long solve(vector<int>& power, int i) {
        if(i == n) return 0;
        if(dp[i] != 0) return dp[i];

        int idx = n, st = i + 1, end = n - 1;
        while(st <= end) {
            int mid = st + (end - st) / 2;

            if( power[mid] > power[i] + 2 ) {
                idx = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        long long take = power[i];
        int k = i + 1;
        while(k < n && power[i] == power[k]) {
            take += power[i];
            k++;  
        }
        take += solve(power, idx);
        
        long long skip = solve(power,  k);
        
        return dp[i] = max(take, skip);
    }
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        
        memset(dp, 0, sizeof(dp));
        n  = power.size();

        return solve(power, 0);
    }
};