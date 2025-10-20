class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(auto &operation:operations){
            if(operation=="X++")
            ans++;
            else if(operation=="++X")
            ++ans;
            else if(operation=="X--")
            ans--;
            else
            --ans;
        }
        return ans;
    }
};