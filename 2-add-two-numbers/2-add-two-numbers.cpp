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
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<char> zero;
        for(int i = 0; l1 != nullptr || l2 != nullptr; i++){
            if(zero.size() <= i){
                zero.push_back(0);
            }
            if(l1 != nullptr) {
                zero[i] += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                zero[i] += l2->val;
                l2 = l2->next;
            }
            if(zero[i] >= 10){
                zero.push_back(zero[i]/10);
                zero[i] %= 10;
            }
        }
        ListNode* answer = new ListNode(0);
        
        ListNode* p = answer;
        for(int i = 0; i < zero.size(); i+= 1){
            p->val = zero[i];
            if( i + 1 < zero.size()){
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        return answer;
    }
};