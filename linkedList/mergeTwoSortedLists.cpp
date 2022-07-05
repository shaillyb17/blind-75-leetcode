#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1 && !l2)
        return NULL;
    if(!l1 && l2)
        return l2;
    if(l1 && !l2)
        return l1;
    ListNode* curr1, *curr2;
    if(l1->val <= l2->val) {
        curr1 = l1;
        curr2 = l2;
    }
    else {
        curr1 = l2;
        curr2 = l1;
    }
    ListNode* head = curr1,*temp = curr1;
    while(curr1 && curr2) {
        if(curr1->val <= curr2->val) {
            head = curr1;
            curr1 = curr1->next;
        }
        else {
            ListNode* t = curr2;
            curr2 = curr1;
            curr1 = t;
            head->next = curr1;
        }
    }
    if(curr1)
        head->next = curr1;
    if(curr2)
        head->next = curr2;
    return temp;
}

int main(){
    // just required functions    
    return 0;
}