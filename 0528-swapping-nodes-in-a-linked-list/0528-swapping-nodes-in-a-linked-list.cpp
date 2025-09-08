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

       //M1

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



  //M2

//  //here kth node from end can be first and kth node from start can be at end when k=n 
//  //here for each node we are going from head,but it is no need
//  //we can make sure k=n and k=1 same right so swap value if k=1 // this optimization in below
//          int len=getLength(head);
//         if(len==0||((len&1)&&k==(len+1)/2)) return head;
//         //when node is null ans is null//constraint lo null is not possible
//         //when kth nodes from end and start are same,no swapping,head is ans
//         int len1=len-k+1;
//         if(len-k+1<k)
//         swap(k,len1);
//         ListNode* a=NULL;
//         ListNode* temp=head;
//         for(int i=0;i<k-1;i++){
//            temp=temp->next;
//         }
//         a=temp;
//         for(int i=k-1;i<len-k;i++)
//         temp=temp->next;
//         //here temp is at kth node from end
//         swap(temp->val,a->val);
//       return head;


        if(!head||!head->next) return head;
        int len=getLength(head);
         // if(len==0||((len&1)&&k==(len+1)/2)) return head;//odd length middle is kth node //then no swapping
        int pos=len-k+1;
        if(pos==k) return head;// odd length middle node that's meaning
        if(pos<k)
        swap(k,pos);
          if(len==2){
            ListNode* rn=head->next;
            rn->next=head;
            head->next=NULL;
            head=rn;
            return head;
          }
          if(k==1){//in higher nodes k=1 case covered// when k=1 head changes and lp not exist,due to that we are handling seperately
        ListNode* rn=head;
        ListNode* rp=NULL;
        while(rn->next!=NULL){
            rp=rn;
            rn=rn->next;
        }
        rn->next=head->next;// due to this here two nodes case is not covered here because of self loop
        rp->next=head;
        head->next=NULL;
        head=rn;
        return head;
        }
        if(pos-k==1){// no nodes in between 
        //rn->next=ln->next this is first step,if both are adjacent,it leads to self loop // hence we handle seperately
        ListNode* lp=NULL;
        ListNode* ln=head;
        for(int i=0;i<k-1;i++){
            lp=ln;
            ln=ln->next;
        }
        ListNode* rn=ln->next;
        lp->next=rn;
        ln->next=rn->next;
        rn->next=ln;
        return head;
        }
        ListNode *lp=NULL,*rp=NULL;
        ListNode* ln=head;
        for(int i=0;i<k-1;i++){
        lp=ln;
        ln=ln->next;
        }
        ListNode* rn=ln;
        for(int i=k-1;i<pos-1;i++){
            rp=rn;
            rn=rn->next;
        }
        ListNode* rnlast=rn->next;
        rn->next=ln->next;
        ln->next=rnlast;
        rp->next=ln;
        lp->next=rn;
      return head;
    }
};