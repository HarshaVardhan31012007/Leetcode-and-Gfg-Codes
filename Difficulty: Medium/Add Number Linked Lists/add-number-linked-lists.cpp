//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  void insertatTail(Node *&ansHead,Node *&ansTail,int digit){
        if(ansHead==NULL&&ansHead==NULL){
            Node *newNode=new Node(digit);
            ansHead=newNode;
            ansTail=newNode;
        }
        else{
             Node *newNode=new Node(digit);
            ansTail->next=newNode;
            ansTail=newNode;
        }
    }
    Node *reversel(Node *head){
        Node *prev=NULL;
        Node *curr=head;
        while(curr!=NULL){
            Node *forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    Node *add(Node *l1,Node *l2){
        int carry=0;
        Node *ansHead=NULL;
        Node *ansTail=NULL;
        while(l1!=NULL&&l2!=NULL){
            int sum=l1->data+l2->data+carry;
            int digit=sum%10;
            carry=sum/10;
            insertatTail(ansHead,ansTail,digit);
            l1=l1->next;
            l2=l2->next;
        }
         while(l2!=NULL){
            int sum=l2->data+carry;
            int digit=sum%10;
            carry=sum/10;
            insertatTail(ansHead,ansTail,digit);
            l2=l2->next;
        }
        while(l1!=NULL){
            int sum=l1->data+carry;
            int digit=sum%10;
            carry=sum/10;
            insertatTail(ansHead,ansTail,digit);
            l1=l1->next;
        }
        if(carry){
            insertatTail(ansHead,ansTail,carry);
        }
        return ansHead;
    }
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
       num1=reversel(num1);
       num2=reversel(num2);
       Node *ans=add(num1,num2);
       ans=reversel(ans);
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends