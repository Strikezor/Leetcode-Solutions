class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> arr = nums;       
        sort(arr.begin(), arr.end()); 
        int groupNo = 0;
        unordered_map<int, queue<int>> group; 
        map<int, int> connect;
        connect[arr[0]] = groupNo;
        group[groupNo].push(arr[0]);
        for (int i = 1; i < nums.size(); i++) { 
            if (abs(arr[i] - arr[i - 1]) <= limit) {
                group[groupNo].push(arr[i]);
                connect[arr[i]] = groupNo;
            } else {
                groupNo++;
                group[groupNo].push(arr[i]);
                connect[arr[i]] = groupNo;
            }
        }
        for (int i = 0; i < nums.size(); i++) { 
            int ele = nums[i];
            nums[i] = group[connect[nums[i]]].front();
            group[connect[nums[i]]].pop();
        }
        return nums;
    }
};