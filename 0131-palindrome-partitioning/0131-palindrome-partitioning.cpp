class Solution {
public:
    bool isSafe(string &str,int s,int e){
        if(s>=e) return true;
        if(str[s]!=str[e]) return false;
        return isSafe(str,s+1,e-1);
    }
    void solve(string &str,int s,int e,vector<vector<string>>&ans,vector<string>&temp){
        if(s>e){
            ans.push_back(temp);
            return;
        }
        for(int i=s;i<=e;i++){
            // if(isSafe(str,s,i)&&isSafe(str,i+1,e)){
            //      temp.push_back(str.substr(s,i+1));
            //      temp.push_back(str.substr(i+1,e+1));
            //      ans.push_back(temp);

            // }
            if(isSafe(str,s,i)){
                temp.push_back(str.substr(s,i-s+1));
                solve(str,i+1,e,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(s,0,s.length()-1,ans,temp);
        return ans;
    }
};