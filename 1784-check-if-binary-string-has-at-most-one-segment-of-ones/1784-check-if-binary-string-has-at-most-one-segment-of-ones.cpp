class Solution {
public:
    // bool checkOnesSegment(string s) {
    //     int n=s.length();
    //     int i=0;
    //     while(i<s.length()&&s[i]=='1') i++;
    //     while(i<s.length()&&s[i]=='0') i++;
    //     return i==n;
    // }

    bool checkOnesSegment(string s) {
        return s.find("01")==string::npos;
    }
};