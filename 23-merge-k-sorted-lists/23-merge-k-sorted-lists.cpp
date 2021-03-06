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
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    ListNode* merge2Lists(ListNode* a, ListNode* b){
        if(a == nullptr ) return b;
        if(b == nullptr ) return a;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        if(a->val < b->val){
            head = tail = a;
            a = a->next;
        }else{
            head = tail = b;
            b= b->next;
        }     
        while( a || b ){
            if(not a){
                tail = tail->next = b;
                b = b->next;
            }else if(not b){
                tail = tail->next = a;
                a = a->next;
            }else if(a->val < b->val){
                tail = tail->next = a;
                a = a->next;
            }else{
                tail = tail->next = b;
                b = b->next;
            }
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        for(int step = 1; step < lists.size(); step *= 2){
            for(int i = 0 ; i + step < lists.size(); i += 2*step){
                lists[i] = merge2Lists(lists[i], lists[i+step]);
            }
        }
        return lists[0];
    }
};