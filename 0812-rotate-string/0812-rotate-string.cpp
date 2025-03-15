class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp=s;
        for(int i=0;i<s.length();i++){
            char t=s[i];
            temp.erase(temp.begin());
            temp=temp+t;
            if(temp==goal)
            return true;
        }
        return false;
    }
};