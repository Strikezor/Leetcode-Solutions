class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long totalSum = 0;
        int count = 0;
        int positiveMin = INT_MAX;
        int negativeMax = INT_MIN;

        for(int nodeVal : nums){
            int nodeValAfter = nodeVal ^ k;
            totalSum += nodeVal;
            int netChange = nodeValAfter - nodeVal;

            if(netChange > 0){
                positiveMin = min(positiveMin, netChange);
                totalSum += netChange;
                count ++;
            }
            else {
                negativeMax = max(negativeMax, netChange);
            }
        }
        if(count % 2==0) return totalSum;

        return max(totalSum - positiveMin, totalSum + negativeMax);
    }
};