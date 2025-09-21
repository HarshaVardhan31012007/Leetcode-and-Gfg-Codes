class Solution {
public:
    void nextGreater(vector<int>&height,vector<int>&nextg){
         stack<int>st;
         for(int i=height.size()-1;i>=0;i--){
            while(!st.empty()&&height[st.top()]<height[i]){
                st.pop();
            }
            if(!st.empty())
            nextg[i]=st.top();
            st.push(i);
         }
    }
    void prevGreater(vector<int>&height,vector<int>&prevg){
         stack<int>st;
         for(int i=0;i<height.size();i++){
            while(!st.empty()&&height[st.top()]<=height[i]){
                st.pop();
            }
            if(!st.empty())
            prevg[i]=st.top();
            st.push(i);
         }
    }
    int trap(vector<int>& height) {

        vector<int>prevg(height.size(),-1);
        prevGreater(height,prevg);
        vector<int>nextg(height.size(),height.size());
        nextGreater(height,nextg);
        int ans=0;
        for(int i=0;i<height.size();i++){
            int h1=-1;
            if(prevg[i]!=-1&&nextg[i]!=height.size())
            h1=min(height[prevg[i]],height[nextg[i]]);
            int h2=height[i];
            int h=0;
            if(h1!=-1)
            h=h1-h2;
            int w=nextg[i]-prevg[i]-1;
            ans+=w*h;
        }
        return ans;

    }
};