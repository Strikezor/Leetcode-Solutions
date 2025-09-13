class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return true;
        return false;
    }
    int maxFreqSum(string s) {
        unordered_map<char,int> vMap;
        unordered_map<char,int> cMap;

        for(char ch: s){
            if(isVowel(ch)){
                vMap[ch]++;
            }
        }
        for(char ch: s){
            if(!isVowel(ch)){
                cMap[ch]++;
            }
        }

        int maxFreqVowel = 0;
        int maxFreqConsonant = 0;

        for(auto it : vMap){
            maxFreqVowel = max(maxFreqVowel,it.second);
        }
        for(auto it : cMap){
            maxFreqConsonant = max(maxFreqConsonant,it.second);
        }

        return (maxFreqVowel + maxFreqConsonant);
    }
};