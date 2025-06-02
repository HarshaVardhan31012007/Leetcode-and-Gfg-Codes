class Solution {
public:
    string intToRoman(int num) {
        int  values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string strs[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans="";
        // for(int i=0;i<13;i++){
        //     while(num>=values[i]){
        //         num-=values[i];
        //         ans+=strs[i];
        //     }
        //     if(num==0) break;
        // }
        int i=0;
        while(num>0){
            if(num>=values[i]){
                ans+=strs[i];
                num-=values[i];
            }
            else
            i++;
        }
        return ans;
    }
};