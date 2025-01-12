class Solution {
public:
    bool canBeValid(string s, string locked) {
        vector<int> stack_locked;
        vector<int> stack_unlocked;

        for (int i = 0; i < s.length(); ++i) {
            if (locked[i] == '0') {
                stack_unlocked.push_back(i);
            } else if (s[i] == '(') {
                stack_locked.push_back(i);
            } else {
                if (!stack_locked.empty()) {
                    stack_locked.pop_back();
                } else if (!stack_unlocked.empty()) {
                    stack_unlocked.pop_back();
                } else {
                    return false;
                }
            }
        }

        while (!stack_locked.empty() && !stack_unlocked.empty() && stack_locked.back() < stack_unlocked.back()) {
            stack_locked.pop_back();
            stack_unlocked.pop_back();
        }

        if (!stack_locked.empty()) {
            return false;
        }

        return stack_unlocked.size() % 2 == 0;
    }
};
