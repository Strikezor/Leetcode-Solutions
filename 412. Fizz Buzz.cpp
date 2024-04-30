class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i=1;i<=n;i++){
            if(i%3==0){
                res[i-1]= (i%5==0) ? "FizzBuzz" : "Fizz";
            }
            else{
                res[i-1] = (i%5==0) ? "Buzz" : to_string(i);
            }
        }
        return res;
    }
};