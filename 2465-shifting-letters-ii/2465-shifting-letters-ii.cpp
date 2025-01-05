class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> prefixDiff(s.size() + 1, 0);

        for (auto& shift : shifts) {
            int left = shift[0], right = shift[1], d = shift[2];
            prefixDiff[left] += d ? 1 : -1;
            prefixDiff[right + 1] += d ? -1 : 1;
        }

        int diff = 0;
        for (int i = 0; i < s.size(); ++i) {
            diff += prefixDiff[i];
            int shiftValue = ((s[i] - 'a' + diff) % 26 + 26) % 26;
            s[i] = 'a' + shiftValue;
        }

        return s;
    }
};
