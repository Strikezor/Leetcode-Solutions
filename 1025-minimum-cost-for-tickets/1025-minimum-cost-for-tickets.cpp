class Solution {
public:
    int dp[366];
    int SolveMemo(vector<int> &days, int idx, vector<int> &costs){
        int n = days.size();
        if(idx >= n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int oneDay = costs[0] + SolveMemo(days, idx+1, costs);

        int i = idx;
        while(i < n && days[i] < days[idx]+7){
            i++;
        }
        int sevenDays = costs[1] + SolveMemo(days, i, costs);

        int j = idx;
        while(j < n && days[j] < days[idx]+30){
            j++;
        }
        int thirtyDays = costs[2] + SolveMemo(days, j, costs);

        return dp[idx] = min({oneDay, sevenDays, thirtyDays});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return SolveMemo(days, 0, costs);        
    }
};