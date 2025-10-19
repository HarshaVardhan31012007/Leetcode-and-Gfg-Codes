class Solution {
public:
    string rotate(string temp,int k){
        reverse(temp.begin(),temp.end());
        reverse(temp.begin(),temp.begin()+k);
        reverse(temp.begin()+k,temp.end());
        return temp;
    }
    string findLexSmallestString(string s, int a, int b) {
        string ans=s;
        queue<string>q;
        unordered_map<string,bool>visited;
        q.push(s);
        visited[s]=1;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            if(front<ans)
            ans=front;
            string temp=front;
            for(int i=1;i<temp.length();i=i+2){
                temp[i]=((temp[i]-'0'+a)%10)+'0';
            }
            if(!visited[temp]){
                visited[temp]=1;
                q.push(temp);
            }
            temp=rotate(front,b);
            if(!visited[temp]){
                visited[temp]=1;
                q.push(temp);
            }
        }
        return ans;
    }
};