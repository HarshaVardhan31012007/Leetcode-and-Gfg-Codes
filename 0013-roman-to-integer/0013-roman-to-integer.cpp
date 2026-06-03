class Solution {
public:
    int romanToInt(string s) {
        int n=s.length();
        unordered_map<string,int>mpp;
        mpp["I"]=1;mpp["V"]=5;mpp["X"]=10;mpp["L"]=50;mpp["C"]=100;mpp["D"]=500;
        mpp["M"]=1000;mpp["IV"]=4;mpp["IX"]=9;mpp["XL"]=40;mpp["XC"]=90;
        mpp["CD"]=400;mpp["CM"]=900;
        int ans=0;string ch="";
        for(int i=0;i<n;i++){
            string temp=(string(1,s[i])+(i==n-1?ch:string(1,s[i+1])));
            if(i+1<n&&mpp.count(temp)){
                ans+=mpp[temp];
                i++;
            }
            else{
                ans+=mpp[string(1,s[i])];
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};