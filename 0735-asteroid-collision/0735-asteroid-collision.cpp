class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>v;
        for(int i=0;i<asteroids.size();i++){
            bool flag=1;
            while(!v.empty()&&asteroids[i]<0&&v.back()>0){
                if(abs(asteroids[i])<v.back()){
                flag=0;
                break;
                }
                else if(abs(asteroids[i])==v.back()){
                    flag=0;
                    v.pop_back();
                    break;
                }
                else{
                    v.pop_back();
                }
            }
            if(flag)
            v.push_back(asteroids[i]);
        }
        return v;
    }
};