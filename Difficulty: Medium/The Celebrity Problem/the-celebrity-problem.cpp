//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    //method 1
    // int checkrow(vector<vector<int> >& mat,int i){
    //   for(int j=0;j<mat[i].size();j++){
    //       if(mat[i][j]==1)
    //       return 0;
    //   } 
    //   return 1;
    // }
    // int checkcol(vector<vector<int> >& mat,int j){
    //   for(int i=0;i<mat.size();i++){
    //       if(i!=j&&mat[i][j]==0)
    //       return 0;
    //   } 
    //   return 1;
    // }
    // int celebrity(vector<vector<int> >& mat) {
    //     //method 1
    //     for(int i=0;i<mat.size();i++){
    //         int ans1=checkrow(mat,i);
    //         int ans2=checkcol(mat,i);
    //         if(ans1==1&&ans2==1)
    //         return i;
    //     }
    //     return -1;
    // }
    
    
    
    //method 2
    
    int celebrity(vector<vector<int> >& mat) {
        //method 2
    //   stack<int>s;
    //   int n=mat.size();
    //   for(int i=0;i<mat.size();i++){
    //       s.push(i);
    //   }
       
    //   while(s.size()!=-1){
    //       int a=s.top();
    //       s.pop();
    //       int b=s.top();
    //       s.pop();
        //   if(mat[a][b]){
        //b might be celebriy not exact
        //       s.push(b);
        //   }
        //it is valid
        //if a dpesnot know b and b does not know a 
        //that means both are not celebrity pop both
        //   else if(mat[b][a]){
        //  a might be celebriy not exact
        //       s.push(a);
        //   }
        //it also works Prefer this only
        //  else{
        //       s.push(a);
        //   }
       //}
        // int mightbecelebrity=s.top();
        // s.pop();
        //   int i=mightbecelebrity;
        //   for(int j=0;j<mat[i].size();j++){
        //   if(mat[i][j]==1)
        //   return -1;
        //   }
        //   int j=mightbecelebrity;
        //   for(int i=0;i<mat.size();i++){
        //   if(i!=j&&mat[i][j]==0)
        //   return -1;
        //   }
        //   return mightbecelebrity;
        
        //method 3
        //two pointer// similar to that if elseif condition
        int n=mat.size();
        int top=0;
        int bottom=n-1;
        while(top<bottom){
            if(mat[top][bottom]){
                top++;
            }
            else if(mat[bottom][top]){
                bottom--;
            }
            else{
                top++;
                bottom--;
            }
        }
        if(top>bottom)
        return -1;
          int mightbecelebrity=top;//or bottom
          int i=mightbecelebrity;
          for(int j=0;j<mat[i].size();j++){
          if(mat[i][j]==1)
          return -1;
          }
          int j=mightbecelebrity;
          for(int i=0;i<mat.size();i++){
          if(i!=j&&mat[i][j]==0)
          return -1;
          }
          return mightbecelebrity;
          
          
          
          
        //don't follow this it is correct but confusing
        // while(!s.empty()){
        //     int a=s.top();
        //     s.pop();
        //     if(!s.empty()){
        //     int b=s.top();
        //     s.pop();
        //     if(mat[a][b]==1&&mat[b][a]==0){
        //         s.push(b);
        //     }
        //     if(mat[b][a]==1&&mat[a][b]==0){
        //         s.push(a);
        //     }
        //     if(s.empty()){
        //         return -1;
        //     }
        //     }
        //     else if(s.empty()){
        //         s.push(a);
        //         break;
        //     }
        // }
        //   int mightbecelebrity=s.top();
        // s.pop();
        //   int i=mightbecelebrity;
        //   for(int j=0;j<mat[i].size();j++){
        //   if(mat[i][j]==1)
        //   return -1;
        //   }
        //   int j=mightbecelebrity;
        //   for(int i=0;i<mat.size();i++){
        //   if(i!=j&&mat[i][j]==0)
        //   return -1;
        //   }
        //   return mightbecelebrity;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends