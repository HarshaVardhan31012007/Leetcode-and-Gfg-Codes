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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    TreeNode* solve(int n,ListNode* &head){
        if(n==0) return NULL;
        //L
        TreeNode* l=solve(n/2,head);
        TreeNode* root=new TreeNode(head->val);
        root->left=l;
        head=head->next;
        TreeNode* r=solve(n-n/2-1,head);
        root->right=r;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n=getLength(head);
        return solve(n,head);
    }
};