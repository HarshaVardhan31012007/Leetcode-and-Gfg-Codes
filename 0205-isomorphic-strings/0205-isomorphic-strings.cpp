class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arr[256]={0};int brr[256]={0};
        for(int i=0;i<s.length();i++){
            if(arr[s[i]]==0&&brr[t[i]]==0){
                     arr[s[i]]=t[i];
                     brr[t[i]]=s[i];
                     s[i]=t[i];
            }
            else{
                s[i]=arr[s[i]];
            }
        }
        return s==t;
    }
};