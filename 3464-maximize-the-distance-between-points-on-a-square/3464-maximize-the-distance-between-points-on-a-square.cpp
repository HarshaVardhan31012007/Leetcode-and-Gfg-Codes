class Solution {
public:
    typedef long long ll;
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll>arr;
        ll n=points.size();
        ll perimeter=4LL*side;
        for(auto &each:points){
            if(each[1]==0){
                arr.push_back(each[0]);
            }
            else if(each[0]==side){
                arr.push_back(side+each[1]);
            }
            else if(each[1]==side){
                arr.push_back(3LL*side-each[0]);
            }
            else{
                arr.push_back(4LL*side-each[1]);
            }
        }
        sort(arr.begin(),arr.end());
        vector<ll>doubled(2*n);
        for(int i=0;i<n;i++){
            doubled[i]=arr[i];
            doubled[i+n]=arr[i]+perimeter;
        }
        auto possible=[&](ll mid){
            for(int i=0;i<n;i++){
                int count=1;
                int lastPos=i;
                for(int j=2;j<=k;j++){
                    auto it=lower_bound(doubled.begin()+i+1,doubled.begin()+i+n,doubled[lastPos]+mid);
                    if(it==doubled.begin()+i+n){
                        break;
                    }
                    lastPos=it-doubled.begin();
                    count++;
                }
                if(count==k&&doubled[i]+perimeter-doubled[lastPos]>=mid){
                    return true;
                }
            }
            return false;
        };
        ll low=0;ll high=side;
        ll ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(possible(mid)){
               ans=mid;
               low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};