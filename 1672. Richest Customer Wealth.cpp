class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxSum = 0;
        for(auto it: accounts){
            int sum = 0;
            for(int i: it){
                sum += i;
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};