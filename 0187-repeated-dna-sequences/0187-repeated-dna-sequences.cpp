class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // unordered_map<string,int>mpp;
        // vector<string>ans;
        // for(int i=0;i<=(int)s.length()-10;i++){
        //     string curr=s.substr(i,10);
        //     mpp[curr]++;
        //     if(mpp[curr]==2)
        //     ans.push_back(curr);
        // }
        // return ans;


        // unordered_map<string,int>mpp;
        // vector<string>ans;
        // for(int i=0;i<=(int)s.length()-10;i++){
        //     string curr=s.substr(i,10);
        //     mpp[curr]++;
        //     if(mpp[curr]>1){
        //     ans.push_back(curr);
        //     mpp[curr]=INT_MIN;
        //     }
        // }
        // return ans;



        unordered_map<string,int>mpp;
        vector<string>ans;
        string temp=s.substr(0,10);
        mpp[temp]++;
        int j=10;
        while(j<s.length()){
            temp+=s[j];
            temp.erase(temp.begin(),temp.begin()+1);
            mpp[temp]++;
            if(mpp[temp]==2)
            ans.push_back(temp);
            j++;
        }
        return ans;
    }
};