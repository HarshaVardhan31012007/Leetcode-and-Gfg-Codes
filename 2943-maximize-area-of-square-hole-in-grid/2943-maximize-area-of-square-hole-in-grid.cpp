class Solution {
public:
//     int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
//         unordered_set<int>st1;unordered_set<int>st2;
//         for(auto &each:hBars){
//            st1.insert(each);
//         }
//         for(auto &each:vBars){
//            st2.insert(each);
//         }
//         int ans=0;
//         for(int i=0;i<hBars.size();i++){
//             for(int j=0;j<vBars.size();j++){
//                 int x=hBars[i];
//                 int y=vBars[j];
//                 int up=x;
//                 while(up>1){
//                     if(st1.count(up)){
//                         up=up-1;
//                     }
//                     else
//                     break;
//                 }
//                 int down=x;
//                 while(down<n+2){
//                     if(st1.count(down)){
//                         down=down+1;
//                     }
//                     else
//                     break;
//                 }
//                 int vl=down-up;
//                 int left=y;
//                 while(left>1){
//                     if(st2.count(left))
//                     left=left-1;
//                     else
//                     break;
//                 }
//                 int right=y;
//                 while(right<m+2){
//                     if(st2.count(right))
//                     right=right+1;
//                     else
//                     break;
//                 }
//                 int hl=right-left;
//                 int l=min(hl,vl);
//                 ans=max(ans,l*l);
//             }
//         }
//         return ans;
//     }
// };




    int findgap(vector<int>&Bars){
        int res=2;int count=2;
        sort(Bars.begin(),Bars.end());
        for(int i=1;i<Bars.size();i++){
            if(Bars[i]==Bars[i-1]+1){
                count++;
            }
            else{
                count=2;
            }
            res=max(res,count);
        }
        return res;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
       int gap=min(findgap(hBars),findgap(vBars));
       return gap*gap;
    }
};