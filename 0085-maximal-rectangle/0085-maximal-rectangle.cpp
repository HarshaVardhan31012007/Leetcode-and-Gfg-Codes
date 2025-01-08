class Solution {
    void findnextsmaller(vector<int>& heights, vector<int>&next){
        stack<int>st;
        st.push(heights.size());
        int n=heights.size();
        for(int i=n-1;i>=0;i--){
          int element=heights[i];
          while(st.top()!=heights.size()&&element<=heights[st.top()]){
            st.pop();
          }
          next.push_back(st.top());
          st.push(i);
        }
    }
     void findprevsmaller(vector<int>& heights, vector<int>&prev){
        stack<int>st;
        st.push(-1);
        int n=heights.size();
        for(int i=0;i<n;i++){
          int element=heights[i];
          while(st.top()!=-1&&element<=heights[st.top()]){
            st.pop();
          }
          prev.push_back(st.top());
          st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev;
        vector<int>next;
        findnextsmaller(heights,next);
        reverse(next.begin(),next.end());
        findprevsmaller(heights,prev);
        int maxarea=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int width=next[i]-prev[i]-1;
            int height=heights[i];
            maxarea=max(maxarea,width*height);
        }
        return maxarea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            vector<int>t;
            for(int j=0;j<n;j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }
        int area=largestRectangleArea(v[0]);
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
               if(v[i][j]){
                v[i][j]+=v[i-1][j];
               }
               else{
                v[i][j]=0;
               }
            }
            area=max(area,largestRectangleArea(v[i]));
        }
        return area;
    }
};