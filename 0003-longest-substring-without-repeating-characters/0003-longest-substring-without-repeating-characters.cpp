class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int i=0;
        // int j=0;
        // unordered_set<int>st;
        // int n=s.length();
        // int ans=0;
        // while(j<n){
        //     if(!st.count(s[j])){
        //         st.insert(s[j]);
        //     }
        //     else{
        //         while(s[i]!=s[j]){
        //             st.erase(s[i]);
        //             i++;
        //         }
        //         i++;
        //     }
        //     ans=max(ans,j-i+1);
        //     j++;
        // }
        // return ans;


        int i=0;
        int j=0;
        int arr[256]={0};
        int n=s.length();
        int ans=0;
        while(j<n){
            if(arr[s[j]]==0){
                arr[s[j]]=1;
            }
            else{
                while(s[i]!=s[j]){
                    arr[s[i]]=0;
                    i++;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};