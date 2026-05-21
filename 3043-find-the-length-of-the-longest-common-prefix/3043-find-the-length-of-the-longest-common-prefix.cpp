class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(int i=0;i<arr1.size();i++){
            int temp=arr1[i];
            while(temp){
                st.insert(temp);
                temp=temp/10;
            }
        }
        int n=arr2.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int temp=arr2[i];
            int len=((int)log10(temp)+1);
            while(temp){
                if(st.count(temp)){
                    ans=max(ans,len);
                    break;
                }
                len--;
                temp=temp/10;
            }
        }
        return ans;
    }
};