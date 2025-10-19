class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
         queue<pair<string,int>>q;
         set<string>st(deadends.begin(),deadends.end());
         unordered_map<string,bool>visited;
         q.push({"0000",0});
         visited["0000"]=1;
         while(!q.empty()){
              auto front=q.front().first;
              auto num=q.front().second;
              q.pop();
              if(st.find(front)!=st.end())
              continue;
              if(front==target)
              return num;
              string temp=front;
              for(int i=0;i<temp.length();i++){
                 char original=temp[i];
                 temp[i]=((temp[i]-'0'+1)%10)+'0';
                 if(!visited[temp]){
                    visited[temp]=1;
                    q.push({temp,num+1});
                 }
                 temp[i]=original;
                 temp[i]=((temp[i]-'0'-1+10)%10)+'0';
                 if(!visited[temp]){
                    visited[temp]=1;
                    q.push({temp,num+1});
                 }
                 temp[i]=original;
              }
         }
         return -1;
    }
};