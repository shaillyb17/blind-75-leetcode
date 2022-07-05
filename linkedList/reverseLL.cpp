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

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL, *next;
    while(head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}


int main(){
    // just required functions    
    return 0;
}