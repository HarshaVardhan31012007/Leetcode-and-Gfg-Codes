class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // int n=asteroids.size();
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     bool destroy=false;
        //     while(!ans.empty()&&ans.back()>0&&asteroids[i]<0){
        //         if(ans.back()<abs(asteroids[i])){
        //             ans.pop_back();
        //         }
        //         else if(ans.back()>=abs(asteroids[i])){
        //             destroy=true;
        //             if(ans.back()==abs(asteroids[i]))
        //             ans.pop_back();
        //             break;
        //         }
        //     }
        //     if(!destroy)
        //     ans.push_back(asteroids[i]);
        // }
        // return ans;




        stack<int>st;
        for(int i=asteroids.size()-1;i>=0;i--){
            bool destroy=false;
            while(!st.empty()&&st.top()<0&&asteroids[i]>0){
                if(abs(st.top())==asteroids[i]){
                    st.pop();
                    destroy=true;
                    break;
                }
                else if(abs(st.top())>asteroids[i]){
                    destroy=true;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(!destroy)
            st.push(asteroids[i]);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};