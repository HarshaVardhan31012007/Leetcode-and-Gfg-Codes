class Solution {
public:
    int csum;
    vector<int>temp;
    Solution(vector<int>& w) {
        csum=0;
        for(auto &each:w){
            csum+=each;
            temp.push_back(csum);
        }
    }
    
    int pickIndex() {
        int r=rand()%csum+1;
        auto it=lower_bound(temp.begin(),temp.end(),r);
        return (it-temp.begin());
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */