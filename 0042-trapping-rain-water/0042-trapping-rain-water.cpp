class Solution {
public:
    // void nextGreater(vector<int>&height,vector<int>&nextg){
    //      stack<int>st;
    //      for(int i=height.size()-1;i>=0;i--){
    //         while(!st.empty()&&height[st.top()]<height[i]){
    //             st.pop();
    //         }
    //         if(!st.empty())
    //         nextg[i]=st.top();
    //         st.push(i);
    //      }
    // }
    // void prevGreater(vector<int>&height,vector<int>&prevg){
    //      stack<int>st;
    //      for(int i=0;i<height.size();i++){
    //         while(!st.empty()&&height[st.top()]<=height[i]){
    //             st.pop();
    //         }
    //         if(!st.empty())
    //         prevg[i]=st.top();
    //         st.push(i);
    //      }
    // }
    // int trap(vector<int>& height) {

    //     vector<int>prevg(height.size(),-1);
    //     prevGreater(height,prevg);
    //     vector<int>nextg(height.size(),height.size());
    //     nextGreater(height,nextg);
    //     int ans=0;
    //     for(int i=0;i<height.size();i++){
    //         int h1=-1;
    //         if(prevg[i]!=-1&&nextg[i]!=height.size())
    //         h1=min(height[prevg[i]],height[nextg[i]]);
    //         int h2=height[i];
    //         int h=0;
    //         if(h1!=-1)
    //         h=h1-h2;
    //         int w=nextg[i]-prevg[i]-1;
    //         ans+=w*h;
    //     }
    //     return ans;

    // }


    // int trap(vector<int>&height){
    //     int watertrapped=0;
    //     for(int i=0;i<height.size();i++){
    //         int j=i;
    //         int leftmax=0,rightmax=0;
    //         while(j>=0){
    //              leftmax=max(leftmax,height[j]);
    //              j--;
    //         }
    //         j=i;
    //         while(j<height.size()){
    //             rightmax=max(rightmax,height[j]);
    //             j++;
    //         }
    //         watertrapped+=min(leftmax,rightmax)-height[i];
    //     }
    //     return watertrapped;
    // }


    int trap(vector<int>&height){
        vector<int>prefix(height.size(),0);
        prefix[0]=height[0];
        for(int i=1;i<height.size();i++){
           prefix[i]=max(height[i],prefix[i-1]);
        }
        vector<int>suffix(height.size(),0);
        suffix[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
             suffix[i]=max(height[i],suffix[i+1]);
        }
        int watertrapped=0;
        for(int i=0;i<height.size();i++){
            watertrapped+=min(prefix[i],suffix[i])-height[i];
        }
        return watertrapped;
    }
};