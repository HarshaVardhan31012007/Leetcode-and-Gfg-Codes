class Solution {
public:
    int d(vector<int>&p1,vector<int>&p2){
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int,int>mpp;
        mpp[d(p1,p2)]++;
        mpp[d(p1,p3)]++;
        mpp[d(p1,p4)]++;
        mpp[d(p2,p3)]++;
        mpp[d(p2,p4)]++;
        mpp[d(p3,p4)]++;
        if(mpp.size()!=2) return false;
        auto it=mpp.end();it--;
        return it->second==2&&(mpp.begin()->second==4)&&(it->first)==(2*(mpp.begin()->first));
    }
};