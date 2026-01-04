class Solution {
public:
    // map<tuple<int,int>,long long>mpp;
    // long long solve(string &s,string &t,int i,int c1,int fc,int sc,int cc){
    //     if(i>=s.length()){
    //         if(c1==0)
    //             return 0LL;
    //         else
    //             return (long long)1e9;
    //     }
    //     if(mpp.count({i,c1})) return mpp[{i,c1}];
    //     if(s[i]==t[i])
    //         return mpp[{i,c1}]=solve(s,t,i+1,c1,fc,sc,cc);
    //     else{
    //         if(s[i]=='0'&&t[i]=='1'){
    //             long long curr=fc+solve(s,t,i+1,c1,fc,sc,cc);
    //             curr=min(curr,solve(s,t,i+1,c1+1,fc,sc,cc));
    //             curr=min(curr,cc+solve(s,t,i+1,c1-1,fc,sc,cc));
    //             if(c1<0){
    //                 curr=min(curr,sc+solve(s,t,i+1,c1+1,fc,sc,cc));
    //             }
    //             return mpp[{i,c1}]=curr;
    //         }
    //         else if(s[i]=='1'&&t[i]=='0'){
    //             long long curr=fc+solve(s,t,i+1,c1,fc,sc,cc);
    //             curr=min(curr,solve(s,t,i+1,c1-1,fc,sc,cc));
    //             curr=min(curr,cc+solve(s,t,i+1,c1+1,fc,sc,cc));
    //             if(c1>0){
    //                 curr=min(curr,sc+solve(s,t,i+1,c1-1,fc,sc,cc));
    //             }
    //             return mpp[{i,c1}]=curr;
    //         }
    //     }
    //     return 1e9;
    // }
    // long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
    //     return solve(s,t,0,0,flipCost,swapCost,crossCost);
    // }





    // long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
    //     long long a=0;long long b=0;
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]=='0'&&t[i]=='1')
    //             a++;
    //         if(s[i]=='1'&&t[i]=='0')
    //             b++;
    //     }
    //     long long ans=0;
    //     while(a>0&&b>0){
    //         if(2*flipCost>swapCost){
    //             ans+=swapCost;
    //             a--;
    //             b--;
    //         }
    //         else{
    //             ans+=2*flipCost;
    //             a--;
    //             b--;
    //         }
    //     }
    //     while(a>1){
    //         if(2*flipCost>swapCost+crossCost){
    //             ans+=swapCost+crossCost;
    //             a-=2;
    //         }
    //         else{
    //             ans+=2*flipCost;
    //             a-=2;
    //         }
    //     }
    //     while(b>1){
    //         if(2*flipCost>swapCost+crossCost){
    //             ans+=swapCost+crossCost;
    //             b-=2;
    //         }
    //         else{
    //             ans+=2*flipCost;
    //             b-=2;
    //         }
    //     }
    //     if(a) ans+=flipCost;
    //     if(b) ans+=flipCost;
    //     return ans;
    // }




    // long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
    //     long long a=0;long long b=0;
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]=='0'&&t[i]=='1')
    //             a++;
    //         if(s[i]=='1'&&t[i]=='0')
    //             b++;
    //     }
    //     int c=min(a,b);
    //     a-=c;b-=c;long long ans=0;
    //     if(2*flipCost<swapCost){
    //         ans+=2LL*c*flipCost;
    //     }
    //     else
    //     ans+=1LL*c*swapCost;
    //     if(a){
    //         if(swapCost+crossCost<2*flipCost)
    //         ans+=1LL*(a/2)*(swapCost+crossCost);
    //         else
    //         ans+=1LL*(a/2)*2LL*(flipCost);
    //     }
    //     if(b){
    //         if(swapCost+crossCost<2*flipCost)
    //         ans+=1LL*(b/2)*(swapCost+crossCost);
    //         else
    //         ans+=1LL*(b/2)*2LL*(flipCost);
    //     }
    //     if(a&1)
    //     ans+=flipCost;
    //     if(b&1)
    //     ans+=flipCost;
    //     return ans;
    // }




    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long a=0;long long b=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'&&t[i]=='1')
                a++;
            if(s[i]=='1'&&t[i]=='0')
                b++;
        }
        long long pairs=min(a,b);
        long long rem=abs(a-b);
        long long ans=pairs*min(2*flipCost,swapCost);
        ans+=(rem/2)*(min(2*flipCost,swapCost+crossCost));
        ans+=(rem%2)*flipCost;
        return ans;
    }
};