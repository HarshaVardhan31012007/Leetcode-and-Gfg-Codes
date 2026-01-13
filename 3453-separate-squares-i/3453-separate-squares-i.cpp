class Solution {
public:
    double find(vector<vector<int>>&squares,double mid){
        double up=0;
        double down=0;
        for(auto &each:squares){
            double l=each[2];
            if(each[1]>=mid){
                up+=l*l;
            }
            else if(mid>=each[1]+l){
                down+=l*l;
            }
            else{
                up+=l*(each[1]+l-mid);
                down+=l*(mid-each[1]);
            }
        }
        return up-down;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double s=(int)1e9;
        double e=0;
        for(auto &each:squares){
            s=min(s,(double)each[1]);
            e=max(e,(double)(each[1]+each[2]));
        }
        double ans;
        while(e-s>0.00001){
            double mid=(s+e)/2.0;
            double diff=find(squares,mid);
            if(diff<=0){
                e=mid-0.000001;
            }
            else{
               s=mid+0.000001;
            }
        }
        return (s+e)/2.0;
    }
};