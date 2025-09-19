class Solution {
public:
    void nextSmaller(vector<int>&temp,vector<int>&nexts){
         stack<int>s;
        for(int i=temp.size()-1;i>=0;i--){
              while(!s.empty()&&temp[s.top()]>=temp[i]){
                s.pop();
              }
              if(s.empty()) nexts[i]=temp.size();
              else nexts[i]=s.top();
              s.push(i);
        }
    }
     void prevSmaller(vector<int>&temp,vector<int>&prevs){
        stack<int>s;
        for(int i=0;i<temp.size();i++){
              while(!s.empty()&&temp[s.top()]>=temp[i]){
                s.pop();
              }
              if(s.empty()) prevs[i]=-1;
              else prevs[i]=s.top();
              s.push(i);
        }
    }
    int find(vector<int>&temp){
        vector<int>nexts(temp.size());
        nextSmaller(temp,nexts);
        vector<int>prevs(temp.size());
        prevSmaller(temp,prevs);
        int maxi=INT_MIN;
        for(int i=0;i<temp.size();i++){
            int w=nexts[i]-prevs[i]-1;
            int h=temp[i];
            maxi=max(maxi,w*h);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>temp(matrix[0].size(),0);
        int ans=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                temp[j]=(matrix[i][j]=='0'?0:(1+temp[j]));
            }
            int curr=find(temp);
            cout<<curr<<endl;
            ans=max(ans,curr);
        }
        return ans;
    }
};