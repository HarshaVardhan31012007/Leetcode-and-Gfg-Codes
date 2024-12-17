class Solution {
public:
    bool isPalindrome(string str){
        string k=str;
        reverse(str.begin(),str.end());
        return k==str;
    }
    void solve(string s,vector<vector<string>>&ans,vector<string>&partitions){
      if(s.length()==0){
        ans.push_back(partitions);
        return;
      }
      for(int i=0;i<s.length();i++){
        string part=s.substr(0,i+1);
        if(isPalindrome(part)){
            partitions.push_back(part);
            solve(s.substr(i+1),ans,partitions);
            partitions.pop_back();
        }
      }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partitions;
        solve(s,ans,partitions);
        return ans;
    }
};