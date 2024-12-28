//{ Driver Code Starts
// Initial template for C++

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

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/
void solve(Node *head,int &carry){
    if(!head)
    return;
    solve(head->next,carry);
    int sum=head->data+carry;
    head->data=sum%10;
    carry=sum/10;
}
class Solution {
  public:
    // Node* reverselist(Node *&head){
    //     Node *prev=NULL;
    //     Node *curr=head;
    //     while(curr!=NULL){
    //         Node *forward=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=forward;
    //     }
    //     return prev;
    // }
    Node* addOne(Node* head) {
        // //reverse
        // head=reverselist(head);
        // //add 1
        // int carry=1;
        // Node *temp=head;
        // while(temp!=NULL){
        //     int sum=carry+temp->data;
        //     temp->data=sum%10;
        //     carry=sum/10;
        //     if(carry==0)
        //     break;
        //     //special case for last node
        //     if(temp->next==NULL&&carry!=0){
        //         Node *newNode=new Node(carry);
        //         temp->next=newNode;
        //         temp=newNode;
        //     }
        //     temp=temp->next;
        // }
        // //reverse
        // head=reverselist(head);
        
        // return head;
        
        //method 2
        int carry=1;
        solve(head,carry);
        if(carry){
            Node *newNode=new Node(carry);
            newNode->next=head;
            head=newNode;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
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
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends