class Solution {
  public:
       int celebrity(vector<vector<int>>& mat) {
        // stack<int>st;
        // st.push(0);
        // int ans=-1;
        // while(!st.empty()){
        //     int top=st.top();
        //     st.pop();
        //     for(int j=0;j<mat.size();j++){
        //         if(mat[j][top]==1){
                    
        //         }
        //     }
        // }
        // if(ans!=-1){
        //     bool flag=1;
        //     for(int i=0;i<mat.size();i++){
        //         if(mat[i][ans]==0){
        //             ans=-1;
        //             break;
        //         }
        //     }
        // }
        // return ans;
        
        
        
        stack<int>st;
        for(int i=0;i<mat.size();i++)
        st.push(i);
        while(st.size()>1){
           int b=st.top();
           st.pop();
           int a=st.top();
           st.pop();
        //   if(mat[a][b]&&mat[b][a]){
        //       st.push(b);
        //   }
        //   if(mat[b][a]&&mat[a][b]){
        //       st.push(a);
        //   }
           if(mat[a][b]){
               st.push(b);
           }
           else{
               st.push(a);
           }
        }
        int ans=st.top();
        for(int i=0;i<mat.size();i++){
            if(mat[i][ans]==0)
            return -1;
        }
        for(int j=0;j<mat.size();j++){
            if(ans!=j&&mat[ans][j]==1)
            return -1;
        }
        return ans;
    }
};