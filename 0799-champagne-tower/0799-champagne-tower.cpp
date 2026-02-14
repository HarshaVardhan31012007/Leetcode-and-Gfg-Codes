class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int row=query_row;
        vector<double>v(1);
        v[0]=poured;
        double ans=v[0];
        for(int i=1;i<=row;i++){
            v.push_back(0.0);
            for(int j=i;j>=0;j--){
                v[j]=(j!=0&&v[j-1]>=1?((v[j-1]-1)/2.0):0)+(j!=i&&v[j]>=1?((v[j]-1)/2.0):0);
                if(j==query_glass&&i==row){
                    ans=v[j];
                    break;
                }
            }
        }
        return (ans>=1)?1.0:ans;
    }
};