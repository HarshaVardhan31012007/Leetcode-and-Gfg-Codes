//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  bool isSafe(int newx,int newy,vector<vector<int>>&mat,int n,vector<vector<bool>>&visited){
      if(newx<0||newy<0||newx>=n||newy>=n)
      return false;
      if(mat[newx][newy]==0)
      return false;
      if(visited[newx][newy]==true)
      return false;
      
      return true;
  }
  void solve(int curx,int cury,int destx,int desty,vector<vector<int>>&mat,vector<vector<bool>>&visited,int n,vector<string>&ans,string output){
          
          if(curx==destx&&cury==desty){
              ans.push_back(output);
              return;
          }
          int dx[]={-1,1,0,0};
          int dy[]={0,0,-1,1};
          char move[]={'U','D','L','R'};
          int m=4;
          
          for(int i=0;i<m;i++){
              int newx=curx+dx[i];
              int newy=cury+dy[i];
              if(isSafe(newx,newy,mat,n,visited)){
                  visited[newx][newy]=true;
                  solve(newx,newy,destx,desty,mat,visited,n,ans,output+move[i]);
                  visited[newx][newy]=false;
              }
          }
  }
    vector<string> findPath(vector<vector<int>> &mat) {
          
          vector<string>ans;
          int n=mat.size();
          vector<vector<bool>>visited(n,vector<bool>(n,0));
          int curx=0;
          int cury=0;
          int destx=n-1;
          int desty=n-1;
          if(mat[0][0]==0)
          return ans;
          visited[0][0]=true;
          string output="";
         solve(curx,cury,destx,desty,mat,visited,n,ans,output);
         return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends