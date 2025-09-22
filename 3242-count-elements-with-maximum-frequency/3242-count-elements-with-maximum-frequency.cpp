class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it: nums) mp[it]++;
        int freq = 0, count = 0;
        for(auto it: mp){
            if(it.second == freq) count++;
            else if(it.second > freq){
                freq = it.second;
                count = 1;
            }
        }
        return freq * count;
    }
};