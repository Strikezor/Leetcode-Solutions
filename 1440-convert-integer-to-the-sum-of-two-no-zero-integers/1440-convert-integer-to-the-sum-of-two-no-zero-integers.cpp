class Solution {
public:
    bool check(int x) {
        while (x > 0) {
            if (x % 10 == 0) 
                return false;
            x /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (check(a) && check(b)) {
                return {a, b};
            }
        }
        return {};
    }
};