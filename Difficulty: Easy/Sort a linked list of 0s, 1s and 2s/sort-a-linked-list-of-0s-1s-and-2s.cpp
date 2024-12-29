//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    // void insertatTail(Node *toMove,Node *&head,Node *&tail){
    //     if(head==NULL&&tail==NULL){
    //         head=toMove;
    //         tail=toMove;
    //     }
    //     else{
    //         tail->next=toMove;
    //         tail=toMove;
    //     }
    // }
    Node* segregate(Node* head) {
    //method1
    Node *temp=head;
    int onesc=0;int zerosc=0;int twosc=0;
    while(temp!=NULL){
        if(temp->data==0)
        zerosc++;
        if(temp->data==1)
        onesc++;
        if(temp->data==2)
        twosc++;
        temp=temp->next;
    }
    Node*temp1=head;
    // while(zerosc--){
    //     temp1->data=0;
    //     temp1=temp1->next;
    // }
    // while(onesc--){
    //     temp1->data=1;
    //     temp1=temp1->next;
    // }
    // while(twosc--&&temp1!=NULL){
    //     temp1->data=2;
    //     temp1=temp1->next;
    // }
    // return head;
    while(temp1!=NULL){
        if(zerosc!=0){
            temp1->data=0;
            zerosc--;
        }
        else if(onesc!=0){
            temp1->data=1;
            onesc--;
        }
        else if(twosc!=0){
            temp1->data=2;
            twosc--;
        }
        temp1=temp1->next;
    }
    
    return head;
    //method 2
    // Node *zeroHead=new Node(-1);
    // Node *zeroTail=zeroHead;
    
    // Node *oneHead=new Node(-1);
    // Node *oneTail=oneHead;
    
    // Node *twoHead=new Node(-1);
    // Node *twoTail=twoHead;
    
    // Node *temp=head;
    
    // while(temp){
        
    //     if(temp->data==0){
    //       zeroTail->next=temp;
    //       zeroTail=temp;
    //     }
    //     if(temp->data==1){
    //       oneTail->next=temp;
    //       oneTail=temp;
    //     }
    //     if(temp->data==2){
    //         twoTail->next=temp;
    //         twoTail=twoTail->next;
    //     }
    //     temp=temp->next;
    // }
    // //merge
    // //empty cases
    // if(oneHead->next!=NULL){
    //     zeroTail->next=oneHead->next;
    // }
    // else{
    //     zeroTail->next=twoHead->next;
    // }
    // oneTail->next=twoHead->next;
    // twoTail->next=nullptr;
    // head=zeroHead->next;
    // delete oneHead;
    // delete zeroHead;
    // delete twoHead;
    // return head;
    
    
    //method3
    // Node *zeroHead=NULL;
    // Node *zeroTail=NULL;
    
    // Node *oneHead=NULL;
    // Node *oneTail=NULL;
    
    // Node *twoHead=NULL;
    // Node *twoTail=NULL;
    
    // Node *temp=head;
    
    // while(temp!=NULL){
    //     Node *toMove=temp;
    //     temp=temp->next;
    //     toMove->next=NULL;
    //     if(toMove->data==0){
    //         insertatTail(toMove,zeroHead,zeroTail);
    //     }
    //     if(toMove->data==1){
    //         insertatTail(toMove,oneHead,oneTail);
    //     }
    //     if(toMove->data==2){
    //         insertatTail(toMove,twoHead,twoTail);
    //     }
    // }
    // //merge
    // //empty cases
    // if(zeroHead!=NULL){
    //     if(oneHead!=NULL){
    //       zeroTail->next=oneHead;
    //       oneTail->next=twoHead;
    //     }
    //     else{
    //         zeroTail->next=twoHead;
    //     }
    //     return zeroHead;
    // }
    // else{
    //     if(oneHead!=NULL){
    //         oneTail->next=twoHead;
    //         return oneHead;
    //     }
    //     else{
    //         return twoHead;
    //     }
    // }
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends