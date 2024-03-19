//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
    private:
    Node* mid(Node* head){
        if(head == NULL)return NULL;
        Node* slow = head;
        Node* fast = head->next;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    Node * merge(Node* h1,Node* h2){
        if(h1 == NULL)return h2;
        if(h2 == NULL)return h1;
        Node* ans = new Node(-1);
        Node* temp = ans;
        while(h1 and h2){
            if(h1->data < h2->data){
                temp->next = h1;
                temp = h1;
                h1 = h1->next;
            }
            else {
                temp->next = h2;
                temp = h2;
                h2 = h2->next;
            }
        }
        while(h1){
            temp->next = h1;
            temp = h1;
            h1 = h1->next;
        }
        while(h2){
            temp->next = h2;
            temp = h2;
            h2 = h2->next;
        }
        ans = ans->next;
        return ans;
    }
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL or head->next == NULL)return head;
        Node* mid_ = mid(head);
        Node* head2 = mid_->next;
        mid_->next = NULL;
        mid_ = mergeSort(head);
        head2 = mergeSort(head2);
        Node* result = merge(mid_,head2);
        return result;
        
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends