// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int>nSteps(100000,INT_MAX);
        nSteps[start]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,start});
        while(!pq.empty()){
            pair<int,int>curr=pq.top();
            int currSteps=curr.first;
            int currNumber=curr.second;
            pq.pop();
            if(currNumber==end) return currSteps;
            for(auto &num:arr){
                int newStart=((currNumber*num)%100000);
                if(currSteps+1<nSteps[newStart]){
                    nSteps[newStart]=currSteps+1;
                    pq.push({nSteps[newStart],newStart});
                }
            }
        }
        return -1;
    }
};
