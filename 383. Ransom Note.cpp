class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> dict;

        for(char ch:magazine){
            if(dict.find(ch)==dict.end()) dict[ch]=1;
            else dict[ch]++;
        }

        for(char ch:ransomNote){
            if(dict.find(ch)!= dict.end() && dict[ch]>0){
                dict[ch]--;
            }
            else return false;
        }
        return true;
    }
};