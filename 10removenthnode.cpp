#include <bits/stdc++.h>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:

    // ✅ Brute Force Approach
    // Step 1: Count total nodes
    // Step 2: Remove (length - n)-th node from start
    // Time Complexity: O(2n)
    // Space Complexity: O(1)
    Node* removeNthFromEnd_Brute(Node* head, int n) {
        int length = 0;
        Node* temp = head;

        while (temp) {
            length++;
            temp = temp->next;
        }

        int target = length - n;
        if (target == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }

        temp = head;
        for (int i = 1; i < target; i++) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        return head;
    }

    // ✅ Optimal Approach using two pointers
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    Node* removeNthFromEnd(Node* head, int n) {
        Node* dummy = new Node(0);
        dummy->next = head;

        Node* fast = dummy;
        Node* slow = dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both fast and slow together
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow is before the node to delete
        Node* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Utility function to create linked list from vector
Node* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

// Utility function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ---------- main function ----------
int main() {
    int n;
    cout << "Enter number of elements in the linked list: ";
    cin >> n;

    vector<int> vals(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> vals[i];

    Node* head = createList(vals);

    int k;
    cout << "Enter n (to remove nth node from end): ";
    cin >> k;

    Solution sol;

    // Brute Force
    Node* bruteHead = createList(vals); // re-create original list
    bruteHead = sol.removeNthFromEnd_Brute(bruteHead, k);
    cout << "Brute Force Result: ";
    printList(bruteHead);

    // Optimal
    Node* optimalHead = createList(vals); // re-create original list
    optimalHead = sol.removeNthFromEnd(optimalHead, k);
    cout << "Optimal Result: ";
    printList(optimalHead);

    return 0;
}

/*🧠 Logic Recap:
🔹 Brute Force:
First pass: Count nodes len

Second pass: Remove (len - n)-th node from start

🔹 Optimal (Two-pointer/Floyd):
Advance fast pointer n + 1 steps ahead

Move both fast and slow until fast hits NULL

Delete node after slow

⏱️ Time and Space Complexity
Approach	Time Complexity	Space Complexity
Brute Force	O(n) + O(n) = O(n)	O(1)
Optimal (2 ptr)	O(n)	O(1)

✅ Sample Input
vbnet
Copy
Edit
Enter number of elements in the linked list: 5
Enter the elements: 1 2 3 4 5
Enter n (to remove nth node from end): 2
✅ Output
rust
Copy
Edit
Brute Force Result: 1 2 3 5
Optimal Result:     1 2 3 5
*/