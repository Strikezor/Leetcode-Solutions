class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans = "";
        for(char ch: s){
            st.push(ch);
            if(ch==']'){
                st.pop();
                string temp= "";
                while(!st.empty() && st.top()!='['){
                    temp = st.top()+temp;
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                string number = "";
                while(!st.empty() && isdigit(st.top())){
                    number = st.top()+number;
                    st.pop();
                }
                int num = stoi(number);
                string curr = "";
                while(num--){
                    curr+=temp;
                }

                for(auto it:curr){
                    st.push(it);
                }
            }
        }
        string end="";
        while(!st.empty()){
            end = st.top()+end;
            st.pop();
        }
        ans += end;
        return ans;
    }
};