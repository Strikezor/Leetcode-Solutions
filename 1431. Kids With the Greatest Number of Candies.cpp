class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxC = 0;
        for(auto it:candies){
            maxC = max(maxC,it);
        }

        vector<bool> greatestC;
        for(int it: candies){
            greatestC.push_back(it+extraCandies >= maxC);
        }
        return greatestC;
    }
};