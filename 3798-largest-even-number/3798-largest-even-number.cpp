class Solution {
public:
    // string largestEven(string s) {
    //     int i=s.length()-1;
    //     while(i>=0){
    //         if(s[i]=='2')
    //             break;
    //         i--;
    //     }
    //     return s.substr(0,i+1);
    // }


    string largestEven(string s) {
        int i=s.length()-1;
        while(i>=0){
            if(s[i]=='2')
                break;
            s.pop_back();
            i--;
        }
        return s;
    }
};