#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    stack<ListNode*> s;
    ListNode* temp = head;
    int size = 0;
    while(temp) {
        s.push(temp);
        temp = temp->next;
        size++;
    }
    ListNode* newNode = head;
    for(int i = 0; i < size/2; i++) {
        ListNode* temp = s.top();
        s.pop();
        temp->next = newNode->next;
        newNode->next = temp;
        newNode = newNode->next->next;
    }
    newNode->next = NULL;
}

int main(){
    // just required functions    
    return 0;
}