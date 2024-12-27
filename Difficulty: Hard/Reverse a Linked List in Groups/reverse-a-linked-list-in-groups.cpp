//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/*
   // Redirecting input from file
  freopen("/Users/debojyoti.mandal/expt/input.txt", "r", stdin);

  // Redirecting output to file
  freopen("/Users/debojyoti.mandal/expt/output.txt", "w", stdout);
*/

struct node {
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/
//no need
// int getLength(Node *head){
//         Node *temp=head;
//         int len=0;
//         while(temp!=NULL){
//             len++;
//             temp=temp->next;
//         }
//         return len;
//     }
class Solution {
  public:
    struct node *reverseIt(struct node *head, int k) {
         //base cases
        //empty case
        if(head==NULL){
            return head;
        }
        //single node case
        if(head->next==NULL){
            return head;
        }
        //no need
        //length less than k//no need
        // int len=getLength(head);
        // if(len<k){
        //     return head;
        // }
        // 1 case
        node *prev=NULL;
        node *curr=head;
        int position=0;
        while(position<k&&curr!=NULL){
            node *forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            position++;
        }
        //recursive calls
        if(curr!=NULL){
            node *recursivehead=reverseIt(curr,k);
            head->next=recursivehead;
        }
        return prev;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        node* head = new node(data);
        node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return (0);
}

// } Driver Code Ends