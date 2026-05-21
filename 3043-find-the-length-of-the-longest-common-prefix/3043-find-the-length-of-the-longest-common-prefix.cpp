class Solution {
public:
    // int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    //     unordered_set<int>st;
    //     if(arr1.size()>arr2.size()) arr1.swap(arr2);
    //     for(int i=0;i<arr1.size();i++){
    //         int temp=arr1[i];
    //         while(temp){
    //             st.insert(temp);
    //             temp=temp/10;
    //         }
    //     }
    //     int n=arr2.size();
    //     int ans=0;
    //     for(int i=0;i<n;i++){
    //         int temp=arr2[i];
    //         int len=((int)log10(temp)+1);
    //         while(temp){
    //             if(st.count(temp)){
    //                 ans=max(ans,len);
    //                 break;
    //             }
    //             len--;
    //             temp=temp/10;
    //         }
    //     }
    //     return ans;
    // }


    
     class Trie{
        public:
        char data;
        Trie* children[10];
        bool isterminal;
        Trie(char val){
            this->data=val;
            this->isterminal=false;
            for(int i=0;i<10;i++)
            this->children[i]=NULL;
        }
     };
     void insert(Trie* root,int val){
        string temp=to_string(val);
        for(int i=0;i<temp.size();i++){
            if(root->children[temp[i]-'0']==NULL)
            root->children[temp[i]-'0']=new Trie(temp[i]);
            root=root->children[temp[i]-'0'];
        }
        root->isterminal=true;
     }
     int search(Trie* root,int val){
        string temp=to_string(val);
        int i=0;
        for(;i<temp.size();i++){
            if(root->children[temp[i]-'0']==NULL) break;
            root=root->children[temp[i]-'0'];
        }
        return i;
     }
     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* root=new Trie(0);
        for(int i=0;i<arr1.size();i++){
            insert(root,arr1[i]);
        }
        int ans=0;
        for(int i=0;i<arr2.size();i++){
            ans=max(ans,search(root,arr2[i]));
        }
        return ans;
    }
};