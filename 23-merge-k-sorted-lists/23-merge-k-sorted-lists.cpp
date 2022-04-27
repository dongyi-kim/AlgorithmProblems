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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        
        priority_queue<pair<int, ListNode*> > pq;
        for(const auto &e : lists){
            if(e) pq.push({-e->val, e});
        }
        
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        
        while(!pq.empty()){
            auto e = pq.top(); pq.pop();
            auto node = e.second;
            if(not head) head = tail = new ListNode(node->val);
            else {
                tail = tail->next = new ListNode(node->val);
            }
            if(not node->next) continue;
            node = node->next;
            pq.push({-node->val, node});
        }
        return head;
    }
};