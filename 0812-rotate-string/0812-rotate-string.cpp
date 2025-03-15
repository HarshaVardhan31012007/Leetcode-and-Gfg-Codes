class Solution {
public:
    bool rotateString(string s, string goal) {
        // string temp=s;
        // for(int i=0;i<s.length();i++){
        //     char t=s[i];
        //     temp.erase(temp.begin());
        //     temp=temp+t;
        //     if(temp==goal)
        //     return true;
        // }
        // return false;
        if(s.length()!=goal.length())
        return false;

        string temp=s+s;
        int i=0;int j=0;
        while(i<temp.length()){
            if(temp[i]==goal[j]){
                j++;
            }
            else{
                i=i-j;
                j=0;
                cout<<i<<" "<<j<<endl;
            }
            if(j>=goal.length()) break;
            i++;
        }
        return j==goal.length();
    }
};