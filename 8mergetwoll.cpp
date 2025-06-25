//Merge Two Sorted Linked Lists
//Time Complexity: O(m+n)-optimal
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
class Solution {
    public:
        Node* mergeTwoLists(Node* l1, Node* l2) {
            Node dummy(0);
            Node* tail = &dummy;
            while(l1 && l2){
                if(l1->data <l2->data){
                    tail->next = l1;
                    l1 = l1->next;
                }
                else {
                    tail->next = l2;
                    l2 = l2->next;
                }
                tail = tail->next;
                }
                //Append remammaing
                tail->next = l1 ? l1 : l2;
                return dummy.next;
            }
        Node* bruteforcemerge(Node* l1, Node* l2){
            vector<int> vals;
            while(l1){
                vals.push_back(l1->data);
                l1 = l1->next;
            }
            while(l2){
                vals.push_back(l2->data);
                l2 = l2->next;
            }
            sort(vals.begin(), vals.end());
            Node* dummy = new Node(0);
            Node* curr = dummy;
            for(int val : vals){
                curr->next = new Node(val);
                curr = curr->next;
            }
            return dummy->next;
        }
};
Node* createList(const vector<int>& arr){
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for(int i=1; i<arr.size(); i++){
        current-> next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}
//Utility function to print linked list
void printList(Node* head){
    while(head){
        cout<<head->data<< " ";
        head = head->next;
    }
    cout<<endl;
}

//----------main function----------
int main(){
    int n, m;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>m;
    vector<int> b(m);
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    Node* list1 = createList(a);
    Node* list2 = createList(b);
    Solution sol;
    Node* bruteforce = sol.bruteforcemerge(list1, list2);
    printList(bruteforce);
    list1 = createList(a);
    list2 = createList(b);
    Node* OptimalmergeTwoLists = sol.mergeTwoLists(list1, list2);
    printList(OptimalmergeTwoLists);
    return 0;
}