class Solution {
public:
    // vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    //      sort(potions.begin(),potions.end());
    //      vector<int>ans;
    //      for(int i=0;i<spells.size();i++){
    //           int count=potions.end()-lower_bound(potions.begin(),potions.end(),((double)success)/spells[i]);// double is imp because potions 1 2 3 4 5 and spells 5 1 3 if you take 7/5=1 but here 1 should not accept so take double
    //           ans.push_back(count);
    //      }
    //      return ans;
    // }



    //  int binarysearch(vector<int>&potions,long long success,int spell){
    //     int i=0;
    //     int j=potions.size()-1;
    //     int idx=potions.size();
    //     while(i<=j){
    //         int mid=i+(j-i)/2;
    //         long long p=spell*((long long)potions[mid]);
    //         if(p>=success){
    //             idx=mid;
    //             j=mid-1;
    //         }
    //         else
    //         i=mid+1;
    //     }
    //     return idx;
    //  }
    //  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    //      sort(potions.begin(),potions.end());
    //      vector<int>ans;
    //      for(int i=0;i<spells.size();i++){
    //          int idx=binarysearch(potions,success,spells[i]);
    //          ans.push_back(potions.size()-idx);
    //      }
    //      return ans;
    // }




     int binarysearch(vector<int>&potions,long long success,int spell){
        int i=0;
        int j=potions.size();//imp here n-1
        while(i<j){
            int mid=i+(j-i)/2;
            long long p=spell*((long long)potions[mid]);
            if(p>=success){
                j=mid;
            }
            else
            i=mid+1;
        }
        return j;
     }
     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
         sort(potions.begin(),potions.end());
         vector<int>ans;
         for(int i=0;i<spells.size();i++){
             int idx=binarysearch(potions,success,spells[i]);
             ans.push_back(potions.size()-idx);
         }
         return ans;
    }
};