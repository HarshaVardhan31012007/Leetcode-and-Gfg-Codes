class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        // vector<vector<int>>ans;
        // int n=arr.size();
        // set<vector<int>>st;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(arr[i]+arr[j]+arr[k]==0){
        //                vector<int>temp={arr[i],arr[j],arr[k]};
        //                sort(temp.begin(),temp.end());
        //                if(st.find(temp)==st.end()){
        //                 ans.push_back(temp);
        //                 st.insert(temp);
        //                }
        //                //or in loop
        //                //sort temp
        //                //st.insert(temp);
        //                //after loop
        //                //vector<int>ans(st.begin(),st.end());
        //             }
        //         }
        //     }
        // }
        // return ans;

        //method 2
       
        // int n=arr.size();
        // set<vector<int>>st;
        // for(int i=0;i<n;i++){
        //     set<int>s;
        //     for(int j=i+1;j<n;j++){
        //         int target=-(arr[i]+arr[j]);
        //         if(s.find(target)!=s.end()){
        //          vector<int>temp={arr[i],arr[j],target};
        //          sort(temp.begin(),temp.end());
        //         st.insert(temp);
        //         }
        //         s.insert(arr[j]);
        //     }
        // }
        // vector<vector<int>>ans(st.begin(),st.end());
        // return ans;

        //method 3
         int n=arr.size();
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            cout<<i<<"hjcdsjc"<<endl;
            if(i>0&&arr[i]==arr[i-1]) continue;
            cout<<i<<endl;
           int j=i+1;
           int k=n-1;
           while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum<0)
            j++;
            else if(sum>0)
            k--;
            else{
                vector<int>temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
               // while(j<k&&arr[j]==arr[j-1])j++;//or 
               while(j<k&&arr[k]==arr[k+1])k--;
               //this any one ot these two should be there
               
            }
           }
        }
        return ans;
    }
};