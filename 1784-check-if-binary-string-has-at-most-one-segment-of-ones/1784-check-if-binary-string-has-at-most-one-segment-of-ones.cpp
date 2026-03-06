class Solution {
public:
    // bool checkOnesSegment(string s) {
    //     int n=s.length();
    //     int i=0;
    //     while(i<s.length()&&s[i]=='1') i++;
    //     while(i<s.length()&&s[i]=='0') i++;
    //     return i==n;
    // }

    // bool checkOnesSegment(string s) {
    //     return s.find("01")==string::npos;
    // }



    bool checkOnesSegment(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<n;){
           if(s[i]=='1'){
            count++;
            while(i<n&&s[i]=='1') i++;
           }
           else
           i++;
        }
        return count<=1;
    }
};