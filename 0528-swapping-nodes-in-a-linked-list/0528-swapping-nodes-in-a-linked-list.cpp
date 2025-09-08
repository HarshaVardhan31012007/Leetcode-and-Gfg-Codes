/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // void solve(ListNode* head,int& k,int& k1,ListNode* &a){
    //     if(!head) return;
    //     k--;
    //     if(k==0)
    //     a=head;
    //     solve(head->next,k,k1,a);
    //     k1--;
    //     if(k1==0)
    //     swap(head->val,a->val);
    // }
    // ListNode* swapNodes(ListNode* head, int k) {
    //     ListNode* a=NULL;
    //     int k1=k;
    //     solve(head,k,k1,a);
    //     return head;
    // }


    int getLength(ListNode* head){
        if(!head) return 0;
        return 1+getLength(head->next);
    }
    ListNode* swapNodes(ListNode* head, int k) {
        //here kth node from end can be first and kth node from start can be at end when k=n //here for each node we are going from head,but it is no need

        //we can make sure k=n and k=1 same right so swap value if k=1 // this optimization in below

        // int len=getLength(head);
        // if(len==0||((len&1)&&k==(len+1)/2)) return head;
        // //when node is null ans is null//constraint lo null is not possible
        // //when kth nodes from end and start are same,no swapping,head is ans
        // ListNode* a=NULL;
        // ListNode* temp=head;
        // for(int i=0;i<k-1;i++){
        //    temp=temp->next;
        // }
        // a=temp;
        // temp=head;
        // for(int i=0;i<len-k;i++)
        // temp=temp->next;
        // //here temp is at kth node from end
        // swap(temp->val,a->val);
        // return head;


 //here kth node from end can be first and kth node from start can be at end when k=n 
 //here for each node we are going from head,but it is no need
 //we can make sure k=n and k=1 same right so swap value if k=1 // this optimization in below
         int len=getLength(head);
        if(len==0||((len&1)&&k==(len+1)/2)) return head;
        //when node is null ans is null//constraint lo null is not possible
        //when kth nodes from end and start are same,no swapping,head is ans
        int len1=len-k+1;
        if(len-k+1<k)
        swap(k,len1);
        ListNode* a=NULL;
        ListNode* temp=head;
        for(int i=0;i<k-1;i++){
           temp=temp->next;
        }
        a=temp;
        for(int i=k-1;i<len-k;i++)
        temp=temp->next;
        //here temp is at kth node from end
        swap(temp->val,a->val);
        return head;
    }
};