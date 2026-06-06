class Solution {
public:
    string convert(string s, int numRows) {
        // if(numRows==1) return s;
        // string ans="";
        // for(int i=0;i<numRows;i++){
        //     int start=i;int direction=0;
        //     while(start<s.length()){
        //         if(i==0||i==(numRows-1)){
        //             ans+=s[start];
        //             start+=(numRows-1)*2;
        //             continue;
        //         }
        //         if(direction==0){
        //             ans+=s[start];
        //             start+=(numRows-i-1)*2;
        //             direction=!direction;
        //         }
        //         else{
        //             ans+=s[start];
        //             start+=i*2;
        //             direction=!direction;
        //         }
        //     }
        // }
        // return ans;


        if(numRows==1) return s;
        vector<string>zigzag(numRows);
        int i=0;
        int direction=0;
        int row=0;
        while(1){
            if(direction==0){
                while(row<numRows&&i<s.length()){
                    zigzag[row++].push_back(s[i++]);
                }
                row=numRows-2;
            }
            else{
                while(row>=0&&i<s.length()){
                    zigzag[row--].push_back(s[i++]);
                }
                row=1;
            }
            if(i>=s.length()) break;
            direction=!direction;
        }
        string ans="";
        for(int i=0;i<numRows;i++)
        ans+=zigzag[i];
        return ans;
    }
};