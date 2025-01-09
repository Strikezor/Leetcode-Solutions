class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(auto it: words){
            if(it.starts_with(pref)) count++;
        }
        return count;
    }
};