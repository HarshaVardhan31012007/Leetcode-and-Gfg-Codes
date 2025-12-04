class Solution {
public:
    int countCollisions(string directions) {
        //    int forward=0;
        //    bool stationary=false;
        //    int ans=0;
        //    for(int i=0;i<directions.length();i++){
        //          if(directions[i]=='S'){
        //             ans+=forward;
        //             forward=0;
        //             stationary=true;
        //          }
        //          if(directions[i]=='L'){
        //              if(forward>0){
        //                ans+=(forward-1)+2;
        //                forward=0;
        //                stationary=true;
        //              }
        //              else{
        //                 if(stationary){
        //                    ans+=1;
        //                 }
        //              }
        //          }
        //          if(directions[i]=='R') forward++;
        //    }
        //    return ans;


        int i=0;
        while(i<directions.length()&&directions[i]=='L'){
            i++;
        }
        int j=directions.length()-1;
        while(j>=0&&directions[j]=='R'){
            j--;
        }
        int collisions=0;
        while(i<=j){
            if(directions[i]!='S')
            collisions++;
            i++;
        }
        return collisions;
    }
};