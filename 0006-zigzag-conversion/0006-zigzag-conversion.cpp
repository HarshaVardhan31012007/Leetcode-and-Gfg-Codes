class Solution {
public:
    string convert(string s, int numRows) {
    //  if(numRows==1) return s;// no need for this approach as it starting from row=0 every time
    //   int i=0;
    //   int direction=1;
    //   int row=0;
    //   vector<string>zigzag(numRows);
    //    while(true){
    //     if(direction){
    //         while(i<s.length()&&row<numRows){
    //             zigzag[row++].push_back(s[i++]);
    //         }
    //         row=numRows-2;
    //     }
    //     else{
    //         while(i<s.length()&&row>=1){
    //             zigzag[row--].push_back(s[i++]);
    //         }
    //         row=0;
    //     }
    //     if(i>=s.length()) break;
    //     direction=!direction;
    //    }
    //    string ans="";
    //    for(int i=0;i<zigzag.size();i++){
    //     ans+=zigzag[i];
    //    }
    //    return ans;


     if(numRows==1) return s;// need for this approach as it starting from row=1 every time expect for first
      int i=0;
      int direction=1;
      int row=0;
      vector<string>zigzag(numRows);
       while(true){
        if(direction){
            while(i<s.length()&&row<numRows){
                zigzag[row++].push_back(s[i++]);
            }
            row=numRows-2;
        }
        else{
            while(i<s.length()&&row>=0){
                zigzag[row--].push_back(s[i++]);
            }
            row=1;
        }
        if(i>=s.length()) break;
        direction=!direction;
       }
       string ans="";
       for(int i=0;i<zigzag.size();i++){
        ans+=zigzag[i];
       }
       return ans;
    }
};