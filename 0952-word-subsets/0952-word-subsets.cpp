class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxCount(26,0);
        for(auto word: words2){
            vector<int> count(26,0);
            for(char ch: word){
                count[ch-'a']++;
            }
            for(int i = 0; i<26; i++){
                maxCount[i] = max(maxCount[i],count[i]);
            }
        }
        vector<string> res;
        for(auto word: words1){
            vector<int> count(26,0);
            for(char ch: word){
                count[ch-'a']++;
            }
            bool isUniversal = true;
            for(int i= 0; i<26; i++){
                if(count[i]<maxCount[i]){
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal) res.push_back(word);
        }
        return res;
    }
};