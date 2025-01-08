class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                string w1 = words[i];
                string w2 = words[j];
                int L = w1.length();
                if (w1 == w2.substr(0, L) && w1 == w2.substr(w2.length() - L)) {
                    ++res;
                }
            }
        }
        return res;
    }
};