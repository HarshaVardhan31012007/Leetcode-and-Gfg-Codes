class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    //    unordered_map<int,int>mpp;
    //    vector<int>ans(2);
    //    int n=grid.size();
    //    for(int i=0;i<n*n;i++)
    //    mpp[i+1]=1;
    //    for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(mpp[grid[i][j]]==0)
    //          ans[0]=grid[i][j];
    //          mpp[grid[i][j]]=0;
    //     }
    //    }
    //    for(auto &each:mpp){
    //     if(each.second==1)
    //     ans[1]=each.first;
    //    }
    //    return ans;



    //    vector<int>ans(2);
    //    int n=grid.size();
    //    for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //        int row=(abs(grid[i][j])-1)/n;
    //        int col=(abs(grid[i][j])-1)%n;
    //        if(grid[row][col]<0)
    //        ans[0]=n*row+col+1;
    //        else
    //        grid[row][col]*=-1;
    //     }
    //    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(grid[i][j]>0){
    //         ans[1]=n*i+j+1;
    //         break;
    //         }
    //     }
    // }
    //     return ans;



    //    vector<int>ans(2);
    //    unordered_map<int,int>mpp;
    //    int n=grid.size();
    //    int sum=((n*n)*((n*n)+1))/2;
    //    int asum=0;
    //    for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //       asum+=grid[i][j];
    //       if(mpp.find(grid[i][j])!=mpp.end()){
    //         ans[0]=grid[i][j];
    //       }
    //       mpp[grid[i][j]]=1;
    //     }
    //    }
    //    ans[1]=sum-asum+ans[0];
    //    return ans;


    //    vector<int>ans(2);
    //    long long int n=grid.size();
    //    int sum=((n*n)*((n*n)+1))/2;
    //    long long int prod=((n*n)*((n*n)+1)*(2*(n*n)+1))/6;
    //    int asum=0;
    //    long long int aprod=0;
    //    for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //       asum+=grid[i][j];
    //       aprod+=grid[i][j]*grid[i][j];
    //     }
    //    }
    //    int a=sum-asum;
    //    int b=prod-aprod;
    //    b=b/a;
    //    ans[0]=(b-a)/2;
    //    ans[1]=(a+b)/2;
    //    return ans;


        int xr=0;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                xr=xr^grid[i][j];
                xr=xr^(n*i+j+1);
            }
        }
        int bitNo=0;
        while(1){
            if((xr & (1<<bitNo))){
                break;
            }
            bitNo++;
        }
        int one=0;int zero=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] & (1<<bitNo))
                one=one^grid[i][j];
                else
                zero=zero^grid[i][j];
            }
        }
        for(int i=0;i<n*n;i++){
            if(i+1 & (1<<bitNo))
            one=one^(i+1);
            else
            zero=zero^(i+1);
        }
        int count=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==one)
               count++;
            }
        }
        if(count==2) return {one,zero};
        return {zero,one};
    }
};