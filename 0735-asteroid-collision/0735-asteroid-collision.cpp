class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //optimal
        // vector<int>v;
        // for(int i=0;i<asteroids.size();i++){
        //     bool destroy=false;
        //     while(!v.empty()&&asteroids[i]<0&&v.back()>0){
        //         if(abs(asteroids[i])<v.back()){
        //         destroy=true;
        //         break;
        //         }
        //         else if(abs(asteroids[i])==v.back()){
        //             destroy=true;
        //             v.pop_back();
        //             break;
        //         }
        //         else{
        //             v.pop_back();
        //         }
        //     }
        //     if(!destroy)
        //     v.push_back(asteroids[i]);
        // }
        // return v;


        
        vector<int>v;
        for(int i=0;i<asteroids.size();i++){
            bool destroy=false;
            if(asteroids[i]>0)
            v.push_back(asteroids[i]);
            else{
            if(v.empty()||v.back()<0)
            v.push_back(asteroids[i]);
            else{
            while(!v.empty()&&asteroids[i]<0&&v.back()>0){
                if(abs(asteroids[i])<v.back()){
                destroy=true;
                break;
                }
                else if(abs(asteroids[i])==v.back()){
                    destroy=true;
                    v.pop_back();
                    break;
                }
                else{
                    v.pop_back();
                }
            }
            if(!destroy)
            v.push_back(asteroids[i]);
            }
            }
        }
        return v;
    }
};