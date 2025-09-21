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


        
        // vector<int>v;
        // for(int i=0;i<asteroids.size();i++){
        //     bool destroy=false;
        //     if(asteroids[i]>0)
        //     v.push_back(asteroids[i]);
        //     else{
        //     if(v.empty()||v.back()<0)
        //     v.push_back(asteroids[i]);
        //     else{
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
        //     }
        //     }
        // }
        // return v;



        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            bool destroy=false;
            if(asteroids[i]>0)
            st.push(asteroids[i]);
            else{
            if(st.empty()||st.top()<0)
            st.push(asteroids[i]);
            else{
            while(!st.empty()&&asteroids[i]<0&&st.top()>0){
                if(abs(asteroids[i])<st.top()){
                destroy=true;
                break;
                }
                else if(abs(asteroids[i])==st.top()){
                    destroy=true;
                    st.pop();
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(!destroy)
            st.push(asteroids[i]);
            }
            }
        }
        vector<int>ans(st.size());
        int idx=st.size()-1;
        while(!st.empty()){
            ans[idx--]=st.top();
            st.pop();
        }
        return ans;
    }
};