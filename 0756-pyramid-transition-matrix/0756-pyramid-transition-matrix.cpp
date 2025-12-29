class Solution {
public:
    // map<tuple<string,string,int>,bool>mpp1;
    // bool isPyramid(string &bottom,string &temp,unordered_map<string,vector<char>>&mpp,int i){
    //     if(bottom.length()==1) return true;
    //     if(i==bottom.length()-1){
    //         string t="";
    //         return isPyramid(temp,t,mpp,0);
    //     }
    //     if(mpp1.count({bottom,temp,i})) return mpp1[{bottom,temp,i}];
    //     string curr=bottom.substr(i,2);
    //     if(!mpp.count(curr)) return false;
    //     bool ans=false;
    //     for(auto &each:mpp[curr]){
    //         temp.push_back(each);
    //         ans=ans||isPyramid(bottom,temp,mpp,i+1);
    //         temp.pop_back();
    //     }
    //     return mpp1[{bottom,temp,i}]=ans;
    // }
    // bool pyramidTransition(string bottom, vector<string>& allowed) {
    //     unordered_map<string,vector<char>>mpp;
    //     for(auto &each:allowed){
    //         mpp[each.substr(0,2)].push_back(each[2]);
    //     }
    //     string temp="";
    //     return isPyramid(bottom,temp,mpp,0);
    // }

    map<string,bool>mpp1;
    bool isPyramid(string &bottom,string &temp,unordered_map<string,vector<char>>&mpp,int i){
        if(bottom.length()==1) return true;
        if(i==bottom.length()-1){
            string t="";
            if(mpp1.count(temp)) return mpp1[temp];
            return mpp1[temp]=isPyramid(temp,t,mpp,0);
        }
        string curr=bottom.substr(i,2);
        if(!mpp.count(curr)) return false;
        bool ans=false;
        for(auto &each:mpp[curr]){
            temp.push_back(each);
            ans=ans||isPyramid(bottom,temp,mpp,i+1);
            temp.pop_back();
        }
        return ans;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>>mpp;
        for(auto &each:allowed){
            mpp[each.substr(0,2)].push_back(each[2]);
        }
        string temp="";
        return isPyramid(bottom,temp,mpp,0);
    }
};