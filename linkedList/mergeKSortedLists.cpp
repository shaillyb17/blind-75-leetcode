#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct comparator {
    bool operator()(const ListNode* l1, const ListNode* l2) {
        return l1->val > l2->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, comparator> pq;
    for(auto x: lists)
        if(x) pq.push(x);
    if(pq.empty())
        return NULL;
    ListNode* head = pq.top();
    pq.pop();
    if(head->next)
        pq.push(head->next);
    ListNode* tail = head;
    while(!pq.empty()) {
        tail->next = pq.top();
        pq.pop();
        tail = tail->next;
        if(tail->next)
            pq.push(tail->next);
    }
    return head;
}

int main(){
    // just required functions    
    return 0;
}