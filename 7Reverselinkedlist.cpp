//Given the head of a singly linked list, reverse the list, and return the reversed list.
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* current = head;
            ListNode* next = nullptr;
            while(current!= nullptr){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            return prev;
        }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* reversedHead = s.reverseList(head);
    ListNode* current = reversedHead;
    while(current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    // Clean up memory
    current = reversedHead;
    while(current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
// where n is the number of nodes in the linked list.
// The algorithm iterates through the linked list once, reversing the pointers of each node.
// The space complexity is O(1) because we are using a constant amount of extra space
// (three pointers: prev, current, and next) regardless of the size of the input linked list.
// The code creates a linked list, reverses it using the reverseList function, and prints
// the values of the reversed linked list. Finally, it cleans up the allocated memory for the
// linked list nodes to prevent memory leaks.
