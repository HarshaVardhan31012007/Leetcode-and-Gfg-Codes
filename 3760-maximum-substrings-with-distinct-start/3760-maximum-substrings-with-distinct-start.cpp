class Solution {
public:
    int maxDistinct(string s) {
        // set<char>st;
        // int ans=0;
        // for(auto &each:s){
        //     if(st.find(each)==st.end()){
        //         st.insert(each);
        //         ans++;
        //     }
        // }
        // return ans;


        // unordered_set<char>st;
        // for(auto &each:s){
        //     if(st.find(each)==st.end()){
        //         st.insert(each);
        //     }
        // }
        // return st.size();


        // int ans=1;
        // sort(s.begin(),s.end());
        // for(int i=1;i<s.length();i++){
        //     if(s[i]==s[i-1]) continue;
        //     ans++;
        // }
        // return ans;


        int freq[26]={0};
        int ans=0;
        for(auto &each:s){
            if(freq[each-'a']==0)
            ans++;
            freq[each-'a']++;
        }
        return ans;
    }
};