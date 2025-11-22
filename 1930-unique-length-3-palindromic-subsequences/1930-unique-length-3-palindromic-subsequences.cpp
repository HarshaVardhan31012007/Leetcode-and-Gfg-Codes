class Solution {
public:
    // void solve(string &s,int i,string temp,int c,set<string>&st){
    //     if(c==0){
    //         if(temp[0]==temp[2])
    //         st.insert(temp);
    //         return;
    //     }
    //     if(i==s.length()) return;
    //     if(c>0)
    //     solve(s,i+1,temp+s[i],c-1,st);
    //     solve(s,i+1,temp,c,st);
    // }
    // int countPalindromicSubsequence(string s) {
    //     set<string>st;
    //     string temp="";
    //     solve(s,0,temp,3,st);
    //     return st.size();
    // }




   
    // int countPalindromicSubsequence(string s) {
    //     int n=s.length();
    //     unordered_map<char,vector<int>>mpp;
    //     for(int i=0;i<n;i++){
    //         mpp[s[i]].push_back(i);
    //     }
    //     int ans=0;
    //     for(auto it=mpp.begin();it!=mpp.end();it++){
    //         vector<int>&vec=it->second;
    //         if(vec.size()<2) continue;
    //         int a=vec[0];
    //         int b=vec[vec.size()-1];
    //         int freq[26]={0};
    //         for(int j=a+1;j<b;j++){
    //             if(freq[s[j]-'a']==0){
    //                 ans++;
    //             }
    //             freq[s[j]-'a']++;
    //         }
    //     }
    //     return ans;
    // }


    int countPalindromicSubsequence(string s) {
        int n=s.length();
        unordered_map<char,vector<int>>mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])==mpp.end()||mpp[s[i]].size()==1)
            mpp[s[i]].push_back(i);
            else
            mpp[s[i]][1]=i;
        }
        int ans=0;
        for(auto it=mpp.begin();it!=mpp.end();it++){
            vector<int>&vec=it->second;
            if(vec.size()<2) continue;
            int a=vec[0];
            int b=vec[1];
            int freq[26]={0};
            for(int j=a+1;j<b;j++){
                if(freq[s[j]-'a']==0){
                    ans++;
                }
                freq[s[j]-'a']++;
            }
        }
        return ans;
    }
};