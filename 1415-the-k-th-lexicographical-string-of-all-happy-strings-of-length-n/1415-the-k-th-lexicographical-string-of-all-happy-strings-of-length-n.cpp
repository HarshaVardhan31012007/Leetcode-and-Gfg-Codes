class Solution {
public:
    void generateHappyStrings(int n,string &temp,int prev,int &count,string &ans,int k){
        if(n==0){
            count++;
            if(count==k)
            ans=temp;
            return;
        }
        if(prev!=0){
            temp.push_back('a');
            generateHappyStrings(n-1,temp,0,count,ans,k);
            if(ans!="") return;
            temp.pop_back();
        }
        if(prev!=1){
            temp.push_back('b');
            generateHappyStrings(n-1,temp,1,count,ans,k);
            if(ans!="") return;
            temp.pop_back();
        }
        if(prev!=2){
            temp.push_back('c');
            generateHappyStrings(n-1,temp,2,count,ans,k);
            if(ans!="") return;
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string temp="";
        string ans="";
        int count=0;
        generateHappyStrings(n,temp,-1,count,ans,k);
        return ans;
    }
};