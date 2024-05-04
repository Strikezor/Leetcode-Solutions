class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int st = 0,boats = 0;
        int ed = people.size()-1;

        while(st<=ed){
            if(people[st]+people[ed]<=limit){
                st++;
                ed--;
                boats++;
            }
            else{
                boats++;
                ed--;
            }
        }
        return boats;
    }
};