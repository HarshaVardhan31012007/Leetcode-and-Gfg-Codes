class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double>time(cars.size(),-1.0);
        stack<int>st;
        for(int i=cars.size()-1;i>=0;i--){
            while(!st.empty()&&cars[st.top()][1]>=cars[i][1]){
                st.pop();
            }
            while(!st.empty()){
                double currTime=(cars[st.top()][0]-cars[i][0])/((double)(cars[i][1]-cars[st.top()][1]));
                if(time[st.top()]==-1||currTime<time[st.top()]){
                    time[i]=currTime;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return time;
    }
};