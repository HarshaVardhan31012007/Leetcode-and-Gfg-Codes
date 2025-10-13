class Solution {
public:
    // array<int,26>find(string &str){
    //     array<int,26>ans={0};
    //     for(auto &ch:str)
    //     ans[ch-'a']++;
    //     return ans;
    // }
    // vector<string> removeAnagrams(vector<string>& words) {
    //     vector<string>ans;
    //     stack<pair<array<int,26>,int>>st;
    //     for(int i=0;i<words.size();i++){
    //        array<int,26>curr=find(words[i]);
    //        if(!st.empty()&&st.top().first==curr)
    //        continue;
    //        else
    //        st.push({curr,i});
    //     }
    //     while(!st.empty()){
    //         ans.push_back(words[st.top().second]);
    //         st.pop();
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }




    //  array<int,26>find(string &str){
    //     array<int,26>ans={0};
    //     for(auto &ch:str)
    //     ans[ch-'a']++;
    //     return ans;
    // }
    // vector<string> removeAnagrams(vector<string>& words) {
    //     vector<string>ans;
    //     array<int,26>prev=find(words[0]);
    //     ans.push_back(words[0]);
    //     for(int i=1;i<words.size();i++){
    //        array<int,26>curr=find(words[i]);
    //        if(curr!=prev){
    //           prev=curr;
    //           ans.push_back(words[i]);
    //        }
    //     }
    //     return ans;
    // }




    
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        unordered_map<char,int>prev;
        for(auto &ch:words[0])
        prev[ch]++;
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
           unordered_map<char,int>curr;
           for(auto &ch:words[i])
           curr[ch]++;
           if(curr!=prev){
              prev=curr;
              ans.push_back(words[i]);
           }
        }
        return ans;
    }
};