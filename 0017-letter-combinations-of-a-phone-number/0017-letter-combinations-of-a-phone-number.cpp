class Solution {
public:
    void solve(string &digits,unordered_map<char,string>&mpp,vector<string>&ans,string &output,int i){
        //base case
        if(i>=digits.length()){
            if(output.length()>0)
            ans.push_back(output);
            return;
        }
        string str=mpp[digits[i]];
        for(int k=0;k<str.length();k++){
            output.push_back(str[k]);
            solve(digits,mpp,ans,output,i+1);
            output.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output="";
        unordered_map<char,string>mpp;
        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']="mno";
        mpp['7']="pqrs";
        mpp['8']="tuv";
        mpp['9']="wxyz";
        int i=0;
        solve(digits,mpp,ans,output,i);
        return ans;
    }
};