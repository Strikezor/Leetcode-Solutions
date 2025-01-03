class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        vector<long long> pref(n,0);
        pref[0] = nums[0];
        for(int i = 1; i<n; i++){
            pref[i] = nums[i] + pref[i-1];
        }
        long long totalSum = pref[n-1];
        for(int i = 0; i<n-1; i++){
            if(pref[i]>=(totalSum-pref[i])) count++;
        }
        return count;
    }
};