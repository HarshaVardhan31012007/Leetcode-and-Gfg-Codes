class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //  vector<pair<int,int>>v;
        //  for(int i=0;i<position.size();i++){
        //        v.push_back({position[i],speed[i]});
        //  }
        //  sort(v.begin(),v.end());
        //  stack<double>st;
        //  for(int i=0;i<v.size();i++){
        //     double currTime=(target-v[i].first)/((double)v[i].second);
        //     while(!st.empty()&&st.top()<=currTime){
        //         st.pop();
        //     }
        //     st.push(currTime);
        //  }
        //  return st.size();


         vector<pair<int,int>>v;
         for(int i=0;i<position.size();i++){
               v.push_back({position[i],speed[i]});
         }
         sort(v.begin(),v.end());
         stack<double>st;
         for(int i=0;i<v.size();i++){
            double currTime=(target-v[i].first)/((double)v[i].second);
            st.push(currTime);
         }
         int count=0;
         while(st.size()>1){
            double b=st.top();
            st.pop();
            double a=st.top();
            if(a<=b){
                st.pop();
                st.push(b);
            }else{
               count++;
            }
         }
         return count+1;
    }
};