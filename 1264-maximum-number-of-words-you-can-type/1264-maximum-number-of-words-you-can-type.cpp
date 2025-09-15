class Solution {
public:
    vector<string> splitSentence(string sentence){
        vector<string> ans;
        string word;
        stringstream ss(sentence);

        while(ss>>word){
            ans.push_back(word);
        }
        return ans;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> brokenChar;
        for(char ch:brokenLetters){
            brokenChar.insert(ch);
        }
        int ans = 0;
        vector<string> words = splitSentence(text);
        for(auto it: words){
            bool ok = true;
            for(char ch: it){
                if(brokenChar.count(ch)){
                    ok = false;
                    break;
                }
            }
            if(ok) ans++;
        }

        return ans;
    }
};