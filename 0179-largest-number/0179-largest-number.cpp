class Solution {
public:
    static bool comp(string &a,string &b){
       string p=a+b;
       string q=b+a;
       int i=0;
       while(i<p.length()){
        if(p[i]==q[i]){
            i++;
        }
        else
        return p[i]<q[i];
       }
       return p[0]<q[0];
    }
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(int i=0;i<nums.size();i++){
            // string k="";
            // int n=nums[i];
            // while(n>0){
            //    char ch=n%10+'0';
            //    k=ch+k;
            // }
            string k=to_string(nums[i]);
            arr.push_back(k);
        }
        sort(arr.begin(),arr.end(),comp);
        string ans="";
        for(int i=arr.size()-1;i>=0;i--){
            ans+=arr[i];
        }
        int i=0;
        while(i<ans.length()&&ans[i]=='0')
        i++;
        if(i==ans.length()) return "0";
        return ans.substr(i);
    }
};