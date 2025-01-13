class Solution {
public:
    int minimumLength(string s) {
        vector<int> mp(26,0);
        int totalLen = 0;
        for(char ch: s){
            mp[ch-'a']++;
        }
        for(auto it :mp){
            if(it==0) continue;
            if(it%2==0) totalLen += 2;
            else totalLen += 1;
        }
        return totalLen;
    }
};