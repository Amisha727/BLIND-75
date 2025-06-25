//Check Cycle or not
#include<bits/stdc++.h>
using namespace std;
//Floyd's Cycle Detection Algorithm TC- O(n), SC- O(1)
//Defining of singly linked list
struct Node{
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
class Solution {
    public:
    bool hasCycle(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast&& fast->next){
            slow= slow->next;
            fast = fast->next->next;
            if(slow==fast) return true; //Cycle detected
        }
        return false;
    }
};

//Helper function to create a linked list from a vector
Node* createList(const vector<int>& arr){
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for(int i=1; i<arr.size(); i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

//Utility function to print linked list
void printList(Node* head) {
    int count = 0;
    while(head && count <20){
        cout << head->data << " ";
        head = head->next;
        count++;
    }
    cout<<(count == 20 ? "..." : "") << endl;
}
// Main function to test the hasCycle function
int main() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the values of the nodes: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Node* head = createList(arr);
    int makeCycle;
    cout << "Do you want to create a cycle? (1 for Yes, 0 for No): ";
    cin >> makeCycle;
    if(makeCycle) {
        int pos;
        cout << "Enter the position (0-indexed) to create a cycle: ";
        cin >> pos;
        Node* cycleNode = head;
        for(int i = 0; i < pos && cycleNode != nullptr; i++) {
            cycleNode = cycleNode->next;
        }
        if(cycleNode != nullptr) {
            Node* tail = head;
            while(tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = cycleNode; // Create the cycle
        } else {
            cout << "Invalid position for cycle creation." << endl;
        }
    }    
    Solution s;
    bool hasCycle = s.hasCycle(head);
    cout << (hasCycle ? "Cycle detected in the linked list." : "No cycle detected in the linked list.") << endl;
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
// The algorithm uses two pointers (slow and fast) to traverse the linked list.
// The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
// If there is a cycle, the fast pointer will eventually meet the slow pointer.
// If the fast pointer reaches the end of the list (nullptr), then there is no cycle.
// The space complexity is O(1) because we are using a constant amount of extra space (