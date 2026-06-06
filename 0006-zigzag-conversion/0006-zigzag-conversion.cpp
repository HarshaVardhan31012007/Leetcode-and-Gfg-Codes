class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string ans="";
        for(int i=0;i<numRows;i++){
            int start=i;int direction=0;
            while(start<s.length()){
                if(i==0||i==(numRows-1)){
                    ans+=s[start];
                    start+=(numRows-1)*2;
                    continue;
                }
                if(direction==0){
                    ans+=s[start];
                    start+=(numRows-i-1)*2;
                    direction=!direction;
                }
                else{
                    ans+=s[start];
                    start+=i*2;
                    direction=!direction;
                }
            }
        }
        return ans;
    }
};