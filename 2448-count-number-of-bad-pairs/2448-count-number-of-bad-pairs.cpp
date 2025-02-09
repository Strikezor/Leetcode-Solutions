class Solution {
public:
    long long sumtill(long long n){
        return (n*(n+1))/2;
    }
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long total_pairs=sumtill(n-1);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        mp[nums[i]-i]++;
        long long good_pairs=0;
        for(auto it:mp)
        good_pairs+=sumtill(it.second-1);
        return total_pairs-good_pairs;
    }
};