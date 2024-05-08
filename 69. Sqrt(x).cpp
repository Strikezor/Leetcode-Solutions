class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;

        int start = 1;
        int end = x;
        int mid = -1;
        while(start <= end){
            mid = start + (end-start)/2;
            long long sq = static_cast<long long>(mid) * mid;
            if(sq > x) end = mid-1;
            else if(sq == x) return mid ;
            else start = mid+1;
        }
        return static_cast<int> (round(end));
    }
};