class Solution {
public:
    // vector<int>valu;
    // void solve(int t,int i,vector<string>&ans,int hour,int min){
    //     if(t==0){
    //        string temp=(min<10)?"0":"";
    //        temp+=to_string(min);
    //        string temp1=to_string(hour);
    //        string curr=temp1+":"+temp;
    //        ans.push_back(curr);
    //        return;   
    //     }
    //     if(i>=10) return;
    //     if(i<4){
    //         if(hour+valu[i]<=11)
    //         solve(t-1,i+1,ans,hour+valu[i],min);
    //     }
    //     if(i>=4){
    //         if(min+valu[i]<=59)
    //         solve(t-1,i+1,ans,hour,min+valu[i]);
    //     }
    //     solve(t,i+1,ans,hour,min);
    // }
    // vector<string> readBinaryWatch(int turnedOn) {
    //     valu.assign(10,0);
    //     for(int i=0;i<10;i++){
    //         if(i<4) valu[i]=(1<<i);
    //         else{
    //             int j=i-4;
    //             valu[i]=(1<<j);
    //         }
    //     }
    //     vector<string>ans;
    //     int hour=0;int min=0;
    //     solve(turnedOn,0,ans,hour,min);
    //     return ans;
    // }



   
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int h=0;h<12;h++){
            for(int m=0;m<60;m++){
                if(__builtin_popcount(h)+__builtin_popcount(m)==turnedOn){
                    string curr=to_string(h)+":";
                    if(m<10)
                    curr+="0";
                    curr+=to_string(m);
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
};