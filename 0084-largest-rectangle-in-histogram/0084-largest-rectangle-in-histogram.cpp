class Solution {
public:
    void nextSmaller(vector<int>& heights,vector<int>&nexts){
        stack<int>s;
        s.push(-1);
        for(int i=heights.size()-1;i>=0;i--){
            while(s.top()!=-1&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.top()!=-1)
            nexts.push_back(s.top());
            else
            nexts.push_back(heights.size());
            s.push(i);
        }
    }
    void prevSmaller(vector<int>& heights,vector<int>&prevs){
        stack<int>s;
        s.push(-1);
        for(int i=0;i<heights.size();i++){
            while(s.top()!=-1&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            prevs.push_back(s.top());
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nexts;
        vector<int>prevs;
        nextSmaller(heights,nexts);
        prevSmaller(heights,prevs);
        reverse(nexts.begin(),nexts.end());
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int w=nexts[i]-prevs[i]-1;
            int h=heights[i];
            maxi=max(maxi,w*h);
        }
        return maxi;
    }
};