class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans(spells.size(),0);
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int low=0;
            int high=potions.size()-1;
            long long  cs=spells[i];
            int cr=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(cs*potions[mid]<success){
                    low=mid+1;
                }else if(cs*potions[mid]>=success){
                    high=mid-1;
                    cr=mid;
                }
            }
            if(cr!=-1){
                ans[i]=potions.size()-cr;
            }
        }
        return ans;
    }
};