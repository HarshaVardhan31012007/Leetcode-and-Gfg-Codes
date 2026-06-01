class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            bool entered=false;
            while(!ans.empty()&&ans.back()>0&&asteroids[i]<0){
                if(ans.back()<abs(asteroids[i])){
                    ans.pop_back();
                }
                else if(ans.back()>=abs(asteroids[i])){
                    entered=true;
                    if(ans.back()==abs(asteroids[i]))
                    ans.pop_back();
                    break;
                }
            }
            if(!entered)
            ans.push_back(asteroids[i]);
        }
        return ans;
    }
};