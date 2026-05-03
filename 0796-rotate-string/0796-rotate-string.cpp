class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        vector<int>v;
        for(int i=0;i<n;i++){
            if(goal[i]==s[0]){
                v.push_back(i);
            }
        }
        if(v.empty()||s.length()!=goal.length()) return false;
        for(auto &start:v){
        bool flag=true;
        for(int i=0;i<n;i++){
            if(s[i]!=goal[start]) flag=false;
            start=(start+1)%n;
        }
        if(flag) return true;
        }
        return false;
    }
};