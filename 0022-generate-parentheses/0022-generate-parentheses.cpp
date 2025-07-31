// class Solution {
// public:
//     void solve(int n,int open,int close,vector<string>&ans,string temp){
//         if(open+close==2*n) {
//             ans.push_back(temp);
//             return;
//         }
//         if(open==close){
//           solve(n,open+1,close,ans,temp+'(');
//         }
//         else if(open>close){
//           solve(n,open,close+1,ans,temp+')');
//           if(open!=n)
//           solve(n,open+1,close,ans,temp+'(');
//         }
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string>ans;
//         string temp="";
//         solve(n,0,0,ans,temp);
//         return ans;
//     }
// };

//in subproblems
// open>close is correct
//open==close correct
//close >open not correct

// class Solution {
// public:
//     void solve(int n,int open,int close,vector<string>&ans,string temp){
//         if(open+close==2*n) {
//             ans.push_back(temp);
//             return;
//         }
//         if(open<n){
//             solve(n,open+1,close,ans,temp+'(');
//         }
//         if(open>close){
//             solve(n,open,close+1,ans,temp+')');
//         }
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string>ans;
//         string temp="";
//         solve(n,0,0,ans,temp);
//         return ans;
//     }
// };



class Solution {
public:
    void solve(int n,int open,int close,vector<string>&ans,string &temp){
        if(open+close==2*n) {
            ans.push_back(temp);
            return;
        }
        if(open<n){
            temp.push_back('(');
            solve(n,open+1,close,ans,temp);
            temp.pop_back();
        }
        if(open>close){
            temp.push_back(')');
            solve(n,open,close+1,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        solve(n,0,0,ans,temp);
        return ans;
    }
};