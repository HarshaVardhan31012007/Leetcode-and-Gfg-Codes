class Solution {
public:
    array<int,26>find(string &str){
        array<int,26>ans={0};
        for(auto &ch:str)
        ans[ch-'a']++;
        return ans;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        stack<pair<array<int,26>,int>>st;
        for(int i=0;i<words.size();i++){
           array<int,26>curr=find(words[i]);
           if(!st.empty()&&st.top().first==curr)
           continue;
           else
           st.push({curr,i});
        }
        while(!st.empty()){
            ans.push_back(words[st.top().second]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};