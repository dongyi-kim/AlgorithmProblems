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
        ListNode* answer = new ListNode(0);
        ListNode* p = answer;
        for(int i = 0; p != nullptr; i++, p=p->next){
            if(l1 != nullptr) {
                p->val += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                p->val += l2->val;
                l2 = l2->next;
            }
            if(p->val >= 10 || l1 != nullptr || l2 != nullptr){
                p->next = new ListNode(p->val/10);
                p->val = p->val%10;
            }
        }
        return answer;
    }
};