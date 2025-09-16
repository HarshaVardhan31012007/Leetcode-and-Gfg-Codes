class Solution {
  public:
       int celebrity(vector<vector<int>>& mat) {
        
        
        stack<int>st;
        for(int i=0;i<mat.size();i++)
        st.push(i);
        while(st.size()>1){
          int b=st.top();
          st.pop();
          int a=st.top();
          st.pop();
          if(mat[a][b]){// a knows b// a cant be celebrity
              st.push(b);
          }
          else if(mat[b][a]){// b knows a // b cant be celebrity
              st.push(a);
          }
          // both zeros // a doesnot know b and b doesnot know a // botha re not celebrity
        }
        int ans=-1;
        if(!st.empty())
        ans=st.top();
        for(int i=0;i<mat.size()&&ans!=-1;i++){
            if(mat[i][ans]==0)
            return -1;
        }
        for(int j=0;j<mat.size()&&ans!=-1;j++){
            if(ans!=j&&mat[ans][j]==1)
            return -1;
        }
        return ans;
        
        
        
        // stack<int>st;
        // for(int i=0;i<mat.size();i++)
        // st.push(i);
        // while(st.size()>1){
        //   int b=st.top();
        //   st.pop();
        //   int a=st.top();
        //   st.pop();
        //   if(mat[a][b]){
        //       st.push(b);
        //   }
        //   else{
        //       st.push(a);
        //   }
        // }
        // int ans=st.top();
        // for(int i=0;i<mat.size();i++){
        //     if(mat[i][ans]==0)
        //     return -1;
        // }
        // for(int j=0;j<mat.size();j++){
        //     if(ans!=j&&mat[ans][j]==1)
        //     return -1;
        // }
        // return ans;
    }
};