class Solution {
public:
    string customSortString(string order, string s) {
        // sort(s.begin(),s.end(),[&](char &a,char &b){
        //     int idx1=order.find(a);
        //     int idx2=order.find(b);
        //     return idx1<idx2;
        // });
        // return s;


        int arr[26]={0};
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<order.length();i++){
            while(arr[order[i]-'a']>0){
                ans+=order[i];
                arr[order[i]-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            while(arr[i]>0){
                ans+=(i+'a');
                arr[i]--;
            }
        }
        return ans;
    }
};