class Solution {
public:
    void solve(int i,int n,unordered_set<string>&st,string &ans,string &temp){
        if(i>=n){
            if(!st.count(temp))
            ans=temp;
            return;
        }
        if(ans!="") return;
        temp.push_back('0');
        solve(i+1,n,st,ans,temp);
        temp.pop_back();
        if(ans!="") return;
        temp.push_back('1');
        solve(i+1,n,st,ans,temp);
        temp.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<string>st(nums.begin(),nums.end());
        string ans="";string temp="";
        solve(0,n,st,ans,temp);
        return ans;
    }
};