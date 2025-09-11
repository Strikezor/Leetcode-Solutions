class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return true;
        return false;
    }
    string sortVowels(string s) {
        string vowelString = "";
        for(char ch:s){
            if(isVowel(ch)){
                vowelString+=ch;
            }
        }

        sort(vowelString.begin(),vowelString.end());
        int j = 0;
        for(int i= 0;i<s.length(); i++){
            if(isVowel(s[i])){
                s[i] = vowelString[j];
                j++;
            }
        }
        return s;
    }
};