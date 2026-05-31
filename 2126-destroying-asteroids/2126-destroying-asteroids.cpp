class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long sum=mass;
        for(auto &each:asteroids){
            if(sum>=each){
                sum+=each;
            }
            else
            return false;
        }
        return true;
    }
};