class Solution {
public:
    void solve(string &digits,unordered_map<char,string>&mpp,int i,vector<string>&ans,string &temp){
    if(i==digits.size()){
        if(temp.length()>0)
        ans.push_back(temp);
        return;
    }
     for(auto &each:mpp[digits[i]]){
        temp.push_back(each);
        solve(digits,mpp,i+1,ans,temp);
        temp.pop_back();
     }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mpp;
        mpp['2']="abc";mpp['3']="def";mpp['4']="ghi";mpp['5']="jkl";
        mpp['6']="mno";mpp['7']="pqrs";mpp['8']="tuv";mpp['9']="wxyz";
        vector<string>ans;
        // if(!digits.size()) return ans;
        string temp="";
        solve(digits,mpp,0,ans,temp);
        return ans;
    }
};