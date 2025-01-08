class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                string w1 = words[i];
                string w2 = words[j];
                if (w2.starts_with(w1) && w2.ends_with(w1)) {
                    ++res;
                }
            }
        }
        return res;
    }
};