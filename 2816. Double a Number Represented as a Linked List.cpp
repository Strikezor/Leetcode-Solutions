/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<int> st;
        int val = 0;

        while(head!=nullptr){
            st.push(head->val);
            head = head->next;
        }

        ListNode *newTail = nullptr;
        while(!st.empty() || val!= 0){
            newTail = new ListNode(0,newTail);

            if(!st.empty()){
                val += st.top()*2;
                st.pop();
            }

            newTail-> val = val%10;
            val /= 10;
        }

        return newTail;
    }
};