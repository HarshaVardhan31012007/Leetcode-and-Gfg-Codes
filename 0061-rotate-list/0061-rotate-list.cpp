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
    // int numberOfNodes(ListNode* head){
    //     int c=0;
    //     while(head!=NULL){
    //        c++;
    //        head=head->next;
    //     }
    //     return c;
    // }
    // ListNode* rotateRight(ListNode* head, int k) {
    //     if(!head||!head->next) return head;
    //     int len=numberOfNodes(head);
    //     k=k%len;
    //     if(k==0) return head;
    //     ListNode* temp=head;
    //     int skip=len-k;
    //     ListNode* prev=NULL;
    //     while(skip--){
    //        prev=head;
    //        head=head->next;
    //     }
    //     ListNode* temp1=head;
    //     prev->next=NULL;
    //     while(temp1->next)
    //     temp1=temp1->next;
    //     temp1->next=temp;
    //     return head;
    // }



    void solve(ListNode* head,ListNode* &node,ListNode* &lastNode,int &k,int &len){
        if(!head) return;
        len++;
        if(head&&!head->next){
            lastNode=head;
            k=k%len;
        }
        solve(head->next,node,lastNode,k,len);
        if(k==0&&head->next){
            node=head;
        }
        k--;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next) return head;
        ListNode* node=NULL;
        ListNode* lastNode=NULL;
        int len=0;
        solve(head,node,lastNode,k,len);
        if(!node) return head;
        ListNode* temp=node->next;
        node->next=NULL;
        lastNode->next=head;
        head=temp;
        return head;
    }
};