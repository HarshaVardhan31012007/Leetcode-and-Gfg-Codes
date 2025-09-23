class Solution {
public:
    int firstUniqChar(string s) {
        // int arr[26]={0};
        // for(int i=0;i<s.length();i++){
        //     arr[s[i]-'a']++;
        // }
        // for(int i=0;i<s.length();i++){
        //     if(arr[s[i]-'a']==1)
        //     return i;
        // }
        // return -1;


        queue<int>q;
        int arr[26]={0};
        for(int i=0;i<s.length();i++){
               char ch=s[i];
               arr[ch-'a']++;
               q.push(i);
               while(!q.empty()){
                    int front=q.front();
                    if(arr[s[front]-'a']==1)
                    break;
                    else
                    q.pop();
               }
        }
        return q.empty()?-1:q.front();
    }
};