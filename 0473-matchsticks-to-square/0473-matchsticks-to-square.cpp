// class Solution {
// public:
// bool solve(vector<int>&matchsticks,vector<int>&sides,int i){
//     if(i==matchsticks.size()){
//         return sides[0]==0&&sides[1]==0&&sides[2]==0&&sides[3]==0;
//     }
//     bool ans=false;
//     for(int j=0;j<4;j++){//4 or sides.size()
//        if(matchsticks[i]<=sides[j]){// or include sides[0]<0||sides[1]<0||sides[2]<0||sides[3]<0 this in if condition and return false
//        sides[j]-=matchsticks[i];
//        ans=ans||solve(matchsticks,sides,i+1);
//        if(ans==1)return 1;
//         //backtracking
//         //if ans not 1 and if condition satisfied
//         sides[j]+=matchsticks[i];
//        }
//     }
//     return ans;
// }
//     bool makesquare(vector<int>& matchsticks) {
//         if(matchsticks.size()<4)
//         return false;
//         int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
//         if(sum%4!=0)
//         return false;
//         vector<int>sides(4,sum/4);
//         sort(matchsticks.rbegin(),matchsticks.rend());
//         bool ans=solve(matchsticks,sides,0);
//         return ans;
//     }
// };





class Solution {
public:
    bool solve(vector<int>&matchsticks,vector<int>&sides,int i){
        if(i==matchsticks.size())
        return sides[0]==0&&sides[1]==0&&sides[2]==0&&sides[3]==0;
        bool ans=false;
        for(int j=0;j<4;j++){
            if(matchsticks[i]<=sides[j]){
                sides[j]-=matchsticks[i];
                ans=ans||solve(matchsticks,sides,i+1);
                if(ans) return true;
                sides[j]+=matchsticks[i];
            }
        }
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) 
        return false;
        vector<int>sides(4,sum/4);
        sort(matchsticks.rbegin(),matchsticks.rend());
        bool ans=solve(matchsticks,sides,0);
        return ans;
    }
};