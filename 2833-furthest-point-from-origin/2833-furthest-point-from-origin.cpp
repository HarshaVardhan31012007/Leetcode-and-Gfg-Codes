class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int mini=0;
        int maxi=0;
        for(auto &each:moves){
            if(each=='L'){
                mini--;
                maxi--;
            }
            else if(each=='R'){
                mini++;
                maxi++;
            }
            else{
                mini--;
                maxi++;
            }
        }
        return max(abs(mini),maxi);
    }
};