/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    Node* solve(Node* head,int k,int& count){
        if(!head) return NULL;
        Node* ans=solve(head->next,k,count);
        if(ans) return ans;
        count++;
        if(count==k)
        return head;
        return NULL;
    }
    int getKthFromLast(Node* head, int k) {
        int count=0;
        Node* ans=solve(head,k,count);
        if(ans)
        return ans->data;
        return -1;
    }
};