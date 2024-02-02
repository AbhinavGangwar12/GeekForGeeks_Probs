//{ Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    
    // Approach 1
    Node* sol(Node* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* beta_head = sol(head->next);
        head->next->next = head;
        head->next = NULL;
        return beta_head;
    }
    struct Node* reverseList(struct Node *head){
        return sol(head);
    }
    
    
    // Approach 2
    // void solution(struct Node* &head,struct Node* curr,struct Node* prev){
    //     if(curr == NULL){
    //         head = prev;
    //         return;
    //     }
    //     Node * forward = curr->next;
    //     solution(head,forward,curr);
    //     curr->next = prev;
    // }
    
    // struct Node* reverseList(struct Node *head){
    //     Node * curr = head;
    //     Node * prev = NULL;
    //     solution(head,curr,prev);
    //     return head;
    // }
    
    // Approach 3
    
    // struct Node* reverseList(struct Node *head)
    // {
    //     // code here
    //     // return head of reversed list
    //     if(head == NULL || head->next == NULL)return head;
    //     Node* prev = NULL;
    //     Node* curr = head;
    //     Node* forward = curr->next;
    //     while(curr!=NULL){
    //         forward = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = forward;
    //     }
    //     return prev;
    // }
    
};
    


//{ Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        if(n!=0)
        {
            cin>>firstdata;
            head = new Node(firstdata);
            tail = head;
        }
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
