class Solution {
public:
    bool ispalindrome(string &s){
        int i=0;int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s,int i,vector<string>&temp,vector<vector<string>>&ans){
        if(i>=s.length()){
            ans.push_back(temp);
            return;
        }
        string temp1="";
        for(int k=i;k<s.length();k++){
            temp1+=s[k];
            if(ispalindrome(temp1)){
                temp.push_back(temp1);
                solve(s,k+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>>ans;
        vector<string>temp;
        solve(s,0,temp,ans);
        return ans;
    }
};