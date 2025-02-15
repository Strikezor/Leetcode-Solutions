class Solution {
public:
    bool canPartition(string num, int target, int start){
        if(start == num.length()) return target == 0;
        int sum = 0;
        for(int i = start; i<num.length(); i++){
            sum = sum * 10 +(num[i]-'0');
            if(sum>target) break;
            if(canPartition(num,target-sum,i+1)) return true;
        }
        return false;
    }
    bool hasSubarraySum(int n){
        int square = n*n;
        return canPartition(to_string(square),n,0);
    }
    int punishmentNumber(int n) {
        if(n==0) return 0;
        int addValue = hasSubarraySum(n) ? (n*n) : 0;
        return addValue + punishmentNumber(n-1);
    }
};